
// Purpose: Designing a BigReal Class that deals with very large numbers

// Authors:
// Sama Ashraf Ahmed
// Shahd Mohammed Abd El-Monjy
// Nouran Ashraf Ali

// IDs:
// 20220436
// 20221085
// 20221242

// Last-Modified-Date: 5/11/2023

#include <iostream>
#include "BigReal.cpp"

using namespace std;

int main()
{
    BigReal n1("11.9000000000000000000000000000000001");
    BigReal n2("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3 << '\n';

    BigReal a1("-99.99"), a2("-99.99"), a3("-53.0"), a4("90"), a5("80.8");
    cout << (a1 + a2) << '\n';
    cout << (a1 - a2) << '\n';
    cout << (a3 + a5) << '\n';
    cout << (a5 - a4) << '\n';

    // testing all kind of numbers initializing
    BigReal b1("+.2"), b2("0.55"), b3("-.03"), b4("0.55");
    cout << b2 + b3 << '\n'
         << b3 << '\n'
         << b4 << '\n';

    // testing < and > operators
    BigReal c1("1000.1"), c2("1000.2"), c3("-1000.05"), c4("-1000.06"), c5("1.99");
    cout << (c1 > c2) << '\n'; // false
    cout << (c1 < c2) << '\n'; // true
    cout << (c3 > c4) << '\n'; // true
    cout << (c1 > c4) << '\n'; // true
    cout << (c2 < c5) << '\n'; // false

    BigReal d1("0.55"), d2("0.05");
    cout << (d1 > d2) << '\n'; // true

    // testing + and -
    BigReal e1("89.00000005"), e2("89.00000009"), e3("-89.00000005"), e4("-89");
    cout << (e1 + e2) << '\n';
    cout << (e1 + e3) << '\n';
    cout << (e1 + e4) << '\n';

    // testing contructor
    BigReal f("000007");
    cout << f << '\n';

    BigReal g("2000000"), h("-6541232585000.2358");

    cout << (g - h) << '\n';

    BigReal i("0.888"), j("0.88800");
    cout << (i == j) << '\n';
}