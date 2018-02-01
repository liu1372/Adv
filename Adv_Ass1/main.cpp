//
//  main.cpp
//  Adv_Ass1
//
//  Created by zheng liu on 1/25/18.
//  Copyright © 2018 zheng liu. All rights reserved.
//

#define us_longint unsigned long long int 
#define longint long long int
#define N 20 //testing 20 times in Miller-Rabin probabilistic test

#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

longint modular_multi(longint x, longint y, longint mo)  
{  
    longint t;  
    x%=mo;  
    for(t=0;y;x=(x<<1)%mo,y>>=1)  
        if (y&1)  
            t=(t+x)%mo;  
    return t;  
}  
   
longint modular_exp(longint num, longint t, longint mo)  
{  
    longint ret=1,temp=num%mo;  
    for(;t;t>>=1,temp=modular_multi(temp,temp,mo))  
        if (t&1)  
            ret=modular_multi(ret,temp,mo);  
    return ret;  
}  

// Miller-Rabin probabilistic test for testing prime
bool miller_rabbin(longint n, unsigned int Ltime)//test if n is prime for "Ltime" times
{  
    if (n==2)return true;  
    if (n<2||!(n&1))return false;  
    int t=0;  
    longint a,x,y,u=n-1;  
    while((u&1)==0) t++,u>>=1;  
    for(int i=0;i<Ltime;i++)  
    {  
        a=rand()%(n-1)+1;  
        x=modular_exp(a,u,n);  
        for(int j=0;j<t;j++)  
        {  
            y=modular_multi(x,x,n);  
            if (y==1&&x!=1&&x!=n-1)  
                return false;  
            ///we use theorem here, if there is a non-trivial square root of 1 for mod n, then n is a composite number
            ///If a number x satisfies the equation x ^ 2≡1 (mod n), but x is not equal to two 'trivial' square roots of 1 for mod n: 1 or -1, 
               ///then x is Non-trivial square root of 1 for mod n 
            x=y;  
        }  
        if (x!=1)///According to Fermat's small theorem, if n is a prime number, there is a ^ (n-1) ≡ 1 (mod n), so n can not be prime
            return false;  
    }  
    return true;  
} 

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
    
// Extended euclid gcd
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

us_longint makePrimeNumber() {
  // TODO add code to return some large prime number
    
    
    
    
  // also make sure these primes arn't so large n overflows unsigned long long int
  return 0;
}

us_longint lrPow(us_longint x, us_longint p) {
  us_longint out = 1;
  while (p > 0) {
    if (p % 2 == 0) {
      x = x * x;
      p = p/2;
    }
    else {
      out = out * x;
      p = p - 1;
    }
  }
  return out;
}

void init_PQ(us_longint &p, us_longint &q) {
  p = makePrimeNumber();
    
  do {
    q = makePrimeNumber();
  } while (p != q);
}

int main(int argc, const char * argv[]) {
    
    
    // get message to encrypt
    vector<char> userInput;
    char inChar;
    int key;
    
    // ask the user for the message and store it in vector
    cout << "What's your message? ";
    while (1) {
        inChar = getchar();
        if (inChar == '\n')
            break;
        userInput.push_back(inChar);
    }
    toUpper(userInput);

    //decM hold the decimal value of the message
    us_longint decM = translateString(userInput);
    
    // init p and q as large primes
    us_longint p, q;
    init_PQ(p, q);
    
    // init n and phi_n
    us_longint n = p*q;
    us_longint phi_n = (p - 1)*(q - 1);
    
    // get user input e as public key
    us_longint e = 0, g = 0;
    longint s = 0, t = 0;
    do {
        cout << "Please enter an integer value for the key: ";
        cin >> key;
        extGCD(e, phi_n, g, s, t);
    } while (g != 1);
    
    // private key
    us_longint d = s;
    
    // encrypt
    us_longint cypher = lrPow(decM, e) % n;
    
    // decrypt
    us_longint decrypt_c = lrPow(cypher, d) % n;
    
    //translate the int message into string in upper case
    translateInt(decrypt_c, (int)userInput.size());
    
    
    return 0;
}
