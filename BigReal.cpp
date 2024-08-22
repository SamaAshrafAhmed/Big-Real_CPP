//File: A2_S8_20220436_20221085_20221242.cpp
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
//Date: 5/11/2023


#include "BigReal.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

//checks if the number is a valid number
bool BigReal::isValid(string rl)
{
    if(regex_match(rl,regex("[+-]?\\d*.?\\d+")))
    return true;
    else
    return false;
}
BigReal::BigReal()
{
    integer="0";
    fraction="0";
}

BigReal::BigReal(string real)
{
    // check if the given number is valid
    if(isValid(real))
    {
        // if the number starts with a sign store it in the sign data member
        // and store the rest of it before the '.' if it exists in the data mamber "integer" 
        if(real[0]=='+' or real[0]=='-')
        { 
        sign = real[0];
        integer = real.substr(1,real.find('.')-1);
        }
        // if the number doesnt contain a sign then its default sign is + 
        // and store all the characters before the '.' in the data member "ïnteger"
        else 
        {
            sign='+';
            integer = real.substr(0,real.find('.'));
        }
        // in case the number starts with a point the integer size = 0
        // then the integer = 0
        if(integer.size()==0)
        integer="0";

        //check if there is a fraction part in the number
        // if the size of the number without considering the sign != the size of the integer then there is a fraction part
        if((real.size()>integer.size()+1 and real[0]==sign)||real.size()>integer.size() and real[0]!=sign)
        {
            // store the integers after the '.' in the data member fraction
            fraction = real.substr(real.find('.')+1, real.size());
        }
        else
        // if there is no fraction part the fraction = 0
        fraction='0';
    }
    // if the number is invalid then it is stored as 0.0
    

}

BigReal::~BigReal()
{

}

