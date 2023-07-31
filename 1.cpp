#include <iostream>
using namespace std;
enum Year
{
	y2022,
	y2023
};
enum Month
{
	JAN,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};
class Timedate
{
private:
	Year year;
	Month month;
	int day;
	int hour;
	int min;
	int sec;

public:
	Timedate(Timedate &a)
	{
		year = a.year;
		month = a.month;
		day = a.day;
		hour = a.hour;
		min = a.min;
		sec = a.sec;
	}
	Timedate()
	{
		year = y2022;
		month = JAN;
		day = 1;
		hour = 0;
		min = 0;
		sec = 0;
	}
	Timedate(Year a, Month b, int c, int d, int e, int f)
	{
		year = a;
		month = b;
		day = c;
		hour = d;
		min = e;
		sec = f;
	}
	void settime(int a, int b, int c)
	{
		hour = a;
		min = b;
		sec = c;
	}
	void setdate(Year a, Month b, int c)
	{
		year = a;
		month = b;
		day = c;
	}
	void show()
	{
		switch (year)
		{
		case y2022:
			cout << "2022/";
			break;
		case y2023:
			cout << "2023/";
			break;
		default:
			break;
		}
		switch (month)
		{
		case JAN:
			cout << "01/";
			break;
		case FEB:
			cout << "02/";
			break;
		case MAR:
			cout << "03/";
			break;
		case APR:
			cout << "04/";
			break;
		case MAY:
			cout << "05/";
			break;
		case JUN:
			cout << "06/";
			break;
		case JUL:
			cout << "07/";
			break;
		case AUG:
			cout << "08/";
			break;
		case SEP:
			cout << "09/";
			break;
		case OCT:
			cout << "10/";
			break;
		case NOV:
			cout << "11/";
			break;
		case DEC:
			cout << "12/";
			break;
		default:
			break;
		}
		cout << day << " ";
		cout << hour << ":" << min << ":" << sec << endl;
	}
	~Timedate() {}
};
int main()
{
	Timedate A(y2023, MAY, 3, 9, 4, 55);
	A.show();
	system("pause");
	return 0;
}