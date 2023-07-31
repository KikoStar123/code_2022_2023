#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

const string digitMap[] = {
    "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"
};

const string unitMap[] = {
    "", "拾", "佰", "仟", "万", "拾万", "佰万", "仟万", "亿", "拾亿", "佰亿", "仟亿"
};

string numberToChineseBanknote(float number) {
    string result;//string类的result

    // Check if the number is negative
    bool isNegative = false;
    if (number < 0) {
        isNegative = true;
        number = abs(number);
    }

    // Separate the integer and fractional parts
    long long intPart = static_cast<long long>(number);//直接转换为long long 类型
    int fractionalPart = round((number - intPart) * 100);//四舍五入函数

    // Process the integer part
    vector<string> intPartChinese;
    if (intPart == 0) {
        intPartChinese.push_back(digitMap[0]);//存入零
    } else {
        int digitIndex = 0;//标注是个十百千
        while (intPart > 0) {
            int digit = intPart % 10;//取出数字
            if (digit != 0) {
                intPartChinese.push_back(unitMap[digitIndex]);//先放入单位
                intPartChinese.push_back(digitMap[digit]);//再放入数字，此处为倒序放入
            } else if (!intPartChinese.empty()/*不为空*/ && intPartChinese.back() != digitMap[0]/*上一个不是零*/) {
                intPartChinese.push_back(digitMap[digit]);//为零的情况，且不写入单位
            }
            intPart /= 10;//向下挪一位
            digitIndex++;//单位+1
        }
    }
    if (isNegative) {
        result += "负";
    }//标注为负号
    for (vector<string>::reverse_iterator it = intPartChinese.rbegin(); it != intPartChinese.rend(); ++it) {
        //反向迭代器，迭代器头为rbegin，即为容器的最后一个元素,迭代器尾为rend，即为容器的第一个元素
        result += *it;
    }
    result += "元";//添加整数部分的元

    // Process the fractional part
    if (fractionalPart == 0) {
        result += "整";//如果没有小数，则直接添加整
    } else {
        int fractionalDigit1 = fractionalPart / 10;//第一个小数
        int fractionalDigit2 = fractionalPart % 10;//第二个小数
        if (fractionalDigit1 != 0) {
            result += digitMap[fractionalDigit1] + "角";
        }
        if (fractionalDigit2 != 0) {
            result += digitMap[fractionalDigit2] + "分";
        }
    }

    return result;
}

int main() {
    float number;
    cout << "Enter a float number: ";
    cin >> number;

    string chineseBanknote = numberToChineseBanknote(number);
    cout << "Chinese Banknote: " << chineseBanknote << endl;

    return 0;
}
