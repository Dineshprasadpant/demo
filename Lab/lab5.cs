using System;

namespace BaseKeywordDemo
{
    class Person
    {
        protected string name;
        protected int age;
        public Person(string name, int age)
        {
            this.name = name;
            this.age = age;
            Console.WriteLine("Base class constructor called.");
        }
        public void DisplayInfo()
        {
            Console.WriteLine($"Name: {name}, Age: {age}");
        }
    }
    class Student : Person
    {
        private double gpa;
        public void SetNameAndAge(string name, int age)
        {
            base.name = name;  // base keyword to access base class field
            base.age = age;
        }
        public void ShowInfo()
        {
            base.DisplayInfo();  // Calling base class method
            Console.WriteLine($"GPA: {gpa}");
        }
        public Student(string name, int age, double gpa) : base(name, age)// Using base to call base class constructor
        {
            this.gpa = gpa;
            Console.WriteLine("Derived class constructor.");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // Creating derived class object (calls base constructor)
            Student s = new Student("Dinesh", 20, 3.75);

            // Setting base class fields explicitly using base
            s.SetNameAndAge("Updated Dinesh", 21);

            // Calling base class method using base
            Console.WriteLine("\nStudent Info:");
            s.ShowInfo();
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 5");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
