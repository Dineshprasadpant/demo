using System;

namespace StructEnumPartialDemo
{
    struct Address
    {
        public string City;
        public string Country;

        public Address(string city, string country)
        {
            City = city;
            Country = country;
        }
        public void ShowAddress()
        {
            Console.WriteLine($"City: {City}, Country: {Country}");
        }
    }
    enum Department
    {
        HR,
        IT,
        Finance,
        Sales
    }
    partial class Employee
    {
        public int Id;
        public string Name;
        public Address EmpAddress;
        public Department Dept;

        public void DisplayBasicInfo()
        {
            Console.WriteLine($"ID: {Id}, Name: {Name}");
        }
    }
    partial class Employee
    {
        public void DisplayFullInfo()
        {
            DisplayBasicInfo();
            Console.WriteLine($"Department: {Dept}");
            EmpAddress.ShowAddress();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Creating a structure instance
            Address addr = new Address("Kathmandu", "Nepal");

            // Creating an enum value
            Department dep = Department.IT;

            // Creating an object of partial class
            Employee emp = new Employee();
            emp.Id = 101;
            emp.Name = "Dinesh";
            emp.EmpAddress = addr;
            emp.Dept = dep;

            // Display employee info
            emp.DisplayFullInfo();
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 8");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
