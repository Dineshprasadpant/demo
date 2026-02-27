class FullyQualifiedDemo {
    public static void main(String[] args) {

        // Using fully qualified class name
        java.util.Scanner sc = new java.util.Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = sc.nextLine();

        System.out.println("Hello " + name);
    }
}
import java.util.Scanner;


class ImportSpecificClass {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        System.out.println("You entered: " + num);
    }
}
import java.util.*;

class ImportAllClasses {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Date d = new Date();

        System.out.println("Current Date: " + d);

        System.out.print("Enter age: ");
        int age = sc.nextInt();

        System.out.println("Age: " + age);
    }
}