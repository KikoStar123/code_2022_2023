
#include <graphics.h>
#include <fstream>
#include <vector>
#include <conio.h>
const int Step = 32;
using namespace std;
class item {
public:
    void load() {
        loadimage(&GROUND, _T("..\\sourse\\brick.jpg"));
    }
    IMAGE GROUND;
private:
};

class map {
public:
    void mapRead(string x) {
        vector<int>line;
        char data;
        fstream infile;
        infile.open(x, ios::in);
        while ((data = infile.get()) != EOF) {
            if (data == '\n') {
                mapdata.push_back(line);
                length = line.size();
                line.clear();
            }
            else {
                line.push_back(data - '0');
            }
        }
        infile.close();
        width = mapdata.size();
    }
    void mapOutput() {
        all.load();
        int x = 0, y = 0;
        for (y; y < width; y++) {
            for (x = 0; x < length; x++) {
                if (mapdata[y][x] == 1) {
                    putimage(x * Step, y * Step, &(all.GROUND));
                }
                else if (mapdata[y][x] == 0) {
                    
                }
            }
        }
    }
private:
    item all;
    int length = 0;
    int width = 0;
    vector<vector<int>>mapdata;
};
int main() {
	initgraph(1000, 800);
    IMAGE Ground;
    loadimage(&Ground, _T("..\\sourse\\brick.jpg"));
    map map01;
    map01.mapRead(".\\map\\map01.txt");
    map01.mapOutput();
	_getch();
}