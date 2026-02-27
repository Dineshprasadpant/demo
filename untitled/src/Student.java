import java.util.Scanner;

class Student {
    int roll_no;

    void readRollNo() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Roll Number: ");
        roll_no = sc.nextInt();
    }

    void displayRollNo() {
        System.out.println("Roll Number: " + roll_no);
    }
}