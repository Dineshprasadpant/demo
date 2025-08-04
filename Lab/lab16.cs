using System;

// a) Built-in attribute example
class OldVersion
{
    [Obsolete("Use NewVersion.Show() instead.")]
    public void Show()
    {
        Console.WriteLine("Old Version Show method");
    }
}

// b) Simple custom attribute
[AttributeUsage(AttributeTargets.Class)]
class MyAttribute : Attribute
{
    public string Info;

    public MyAttribute(string info)
    {
        Info = info;
    }
}

// Using custom attribute on this class
[MyAttribute("This is my custom attribute")]
class MyClass
{
    public void Display()
    {
        Console.WriteLine("MyClass Display method");
    }
}

class Program
{
    static void Main()
    {
        OldVersion oldObj = new OldVersion();
        oldObj.Show();  // This will show a compiler warning because of [Obsolete]

        MyClass obj = new MyClass();
        obj.Display();

        // Read custom attribute data
        var attr = (MyAttribute)Attribute.GetCustomAttribute(typeof(MyClass), typeof(MyAttribute));
        if (attr != null)
        {
            Console.WriteLine("Custom Attribute Info: " + attr.Info);
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
