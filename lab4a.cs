using System;
namespace IndexerDemo
{
    class Student
    {
        private string[] subjects = new string[5];
        public string this[int index]
        {
            get 
            {
                if (index >= 0 && index < subjects.Length)
                    return subjects[index];
                else
                    return "Invalid Index";
            }
            set 
            {
                if (index >= 0 && index < subjects.Length)
                    subjects[index] = value;
            }
        }
        public int Length => subjects.Length; 
    }
    class Program
    {
        static void Main(string[] args)
        {
            
            Student s = new Student();
            s[0] = "Math";
            s[1] = "Science";
            s[2] = "English";
            s[3] = "Computer";
            s[4] = "History";
            Console.WriteLine("Student's Subjects:");
            for (int i = 0; i < s.Length; i++)
            {
                Console.WriteLine($"Subject {i + 1}: {s[i]}");
            }
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
