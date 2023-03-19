using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tetris_10110
{
    public partial class Form1 : Form
    {
        Game game;
        int bx;
        int by;
        int bwidth;
        int bheight;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            game = Game.Singleton;
            bx = GameRule.BX;
            by = GameRule.BY;
            bwidth = GameRule.B_WIDTH;
            bheight = GameRule.B_HEIGHT;
            SetClientSizeCore(bx * bwidth, by * bheight);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            DrawGraduation(e.Graphics);
            DrawDiagram(e.Graphics);
        }

        private void DrawDiagram(Graphics graphics)
        {
            DrawHorizons(graphics);
            DrawDiagramVerticals(graphics);
        }

        private void DrawDiagramVerticals(Graphics graphics)
        {
            Point st = new Point();
            Point et = new Point();
            for (int cx = 0; cx < bx; cx++)
            {
                st.X = cx * bwidth;
                st.Y = 0;
                et.X = st.X;
                et.Y = by * bheight;
                graphics.DrawLine(Pens.Green, st, et);
            }

        }

        private void DrawHorizons(Graphics graphics)
        {
            Point st = new Point();
            Point et = new Point();

            for (int cy = 0; cy < by; cy++)
            {
                st.X = 0;
                st.Y = cy * bheight;
                et.X = bx * bwidth;
                et.Y = st.Y;
                graphics.DrawLine(Pens.Green, st, et);
            }
        }

        private void DrawGraduation(Graphics graphics)
        {
            Pen dpen = new Pen(Color.Red, 4);
            Point now = game.NowPosition;
            Rectangle rect = new Rectangle(now.X * bwidth + 2, now.Y * bheight, bwidth - 4, bheight - 4);
            graphics.DrawRectangle(dpen, rect);
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Right: MoveRight(); return;
                case Keys.Left: MoveLeft(); return;
                case Keys.Space: MoveDown(); return;
                case Keys.Up: MoveTurn(); return;
            }
        }

        private void MoveTurn()
        {
            //throw new NotImplementedException();
        }

        private void MoveDown()
        {
            if (game.MoveDown()) //아래로 내려간 경우 if 문 수행
            {
                Region rg = MakeRegion(0, -1);
                Invalidate(rg);
            }
        }

        private Region MakeRegion(int cx, int cy)
        {
            Point now = game.NowPosition;
            Rectangle rect1 = new Rectangle(now.X * bwidth, now.Y * bheight, bwidth, bheight);
            Rectangle rect2 = new Rectangle((now.X + cx) * bwidth, (now.Y + cy) * bheight, bwidth, bheight);
            Region rg1 = new Region(rect1);
            Region rg2 = new Region(rect2);
            rg1.Union(rg2);
            return rg1;
        }

        private void MoveLeft()
        {
            if (game.MoveLeft())
            {
                Region rg = MakeRegion(1, 0);
                Invalidate(rg);
            }
        }

        private void MoveRight()
        {
            if (game.MoveRight())
            {
                Region rg = MakeRegion(-1, 0);
                Invalidate(rg);
            }
        }

        private void timer_down_Tick(object sender, EventArgs e)
        {
            MoveDown();
        }
    }
}
