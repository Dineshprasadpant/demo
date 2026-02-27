// Interface
interface Shape {
    double area(double x, double y);
    double perimeter(double x, double y);
}

// Implementing class
class Rectangle implements Shape {

    double length, breadth;

    // Implementing area method
    public double area(double x, double y) {
        length = x;
        breadth = y;
        return length * breadth;
    }

    // Implementing perimeter method
    public double perimeter(double x, double y) {
        length = x;
        breadth = y;
        return 2 * (length + breadth);
    }
}

// Main class
public class Main {
    public static void main(String[] args) {

        Rectangle r = new Rectangle();

        double a = r.area(5, 4);
        double p = r.perimeter(5, 4);

        System.out.println("Area of Rectangle: " + a);
        System.out.println("Perimeter of Rectangle: " + p);
    }
}
