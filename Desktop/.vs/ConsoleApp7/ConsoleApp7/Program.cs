using System;

namespace ConsoleApp7
{
    internal class Program
    {
        public class RockScissorsPaper
        {
            public int iRandom = 0;
            public int selection = 0;
            public string[] choice = new string[] { "가위", "바위", "보" };
        }

        static void Main(string[] args)
        {
            //ArmorSuite armorsuite = new ArmorSuite();
            //armorsuite.Initialize();
            //ArmorSuite ironman = new IronMan();
            //ironman.Initialize();
            //ArmorSuite warmachine = new WarMachine();
            //warmachine.Initialize();

            //MyClass myClass = new MyClass();
            //myClass.Method1();
            //myClass.Method2();
            //myClass.Method3();
            //myClass.Method4();

            Rectangle rec = new Rectangle();
            RectWithProp recwp = new RectWithProp();
            RectWithfullProp recwfp = new RectWithfullProp();

            rec.SetHeight(-10);
            rec.SetWidth(-10);
            Console.WriteLine(rec.GetWidth());
            Console.WriteLine(rec.GetHeight());

            recwp.Width = -10;
            recwp.Height = -10;
            Console.WriteLine(recwp.Width);
            Console.WriteLine(recwp.Height);

            recwfp.Width = -10;
            recwfp.Height = -10;
            Console.WriteLine(recwfp.Width);
            Console.WriteLine(recwfp.Height);



        }


        class Rectangle
        {
            private int _width;
            public void SetWidth(int value)
            {
                if(value > 0)
                _width = value;
            }
            public int GetWidth()
            {
                return _width;
            }


            private int _height;
            public void SetHeight(int value)
            {
                if (value > 0)

                    _height = value;
            }
            public int GetHeight()
            {
                return _height;
            }

        }
        
        class RectWithfullProp
        {
            private int _width;

            public int Width
            {
                get { return _width; }
                set { if (value > 0)
                        _width = value; }
            }

            private int _height;

            public int Height
            {
                get { return _height; }
                set { if (value > 0)
                        _height = value; }
            }
        }
        class RectWithProp
        {
            public int Width
            {
                get;
                set;
            }
            public int Height
            {
                get;
                set;
            }
        }


        internal void RockSciPap()
        {
            RockScissorsPaper rock = new RockScissorsPaper();

            rock.iRandom = 0;
            rock.selection = 0;

            Random random = new Random();

            rock.iRandom = random.Next(0, 3);
            Console.WriteLine("가위 : 0, 바위 : 1, 보 : 2");
            rock.selection = int.Parse(Console.ReadLine());



            if (rock.selection > 2 || rock.selection < 0 || rock.iRandom > 2 || rock.iRandom < 0)
            {
                Console.WriteLine("값 오류");
                return;
            }
            else
            {
                Console.WriteLine("컴퓨터 : " + rock.choice[rock.iRandom]);
                Console.WriteLine("플레이어 : " + rock.choice[rock.selection]);
            }

            if (rock.iRandom < rock.selection)
            {
                if (rock.selection == 2)
                    Console.WriteLine("패");
                else
                    Console.WriteLine("승");
            }
            else if (rock.iRandom > rock.selection)
            {
                if (rock.selection == 0)
                    Console.WriteLine("승");
                else
                    Console.WriteLine("패");
            }
            else
            {
                Console.WriteLine("비김");
            }
        }

        class ArmorSuite
        {
            public virtual void Initialize()
            {
                Console.WriteLine("슈트 생성");
            }
        }

        class IronMan : ArmorSuite
        {
            public override void Initialize()
            {
                base.Initialize();
                Console.WriteLine("아이언맨 무장 완료.");
            }
        }

        class WarMachine : ArmorSuite
        {
            public override void Initialize()
            {
                base.Initialize();
                Console.WriteLine("전투 준비 완료.");
            }
        }
        public class Base
        {
            public virtual void SealMe()
            {

            }

        }
        public class Derived : Base
        {
            public sealed override void SealMe()
            {
                Console.WriteLine("오버라이딩");
            }
        }
    }
    internal partial class MyClass
    {
        public void Method1()
        {
            Console.WriteLine("Method1");

        }
        public void Method2()
        {
            Console.WriteLine("Method2");

        }
    }


}
