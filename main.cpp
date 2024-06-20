// Ahmed Mahmoud Lotfy ID: 20230536690
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#define ll long long

using namespace std;

// 3 Function (Prime, GCD, Mod) are used throughout the code

int Prime(int a) {   //Finding prime

    int pri;

    for (int i=a; i>=2; i--) {              //Descending order to find the nearest/largest prime number
        int cnt=0;                          //Counter for knowing the number of possible divisions

        for (int j=2; j<=i; j++) {

            if (i%j==0) {
                cnt++;
                continue;
                }
            }

            if (cnt==1) {                   //If found 1 division only, then prime
                pri=i;
                break;
            }
        }
        return pri;
}


int GCD(int x, int y) {   //Finding greatest common divisor

    int ans = min(x,y);

    while (ans>0) {
        if (x%ans==0 && y%ans==0)
            break;

        ans--;
    }

    return ans;
}

//ll = long long
ll Mod(ll base, ll exponent, int modulu) {  //Finding Mod

    ll result = 1;

    while (exponent > 0) {

        if (exponent%2==1)
            result = (result*base)%modulu;
        exponent = exponent >> 1;
        base = (base*base)%modulu;
    }

    return result;
}

int main()
{
    int p,q,m,n,e,d,k;

    cout << "Enter 2 distinct upper limits for 2 prime numbers p , q: " << endl;

    cout << "Upper limit for p: ";
    cin >> p;
    p = Prime(p);               //Finding max prime P

    cout << "Upper limit for q: ";
    cin >> q;
    q = Prime(q);               // Max prime Q

    n=p*q;
    m=(p-1)*(q-1);

    for  (e=2; true; e++) {  //Finding GCD
        if (GCD(m,e)==1)   //GCD function will keep looping till it equals 1
            break;
}

    for (int i=0; true; i++) { //find K
        if (((m*i+1)%e)==0) {
            k=i;
            break;
        }
    }

    d= (m*k+1)/e;

    cout << "P: " << p << endl << "Q: " << q << endl << "N: " << n << endl << "M: " << m << endl  << "E: " << e << endl << "D: " << d << endl;

    string plain,cipher, decrypted;
    cout << "Enter original message: ";
    cin.ignore();
    getline(cin,plain);
    cipher = plain;

    vector<long> save;  //Vector for saving values of cipher text after using Mod function

    for (int i=0; i<plain.size(); i++) {
        long a = long(plain[i]);           //Assigning Ascii of plain characters to a
        cipher[i] = Mod(a,e,n);
        save.push_back(Mod(a,e,n));       //Saving values
    }

    cout << "Cipher message: " << cipher << endl;

    cout << "Decrypted message: ";

    for (int i=0; i<save.size(); i++) {
        ll r = save[i];                 //Using saved values and assigning them to r
        decrypted[i] = char(Mod(r,d,n));
        cout << decrypted[i];
    }

    return 0;
}
