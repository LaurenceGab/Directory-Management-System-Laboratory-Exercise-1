
package laboratoryexercise1;

import java.util.Scanner;

public class LaboratoryExercise1 {


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your full name: ");
        String name = scanner.nextLine();

        System.out.print("Enter your age: ");
        int age = scanner.nextInt();

        int yearnow = 2025;

        int yearAtSixty = yearnow + (60 - age);

        System.out.println("Hello " + name + ", you are " + age + " years old!");
        System.out.println("You will turn 60 years old in " + yearAtSixty + ".");

    }

}
