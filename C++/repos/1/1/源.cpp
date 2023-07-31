#include<iostream>
#include<iomanip>
using namespace std;
int i, j,l,m,n;

int main() {
	int a = 2, b, c;
	b = a++ * 3;
	c = ++a * 2;
	cout << b + c;
	i = 1;
	cout << i << ++i;
	int k = 100;
	cout << ~k<<endl;
	int AtoB = 520, key = 2022;
	//key是密钥;
	int Bget=AtoB^key;
	cout << (AtoB ^ key) << endl;
	int Bdecrypt = Bget ^ key;
	cout << Bdecrypt << endl;
	//解密算法，用位异或；
	//单次加密解密；
	//A^B^B=A=A^(B^B)=A^0=A;
	//对称加密；
	int x = 3;
	cout << (x + 5, x *= 2,2 * x) << endl;

}