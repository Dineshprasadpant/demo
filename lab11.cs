using System;

namespace GenericClassDemo
{
    // Generic Class with type parameter T
    class Container<T>
    {
        // Generic Field
        private T item;

        // Constructor to initialize the item
        public Container(T value)
        {
            item = value;
        }

        // Generic Method
        public void ShowInfo<U>(U extraInfo)
        {
            Console.WriteLine("Item: " + item);
            Console.WriteLine("Extra Info: " + extraInfo);
        }

        // Method to get the stored item
        public T GetItem()
        {
            return item;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Create a generic container of type string
            Container<string> strContainer = new Container<string>("Hello Generic World!");
            strContainer.ShowInfo<int>(2025); // Call generic method with int

            Console.WriteLine();

            // Create a generic container of type int
            Container<int> intContainer = new Container<int>(100);
            intContainer.ShowInfo<string>("is a lucky number"); // Call generic method with string
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 11");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
