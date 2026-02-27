class GrandParent {
    int x = 10;

    GrandParent() {
        System.out.println("GrandParent constructor called");
    }
}

class Parent extends GrandParent {
    int x = 20;

    Parent() {
        super(); 
        System.out.println("Parent constructor called");
    }

    void show() {
        System.out.println("Parent x = " + x);
        System.out.println("GrandParent x = " + super.x); 
    }
}

class Child extends Parent {
    int x = 30;

    Child() {
        super(); 
        System.out.println("Child constructor called");
    }

    void display() {
        System.out.println("Child x = " + x);
        System.out.println("Parent x = " + super.x); 
    }
}

public class Demo {
    public static void main(String[] args) {
        Child obj = new Child();

        obj.show();
        obj.display();
    }
}
