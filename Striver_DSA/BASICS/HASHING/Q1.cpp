#include <iostream>
using namespace std;

int main() {
    // 1. INPUT PHASE: Get the array size and elements
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;
    
    int arr[n];
    cout << "Enter " << n << " numbers (values must be between 0 and 12): " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 2. HASHING PHASE: Count frequencies using the pre-stored array
    // Size 13 means indices 0 to 12 are valid.
    int hash[13] = {0}; 
    for(int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    // 3. QUERY PHASE: Answer questions about frequencies instantly
    int q;
    cout << "Enter the number of queries (q): ";
    cin >> q;
    
    cout << "Enter the numbers you want to search for: " << endl;
    while(q--) {
        int number;
        cin >> number;

        // Instant O(1) lookup
        cout << "Frequency of " << number << " is: " << hash[number] << endl;
    }

    return 0;
}