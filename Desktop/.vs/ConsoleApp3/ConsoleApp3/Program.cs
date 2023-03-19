using System;
using System.Collections;
using System.Collections.Generic;
namespace ConsoleApp3
{
    internal class Program
    {
        enum Color
        {
            Red = 0, Green = 1, Blue = 2,
        }
        static void Main(string[] args)
        {

            //Random rand = new Random();
            //Color c = (Color)rand.Next(0,2);

            //switch(c)
            //{
            //    case Color.Red:
            //        Console.WriteLine("red");
            //        break;
            //    case Color.Green:
            //        Console.WriteLine("red");
            //        break;
            //    case Color.Blue:
            //        Console.WriteLine("red");
            //        break;
            //    default:
            //        Console.WriteLine("??");
            //        break;
            //}


            //ArrayList sweets = null;

            //sweets?.Add("사탕");
            //sweets?.Add("초콜릿");



            //Console.WriteLine(sweets?[0]);
            //Console.WriteLine(sweets?[1]);
            //Console.WriteLine(sweets?.Count);



            //sweets = new ArrayList();


            //sweets?.Add("사탕");
            //sweets?.Add("초콜릿");


            //Console.WriteLine(sweets?[0]);
            //Console.WriteLine(sweets?[1]);
            //Console.WriteLine(sweets?.Count);


            //int a = int.Parse(Console.ReadLine());
            //int b = int.Parse(Console.ReadLine());
            //Console.WriteLine($"a|b = {a|b}");
            //Console.WriteLine($"a&b = {a|b}");
            //Console.WriteLine($"a^b = {a|b}");

            //int c = int.Parse(Console.ReadLine());
            //Console.WriteLine($"~c = {~c} c<<2 = {c <<2} c > 1 = {c > 1}");


            //int? a = null;
            //Console.WriteLine($"{a ?? 1}");

            //string str = Console.ReadLine();

            //Console.WriteLine($"{str ?? "default"}");

            //int? num = null;
            //Console.WriteLine($"{num?? 0}");

            //num = int.Parse(Console.ReadLine());
            //Console.WriteLine($"{num ?? 0}");

            //float height = float.Parse(Console.ReadLine())/ 100;
            //float weight = float.Parse(Console.ReadLine());
            //float bmi = weight / (height * height);
            //string comment;
            //if (bmi < 20) comment = "저체중";
            //else if (bmi < 25) comment = "정상체중";
            //else if (bmi < 30) comment = "경도비만";
            //else if (bmi < 40) comment = "비만";
            //else comment = "고도비만";
            //Console.WriteLine(comment);
            //int sum = 0;

            //for(int i= 1; i<= 100;i+=2 )
            //{
            //    sum += i;
            //}
            //Console.WriteLine(sum);

            //double sum2 = 0;
            //for(int i =1; i<= 100; i++)
            //{
            //    sum2 += 1.0f / i;
            //}
            //Console.WriteLine(sum2);

            //int n = int.Parse(Console.ReadLine());
            //int fact = 1;
            //for(int i = n; i>0; i--)
            //{
            //    fact *= i;
            //}
            //Console.WriteLine(fact);

            int sum = 1;
            Console.WriteLine(sum / 2);

        }

    }
}
