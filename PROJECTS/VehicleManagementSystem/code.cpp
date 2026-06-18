#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <limits>
#include <algorithm>
#include <sstream>
#include <memory>      // Smart pointers
#include <stdexcept>   // Exception handling
#include <chrono>      // Date handling
#include <ctime>
#include <map>

using namespace std;

// ==========================================
// DATE UTILITY CLASS
// ==========================================
class Date {
private:
    int year, month, day;

public:
    Date() : year(2024), month(1), day(1) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    static Date fromString(const string& dateStr) {
        // Parse YYYY-MM-DD format
        istringstream ss(dateStr);
        int y, m, d;
        char dash1, dash2;
        ss >> y >> dash1 >> m >> dash2 >> d;
        return Date(y, m, d);
    }
    
    string toString() const {
        ostringstream oss;
        oss << year << "-" << setfill('0') << setw(2) << month << "-" << setw(2) << day;
        return oss.str();
    }
    
    // Calculate days between dates (simplified)
    int daysUntil(const Date& other) const {
        // Simplified calculation (not accounting for leap years properly)
        int days1 = year * 365 + month * 30 + day;
        int days2 = other.year * 365 + other.month * 30 + other.day;
        return abs(days2 - days1);
    }
    
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

// ==========================================
// DATA VALIDATION HELPER FUNCTIONS
// ==========================================
int getValidInt(const string& prompt, int min = numeric_limits<int>::min(), 
                int max = numeric_limits<int>::max()) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

float getValidFloat(const string& prompt, float min = 0.0f, 
                   float max = numeric_limits<float>::max()) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string getValidString(const string& prompt, bool allowEmpty = false) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);
        if (!value.empty() || allowEmpty) return value;
        cout << "Input cannot be empty. Please try again.\n";
    }
}

Date getValidDate(const string& prompt) {
    while (true) {
        string dateStr = getValidString(prompt);
        try {
            return Date::fromString(dateStr);
        } catch (...) {
            cout << "Invalid date format. Please use YYYY-MM-DD.\n";
        }
    }
}

// ==========================================
// MULTIPLE INHERITANCE PREP
// ==========================================
class LivingAccommodation {
protected:
    int beds;
    bool hasKitchen;

public:
    LivingAccommodation(int b, bool k) : beds(b), hasKitchen(k) {}
    
    void displayAccommodation() const {
        cout << " [Beds: " << beds << (hasKitchen ? ", Kitchen: Yes]" : ", Kitchen: No]");
    }
    
    int getBeds() const { return beds; }
    bool getHasKitchen() const { return hasKitchen; }
};

// ==========================================
// BASE CLASS: VEHICLE
// ==========================================
class Vehicle {
private:
    string make;
    string model;
    int year;
    float baseRate;
    bool isRented;
    static int totalVehicles;

protected:
    string licensePlate;

public:

    Vehicle(const string& mk, const string& md, int yr, float rate, const string& plate) 
    : make(mk), model(md), year(yr), baseRate(rate), isRented(false), licensePlate(plate) {
    totalVehicles++;
    }

    virtual ~Vehicle() { totalVehicles--; }