//takes fractions of two big reals and returns the fraction of smaller size after balancing it
// fraction is balanced by adding zeros on the right with no effect on the number
string BigReal::BalanceFrac(string b1, string b2)
{
    if(b1.size()<b2.size())
   { 
    while(b1.size()<b2.size())
    {
        b1+='0';
    }
    return b1;
    }
    while(b2.size()<b1.size())
    {
        b2+='0';
    }
    return b2;

}
//takes integers of two big reals and returns the integer of smaller size after balancing it
// integers are balanced by adding zeros on the left with no effect on the number
string BigReal::BalanceInt(string b1, string b2)
{
    if(b1.size()<b2.size())
   { 
    reverse(b1.begin(),b1.end());
    while(b1.size()<b2.size())
    {
        b1+='0';
    }
     reverse(b1.begin(),b1.end());
     return b1;
    }
    else if(b2.size()<b1.size())
    {
    reverse(b2.begin(),b2.end());
    while(b2.size()<b1.size())
    {
        b2+='0';
    }
    reverse(b2.begin(),b2.end());
    return b2;
    }
    return b2;

}
bool BigReal:: operator == (BigReal bgrl)
{
    // balances two numbers for comparing them
    // for a case like 05.0 and 5.0 without balancing will return false
    if(fraction.size()<bgrl.fraction.size())
    fraction=BalanceFrac(fraction, bgrl.fraction);
    else 
    bgrl.fraction=BalanceFrac(fraction, bgrl.fraction);

    if(integer.size()<bgrl.integer.size())
    {
    integer=BalanceInt(integer,bgrl.integer);
    }
    else 
    bgrl.integer=BalanceInt(integer,bgrl.integer);
    // if the two numbers have the same sign and integer and fraction then they are equal 
    if((integer == bgrl.integer) and (fraction == bgrl.fraction) and (sign==bgrl.sign))
    return true;
    else 
    return false;
    
}
bool BigReal:: operator> (BigReal bgrl)
{
    // balances two numbers for comparing them

    if(fraction.size()<bgrl.fraction.size())
    fraction=BalanceFrac(fraction, bgrl.fraction);
    else 
    bgrl.fraction=BalanceFrac(fraction, bgrl.fraction);

    if(integer.size()<bgrl.integer.size())
    {
    integer=BalanceInt(integer,bgrl.integer);
    }
    else 
    bgrl.integer=BalanceInt(integer,bgrl.integer);

    // if the sign of the first number is +ve and the second is -ve then the first is greater
    if(sign=='+' and bgrl.sign=='-')
    return true;
    // if they have the same sign
    else if(sign==bgrl.sign)
    {
        // if they doesn't have the same integer part 
        // compare integers from left to right 
        if(integer!=bgrl.integer)
        {
        for(int i=0; i<integer.size(); i++)
        {
            if ((integer[i]-'0')>(bgrl.integer[i]-'0'))
            {
                if(sign=='+')
                return true;
                // if the two numbers are decimal then the smaller number without considering the sign is the greater one
                // -1 > -2
                else 
                return false;
            }
            else if((integer[i]-'0')<(bgrl.integer[i]-'0'))
            {
                if(sign=='+')
                return false;
                // if the two numbers are decimal then the smaller number without considering the sign is the greater one
                // -1 > -2

                else 
                return true;
            }
        }
        }
        // if the numbers have the same integer part then compare fractions from left to right 
        else
        {
        if(fraction!=bgrl.fraction)
        {
        for(int i=0; i<fraction.size(); i++)
        {
            if ((fraction[i]-'0')>(bgrl.fraction[i]-'0'))
            {
                if(sign=='+')
                return true;
                else 
                return false;
            }
            else if((fraction[i]-'0')<(bgrl.fraction[i]-'0'))
            {
                if(sign=='+')
                return false;
                else 
                return true;
            }
        }
        }
        return false;
        }
        }
        return false;
}
bool BigReal::operator < (BigReal bgrl)
{
    // balancing the two numbers for comparing them
    if(fraction.size()<bgrl.fraction.size())
    fraction=BalanceFrac(fraction, bgrl.fraction);
    else 
    bgrl.fraction=BalanceFrac(fraction, bgrl.fraction);

    if(integer.size()<bgrl.integer.size())
    {
    integer=BalanceInt(integer,bgrl.integer);
    }
    else 
    bgrl.integer=BalanceInt(integer,bgrl.integer);
    


    // if the number on the left is negative and that on the right is positive then the left number is smaller
    if(sign=='-' and bgrl.sign=='+')
    return true;
    // if they have the same sign
    else if(sign==bgrl.sign)
    {
        // if they dont have the same integer
        // compare integers from right to left 
        if(integer!=bgrl.integer)
        {
        for(int i=0; i<integer.size(); i++)
        {
            if ((integer[i]-'0')>(bgrl.integer[i]-'0'))
            {
                if(sign=='+')
                return false;
                else 
                // in case the two numbers are negative the smaller one is that of the greater integer
                return true;
            }
            else if((integer[i]-'0')<(bgrl.integer[i]-'0'))
            {
                if(sign=='+')
                return true;
                // in case the two numbers are negative the smaller one is that of the greater integer
                else 
                return false;
            }
        }
        }
        else
        {
        // if the integers are equal then compare the fractions from left to right
        if(fraction!=bgrl.fraction)
        {
        for(int i=0; i<fraction.size(); i++)
        {
            if ((fraction[i]-'0')>(bgrl.fraction[i]-'0'))
            {
                if(sign=='+')
                return false;
                else 
                return true;
            }
            else if((fraction[i]-'0')<(bgrl.fraction[i]-'0'))
            {
                if(sign=='+')
                return true;
                else 
                return false;
            }
        }
        }
        return true;
        }
    }
        return false;
}
BigReal BigReal::operator+ (BigReal bgrl)
{
    // balance two integers for adding them
    if(fraction.size()<bgrl.fraction.size())
    fraction=BalanceFrac(fraction, bgrl.fraction);
    else 
    bgrl.fraction=BalanceFrac(fraction, bgrl.fraction);

    if(integer.size()<bgrl.integer.size())
    {
    integer=BalanceInt(integer,bgrl.integer);
    }
    else 
    bgrl.integer=BalanceInt(integer,bgrl.integer);

    // new bigreal number that stores the result
    BigReal New("0");

    // if the two reals have the same sign then the sign remains the same and the values are normally added
    if(sign==bgrl.sign)
    {
        // first add the fraction part from right to left and store the result in string   
        int carry=0;
        string addFrc = "";
        for(int i=fraction.size()-1; i>=0; i--)
        {
            int ad = (fraction[i]-'0')+(bgrl.fraction[i]-'0')+carry;
            carry=int(ad/10);
            ad%=10;
            addFrc += to_string(ad);
        }
        //reverse the string of the result
        reverse(addFrc.begin(), addFrc.end());

        // then adding the integers part with considering the carry remained from adding the fraction part
        string addInt = "";
        for(int i=integer.size()-1; i>=0; i--)
        {
            // adding two integers and the carry
            int ad = (integer[i]-'0')+(bgrl.integer[i]-'0')+carry;
            // carry appears if the result of adding is greater then 9
            carry=int(ad/10);
            ad%=10;
            addInt+= to_string(ad);
        }
        if(carry)
        addInt+='1';
        reverse(addInt.begin(), addInt.end());
        New.sign=sign;
        New.integer = addInt;
        New.fraction = addFrc;
        return New;
    }
    // if the signs are different then subtrcation occurs
    else
    {
        bool swapped=0;
        BigReal temp("0");
        char temp1 = sign;
        char temp2 = bgrl.sign;
        // the sign of the result is the sign of the greater of the numbers without considering signs
        // so signs of the two bigreals are changed to +ve while comparing them
        sign='+';
        bgrl.sign='+';
        
        if(*this < bgrl)
        {
        New.sign = temp2;
        temp = *this;
        *this = bgrl;
        bgrl = temp;
        swapped =1;
        }
        else
        New.sign = temp1;
        // subtrcating the two fractions first from right to left 
        string subtFrc=""; // stores the fraction part after subtraction
        int carry=0;
        for(int i = fraction.size()-1; i >= 0; i--)
        {
            // subtracting the two integers and the carry 
            int sb = (fraction[i]-'0') - (bgrl.fraction[i]-'0') - carry;
            if (sb<0)
            {
                // carry apears if the result after subtracting is negative
                sb+=10;
                carry=1;
            } 
            else
            carry = 0 ;

            subtFrc += to_string(sb);
        }
        reverse(subtFrc.begin(), subtFrc.end());

        // subtracting integers with considering the remaining carry from subtracting the fraction part
        string subtInt=""; // stores the integer part after subtraction
        for(int i = integer.size()-1; i >= 0; i--)
        {
            int sb = (integer[i]-'0') - (bgrl.integer[i]-'0') - carry;
            if (sb<0)
            {
                sb+=10;
                carry=1;
            } 
            else
            carry = 0 ;

            subtInt += to_string(sb);
        }
        reverse(subtInt.begin(), subtInt.end()); 
        
        
        // returning the original signs
        sign = temp1;
        bgrl.sign = temp2;
        New.integer=subtInt;
        New.fraction=subtFrc;
        if(swapped)
        {
            bgrl=*this;
            *this = temp;
            
        }
        return New;
    }
}


