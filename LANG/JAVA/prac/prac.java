import java.util.Scanner;

public class prac {
    public static void main(String[] Args){
        Scanner reader = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = reader.nextLine();

        System.out.print("Enter your age: ");
        int age = reader.nextInt();

        System.out.println("Hello, " + name + "!");
        if(age >= 18){
            System.out.println("You are eligible to vote!");
        }

        else{
            System.out.println("You are NOT eligible to vote!");
        }
        reader.close();
    }
}