    // Prevent copying (Rule of Five)
    Vehicle(const Vehicle&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    Vehicle(Vehicle&&) = default;
    Vehicle& operator=(Vehicle&&) = default;

    static int getTotalVehicles() { return totalVehicles; }

    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    float getBaseRate() const { return baseRate; }
    string getPlate() const { return licensePlate; }
    bool getStatus() const { return isRented; }
    
    void setStatus(bool status) { isRented = status; }

    // Pure virtual functions for polymorphism
    virtual float calculateRentalCost(int days) const = 0;
    virtual string getType() const = 0;
    virtual string serialize() const = 0;  // For saving complete data

    // Virtual display function
    virtual void displayDetails() const {
        cout << left << setw(10) << licensePlate << " | " 
             << setw(6) << year << " | " 
             << setw(12) << make << " | " 
             << setw(12) << model << " | $" 
             << setw(6) << fixed << setprecision(2) << baseRate << "/day | "
             << (isRented ? "RENTED   " : "AVAILABLE");
    }

    // Operator overloading for searching
    bool operator==(const string& plateSearch) const {
        return this->licensePlate == plateSearch;
    }

    // Friend function for audit
    friend void auditVehicle(const Vehicle& v);
};

int Vehicle::totalVehicles = 0;

void auditVehicle(const Vehicle& v) {
    cout << "AUDIT: Vehicle " << v.licensePlate 
         << " base daily revenue: $" << fixed << setprecision(2) << v.baseRate << endl;
}

// ==========================================
// DERIVED CLASSES
// ==========================================
class Car : public Vehicle {
private:
    int passengerCapacity;

public:
    Car(const string& mk, const string& md, int yr, float rate, 
        const string& plate, int cap)
        : Vehicle(mk, md, yr, rate, plate), passengerCapacity(cap) {}

    float calculateRentalCost(int days) const override {
        float total = getBaseRate() * days;
        if (days > 7) total *= 0.90f;  // 10% discount for week+
        if (days > 30) total *= 0.85f; // Additional 15% off for month+
        return total;
    }
    
    string getType() const override { return "Car"; }

    string serialize() const override {
        ostringstream oss;
        oss << getPlate() << "," << getType() << "," << getMake() << "," 
            << getModel() << "," << getYear() << "," << getBaseRate() << "," 
            << (getStatus() ? "1" : "0") << "," << passengerCapacity;
        return oss.str();
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << " | Type: Car (" << passengerCapacity << " seats)" << endl;
    }
    
    int getCapacity() const { return passengerCapacity; }
};

class Truck : public Vehicle {
private:
    float payloadCapacity;

public:
    Truck(const string& mk, const string& md, int yr, float rate, 
          const string& plate, float payload)
        : Vehicle(mk, md, yr, rate, plate), payloadCapacity(payload) {}

    float calculateRentalCost(int days) const override {
        return (getBaseRate() * days) + 50.0f;  // Flat insurance fee
    }
    
    string getType() const override { return "Truck"; }

    string serialize() const override {
        ostringstream oss;
        oss << getPlate() << "," << getType() << "," << getMake() << "," 
            << getModel() << "," << getYear() << "," << getBaseRate() << "," 
            << (getStatus() ? "1" : "0") << "," << payloadCapacity;
        return oss.str();
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << " | Type: Truck (" << fixed << setprecision(1) 
             << payloadCapacity << " tons)" << endl;
    }
    
    float getPayload() const { return payloadCapacity; }
};

class CamperVan : public Vehicle, public LivingAccommodation {
public:
    CamperVan(const string& mk, const string& md, int yr, float rate, 
              const string& plate, int beds, bool kitchen)
        : Vehicle(mk, md, yr, rate, plate), LivingAccommodation(beds, kitchen) {}

    float calculateRentalCost(int days) const override {
        return (getBaseRate() + 20.0f) * days;  // Extra cleaning fee per day
    }
    
    string getType() const override { return "CamperVan"; }

    string serialize() const override {
        ostringstream oss;
        oss << getPlate() << "," << getType() << "," << getMake() << "," 
            << getModel() << "," << getYear() << "," << getBaseRate() << "," 
            << (getStatus() ? "1" : "0") << "," << beds << "," << (hasKitchen ? "1" : "0");
        return oss.str();
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << " | Type: CamperVan";
        displayAccommodation(); 
        cout << endl;
    }
};

// ==========================================
// CUSTOMER CLASS
// ==========================================
class Customer {
private:
    string name;
    string driversLicense;
    int loyaltyPoints;
    string email;
    string phone;

public:
    Customer(const string& n, const string& dl, int points = 0, 
             const string& em = "", const string& ph = "")
        : name(n), driversLicense(dl), loyaltyPoints(points), email(em), phone(ph) {}

