import java.util.Scanner;
public class Q2 {
    public static void main(String[] Args){
        Scanner reader = new Scanner(System.in);

        System.out.print("Enter length: ");
        int l = reader.nextInt();

        System.out.print("Enter breadth: ");
        int b = reader.nextInt();

        System.out.println("Perimeter: " + 2*(l+b) );
        System.out.println("Area: " + l*b );

        reader.close();
    }
    
}
