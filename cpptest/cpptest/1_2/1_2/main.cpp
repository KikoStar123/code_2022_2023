//
//  main.cpp
//  1_2
//
//  Created by  KIKO on 2023/6/24.
//

#include <iostream>

class HugeInteger
{
public:
HugeInteger( int = 0 ); // conversion/default constructor
HugeInteger( const char * ); // conversion constructor
    
// addition operator; HugeInteger + HugeInteger
HugeInteger add( const HugeInteger & );
    
// addition operator; HugeInteger + int
HugeInteger add( int );
    
// addition operator;
// HugeInteger + string that represents large integer value
    
HugeInteger add( const char * );
    
// subtraction operator; HugeInteger - HugeInteger
HugeInteger subtract( const HugeInteger & );
    
// subtraction operator; HugeInteger - int
HugeInteger subtract( int );
// subtraction operator;
// HugeInteger - string that represents large integer value

HugeInteger subtract( const char * );
bool isEqualTo( HugeInteger & ); // is equal to
bool isNotEqualTo( HugeInteger & ); // not equal to
bool isGreaterThan(HugeInteger & ); // greater than
bool isLessThan( HugeInteger & ); // less than
bool isGreaterThanOrEqualTo( HugeInteger & ); // greater than
// or equal to
bool isLessThanOrEqualTo( HugeInteger & ); // less than or equal bool isZero(); // is zero
void input( const char * ); // input
void output(); // output
private:
int integer[ 40 ]; // 40 element array
}; // end class HugeInteger


int main(int argc, const char * argv[]) {
    
    return 0;
}

void HugeInteger:: input( const char * ){
    
} // input
