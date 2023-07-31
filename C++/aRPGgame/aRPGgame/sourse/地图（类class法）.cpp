
#include <vector>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
void gotoxy(int x, int y);
class map {
public:
    int length = 0;
        int width = 0;
    vector<int>mapdata;
    bool outPut() {
        int i = 0, j = 0, count = 0;
        for (j = 0; j <= length; j++) {
            for (i = 0; i <= width; (i++,count++)) {
                if (mapdata[count] == 1) {
                    gotoxy(2*i, j); printf("□");
                }
                else if (mapdata[count] == 0) {
                    gotoxy(2*i, j); printf("■");
                }
            }
            if (count == length * width) {
                return 0;
            }
        }
    }
    void mapRead(string x) {
        ifstream infile;
        infile.open(x, ios::in);
        char data;
        data = infile.get();
        length = data - '0';
        data = infile.get();
        width = data-'0';
        while ((data = infile.get()) != EOF) {
            mapdata.push_back(data-'0');
        }
    }
};
int main1()
{
    map m1;
    m1.mapRead(".\\mData.txt");
    m1.outPut();
    return 0;
}