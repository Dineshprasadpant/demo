using System;

namespace DelegateEventDemo
{
    // a) Declare a Delegate
    public delegate void MyDelegate(string message);

    // f) Event publisher class
    class Publisher
    {
        // f) Event declaration
        public event EventHandler MyEvent;

        public void RaiseEvent()
        {
            Console.WriteLine("\nEvent is raised...");
            MyEvent?.Invoke(this, EventArgs.Empty); // Raise the event
        }
    }

    class Program
    {
        // a) Simple method to use with delegate
        static void ShowMessage(string msg)
        {
            Console.WriteLine("Message: " + msg);
        }

        // b) Another method for multicast
        static void ShowUpper(string msg)
        {
            Console.WriteLine("Upper: " + msg.ToUpper());
        }

        static void Main(string[] args)
        {
            Console.WriteLine("==== Delegate ====");
            MyDelegate del = ShowMessage;
            del("Hello!");

            Console.WriteLine("\n==== Multicast Delegate ====");
            MyDelegate multiDel = ShowMessage;
            multiDel += ShowUpper;
            multiDel("Hello World");

            Console.WriteLine("\n==== Func Delegate ====");
            Func<int, int, int> add = (a, b) => a + b;
            Console.WriteLine($"Add(10, 20): {add(10, 20)}");

            Console.WriteLine("\n==== Action Delegate ====");
            Action<string> greet = (name) => Console.WriteLine($"Hello, {name}!");
            greet("Dinesh");

            Console.WriteLine("\n==== Anonymous Method ====");
            MyDelegate anon = delegate (string msg)
            {
                Console.WriteLine("Anonymous: " + msg);
            };
            anon("This is an anonymous method.");

            Console.WriteLine("\n==== Event ====");
            Publisher pub = new Publisher();

            // f) Event subscriber using lambda
            pub.MyEvent += (sender, e) =>
            {
                Console.WriteLine("Event received in subscriber!");
            };

            // Trigger the event
            pub.RaiseEvent();
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 9");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