BigReal BigReal::operator- (BigReal bgrl)
{
    // using the + overloaded operator in subtrcation 
    //A-B = A+(-B)
    //(-A)-(-B) = -A+B
    // (-A)-(+B) = -A-B
    // (+A)- (-B) = A + B

    BigReal New("0");
    char temp1= sign;
    char temp2= bgrl.sign;

    if(sign==bgrl.sign)
    {
        if(sign=='+')
        {
            bgrl.sign='-';
        }
        else
        {
            sign='-';
            bgrl.sign ='+';
        }
            New=*this+bgrl;
    }
    else 
    {
        if(sign=='+')
        {
            bgrl.sign='+';
        }
        else
        {
            bgrl.sign='-';
        }
        New=*this+bgrl;
    }
    sign = temp1;
    bgrl.sign = temp2;
    return New;
}
 ostream& operator <<(ostream& out, const BigReal& num){
    int zerofrac = 1, zeroInt = 1;
    // if the real number = 0 cout "0.0";
        for(int i=0; i<num.integer.size(); i++ )
        {
            if(num.integer[i]!='0')
            {
                zeroInt=0;
                break;
            }
        }
        for(int i=0; i<num.fraction.size(); i++ )
        {
            if(num.fraction[i]!='0')
            {
                zerofrac=0;
                break;
            }
        }

    
    if(zeroInt and zerofrac)
        out<< "0.0";
    else
     {
    if(num.sign=='-')
    out<<num.sign;
    out<<num.integer<<"."<<num.fraction;
    }
    return out;
 }
