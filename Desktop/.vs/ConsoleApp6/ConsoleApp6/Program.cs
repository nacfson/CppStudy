using System;
using System.Data;
using System.Globalization;

namespace ConsoleApp6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Employee emp = new Employee("유형주","학생");


            //Console.WriteLine(emp.GetName());
            //Console.WriteLine(emp.GetPosition());

            //Myclass myClass = new Myclass();
            //myClass.PrintFields();

            //Myclass myClass1 = new Myclass(1);
            //myClass1.PrintFields();

            //Myclass myClass2 = new Myclass(10,20);
            //myClass2.PrintFields();

            //Base ba = new Base("a");
            //Derived de = new Derived("b");
            //ba.BaseMethod();
            //de.BaseMethod();
            //de.DerivedMethod();

            Mammal mammal = new Dog();
            Dog dog;

            if(mammal is Dog )
            {
                dog = (Dog)mammal;
                dog.Bark();
            }

            Mammal mammal2 = new Cat();
            Cat cat;

            if(mammal2 is Cat)
            {
                cat = (Cat)mammal2;
                cat.Meow();
            }

            Cat cat2;
            cat2 = mammal as Cat;

            if(cat2 != null)
                cat2.Meow();
            else
                Console.WriteLine("cat2는 cat 형식이 아닙니다.");


        }
        class Employee
        {
            public Employee(string name, string position)
            {
                Name = name;
                Position = position;
            }

           
            private string Name;
            private string Position;
            public void SetName(string name)
            {
                this.Name = name;
            }

            public string GetName()
            {
                return Name;
            }

            public void SetPosition(string position)
            {
                this.Position = position;
            }

            public string GetPosition()
            {
                return Position;
            }
        }

        class Myclass
        {
            int a, b, c;
            public Myclass()
            {
                a = 314;
                Console.WriteLine($"MyClass({this.a})");
            }
            public Myclass(int b) :this()
            {
                this.b = b;
                Console.WriteLine($"MyClass({this.b})");
            }
            public Myclass(int b, int c) :this(b)
            {
                this.c = c;
                Console.WriteLine($"MyClass({this.b},{this.c})");
            }

            public void PrintFields()
            {
                Console.WriteLine($"a : {a} b: {b} c: {c}");
            }


        }
        class Base
        {
            protected string Name;

            public Base(string name)
            {
                this.Name = name;
                Console.WriteLine($"호출 객체의 {this.Name}.Base()");
            }

            public void BaseMethod()
            {
                Console.WriteLine($"호출 객체의 {this.Name}.BaseMethod()");
            }
        }
        class Derived : Base
        {
            public Derived(string a) : base(a)
            {
                Console.WriteLine($"호출 객체의 {this.Name}.Derived()");
            }

            public void DerivedMethod()
            {
                Console.WriteLine($"호출 객체의 {this.Name}.DerivedMethod()");
            }
        }

        class Mammal
        {
            public void Nurse()
            {
                Console.WriteLine("Nurse");
            }
        }
        class Dog : Mammal
        {
            public void Bark()
            {
                Console.WriteLine("Bark");
            }
        }
        class Cat : Mammal
        {
            public void Meow()
            {
                Console.WriteLine("Meow");
            }
        }



    }
}
