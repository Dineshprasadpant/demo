using System;
using System.Collections;
using System.Collections.Generic;

namespace CollectionDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            // a) Non-Generic Collection (ArrayList)
            Console.WriteLine("=== Non-Generic Collection (ArrayList) ===");
            ArrayList nonGenericList = new ArrayList();
            nonGenericList.Add("Dinesh");
            nonGenericList.Add(22);
            nonGenericList.Add(3.75);
            nonGenericList.Add(true);

            foreach (var item in nonGenericList)
            {
                Console.WriteLine(item + " (Type: " + item.GetType().Name + ")");
            }

            // b) Generic Collection (List<string>)
            Console.WriteLine("\n=== Generic Collection (List<string>) ===");
            List<string> genericList = new List<string>();
            genericList.Add("Apple");
            genericList.Add("Banana");
            genericList.Add("Cherry");

            foreach (string fruit in genericList)
            {
                Console.WriteLine(fruit);
            }
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 10");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
