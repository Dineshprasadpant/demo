using System;
namespace Lab2
{
    class Student
    {
        private string name;
        private int age;
        public string Name // 1. Standard property for Name
        {
            get { return name; }
            set { name = value; }
        }
        public int Roll { get; set; }// 2. Auto-implemented property for Roll
        public int Age// 3. Read-only property for Age
        {
            get { return age; }
        }
        public Student(string name, int roll, int age)
        {
            this.name = name;
            this.Roll = roll;
            this.age = age;
        }
    }
    class Program
    {
        static void Main()
        {
            Student s = new Student("Dinesh", 03, 20);

            Console.WriteLine("Student Details:");
            Console.WriteLine("Name : " + s.Name);
            Console.WriteLine("Roll : " + s.Roll);
            Console.WriteLine("Age  : " + s.Age);

            // s.Age = 25; // Cannot assign to Age
            Info(); 
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 2");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
