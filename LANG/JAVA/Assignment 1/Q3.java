import java.util.Scanner;

class BMI{

    String person_name;
    int person_age;
    char person_gender;
    double person_height;
    double person_weight;

    BMI(String name, int age, char gender, double height, double weight){
        person_name = name;
        person_age = age;
        person_gender = gender;
        person_height = height;
        person_weight = weight;
    }

    public double calculateBMI(){
        double bmi = person_weight/(person_height*person_height);
        return bmi;
    }

    public void displayData(){
        System.out.println("Health Status ----->\n");
        System.out.println("Name: " + person_name + "\nAge: " + person_age +
         "\nGender: " + person_gender + "\nHeight: " + person_height + "\nWeight: " + person_weight + "\n" );
        System.out.println("BMI STATUS ----->");
        double bmi = calculateBMI();

        if( bmi < 18.5){
            System.out.println("BMI: " + bmi + " status: UNDER_WEIGHT" );
        }

        else if( bmi >= 18.5 && bmi <= 24.9){
            System.out.println("BMI: " + bmi + " status: NORMAL_WEIGHT" );
        }

        else if( bmi >= 25.0 && bmi <= 29.9){
            System.out.println("BMI: " + bmi + " status: OVER_WEIGHT" );
        }

        else{
            System.out.println("BMI: " + bmi + " status: OBESE" );
        }
        System.out.println("\n");
    }
}

public class Q3{
    public static void main(String[] Args){
        BMI b1 = new BMI("Rudraksh", 19, 'M', 1.7272, 74.6);
        BMI b2 = new BMI("Krish", 20, 'M', 1.8772, 75.6);

        b1.displayData();
        b2.displayData();
    }
}