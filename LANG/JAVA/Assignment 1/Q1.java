import java.util.Scanner;

class bankAccount{
    String accountNumber;
    String accountName;
    double accountBalance;

    bankAccount(String accnumber, String accname, double accbalance){
        accountNumber = accnumber;
        accountName = accname;
        accountBalance = accbalance;
    }

    public void deposit(double money){
        double Amount = money;
        if( Amount < 0){
            System.out.println("Invalid Amount!");
        }

        else{
            accountBalance += Amount;
            System.out.println("Successfully Deposited Amount of " + Amount + " into your Bank Account");
        }

    }

    public void withdraw(double money){
        double Amount = money;
        if( Amount < 0 ){
            System.out.println("Invalid Amount!");
        }

        else if(accountBalance < Amount){
            System.out.println("Insufficient Account Balance!");
        }

        else{
            accountBalance -= Amount;
            System.out.println("Successfully withdrawn amount of " + Amount + " from your Bank Account!" );
        }
    }

    public void displayBalance(){
        System.out.println("Account Balance = " + accountBalance);
    }

    public void displayAccountDetails(){
        System.out.println("\nAccount Details -->");
        System.out.println("Account number: " + accountNumber);
        System.out.println("Account name: " + accountName);
        System.out.println("Account balance: " + accountBalance);
        System.out.println("-----------------------------------");
    }

}

public class Q1{
    public static void main(String[] Args){
        bankAccount account = new bankAccount("987654321", "Aryan Sharma", 5000.0);

        account.displayAccountDetails();

        System.out.println("\n[Testing Deposit]");
        account.deposit(1500.0);
        account.displayBalance();

        System.out.println("\n[Testing Failed Withdrawal]");
        account.withdraw(8000.0);

        // 3. Test Successful Withdrawal
        System.out.println("\n[Testing Successful Withdrawal]");
        account.withdraw(2000.0);
        account.displayBalance();

        account.displayAccountDetails();
    }
}
