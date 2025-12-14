using System;

namespace PolymorphismDemo
{
    class Animal
    {
        public virtual void Speak()
        {
            Console.WriteLine("Animal speaks (base virtual method).");
        }

        public void Eat()
        {
            Console.WriteLine("Animal eats (base non-virtual method).");
        }
    }
    class Dog : Animal
    {
        // Method Overriding (Dynamic Polymorphism)
        public override void Speak()
        {
            Console.WriteLine("Dog barks (overridden method).");
        }

        // Method Hiding (Static/Compile-Time)
        public new void Eat()
        {
            Console.WriteLine("Dog eats (hidden method).");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Animal animalRef;
            animalRef = new Animal();
            Console.WriteLine("Base Class Reference to Base Object:");
            animalRef.Speak(); // Calls Animal.Speak
            animalRef.Eat();   // Calls Animal.Eat
            Console.WriteLine();

            animalRef = new Dog();
            Console.WriteLine("Base Class Reference to Derived Object:");
            animalRef.Speak(); // Calls Dog.Speak (Dynamic Polymorphism)
            animalRef.Eat();   // Calls Animal.Eat (Not Dog.Eat because it's hidden)
            Console.WriteLine();

            Dog dogRef = new Dog();
            Console.WriteLine("Derived Class Reference to Derived Object:");
            dogRef.Speak(); // Dog.Speak
            dogRef.Eat();   // Dog.Eat
            Console.WriteLine();
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 6");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
