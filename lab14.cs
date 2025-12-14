using System;
using System.Collections.Generic;
using System.Linq;

namespace LambdaDemo
{
    class Program
    {
        static void Main()
        {
            List<int> numbers = new List<int> { 2, 5, 8, 11, 14, 17, 20 };

            // 1) Filtering: Get even numbers using lambda
            var evenNumbers = numbers.Where(n => n % 2 == 0);

            Console.WriteLine("Even Numbers:");
            foreach (var num in evenNumbers)
                Console.WriteLine(num);

            // 2) Projection: Get squares of numbers
            var squares = numbers.Select(n => n * n);

            Console.WriteLine("\nSquares:");
            foreach (var sq in squares)
                Console.WriteLine(sq);

            // 3) Ordering: Sort numbers descending
            var descNumbers = numbers.OrderByDescending(n => n);

            Console.WriteLine("\nNumbers in Descending Order:");
            foreach (var num in descNumbers)
                Console.WriteLine(num);

            // 4) Using lambda to find first number > 10
            int firstOverTen = numbers.FirstOrDefault(n => n > 10);
            Console.WriteLine($"\nFirst number greater than 10: {firstOverTen}");
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