    // Getters
    string getName() const { return name; }
    string getLicense() const { return driversLicense; }
    int getPoints() const { return loyaltyPoints; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    
    void addPoints(int p) { 
        loyaltyPoints += p; 
        if (loyaltyPoints >= 500) {
            cout << "🎉 " << name << " has earned VIP status with " 
                 << loyaltyPoints << " points!\n";
        }
    }
    
    void redeemPoints(int p) {
        if (p <= loyaltyPoints) {
            loyaltyPoints -= p;
            cout << "Redeemed " << p << " points. Remaining: " << loyaltyPoints << "\n";
        } else {
            cout << "Insufficient points. Available: " << loyaltyPoints << "\n";
        }
    }

    string serialize() const {
        ostringstream oss;
        oss << name << "," << driversLicense << "," << loyaltyPoints << "," 
            << email << "," << phone;
        return oss.str();
    }

    // Operator overloading for easy printing
    friend ostream& operator<<(ostream& os, const Customer& c) {
        os << left << setw(20) << c.name << " | DL: " << setw(15) << c.driversLicense 
           << " | Points: " << setw(4) << c.loyaltyPoints;
        if (!c.email.empty()) os << " | Email: " << c.email;
        return os;
    }
};

// ==========================================
// RENTAL RECORD CLASS
// ==========================================
class RentalRecord {
private:
    shared_ptr<Customer> customer;  // Changed to shared_ptr for safety
    string customerLicense;          // Store license for persistence
    Vehicle* vehicle;
    string vehiclePlate;             // Store plate for persistence
    Date dateRented;
    Date dateReturned;
    float totalCost;
    bool isActive;
    int daysRented;

public:
    RentalRecord(shared_ptr<Customer> c, Vehicle* v, const Date& dRented) 
        : customer(c), customerLicense(c->getLicense()), vehicle(v), 
          vehiclePlate(v->getPlate()), dateRented(dRented), 
          totalCost(0.0f), isActive(true), daysRented(0) {}

    void closeRecord(const Date& dReturned, int days) {
        dateReturned = dReturned;
        daysRented = days;
        totalCost = vehicle->calculateRentalCost(days);
        isActive = false;
        
        // Award loyalty points (1 point per $10 spent)
        if (customer != nullptr) {
            int pointsEarned = static_cast<int>(totalCost / 10);
            customer->addPoints(pointsEarned);
            cout << "🎁 Earned " << pointsEarned << " loyalty points!\n";
        }
    }

    bool getIsActive() const { return isActive; }
    Vehicle* getVehicle() const { return vehicle; }
    float getTotalCost() const { return totalCost; }
    
    string serialize() const {
        ostringstream oss;
        oss << customerLicense << "," << vehiclePlate << "," 
            << dateRented.toString() << "," 
            << (isActive ? "ACTIVE" : dateReturned.toString()) << "," 
            << totalCost << "," << (isActive ? "1" : "0") << "," << daysRented;
        return oss.str();
    }

    void displayRecord() const {
        cout << left << setw(15) << (customer ? customer->getName() : "Unknown") 
             << " | Vehicle: " << setw(10) << vehiclePlate
             << " | Out: " << setw(12) << dateRented.toString()
             << " | In: " << setw(12) << (isActive ? "Pending" : dateReturned.toString())
             << " | Days: " << setw(3) << daysRented
             << " | Cost: $" << setw(8) << fixed << setprecision(2) << totalCost 
             << " | " << (isActive ? "ACTIVE" : "CLOSED") << "\n";
    }
};

// ==========================================
// RENTAL AGENCY (Enhanced)
// ==========================================
class RentalAgency {
private:
    vector<unique_ptr<Vehicle>> fleet;  // Smart pointers for automatic memory management
    map<string, shared_ptr<Customer>> customers;  // Map for O(1) lookup
    vector<unique_ptr<RentalRecord>> rentalHistory;
    
    // Statistics
    float totalRevenue;
    int totalRentals;

    // Helper to find vehicle by plate
    Vehicle* findVehicle(const string& plate) {
        auto it = find_if(fleet.begin(), fleet.end(), 
            [&plate](const unique_ptr<Vehicle>& v) { return *v == plate; });
        return (it != fleet.end()) ? it->get() : nullptr;
    }

