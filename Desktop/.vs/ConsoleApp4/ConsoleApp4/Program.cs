using System;

namespace ConsoleApp4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Print(3.1f);
            //Print(3);
            //Print(3,"ㅇㅇ");
            Printint(1, 2, 3, 4);
            PrintObject(1, 1.2, "Dd");
            int[] arr = new int[] { 1, 2, 3, 4 };
            object[] arr2 = new object[] { 1, 2, 3, 4 };
            Printint(arr);
            PrintObject(arr2);

        }
        static void Print(float x )
        {
            Console.WriteLine(x);
        }
        static void Print(float x,string y)
        {
            Console.WriteLine(x);
        }
        static void Print(int x)
        {
            Console.WriteLine(x);
        }
        static void Printint(params int[] dd)
        {
            for(int i= 0; i<dd.Length; i++)
            {
                Console.WriteLine(dd[i]);
            }
        }
        static void PrintObject(params object[] dd)
        {
            for (int i = 0; i < dd.Length; i++)
            {
                Console.WriteLine(dd[i]);
            }
        }
    }
}
