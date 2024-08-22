//File: A2_S8_20220436_20221085_20221242
// Purpose: Designing a BigReal Class that deals with very large numbers

// Authors: 
// Sama Ashraf Ahmed
// Shahd Mohammed Abd El-Monjy
// Nouran Ashraf Ali

// IDs:
//20220436
//20221085
//20221242

//T.A: Eng. Khalid Ibrahim
//Date: 5//11//2023


#ifndef BIGREAL_H
#define BIGREAL_H

#pragma once
#include <string>
using namespace std;
class BigReal
{
private:
char sign='+';
string integer;
string fraction;

bool isValid(string rl);
string BalanceInt(string b1, string b2);
string BalanceFrac(string b1, string b2);


public:

    BigReal();
    BigReal(string real);
    BigReal operator +(BigReal bgrl);
    BigReal operator - (BigReal bgrl);
    bool operator > (BigReal bgrl); // done
    bool operator < (BigReal bgrl); 
    bool operator == (BigReal bgrl); 
    friend ostream& operator <<(ostream& out, const BigReal& num);
    ~BigReal();


};

#endif