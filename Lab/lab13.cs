using System;
using System.Collections.Generic;
using System.Linq;

namespace LINQDemo
{
    // Sample classes representing backend entities
    class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public bool IsActive { get; set; }
    }

    class Order
    {
        public int OrderId { get; set; }
        public int UserId { get; set; }
        public double Amount { get; set; }
    }

    class Program
    {
        static void Main()
        {
            // Sample data: users
            List<User> users = new List<User>
            {
                new User{ Id=1, Name="Alice", IsActive=true },
                new User{ Id=2, Name="Bob", IsActive=false },
                new User{ Id=3, Name="Charlie", IsActive=true },
                new User{ Id=4, Name="Diana", IsActive=true }
            };

            // Sample data: orders
            List<Order> orders = new List<Order>
            {
                new Order{ OrderId=101, UserId=1, Amount=250.0 },
                new Order{ OrderId=102, UserId=3, Amount=450.0 },
                new Order{ OrderId=103, UserId=1, Amount=150.0 },
                new Order{ OrderId=104, UserId=4, Amount=350.0 }
            };

            // 1) Filter: Get active users
            var activeUsers = users.Where(u => u.IsActive);

            Console.WriteLine("Active Users:");
            foreach (var user in activeUsers)
                Console.WriteLine($"{user.Id}: {user.Name}");

            // 2) Projection: Select only names of active users
            var activeUserNames = activeUsers.Select(u => u.Name);

            Console.WriteLine("\nActive User Names:");
            foreach (var name in activeUserNames)
                Console.WriteLine(name);

            // 3) Ordering: Order active users by name descending
            var orderedUsers = activeUsers.OrderByDescending(u => u.Name);

            Console.WriteLine("\nActive Users Ordered by Name Descending:");
            foreach (var user in orderedUsers)
                Console.WriteLine(user.Name);

            // 4) Grouping: Group orders by user id
            var ordersGroupedByUser = orders.GroupBy(o => o.UserId);

            Console.WriteLine("\nOrders Grouped by User:");
            foreach (var group in ordersGroupedByUser)
            {
                Console.WriteLine($"UserId: {group.Key}");
                foreach (var order in group)
                    Console.WriteLine($"   OrderId: {order.OrderId}, Amount: {order.Amount}");
            }

            // 5) Joining users with their orders
            var userOrders = from u in users
                             join o in orders on u.Id equals o.UserId
                             select new { u.Name, o.OrderId, o.Amount };

            Console.WriteLine("\nUser Orders (Join):");
            foreach (var item in userOrders)
                Console.WriteLine($"{item.Name} placed Order {item.OrderId} with Amount {item.Amount}");

            /*// 6) Aggregation: Total order amount per user
            var totalOrderAmount = from o in orders
                                   group o by o.UserId into g
                                   select new
                                   {
                                       UserId = g.Key,
                                       TotalAmount = g.Sum(x => x.Amount)
                                   };

            Console.WriteLine("\nTotal Order Amount per User:");
            foreach (var item in totalOrderAmount)
            {
                var userName = users.First(u => u.Id == item.UserId).Name;
                Console.WriteLine($"{userName} - {item.TotalAmount}");
            }
*/
            Info();
            Console.ReadKey();
        }
        static void Info()
        {
            Console.WriteLine("\n=== Lab Information ===");
            Console.WriteLine("Lab No.   : 13");
            Console.WriteLine("Name      : Dinesh Prasad Pant");
            Console.WriteLine("Roll No./ Section : 03/ A");
        }
    }
}
