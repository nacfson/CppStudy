using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tetris_10110
{
    internal class Game
    {
        Diagram now;
        internal Point NowPosition
        {
            get
            {
                if(now == null) //도형이 없는경우
                {
                    return new Point(0, 0);
                }
                return new Point(now.X, now.Y); //도형의 좌표 호출
            }
        }
        internal static Game Singleton //static 이므로 유일성이 보장
        {
            get;
            private set;
        }
        static Game() //정적 생성자 
        {
            Singleton = new Game();
        }
        Game() //인스턴스 생성자
        {
            now = new Diagram(); 
        }
        internal bool MoveLeft()
        {
            if(now.X > 0)
            {
                now.MoveLeft();
                return true;
            }
            else
            {
                return false;
            }

        }
        internal bool MoveRight()
        {
            if(now.X + 1 < GameRule.BX)
            {
                now.MoveRight();
                return true;
            }
            return false;
        }
        internal bool MoveDown()
        {
            if (now.Y + 1 < GameRule.BY)
            {
                now.MoveDown();
                return true;
            }
            return false;
        }
    }

}
