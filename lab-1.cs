using System;
namespace Lab1
{
    class Student
    {
        private static int count;
        private string name;
        private int roll, age;
        public Student()// 1. Default Constructor
        {
            Console.WriteLine("Default Constructor");
            name = "N/A"; roll = age = 0;
        }
        public Student(string n, int r, int a)// 2. Parameterized Constructor
        {
            Console.WriteLine("Parameterized Constructor");
            name = n; roll = r; age = a;
        }
        public Student(Student s)// 3. Copy Constructor
        {
            Console.WriteLine("Copy Constructor");
            name = s.name; roll = s.roll; age = s.age;
        }
        static Student()// 4. Static Constructor
        {
            Console.WriteLine("Static Constructor");
            count = 0;
        }
        private Student(string msg) // 5. Private Constructor
        {
            Console.WriteLine("Private Constructor: " + msg);
        }
        public static void ShowPrivate()
        {
            new Student("only accessible within the same class");
        }
        public void Show() => Console.WriteLine($"Name: {name}, Roll: {roll}, Age: {age}");
    }
    class Program
    {
        static void Main()
        {
            Student s1 = new Student();                  // Default
            Student s2 = new Student("John", 101, 20);   // Parameterized
            Student s3 = new Student(s2);                // Copy
            Student.ShowPrivate();                       // Private

            s1.Show(); s2.Show(); s3.Show();
            Info();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 1");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
    
}
