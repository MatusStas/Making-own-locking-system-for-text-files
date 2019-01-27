using System;
using System.Diagnostics;
using System.IO;

namespace secure_that.io
{
    class Program
    {
        static void Main(string[] args)
        {
            string record;
            string input;
            string dPath;
            Console.WriteLine("Write path of the file:  ");
            dPath = Console.ReadLine();
            FileStream inFile = new FileStream(dPath, FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(inFile);

            Console.WriteLine("Enter your password please. *if you dont have any you can add it by writing password-new");
     
            if (Console.ReadLine() != null && Console.ReadLine() != "password-new")
            {
                string password = Console.ReadLine();
            }
            else if (Console.ReadLine() == "password-new")
            {
                Console.WriteLine("Enter your new password");
                string password = Console.ReadLine();
            }
            else
            {
                Console.WriteLine("420 error");
            }
     
            try
            {

                record = reader.ReadLine();
                while (record != null)
                {
                    if (record.Contains("#secure-that"))
                    {
                        Console.WriteLine("Document contains protection.");

                           Console.WriteLine("Acces confirmed");
                           File.Open(dPath, FileMode.Open);
                    }
                    else
                    {
                        Console.WriteLine("Document doesnt contain protection");
                    }
                    record = reader.ReadLine();
                }
            }
            finally
            {
                reader.Close();
                inFile.Close();
            }

            Console.WriteLine("Closing...");
            Console.ReadLine();
        }
        
    }
}
