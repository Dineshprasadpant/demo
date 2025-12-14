using System;
namespace AbstractInterfaceDemo
{
    abstract class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public void Display()
        {
            Console.WriteLine($"Name: {Name}, Age: {Age}");
        }
        public abstract void Work(); // Abstract method (must be overridden)
    }
    interface IStudent
    {
        void Study();
    }
    interface IEmployee
    {
        void DoWork();
    }
    class WorkingStudent : Person, IStudent, IEmployee
    {
        public string University { get; set; }
        public string Company { get; set; }
        public override void Work()
        {
            Console.WriteLine("WorkingStudent works part-time and studies full-time.");
        }
        public void Study()
        {
            Console.WriteLine($"Studying at {University}.");
        }
        public void DoWork()
        {
            Console.WriteLine($"Working at {Company}.");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            WorkingStudent ws = new WorkingStudent();
            ws.Name = "Dinesh";
            ws.Age = 22;
            ws.University = "ABC University";
            ws.Company = "XYZ Tech";
            ws.Display();
            ws.Work();
            ws.Study();
            ws.DoWork();
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 7");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