    // Helper to find customer by license
    shared_ptr<Customer> findCustomer(const string& dl) {
        auto it = customers.find(dl);
        return (it != customers.end()) ? it->second : nullptr;
    }

    // Parse CSV line safely
    vector<string> parseCSV(const string& line) {
        vector<string> result;
        stringstream ss(line);
        string field;
        while (getline(ss, field, ',')) {
            result.push_back(field);
        }
        return result;
    }

public:
    RentalAgency() : totalRevenue(0.0f), totalRentals(0) {}

    void loadDummyData() {
        if (!fleet.empty()) return;
        
        fleet.push_back(make_unique<Car>("Toyota", "Camry", 2022, 45.0, "CAR-123", 5));
        fleet.push_back(make_unique<Car>("Honda", "Civic", 2023, 42.0, "CAR-456", 5));
        fleet.push_back(make_unique<Truck>("Ford", "F-150", 2021, 75.0, "TRK-999", 2.5));
        fleet.push_back(make_unique<CamperVan>("Mercedes", "Sprinter", 2023, 120.0, "VAN-001", 2, true));
        
        customers["DL-987654"] = make_shared<Customer>("Alice Smith", "DL-987654", 150, 
                                                        "alice@email.com", "555-0101");
        customers["DL-123456"] = make_shared<Customer>("Bob Johnson", "DL-123456", 20, 
                                                        "bob@email.com", "555-0202");
    }

    void displayFleet() const {
        cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                         CURRENT FLEET INVENTORY                                ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
        
        if (fleet.empty()) { 
            cout << "Fleet is empty.\n"; 
            return; 
        }
        
        int available = count_if(fleet.begin(), fleet.end(), 
            [](const unique_ptr<Vehicle>& v) { return !v->getStatus(); });
        
        for (const auto& v : fleet) v->displayDetails();
        
        cout << "─────────────────────────────────────────────────────────────────────────────────\n";
        cout << "Total Vehicles: " << Vehicle::getTotalVehicles() 
             << " | Available: " << available 
             << " | Rented: " << (Vehicle::getTotalVehicles() - available) << "\n";
    }

    void displayCustomers() const {
        cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                         REGISTERED CUSTOMERS                                   ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
        
        if (customers.empty()) { 
            cout << "No customers registered.\n"; 
            return; 
        }
        
        for (const auto& pair : customers) {
            cout << *(pair.second) << endl;
        }
        cout << "Total Customers: " << customers.size() << "\n";
    }

    void displayRentalRecords() const {
        cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                            RENTAL HISTORY                                      ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
        
        if (rentalHistory.empty()) { 
            cout << "No rental records exist.\n"; 
            return; 
        }
        
        int active = 0;
        for (const auto& r : rentalHistory) {
            r->displayRecord();
            if (r->getIsActive()) active++;
        }
        cout << "─────────────────────────────────────────────────────────────────────────────────\n";
        cout << "Total Rentals: " << rentalHistory.size() 
             << " | Active: " << active 
             << " | Completed: " << (rentalHistory.size() - active) << "\n";
    }

    void displayStatistics() const {
        cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                          BUSINESS STATISTICS                                   ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
        
        cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << "\n";
        cout << "Total Rentals Completed: " << totalRentals << "\n";
        cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << "\n";
        cout << "Total Customers: " << customers.size() << "\n";
        
        if (totalRentals > 0) {
            cout << "Average Revenue per Rental: $" 
                 << (totalRevenue / totalRentals) << "\n";
        }
    }

