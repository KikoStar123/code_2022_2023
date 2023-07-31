#include <iostream> 
#include <cstring> 
#include <cassert> 
using namespace std;

class String {
    public:
    friend ostream &operator<<(ostream &output, const String &s){
        output<<s.sPtr;
        return output;
    }
    String(const char *  x= ""){
        char* templist=new char[strlen(x)+1];
        strcpy(templist,x);
        length=strlen(templist);
        sPtr=templist;
    } // conversion constructor String(const String &); // copy constructor
    ~String(){
        delete[] sPtr;
    } // destructor
    const String &operator=(const String &x){
        delete[] sPtr;
        char* templist=new char[strlen(x.sPtr)+1];
        strcpy(templist,x.sPtr);
        sPtr=templist;
        length=x.length;
        return *this;
    }
    String operator+(const String &x){
        char* templist=new char[strlen(x.sPtr)+strlen(sPtr)+1];
        strcpy(templist,sPtr);
        strcat(templist,x.sPtr);
        return String(templist);
    }
    private:
    char *sPtr; // pointer to start of string
    int length; // string length }; // end class String
};

int main() {
String string1;
String string2("The date is"); 
String string3(" August 1, 1993");
cout<<string2<<endl;
cout<<string3<<endl;
// test overloaded operators
cout << "string1 = string2 + string3\n";
string1 = string2 + string3; // tests overloaded = and + operator cout << "\"" << string1 << "\" = \"" << string2 << "\" + \""
cout << "\"" << string1 << "\" = \"" << string2 << "\" + \""
<< string3 << "\"" << endl;
}