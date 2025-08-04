using System;

namespace ExceptionDemo
{
    // c) Custom exception class
    class MyCustomException : Exception
    {
        public MyCustomException(string message) : base(message) { }
    }

    class Program
    {
        // b) Method demonstrating throw keyword
        static void CheckNumber(int num)
        {
            if (num < 0)
            {
                // Throw custom exception if number is negative
                throw new MyCustomException("Negative numbers are not allowed.");
            }
            else
            {
                Console.WriteLine($"Number is valid: {num}");
            }
        }

        static void Main()
        {
            try
            {
                Console.Write("Enter a number: ");
                int number = Convert.ToInt32(Console.ReadLine());

                CheckNumber(number); // may throw exception
            }
            catch (FormatException)
            {
                Console.WriteLine("Input was not a valid integer.");
            }
            catch (MyCustomException ex)
            {
                Console.WriteLine("Custom Exception caught: " + ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Some other exception occurred: " + ex.Message);
            }
            finally
            {
                Console.WriteLine("Execution of try-catch block is complete.");
            }
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
