public class Main {
    public static void main(String[] args) {

        Result r = new Result();

        r.readRollNo();
        r.readMarks();
        r.calculateTotal();

        System.out.println("\n--- Student Result ---");
        r.displayRollNo();
        r.displayMarks();
        r.displayTotal();
    }

}

