class Result extends Test {
    int total;

    void calculateTotal() {
        total = marks1 + marks2;
    }

    void displayTotal() {
        System.out.println("Total Marks: " + total);
    }
}