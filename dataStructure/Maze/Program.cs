using System;

namespace Algorithm
{
    class Program
    {
        static void Main(string[] args) 
        {
            Board board = new Board();
            Player player = new Player();
            board.Initialize(25,player);
            player.Initialize(1, 1,board);

            const int WAIT_TICK = 1000 / 30;
            const char CIRCLE = '\u25cf';
            Console.CursorVisible = false;

            int lastTick = 0;
        
            while (true)
            {
                #region
                int currentTick = System.Environment.TickCount;
                if (currentTick - lastTick < WAIT_TICK)
                    continue;
                int deltaTick = currentTick - lastTick;
                lastTick = currentTick;
                #endregion

                player.Update(deltaTick);
                Console.SetCursorPosition(0, 0);
                board.Render();
            }
        }
    }
}