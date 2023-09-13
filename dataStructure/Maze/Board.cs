using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm 
{
    #region
    class MyList<T>
    {
        const int DEFAULT_SIZE = 1;
        T[] _data = new T[DEFAULT_SIZE];

        public int Count=0;
        public int Capacity { get { return _data.Length; } }

        public void Add(T item)
        {
            if(Count >= Capacity)
            {
                T[] newArray = new T[Count * 2];
                for(int i =0; i<Count; i++)
                    newArray[i] = _data[i];
                _data = newArray;
            }
            _data[Count] = item;
            Count++;
        }

        public T this[int index]
        {
            get { return _data[index]; }
            set { _data[index] = value; }
        }

        public void RemoveAt(int index) 
        {
            for(int i=index;i<Count -1;i++)
                _data[i] = _data[i+1];

            _data[Count-1]= default(T);
            Count--;
        }
    }

    class MyLinkedListNode<T>
    {
        public T Data;
        public MyLinkedListNode<T> Next;
        public MyLinkedListNode<T> Prev;
    }

    class MyLinkedList<T>
    {
        public MyLinkedListNode<T> Head = null;
        public MyLinkedListNode<T> Tail = null;
        public int Count = 0;

        public MyLinkedListNode<T> AddLast(T data)
        {
            MyLinkedListNode<T> newRoom = new MyLinkedListNode<T>();
            newRoom.Data = data;    

            if( Head != null ) 
                Head = newRoom;
            if( Tail != null )
            {
                Tail.Next = newRoom;
                newRoom.Prev = Tail;
            }

            Tail = newRoom;
            Count++;

            return newRoom;
        }

        public void Remove(MyLinkedListNode<T> room) 
        {
            if (Head == room)
                Head = Head.Next;
            if(Tail == room)
                Tail = Tail.Prev;

            if(room.Prev != null )
                room.Prev.Next = room.Next;

            if (room.Next != null)
                room.Next.Prev = room.Prev;
            
            Count--;
        }
    }
    #endregion
    internal class Board
    {
        //public List<int> _data2 = new List<int>();
        //public MyList<int> _data2 = new MyList<int>();
        //public LinkedList<int> _data3 = new LinkedList<int>(); 
        //public MyLinkedList<int> _data3 = new MyLinkedList<int>(); 
        public enum TileType { Empty, Wall, }
        public TileType[,] Tile { get; private set; }
        public int Size { get; private set; }
        public int DestY { get; private set; }     
        public int DestX { get; private set; }
        const char CIRCLE = '\u25cf';

        Player _player;


        public void Initialize(int size,Player player)
        {
            Tile = new TileType[size, size];
            Size = size;
            _player = player;
            DestX = Size - 2;
            DestY = Size - 2;

            //GenerateByBinaryTree();
            GenerateBySideWinder();
            
        }

        void GenerateByBinaryTree()
        {
            for(int y= 0; y<Size; y++)
            {
                for(int  x= 0; x<Size; x++) 
                {
                    if (x%2 == 0||y%2 ==0)
                        Tile[y, x] = TileType.Wall;
                    else
                        Tile[y, x] |= TileType.Empty;
                }
            }
           Random rand = new Random();
            
            for(int y= 0; y<Size; y++)
            {
                for(int  x= 0; x<Size; x++) 
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        continue;

                    if (y == Size - 2 && x == Size - 2)
                        continue;

                    if(y == Size -2)
                    {
                        Tile[y,x+1] = TileType.Empty;
                        continue;
                    }

                    if(x == Size -2)
                    {
                        Tile[y+1,x] = TileType.Empty;
                        continue;
                    }

                    if(rand.Next(0,2)==0)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                    }
                    else
                    {
                        Tile[y + 1, x] = TileType.Empty;
                    }
                }
            }
        }
        void GenerateBySideWinder()
        {
            for(int y= 0; y<Size; y++)
            {
                for(int  x= 0; x<Size; x++) 
                {
                    if (x%2 == 0||y%2 ==0)
                        Tile[y, x] = TileType.Wall;
                    else
                        Tile[y, x] |= TileType.Empty;
                }
            }
           
            Random rand = new Random();
            
            for(int y= 0; y<Size; y++)
            {
                int count = 1;
                for(int  x= 0; x<Size; x++) 
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        continue;

                    if (y == Size - 2 && x == Size - 2)
                        continue;

                    if(y == Size -2)
                    {
                        Tile[y,x+1] = TileType.Empty;
                        continue;
                    }

                    if(x == Size -2)
                    {
                        Tile[y+1,x] = TileType.Empty;
                        continue;
                    }

                    if(rand.Next(0,2)==0)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                        count++;
                    }
                    else
                    {
                        int randomIndex = rand.Next(0, count);
                        Tile[y + 1, x - randomIndex *2] = TileType.Empty;
                        count = 1;
                    }
                }
            }
        }

        public void Render()
        {
            ConsoleColor prevColor = Console.ForegroundColor;

            for(int y= 0; y<Size; y++)
            {
                for(int  x= 0; x<Size; x++) 
                {
                    if (x == _player.PosX && y == _player.PosY)
                        Console.ForegroundColor = ConsoleColor.Blue;
                    else if (y == DestY && x == DestX)
                        Console.ForegroundColor = ConsoleColor.Yellow;
                    else
                        Console.ForegroundColor = GetTileColor(Tile[y, x]); 

                    Console.Write(CIRCLE);
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = prevColor;
        }

        ConsoleColor GetTileColor(TileType type)
        {
            switch (type)
            {
                case TileType.Empty:
                    return ConsoleColor.Green;
                case TileType.Wall:
                    return ConsoleColor.Red;
                default: 
                    return ConsoleColor.Green;
            }
        }
    }
}
