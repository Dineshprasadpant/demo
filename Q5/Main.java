class Demo {
    static int count = 0;
    final int MAX = 100;

    static {
        System.out.println("Static block executed");
    }
    Demo() {
        count++;
    }

    static void showCount() {
        System.out.println("Number of objects created: " + count);
    }
    final void displayMax() {
        System.out.println("Final variable MAX = " + MAX);
    }
}
final class FinalClass {
    void show() {
        System.out.println("This is a final class");
    }
}

public class Main {
    public static void main(String[] args) {

        Demo d1 = new Demo();
        Demo d2 = new Demo();

        Demo.showCount();

        d1.displayMax();

        FinalClass f = new FinalClass();
        f.show();
    }
}
