//
//  main.cpp
//  Adv_Ass1
//
//  Created by zheng liu on 1/25/18.
//  Copyright © 2018 zheng liu. All rights reserved.
//

#include <iostream>
#include <cmath>
#include<vector>
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
unsigned long long int translateStrinng (vector<char>& mString)
{
    long long int result = 0;
    vector<int> mBase27;

    size_t n = mString.size();
    //store the message in a array as base of 27
    for (int i=0; i<n; i++){
        if(mString[i] != ' '){
            mBase27.push_back((int)mString[i] - 64);
            
        }else{
            mBase27.push_back(0);
        }

    }
    
    int power = (int)n-1;
    cout << " n:  ";
    cout<< power;
    for (int i=0; i<n; i++){
        //cout << " m[i]:  ";
        //cout<< mBase27[i];
        result = result + mBase27[i] * pow(27,power);
        //cout << " result:  ";
        //cout<< result;
        //cout<<"\n";
        power--;

    }
    //return the decimal value of the message
    return result;
}

//translate the message from decimal number to string
void translateInterger (unsigned long long int mInterger, int size){
    //string result;
    int length = size;
   
    //cout << length;
    
    
    vector<int> mBase27;
    //store the base 27 message in the array
    for (int i= 0; i <length; i++){
        int a = mInterger % 27;
        mBase27.push_back(a);
        //cout << "  ";
        //cout << a;
        mInterger = mInterger / 27;
    }
    
    //convert the base 27 messag eto string message and display the message
    cout << "the original message is: ";
    for (int i = length-1;i >=0 ;i--){
        if( mBase27[i] == 0){
            cout << " ";
        }else{
            cout << (char)(mBase27[i]+64);
        }
    }
    
    
}
    


int main(int argc, const char * argv[]) {
    vector<char> userInput;
    char inuptChar;
    // ask the user for the message and store it in vector
    cout << "What's your message? ";
    while (1)
    {
        inuptChar = getchar();
        if (inuptChar == '\n')
            break;
        userInput.push_back(inuptChar);
    }
    //cout << userInput.size();
    toUpper(userInput);
    //cout << userInput.size();

    
    //decM hold the decimal value of the message
    unsigned long long int decM = translateStrinng(userInput);
    cout<<decM;
    
    
    
    
    //translate the integer message into string in upper case
    translateInterger(decM,(int)userInput.size());
    return 0;


    
}
