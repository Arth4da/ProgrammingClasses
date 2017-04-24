using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Rectangle
{
    public static int length = 10, width = 5;
    public static bool isInstantiated = false;

    public Rectangle()
    {
        isInstantiated = true;
    }

    public Rectangle(int x, int y)
    {
        length = x;
        width = y;
    }

    public static void resetValues(int x, int y)
    {
        length = x;
        width = y;
    }
}

namespace ConsoleApplication17
{
    class Program
    {
        static void Main(string[] args)
        {
            Rectangle r = new Rectangle(10, 20);
            Console.WriteLine(Rectangle.length + ", " + Rectangle.width);

            Rectangle m = new Rectangle(20, 40);
            Console.WriteLine(Rectangle.length + ", " + Rectangle.width);
            
        }
    }
}
