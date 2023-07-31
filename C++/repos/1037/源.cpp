#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if ((n != 0) && (n != 1) && (n != 2) && (n != 3) && (n != 4) && (n != 5) && (n != 6)) {
		cout << "Bad" << endl;
	}else{
		switch (n) {
			{case(0):cout << "Sunday";
					break; }
			{case(1):cout << "Monday";
					break; }
			{case(2):cout << "Tuesday";
					break; }
			{case(3):cout << "Wednesday";
					break; }
			{case(4):cout << "Thursday";
					break; }
			{case(5):cout << "Friday";
					break; }
			{case(6):cout << "Saturday";
					break; }
		}
	}
		return 0;
}