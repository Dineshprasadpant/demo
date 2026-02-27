interface Printable {
    void print();
}

interface Drawable {
    void draw();
}

abstract class Figure {
    abstract double area(); // abstract method

    void showType() {
        System.out.println("This is a geometric figure");
    }
}

class Rectangle extends Figure implements Printable, Drawable {
    double length, breadth;

    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    @Override
    double area() {
        return length * breadth;
    }

    public void print() {
        System.out.println("Rectangle area = " + area());
    }

    public void draw() {
        System.out.println("Drawing Rectangle");
    }
}


class Triangle extends Figure implements Printable {
    double base, height;

    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    @Override
    double area() {
        return 0.5 * base * height;
    }

    public void print() {
        System.out.println("Triangle area = " + area());
    }
}


public class Q8 {
    public static void main(String[] args) {

        Figure f;

        f = new Rectangle(10, 5);
        f.showType();
        System.out.println("Area = " + f.area());

        f = new Triangle(8, 6);
        f.showType();
        System.out.println("Area = " + f.area());

        Printable p = new Rectangle(4, 3);
        p.print();
        p.area(); // This will cause a compile-time error since Printable does not have area() method
    }
}