    void addVehicle() {
        cout << "\n--- Add New Vehicle ---\n";
        int type = getValidInt("Enter Type (1: Car, 2: Truck, 3: CamperVan): ", 1, 3);
        
        string make = getValidString("Enter Make: ");
        string model = getValidString("Enter Model: ");
        int year = getValidInt("Enter Year: ", 1900, 2030);
        float rate = getValidFloat("Enter Daily Rate: $", 0.0f, 10000.0f);
        string plate = getValidString("Enter License Plate (unique): ");

        if (findVehicle(plate) != nullptr) {
            cout << "❌ Error: Vehicle with this plate already exists!\n";
            return;
        }

        try {
            if (type == 1) {
                int cap = getValidInt("Enter Passenger Capacity: ", 1, 20);
                fleet.push_back(make_unique<Car>(make, model, year, rate, plate, cap));
            } else if (type == 2) {
                float payload = getValidFloat("Enter Payload Capacity (Tons): ", 0.0f, 100.0f);
                fleet.push_back(make_unique<Truck>(make, model, year, rate, plate, payload));
            } else {
                int beds = getValidInt("Enter Number of Beds: ", 1, 10);
                int k = getValidInt("Kitchen included? (1: Yes, 0: No): ", 0, 1);
                fleet.push_back(make_unique<CamperVan>(make, model, year, rate, plate, beds, k == 1));
            }
            cout << "✅ Vehicle successfully added to fleet!\n";
        } catch (const exception& e) {
            cout << "❌ Error adding vehicle: " << e.what() << "\n";
        }
    }

    void rentVehicle() {
        cout << "\n--- Rent a Vehicle ---\n";
        string dl = getValidString("Enter Customer Driver's License: ");
        auto c = findCustomer(dl);
        
        if (!c) {
            cout << "Customer not found. Creating new customer profile.\n";
            string name = getValidString("Enter Customer Name: ");
            string email = getValidString("Enter Email (optional): ", true);
            string phone = getValidString("Enter Phone (optional): ", true);
            c = make_shared<Customer>(name, dl, 0, email, phone);
            customers[dl] = c;
            cout << "✅ New customer profile created.\n";
        }

        string plate = getValidString("Enter License Plate of vehicle to rent: ");
        Vehicle* v = findVehicle(plate);
        
        if (!v) {
            cout << "❌ Error: Vehicle not found.\n";
            return;
        }
        if (v->getStatus()) {
            cout << "❌ Error: Vehicle is already rented out.\n";
            return;
        }

        Date dateRented = getValidDate("Enter rental start date (YYYY-MM-DD): ");

        v->setStatus(true);
        rentalHistory.push_back(make_unique<RentalRecord>(c, v, dateRented));
        
        cout << "✅ Vehicle successfully rented to " << c->getName() << "!\n";
        
        // Show estimated cost
        int estimatedDays = getValidInt("Enter estimated rental days (for quote): ", 1, 365);
        float estimate = v->calculateRentalCost(estimatedDays);
        cout << "💰 Estimated cost for " << estimatedDays << " days: $" 
             << fixed << setprecision(2) << estimate << "\n";
    }

    void returnVehicle() {
        cout << "\n--- Return a Vehicle ---\n";
        string plate = getValidString("Enter License Plate of vehicle to return: ");
        Vehicle* v = findVehicle(plate);
        
        if (!v) {
            cout << "❌ Error: Vehicle not found.\n";
            return;
        }
        if (!v->getStatus()) {
            cout << "❌ Error: Vehicle is not currently rented.\n";
            return;
        }

        // Find active rental record
        RentalRecord* activeRecord = nullptr;
        for (const auto& r : rentalHistory) {
            if (r->getVehicle() == v && r->getIsActive()) {
                activeRecord = r.get();
                break;
            }
        }

        if (!activeRecord) {
            cout << "❌ Error: Could not locate the active rental record.\n"; 
            return;
        }

        Date dateReturned = getValidDate("Enter return date (YYYY-MM-DD): ");
        int days = getValidInt("Enter total number of days rented: ", 1, 365);
        
        // Close the record
        activeRecord->closeRecord(dateReturned, days);
        v->setStatus(false);

        // Update statistics
        totalRevenue += activeRecord->getTotalCost();
        totalRentals++;

        cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                            RETURN RECEIPT                                      ║\n";
        cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
        activeRecord->displayRecord();
        cout << "✅ Vehicle " << plate << " successfully returned to the fleet.\n";
    }

