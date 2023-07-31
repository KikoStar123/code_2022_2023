#include <iostream>
#include <cstring>

class HugeInteger {
private:
    int integer[40]; // Array of digits

public:
    HugeInteger() {
        // Constructor
        memset(integer, 0, sizeof(integer)); // Initialize array with zeros
    }

    ~HugeInteger() {
        // Destructor
    }

    void input() {
        // Function to input a HugeInteger from the user
        std::string input;
        std::cout << "Enter a huge integer: ";
        std::cin >> input;

        // Convert each digit character to an integer and store in the array
        int length = input.length();
        int index = 0;
        for (int i = length - 1; i >= 0; i--) {
            integer[index] = input[i] - '0';
            index++;
        }
    }

    void output() {
        // Function to output the HugeInteger
        int index = 39;
        while (index >= 0 && integer[index] == 0) {
            index--;
        }

        if (index < 0) {
            std::cout << "0";
        } else {
            while (index >= 0) {
                std::cout << integer[index];
                index--;
            }
        }

        std::cout << std::endl;
    }

    HugeInteger add(const HugeInteger& other) const {
        // Function to add two HugeIntegers
        HugeInteger result;

        int carry = 0;
        for (int i = 0; i < 40; i++) {
            int sum = integer[i] + other.integer[i] + carry;
            result.integer[i] = sum % 10;
            carry = sum / 10;
        }

        return result;
    }

    HugeInteger subtract(const HugeInteger& other) const {
        // Function to subtract two HugeIntegers
        HugeInteger result;

        int borrow = 0;
        for (int i = 0; i < 40; i++) {
            int diff = integer[i] - other.integer[i] - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.integer[i] = diff;
        }

        return result;
    }

    bool isEqualTo(const HugeInteger& other) const {
        // Function to check if two HugeIntegers are equal
        for (int i = 0; i < 40; i++) {
            if (integer[i] != other.integer[i]) {
                return false;
            }
        }
        return true;
    }

    bool isNotEqualTo(const HugeInteger& other) const {
        // Function to check if two HugeIntegers are not equal
        return !isEqualTo(other);
    }

    bool isGreaterThan(const HugeInteger& other) const {
        // Function to check if the current HugeInteger is greater than the other HugeInteger
        for (int i = 39; i >= 0; i--) {
            if (integer[i] > other.integer[i]) {
                return true;
            } else if (integer[i] < other.integer[i]) {
                return false;
            }
        }
        return false;
    }

        bool isLessThan(const HugeInteger& other) const {
        // Function to check if the current HugeInteger is less than the other HugeInteger
        for (int i = 39; i >= 0; i--) {
            if (integer[i] < other.integer[i]) {
                return true;
            } else if (integer[i] > other.integer[i]) {
                return false;
            }
        }
        return false;
    }

    bool isGreaterThanOrEqualTo(const HugeInteger& other) const {
        // Function to check if the current HugeInteger is greater than or equal to the other HugeInteger
        return !isLessThan(other);
    }

    bool isLessThanOrEqualTo(const HugeInteger& other) const {
        // Function to check if the current HugeInteger is less than or equal to the other HugeInteger
        return !isGreaterThan(other);
    }

    bool isZero() const {
        // Function to check if the HugeInteger is zero
        for (int i = 0; i < 40; i++) {
            if (integer[i] != 0) {
                return false;
            }
        }
        return true;
    }
    
    HugeInteger multiply(const HugeInteger& other) const {
        // Function to multiply two HugeIntegers
        HugeInteger result;
        int product, carry = 0;

        for (int i = 0; i < 40; i++) {
            for (int j = 0; j < 40; j++) {
                if (i + j < 40) {
                    product = integer[i] * other.integer[j] + carry + result.integer[i + j];
                    carry = product / 10;
                    result.integer[i + j] = product % 10;
                }
            }
        }

        return result;
    }

    HugeInteger divide(const HugeInteger& other) const {
        // Function to divide two HugeIntegers
        HugeInteger result;
        HugeInteger dividend = *this;

        // Check for division by zero
        if (other.isZero()) {
            std::cout << "Error: Division by zero!" << std::endl;
            return result;
        }

        // Check if dividend is zero
        if (dividend.isZero()) {
            return result;
        }

        HugeInteger divisor = other;
        HugeInteger quotient;
        HugeInteger remainder;

        int divisorLength = 39;
        while (divisor.integer[divisorLength] == 0 && divisorLength > 0) {
            divisorLength--;
        }

        int dividendLength = 39;
        while (dividend.integer[dividendLength] == 0 && dividendLength > 0) {
            dividendLength--;
        }

        int diff = dividendLength - divisorLength;
        if (diff < 0) {
            result = quotient;
            return result;
        }

        for (int i = diff; i >= 0; i--) {
            quotient.integer[i] = 0;
            while (dividend.isGreaterThanOrEqualTo(divisor)) {
                dividend = dividend.subtract(divisor);
                quotient.integer[i]++;
            }
            divisor.shiftRight();
        }

        result = quotient;
        return result;
    }

    HugeInteger modulus(const HugeInteger& other) const {
        // Function to calculate the modulus of two HugeIntegers
        HugeInteger result;
        HugeInteger dividend = *this;

        // Check for division by zero
        if (other.isZero()) {
            std::cout << "Error: Division by zero!" << std::endl;
            return result;
        }

        // Check if dividend is zero
            if (dividend.isZero()) {
        return result;
    }

    HugeInteger divisor = other;
    HugeInteger quotient;
    HugeInteger remainder;

    int divisorLength = 39;
    while (divisor.integer[divisorLength] == 0 && divisorLength > 0) {
        divisorLength--;
    }

    int dividendLength = 39;
    while (dividend.integer[dividendLength] == 0 && dividendLength > 0) {
        dividendLength--;
    }

    int diff = dividendLength - divisorLength;
    if (diff < 0) {
        result = dividend;
        return result;
    }

    for (int i = diff; i >= 0; i--) {
        quotient.integer[i] = 0;
        while (dividend.isGreaterThanOrEqualTo(divisor)) {
            dividend = dividend.subtract(divisor);
            quotient.integer[i]++;
        }
        divisor.shiftRight();
    }

    result = dividend;
    return result;
}

void shiftRight() {
    // Function to perform a right shift on the HugeInteger
    for (int i = 39; i > 0; i--) {
        integer[i] = integer[i - 1];
    }
    integer[0] = 0;
}
};