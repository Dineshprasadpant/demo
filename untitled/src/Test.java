import java.util.Scanner;

class Test extends Student {
    int marks1, marks2;

    void readMarks() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter marks of Subject 1: ");
        marks1 = sc.nextInt();
        System.out.print("Enter marks of Subject 2: ");
        marks2 = sc.nextInt();
    }

    void displayMarks() {
        System.out.println("Marks of Subject 1: " + marks1);
        System.out.println("Marks of Subject 2: " + marks2);
    }
}