using System;

namespace StringIndexerStudent
{
    class Student
    {
        private string name;
        private int age;
        private double gpa;
        public string this[string key]
        {
            get
            {
                switch (key.ToLower())
                {
                    case "name": return name;
                    case "age": return age.ToString();
                    case "gpa": return gpa.ToString("F2");
                    default: return "Invalid key";
                }
            }
            set
            {
                switch (key.ToLower())
                {
                    case "name":
                        name = value;
                        break;
                    case "age":
                        if (int.TryParse(value, out int a))
                            age = a;
                        else
                            Console.WriteLine("Invalid age input.");
                        break;
                    case "gpa":
                        if (double.TryParse(value, out double g))
                            gpa = g;
                        else
                            Console.WriteLine("Invalid GPA input.");
                        break;
                    default:
                        Console.WriteLine("Invalid key.");
                        break;
                }
            }
        }
        public void Display()
        {
            Console.WriteLine($"Name: {name}, Age: {age}, GPA: {gpa:F2}");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("String Indexer");
            Student s = new Student();
            s["name"] = "Dinesh";
            s["age"] = "22";
            s["gpa"] = "3.8";
            Console.WriteLine("Name: " + s["name"]);
            Console.WriteLine("Age: " + s["age"]);
            Console.WriteLine("GPA: " + s["gpa"]);
            Console.WriteLine("\nFull Info:");
            s.Display();
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 4");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
