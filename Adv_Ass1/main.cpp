//
//  main.cpp
//  Adv_Ass1
//
//  Created by zheng liu on 1/25/18.
//  Copyright © 2018 zheng liu. All rights reserved.
//

#include <iostream>
#include <cmath>


using namespace std;

//translate the message from string to decimal number
int translateStrinng (string mString)
{
    int result = 0;
    
    int n = (int)mString.length();
    char char_array[n+1];
    strcpy(char_array, mString.c_str());
    int mBase27_array[n+1];
    //store the message in a array as base of 27
    for (int i=0; i<n; i++){
        if(char_array[i] != ' '){
            mBase27_array[i] = (int)char_array[i] - 64;
        }else{
            mBase27_array[i] = 0;
        }
    }
    int power = n-1;
    for (int i=0; i<n; i++){
        result = result + mBase27_array[i] * pow(27,power);
        power--;

    }
    //return the decimal value of the message
    return result;
}

//translate the message from decimal number to string
void translateInterger (int mInterger){
    //string result;
    int length = 0;
    int temp = mInterger;
    //get the length of the message in string
    while(temp>0){
        temp = temp/27;
        length++;
    }
    //cout << length;
    int base27Array[length];
    //store the base 27 message in the array
    for (int i= length-1; i >= 0; i--){
        base27Array[i] = mInterger % 27;
        //cout << base27Array[i];
        mInterger = mInterger / 27;
    }
    
    //convert the base 27 messag eto string message and display the message
    cout << "the original message is: ";
    for (int i =0;i< length;i++){
        if( base27Array[i] == 0){
            cout << " ";
        }else{
            cout << (char)(base27Array[i]+64);
        }
    }
    
}
    


int main(int argc, const char * argv[]) {
    
    string userM;
    // ask the user for the message
    cout << "What's your message? ";
    getline (cin, userM);
    //decM hold the decimal value of the message
    int decM = translateStrinng(userM);
    //cout<<decM;
    translateInterger(decM);
    return 0;


    
}
