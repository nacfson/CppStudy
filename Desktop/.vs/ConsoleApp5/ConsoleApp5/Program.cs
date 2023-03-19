using System;
using System.Reflection.PortableExecutable;
using System.Runtime.InteropServices;

namespace ConsoleApp5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //int count = 0;
            //for(int i =2; i<= 100; i++)
            //{
            //    if (IsPrime(i))
            //    {
            //        count++;
            //    }
            //}
            //Console.WriteLine($"{count}개");

            //Rectangle rect1 = new Rectangle(1,2);
            //Rectangle rect2= new Rectangle(1, 3);
            //Rectangle rect3= new Rectangle(2, 2);
            //Console.WriteLine(rect1.calcArea());
            //Console.WriteLine(rect1.isSquare());



            //Rectangle.printCount();


            //Person.Show();
            //Person p = new Person();
            //p.Print();
            //Person p1 = new Person(20);
            //p1.Print();


            MyClass source = new MyClass();
            MyClass target = new MyClass();
            target.MyField1 = 30;
            source = target;
            source.MyField1 = 15;
            Console.WriteLine($"{source.MyField1} + {source.MyField2}" );
            Console.WriteLine($"{target.MyField1} + {target.MyField2}" );

            MyClass source2 = new MyClass();
            MyClass target2 = new MyClass();
            source2.MyField1 = 15;
            target2.MyField1 = 30;
            target2 = source2.DeepCopy();
            Console.WriteLine($"{source2.MyField1} + {source2.MyField2}");
            Console.WriteLine($"{target2.MyField1} + {target2.MyField2}");

        }
        static bool IsPrime(int x)
        { 
            for(int i = 2; i <x; i++)
            {
                if (x % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
        class Rectangle
        {
            public static int count = 0;
            int width, height = 1;

            public Rectangle(int a, int b)
            {
                width = a;
                height = b;
                count++;
            }

            public int calcArea()
            {
                return width * height;
            }
            public bool isSquare()
            {
                return (width == height);
            }
            public static void printCount()
            {
                Console.WriteLine($"{count}");
            }
        }
        class Person
        {
            public static string name;
            public int age;

            static Person()
            {
                name = "홍길동";
            }
            public Person()
            {
                age = 17;
            }
            public Person(int age)
            {
                this.age = age;
            }
            public static void Show()
            {
                Console.WriteLine($"{name}");
            }
            public void Print()
            {
                Console.WriteLine($"{age}");
            }
        }

        class MyClass
        {
            public int MyField1;
            public int MyField2;

            public MyClass DeepCopy()
            {
                MyClass newCopy = new MyClass();
                newCopy.MyField1 = MyField1;
                newCopy.MyField2 = MyField2;
                return newCopy;
            }
        }


    }
}
