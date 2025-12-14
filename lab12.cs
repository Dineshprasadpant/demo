using System;
using System.IO;

class Program
{
    static void Main()
    {
        string filePath = "user_input.txt";

        Console.WriteLine("Enter multiple lines of text:");

        // Create a StreamWriter to write to the file
        using (StreamWriter writer = new StreamWriter(filePath))
        {
            string line;
            while (true)
            {
                line = Console.ReadLine();

                // Stop input when user enters an empty line
                if (string.IsNullOrWhiteSpace(line))
                    break;

                writer.WriteLine(line);
            }
        }

        Console.WriteLine("Input written to file: " + filePath);
        Info();
        Consloe.ReadKey();
    }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 12");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
}
