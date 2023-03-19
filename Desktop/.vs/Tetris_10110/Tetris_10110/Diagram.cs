using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Tetris_10110;

namespace Tetris_10110
{
    internal class Diagram
    {
        internal int X
        {
            get;
            private set;
        }

        internal int Y
        {
            get;
            private set;
        }

        internal Diagram()
        {
            Reset();
        }

        private void Reset()
        {
            X = GameRule.SX; // 4
            Y = GameRule.SY; // 0
        }

        internal void MoveLeft()
        {
            X--;
        }

        internal void MoveRight()
        {
            X++;
        }

        internal void MoveDown()
        {
            Y++;
        }


    }
}
