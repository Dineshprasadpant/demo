using System;
using System.Threading.Tasks;

namespace AsyncAwaitDemo
{
    class Program
    {
        // An async method that simulates a time-consuming operation
        static async Task LongRunningOperation()
        {
            Console.WriteLine("Operation started...");
            await Task.Delay(3000); // Simulate 3-second delay asynchronously
            Console.WriteLine("Operation completed!");
        }

        static async Task Main(string[] args)
        {
            Console.WriteLine("Before calling async method.");

            // Await the asynchronous operation
            await LongRunningOperation();

            Console.WriteLine("After async method call.");
            Info();
            Console.ReadKey();
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
