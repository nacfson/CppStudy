using System;
using System.Security.Cryptography.X509Certificates;
using MyCar;
namespace cSharpClass
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Car c = new Car(30120, 30, "NiceCar");
            //c.Ride();
            //string prime;

            //for (int i = 1; i < 11; i++)
            //{
            //    for (int j = 2; j < 11; i++)
            //    {
            //        if (j % i != 0)
            //        {
            //            if (j == i)
            //            {
            //                Console.WriteLine(j);
            //            }
            //        }
            //    }
            //}
            //prime = String.Format("10 이하의 소수는 {0},{1},{2},{3}", 2, 3, 5, 7);
            //Console.WriteLine(prime);

            //int i = 123;
            //object o = i;
            //i += 10;
            //int j = (int)o;
            //Console.WriteLine(i);
            //Console.WriteLine(o);
            //Console.WriteLine(j);

            //object p = o;
            //o = 100;
            //Console.WriteLine(o);
            //Console.WriteLine(p);


            //const int MAXINT = int.MaxValue;
            //const int MININT = int.MinValue;
            //Console.WriteLine($"{MAXINT},{MININT}");

            //uint a = int.MaxValue;
            //Console.WriteLine(a);
            //a += 1;
            //Console.WriteLine(a);

            byte b = byte.MaxValue;
            Console.WriteLine(b);
            b += 1;
            Console.WriteLine(b);


            
        }
    }
}

namespace MyCar
{

    class Car
    {
        public int oil;
        public string name;
        public int id;
        public Car(int id, int oil, string name)
        {
            this.oil = oil;
            this.name = name;
            this.id = id;

        }
        public void Ride()
        {
            Console.WriteLine($"{id} : {name} 기름은 {oil} 리터만큼 남았습니다.");
        }
    }
}