    void saveSystemData() {
        try {
            // Save vehicles
            ofstream vehicleFile("fleet_data.txt");
            if (!vehicleFile) throw runtime_error("Cannot open fleet_data.txt");
            
            vehicleFile << "PLATE,TYPE,MAKE,MODEL,YEAR,RATE,STATUS,EXTRA\n";
            for (const auto& v : fleet) {
                vehicleFile << v->serialize() << "\n";
            }
            vehicleFile.close();

            // Save customers
            ofstream customerFile("customer_data.txt");
            if (!customerFile) throw runtime_error("Cannot open customer_data.txt");
            
            customerFile << "NAME,LICENSE,POINTS,EMAIL,PHONE\n";
            for (const auto& pair : customers) {
                customerFile << pair.second->serialize() << "\n";
            }
            customerFile.close();

            // Save rental history
            ofstream rentalFile("rental_history.txt");
            if (!rentalFile) throw runtime_error("Cannot open rental_history.txt");
            
            rentalFile << "CUSTOMER_DL,VEHICLE_PLATE,DATE_RENTED,DATE_RETURNED,COST,ACTIVE,DAYS\n";
            for (const auto& r : rentalHistory) {
                rentalFile << r->serialize() << "\n";
            }
            rentalFile.close();

            // Save statistics
            ofstream statsFile("statistics.txt");
            if (!statsFile) throw runtime_error("Cannot open statistics.txt");
            statsFile << totalRevenue << "," << totalRentals << "\n";
            statsFile.close();

            cout << "✅ System data saved successfully!\n";
        } catch (const exception& e) {
            cout << "❌ Error saving data: " << e.what() << "\n";
        }
    }

    void loadSystemData() {
        try {
            // Load vehicles
            ifstream vehicleFile("fleet_data.txt");
            if (vehicleFile) {
                string line;
                getline(vehicleFile, line); // Skip header
                
                while (getline(vehicleFile, line)) {
                    if (line.empty()) continue;
                    
                    auto fields = parseCSV(line);
                    if (fields.size() < 8) continue;
                    
                    string plate = fields[0];
                    string type = fields[1];
                    string make = fields[2];
                    string model = fields[3];
                    int year = stoi(fields[4]);
                    float rate = stof(fields[5]);
                    bool status = (fields[6] == "1");
                    
                    if (findVehicle(plate)) continue;
                    
                    unique_ptr<Vehicle> v;
                    if (type == "Car") {
                        int cap = (fields.size() > 7) ? stoi(fields[7]) : 4;
                        v = make_unique<Car>(make, model, year, rate, plate, cap);
                    } else if (type == "Truck") {
                        float payload = (fields.size() > 7) ? stof(fields[7]) : 2.0f;
                        v = make_unique<Truck>(make, model, year, rate, plate, payload);
                    } else if (type == "CamperVan") {
                        int beds = (fields.size() > 7) ? stoi(fields[7]) : 2;
                        bool kitchen = (fields.size() > 8) ? (fields[8] == "1") : true;
                        v = make_unique<CamperVan>(make, model, year, rate, plate, beds, kitchen);
                    }
                    
                    if (v) {
                        v->setStatus(status);
                        fleet.push_back(move(v));
                    }
                }
                vehicleFile.close();
                cout << "✅ Loaded " << fleet.size() << " vehicles.\n";
            }

            // Load customers
            ifstream customerFile("customer_data.txt");
            if (customerFile) {
                string line;
                getline(customerFile, line); // Skip header
                
                while (getline(customerFile, line)) {
                    if (line.empty()) continue;
                    
                    auto fields = parseCSV(line);
                    if (fields.size() < 3) continue;
                    
                    string name = fields[0];
                    string license = fields[1];
                    int points = stoi(fields[2]);
                    string email = (fields.size() > 3) ? fields[3] : "";
                    string phone = (fields.size() > 4) ? fields[4] : "";
                    
                    customers[license] = make_shared<Customer>(name, license, points, email, phone);
                }
                customerFile.close();
                cout << "✅ Loaded " << customers.size() << " customers.\n";
            }

            // Load statistics
            ifstream statsFile("statistics.txt");
            if (statsFile) {
                string line;
                if (getline(statsFile, line)) {
                    auto fields = parseCSV(line);
                    if (fields.size() >= 2) {
                        totalRevenue = stof(fields[0]);
                        totalRentals = stoi(fields[1]);
                    }
                }
                statsFile.close();
            }

            if (fleet.empty()) {
                cout << "No saved data found. Loading default data.\n";
                loadDummyData();
            }
        } catch (const exception& e) {
            cout << "⚠️  Error loading data: " << e.what() << "\nLoading default data.\n";
            loadDummyData();
        }
    }

