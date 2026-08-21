import java.util.Scanner;

class Employee{
    int employeeId;
    String employeeName;
    double employeeSalary;
    char performanceGrade;

    Employee(int id, String name, double salary, char grade){
        employeeId = id;
        employeeName = name;
        employeeSalary = salary;
        performanceGrade = grade;
    }

    public void displaySalary(){
        System.out.println("Annual Salary: " + employeeSalary);
    }

    public double displayBonusAmount(){
        if(performanceGrade == 'A'){
            System.out.println("Bonus Amount: " + 15*employeeSalary/100);
            return 15*employeeSalary/100;
        }

        else if(performanceGrade == 'B'){
            System.out.println("Bonus Amount: " + 10*employeeSalary/100);
            return 10*employeeSalary/100;
        }

        else if(performanceGrade == 'C'){
            System.out.println("Bonus Amount: " + 5*employeeSalary/100);
            return 5*employeeSalary/100;
        }

        else{
            System.out.println("No Bonus Amount, Improve Performance!");
            return 0;
        }
    }

    public double displayTaxAmount(){
        if(employeeSalary < 300000){
            System.out.println("No Tax Amount!");
            return 0;
        }

        else if(employeeSalary >= 300000 && employeeSalary <= 699999){
            System.out.println("Tax Amount: " + 10*employeeSalary/100);
            return 10*employeeSalary/100;
        }

        else if(employeeSalary >= 700000 && employeeSalary <= 999999){
            System.out.println("Tax Amount: " + 20*employeeSalary/100);
            return 20*employeeSalary/100;
        }

        else if(employeeSalary >= 1000000){
            System.out.println("Tax Amount: " + 30*employeeSalary/100);
            return 30*employeeSalary/100;
        }

        return -1;
    } 

    public void displayNetSalaryAfterTax(){
        double netAmount = employeeSalary - displayTaxAmount();
        System.out.println("Net Salary After: " + netAmount);
    }

}

public class Q2{
    public static void main(String[] Args){
        Employee e1 = new Employee(301, "Rudraksh Singh Chamyal", 3000000, 'A');

        e1.displaySalary();
        e1.displayBonusAmount();
        e1.displayBonusAmount();
        e1.displayNetSalaryAfterTax();
    }
}

