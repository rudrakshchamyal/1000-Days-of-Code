import java.util.Scanner;

public class Q1{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        System.out.print("Enter your age: ");
        int age = scanner.nextInt();

        System.out.println("\nHello, " + name + "!");

        if( age >= 18){
            System.out.println("You are eligible to vote!");
        }

        else{
            System.out.println("You are NOT eligible to vote!");
        }

        scanner.close();
    }
}