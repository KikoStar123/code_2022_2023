#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void setColor(int backColor, int foreColor)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, BACKGROUND_INTENSITY | backColor * 16 | FOREGROUND_INTENSITY | foreColor);
}

class Game
{
	int width;
	int height;
	int* data;
	int* lastData;
	int final=0;
	int counter = 0;
public:
	//构造函数
	Game(int width, int height, int initDepth = 3)
	{
		this->width = width;
		this->height = height;
		data = new int[width * height] {0};
		lastData = new int[width * height] {0};

		for (int y = height - initDepth; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				if (rand() % 3 > 0)
					SetBlock(x, y, 1);
			}
			SetBlock(rand() % this->width, y, 0);
		}
	}

	void SetBlock(int x, int y, int val)
	{
		this->data[y * this->width + x] = val;
	}

	int GetBlock(int x, int y)
	{
		return data[y * this->width + x];
	}

	//析构
	~Game()
	{
		delete[] data;
		delete[] lastData;
	}

	void DrawFrame()
	{
		gotoxy(0, 0);
		cout << "╔ ";
		for (int x = 0; x < width; ++x)
		{
			cout << "═ ";
		}
		cout << "╗ ";

		for (int y = 0; y < height; ++y)
		{
			gotoxy(0, y + 1);
			cout << "║ ";
			gotoxy(width * 2 + 2, y + 1);
			cout << "║ ";
		}





		gotoxy(0, height + 1);
		cout << "╚ ";
		for (int x = 0; x < width; ++x)
		{
			cout << "═ ";
		}
		cout << "╝ ";
	}

	void DrawBlocks()
	{
		for (int y = 0; y < height; ++y)
			for (int x = 0; x < width; ++x)
			{
				int id = y * width + x;
				if (data[id] != lastData[id])
				{
					gotoxy(x * 2 + 2, y + 1);
					switch (data[id])
					{
					case 0: cout << "　"; break;
					case 1: cout << "齉"; break;
					case 2: cout << "囗"; break;
					}
					lastData[id] = data[id];
				}
			}

		gotoxy(0, height + 2);
	}


	void CreateNewBlocks()
	{
		int m =rand()%5;
		if(m==0)
		{
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++)
				{

					SetBlock(this->width / 2 + j - 1, k, 2);
				}
		}
		if(m==1)
		{
			for (int j = 0; j < 1; j++)
				for (int k = 0; k < 4; k++)
				{

					SetBlock(this->width / 2 + j - 1, k, 2);
				}
		}
		if (m == 2)
		{
			SetBlock(this->width / 2 + 0 - 1, 0, 2);
			SetBlock(this->width / 2 + 1 - 1, 0, 2);
			SetBlock(this->width / 2 + 2 - 1, 0, 2);
			SetBlock(this->width / 2 + 2 - 1, 1, 2);
		}
		if (m == 3)
		{
			SetBlock(this->width / 2 + 0 - 1, 0, 2);
			SetBlock(this->width / 2 + 1 - 1, 1, 2);
			SetBlock(this->width / 2 + 2 - 1, 1, 2);
			SetBlock(this->width / 2 + 0 - 1, 1, 2);
		}
		if (m == 4)
		{
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 2; k++)
				{

					SetBlock(this->width / 2 + j - 1, k, 2);
				}
		}
		counter = counter + 1;
	}

	void FixBlocks()
	{
		for (int y = height - 1; y >= 0; --y)
			for (int x = 0; x < width; ++x)
				if (GetBlock(x, y) == 2)
					SetBlock(x, y, 1);
	}

	void CheckAndDeleteLines(int height,int weight)
	{
		for (int y = 0; y < height; y++)
		{
			int sum = 0;
			for (int x = 0; x < width; x++)
			{
				if (GetBlock(x, y)==1)
				{
					sum++;
				}
			}
			if (sum >=width)
			{
				for (int x = 0; x < width; x++)
				{
					SetBlock(x, y, 0);
				}
				for (int i =y-1; i >=0; i--)
				{
					for (int x = 0; x < width; x++)
					{
						if (GetBlock(x, i) == 1)
						{
							SetBlock(x, i+1, 1);
							SetBlock(x, i, 0);
						}
					}
				}
			}
		}
	}

	void MoveUp()
	{

	}

	void MoveLeft()
	{
		bool canMoveLeft = true;
		for (int x = 0; x < width; ++x)
		{
			for (int y = 0; y < height; ++y)
			{
				if (GetBlock(x, y) == 2)
				{
					if (x <= 0 ||
						GetBlock(x - 1, y) == 1)
					{
						canMoveLeft = false;
						break;
					}
				}
			}
			if (!canMoveLeft)
				break;
		}

		if (canMoveLeft)
			for (int x = 0; x < width; ++x)
				for (int y = 0; y < height; ++y)
				{
					if (GetBlock(x, y) == 2)
					{
						SetBlock(x - 1, y, 2);
						SetBlock(x, y, 0);
					}
				}
	}
	
	void MoveRight()
	{
		bool canMoveRight = true;
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; ++y)
			{
				if (GetBlock(x, y) == 2)
				{
					if (x >= width-1 ||
						GetBlock(x + 1, y) == 1)
					{
						canMoveRight = false;
						break;
					}
				}
			}
			if (!canMoveRight)
				break;
		}

		if (canMoveRight)

			for (int x = width - 1; x >= 0; --x)
				for (int y = 0; y < height; ++y)
				{
					if (GetBlock(x, y) == 2)
					{
						SetBlock(x + 1, y, 2);
						SetBlock(x, y, 0);
					}
				}

	}
	void MoveDown()
	{

		bool canMoveDown = true;
		for (int y = height - 1; y >= 0; --y)
		{
			for (int x = 0; x < width; ++x)
			{
				if (GetBlock(x, y) == 2)
				{
					if (y == height - 1 ||
						GetBlock(x, y + 1) == 1)
					{
						canMoveDown = false;
						if (y <= 2)
						{
							cout << "The game is over! Your final point is"<<this->counter;
							
							final = 1;
						}
						break;
					}
				}
			}
			if (!canMoveDown)
				break;
		}

		if (canMoveDown)
			for (int y = height - 1; y >= 0; --y)
				for (int x = 0; x < width; ++x)
				{
					if (GetBlock(x, y) == 2)
					{
						SetBlock(x, y + 1, 2);
						SetBlock(x, y, 0);
					}
				}
		else
		{
			FixBlocks();
			CheckAndDeleteLines(this->height,this->width);
			CreateNewBlocks();
		}
	}

public:
	void Run()
	{
		CreateNewBlocks();
		DrawFrame();
		DrawBlocks();

		////gotoxy(cursorX * 8 + 4, cursorY * 4 + 2);

		int lastCh = 0;

		long long t1 = ::GetTickCount64();
		for (;;)
		{
			if (final ==1)
			{
				break;
			}
			if (_kbhit())
			{
				int ch = _getch();
				//cout << ch << endl;

				if (lastCh == 224 && ch == 72)//U
					MoveUp();
				if (lastCh == 224 && ch == 80)//D
					MoveDown(); ;
				if (lastCh == 224 && ch == 75)//L
					MoveLeft();
				if (lastCh == 224 && ch == 77)//R
					MoveRight();

				lastCh = ch;
			}

			Sleep(1);

			long long t2 = ::GetTickCount64();
			if (t2 - t1 >= 500)
			{
				MoveDown();
				t1 = t2;
			}

			DrawBlocks();


		}
		Sleep(1000);
		gotoxy(0, height + 2);
	}
};


int main()
{
	srand(time(0));

	Game g(12, 20);
	g.Run();
	return 0;
}