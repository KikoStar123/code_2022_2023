#include <stdio.h>
using namespace std;
bool compare(int x,int y, int xd[],int yd[],int map[99][99]);
int map001[5][99]={0};
int main(){
	int map1[5]={1,2,3,4,5};
	int map2[5]={1,2,3,4,5};//5个点位的坐标 
	if(compare(3,3,map1,map2,map001)){
		printf("YES");
	}
	else{
		printf("NO");
	}
}
bool compare(int x,int y, int xd[],int yd[],int map[][99])
{	
	int yi = 0,xi = 0;
	for(yi = 0;yi<=y;yi++){
		for(xi=0;xi<=x;xi++){
			if(map[yd[yi]][xd[xi]]==2){//外部数组map[][] 如何调过来呢 
				continue;
			}
			else{
				return 0 ;
			}
		}
	}
	return 1;
}
// multidimensional array>>>>>  arr[][x],x must be given
//
//4+ sec??????  perhaps i'm wrong...
//size? how ? 
// 				人在写高数 





