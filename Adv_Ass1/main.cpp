//
//  main.cpp
//  Adv_Ass1
//
//  Created by zheng liu on 1/25/18.
//  Copyright © 2018 zheng liu. All rights reserved.
//

#define us_longint unsigned long long int 
#define longint long long int

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//convert the lower case to upper case
void toUpper(vector<char>& inputString)
{
    size_t size = inputString.size();
    for (int i = 0; i < size; i++)
    {
        if (inputString[i] >= 97 && inputString[i] <= 122)
            inputString[i] -= 32;
    }
}

//translate the message from string to decimal number
us_longint translateString(vector<char>& mString)
{
    longint result = 0;
    vector<int> mBase27;

    size_t n = mString.size();
    //store the message in a array as base of 27
    for (int i = 0; i < n; i++) {
        if (mString[i] != ' ') {
            mBase27.push_back((int)mString[i] - 64);
        }
        else {
            mBase27.push_back(0);
        }

    }
    
    int power = (int)n - 1;
    cout << " n:  ";
    cout << power;
    for (int i = 0; i < n; i++){
        //cout << " m[i]:  ";
        //cout<< mBase27[i];
        result = result + mBase27[i] * pow(27, power);
        //cout << " result:  ";
        //cout<< result;
        //cout<<"\n";
        power--;

    }
    //return the decimal value of the message
    return result;
}

//translate the message from decimal number to string
void translateInt(us_longint mInt, int size) {
    //string result;
    int length = size;
   
    //cout << length;
    
    vector<int> mBase27;
    //store the base 27 message in the array
    for (int i = 0; i < length; i++) {
        int a = mInt % 27;
        mBase27.push_back(a);
        //cout << "  ";
        //cout << a;
        mInt = mInt / 27;
    }
    
    //convert the base 27 messag eto string message and display the message
    cout << "the original message is: ";
    for (int i = length - 1; i >= 0 ; i--) {
        if( mBase27[i] == 0) {
            cout << " ";
        } 
        else {
            cout << (char)(mBase27[i] + 64);
        }
    }
    
    
}
    
// Extended gcd
void extGCD(us_longint a, us_longint b, us_longint &g, longint &s, longint &t) {
    // base case
    if (b == 0) {
        s = 1;
        t = 0;
        g = a;
        return;
    }
    
    us_longint r = a % b;
    us_longint q = a / b;
    extGCD(b, r, g, s, t);
    longint tmpS = s;
    s = t;
    t = tmpS - t*q;
}

int main(int argc, const char * argv[]) {
    // test char translation
    /*
    vector<char> userInput;
    char inChar;
    // ask the user for the message and store it in vector
    cout << "What's your message? ";
    while (1)
    {
        inChar = getchar();
        if (inChar == '\n')
            break;
        userInput.push_back(inChar);
    }
    //cout << userInput.size();
    toUpper(userInput);
    //cout << userInput.size();

    //decM hold the decimal value of the message
    us_longint decM = translateStrinng(userInput);
    cout << decM;
    
    //translate the integer message into string in upper case
    translateInt(decM, (int)userInput.size());
    */
    
    // test egcd
    
    us_longint a = 8;
    us_longint b = 6;
    us_longint g = 0;
    longint s = 0;
    longint t = 0;
    
    extGCD(a, b, g, s, t);
    cout << a << " " << b << " " << g << " " << s << " " << t << "\n";
    
    return 0;
}
