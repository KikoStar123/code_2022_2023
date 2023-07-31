#include<iostream>
using namespace std;

int main(){
    string str;
    cin>>str;
    string findstring;
    cin>>findstring;
    string replacestring;
    cin>>replacestring;

    size_t found = str.find_first_of(findstring);
    if (found != std::string::npos) {
    str.replace(found,replacestring.length(),replacestring);
}

    cout<<str<<endl;
    return 0;
}