    void searchVehicles() {
        cout << "\n--- Search Vehicles ---\n";
        cout << "1. Search by Type\n";
        cout << "2. Search by Make\n";
        cout << "3. Search by Max Price\n";
        cout << "4. Show Available Only\n";
        
        int choice = getValidInt("Enter search option: ", 1, 4);
        
        vector<Vehicle*> results;
        
        if (choice == 1) {
            string type = getValidString("Enter type (Car/Truck/CamperVan): ");
            for (const auto& v : fleet) {
                if (v->getType() == type) results.push_back(v.get());
            }
        } else if (choice == 2) {
            string make = getValidString("Enter make: ");
            for (const auto& v : fleet) {
                if (v->getMake() == make) results.push_back(v.get());
            }
        } else if (choice == 3) {
            float maxPrice = getValidFloat("Enter max daily rate: $", 0.0f);
            for (const auto& v : fleet) {
                if (v->getBaseRate() <= maxPrice) results.push_back(v.get());
            }
        } else {
            for (const auto& v : fleet) {
                if (!v->getStatus()) results.push_back(v.get());
            }
        }
        
        cout << "\n--- Search Results (" << results.size() << " found) ---\n";
        for (auto v : results) v->displayDetails();
    }

    void run() {
        loadSystemData();
        
        int choice;
        do {
            cout << "\n╔════════════════════════════════════════════════════════════════════════════════╗\n";
            cout << "║              🚗 VEHICLE RENTAL MANAGEMENT SYSTEM 🚗                            ║\n";
            cout << "╚════════════════════════════════════════════════════════════════════════════════╝\n";
            cout << " 1. View Fleet Inventory\n";
            cout << " 2. View Registered Customers\n";
            cout << " 3. View Rental Records\n";
            cout << " 4. View Business Statistics\n";
            cout << " 5. Add New Vehicle to Fleet\n";
            cout << " 6. Search Vehicles\n";
            cout << " 7. Process a Rental\n";
            cout << " 8. Return a Vehicle\n";
            cout << " 9. Save Data to Files\n";
            cout << " 10. Exit System\n";
            cout << "════════════════════════════════════════════════════════════════════════════════\n";
            
            choice = getValidInt("Enter your choice (1-10): ", 1, 10);

            switch (choice) {
                case 1: displayFleet(); break;
                case 2: displayCustomers(); break;
                case 3: displayRentalRecords(); break;
                case 4: displayStatistics(); break;
                case 5: addVehicle(); break;
                case 6: searchVehicles(); break;
                case 7: rentVehicle(); break;
                case 8: returnVehicle(); break;
                case 9: saveSystemData(); break;
                case 10: 
                    cout << "\n💾 Would you like to save before exiting? (1: Yes, 0: No): ";
                    if (getValidInt("", 0, 1) == 1) saveSystemData();
                    cout << "👋 Shutting down system. Goodbye!\n"; 
                    break;
            }
        } while (choice != 10);
    }
};

// ==========================================
// MAIN FUNCTION
// ==========================================
int main() {

    SetConsoleOutputCP(CP_UTF8);

    try {
        RentalAgency myAgency;
        myAgency.run();
    } catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    }
    return 0;
}