#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 
        0) return false;
    }
    return true;
}

int main() {
    ofstream fout_text("prime_text.txt");
    ofstream fout_binary("prime_binary.bin", ios::binary);

    int count = 0;
    for (int i = 2; i <= 100; i++) {
        if (isPrime(i)) {
            count++;
            fout_text.width(6);
            fout_text << left << i;
            fout_binary.write((const char*)&i, sizeof(i));
            if (count % 10 == 0) fout_text << endl;
        }
    }

    fout_text.close();
    fout_binary.close();

    return 0;
}