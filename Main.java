class Mobile {

    String brand;
    int price;
    Mobile() {
        brand = "Unknown";
        price = 0;
    }
    Mobile(String b) {
        brand = b;
        price = 10000;
    }
    Mobile(String b, int p) {
        brand = b;
        price = p;
    }


    void display() {
        System.out.println("Brand: " + brand + ", Price: " + price);
    }

    void display(String offer) {
        System.out.println("Brand: " + brand + ", Price: " + price + ", Offer: " + offer);
    }
}

public class Main {
    public static void main(String[] args) {

        Mobile m1 = new Mobile();
        Mobile m2 = new Mobile("Samsung");
        Mobile m3 = new Mobile("Nothing", 45000);

        m1.display();
        m2.display();
        m3.display("Student Discount");
    }
}
