using System;

namespace Lab3
{
    class JaggedArray
    {
        static void Main()
        {
            int[][] jagged = new int[3][];
            for (int i = 1; i <= 3; i++)
            {
                Console.WriteLine("Enter size of " + i + " array");
                int n = Convert.ToInt32(Console.ReadLine());
                jagged[i - 1] = new int[n];

                Console.WriteLine("Enter elements of " + i + " array");
                for (int j = 0; j < n; j++)
                {
                    jagged[i - 1][j] = Convert.ToInt32(Console.ReadLine());
                }
            }

            Console.WriteLine("Given jagged array is:");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < jagged[i].Length; j++)
                {
                    Console.Write(jagged[i][j] + "\t");
                }
                Console.WriteLine();
            }
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 3");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
