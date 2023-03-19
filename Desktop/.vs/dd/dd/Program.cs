using System;
using System.Drawing;

namespace dd
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine(Area(hor:5,ver :8));
            //PrintP("형주");
            //PrintP("형주","010 - 2358 - 6960");
            //int Add(int a, int b)
            //{
            //    return a + b;
            //}
            //int Sub(int a, int b)
            //{
            //    return a - b;
            //}
            //Console.WriteLine(Add(int.Parse(Console.ReadLine()), int.Parse(Console.ReadLine())));
            //Console.WriteLine(Add(int.Parse(Console.ReadLine()), int.Parse(Console.ReadLine())));
            //DateClass cDay = new DateClass() { year = 2022, day = 12, month = 11 };
            //Console.WriteLine(cDay.day);
            //Console.WriteLine(cDay.year);
            //Console.WriteLine(cDay.month);
            //DateClass cDay2 = new DateClass() { year = 2022, day = 12, month = 11 };
            //Console.WriteLine(cDay2.day);
            //Console.WriteLine(cDay2.year);
            //Console.WriteLine(cDay2.month);
            Animal MyDog = new Animal("기여미",5,"강아지");
            Animal MyCat = new Animal();
            MyDog.Walk();
            MyDog.Eat();
            MyCat.Walk();
            MyCat.Eat();
            new ClassA();
            new ClassB();
            new ClassB();
            new ClassA();
            Console.WriteLine(Global.count);

        }
        class Animal
        {
            public string name;
            public int age;
            public string species;
            public void Walk()
            {
                Console.WriteLine($"{name}가 걷습니다");
            }
            public void Eat()
            {
                Console.WriteLine($"{name}가 먹습니다");
            }
            public Animal()
            {
                name = "키티";
                age = 5;
                species = "고양이";
            }
            public Animal(string name, int age, string species)
            {
                this.name = name;
                this.age = age;
                this.species = species;
            }

        }
        static int Area(int hor, int ver)
        {
            return hor * ver;
        }
        static void PrintP(string name, string phone = "")
        {
            Console.WriteLine($"name : {name} phone : {phone}");
        }
        class DateClass
        {
            public int year;
            public int day;
            public int month;
        }
        class Global
        {
            static public int count = 0;


        }
        public class ClassA
        {
            public ClassA()
            {
                Global.count++;
            }

        }
        public class ClassB
        {
            public ClassB()
            {
                Global.count++;
            }
        }

    }
}
