#include <iostream>
#include <cmath>
using namespace std;

class Rat {

private:
    int n;
    int d;

public:
    // constructors

    // default
    Rat() {
        n = 0;
        d = 1;
    }

    // 2 parameter
    Rat(int i, int j) {
        n = i;
        d = j;
        lowestTerm(n, d);
    }

    // conversion
    Rat(int i) {
        n = i;
        d = 1;
    }

    // setters & getters
    int getN() { return n; }
    int getD() { return d; }

    void setN(int i) { n = i; }
    void setD(int i) { d = i; }

    // arithmetic ops
    Rat operator+(Rat r) {
        Rat t;
        t.n = (n * r.d) + (d * r.n);
        t.d = d * r.d;
        return t;
    }

    Rat operator-(Rat r) {
        Rat t;
        t.n = (n * r.d) - (d * r.n);
        t.d = d * r.d;
        return t;
    }

    Rat operator*(Rat r) {
        Rat t;
        t.n = n * r.n;
        t.d = d * r.d;
        return t;
    }

    Rat operator/(Rat r) {
        Rat t;
        t.n = n * r.d;
        t.d = d * r.n;
        return t;
    }

    // Write a function to reduce the Rat to lowest terms
    void lowestTerm(int& n, int& d) {
        if(d < 0) return
        int commonNum = gcd(d, n);
        n /= commonNum;
        d /= commonNum;
    }

    // Calculate the GCD
    int gcd(int n, int d) {
        if (n == 0) return d;
        else return gcd((d % n), n);
    }

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);

};// end Rat class

ostream& operator<<(ostream& os, Rat r){
   if (r.d == 1) os << r.n << endl;
   else if (r.n == 0) os << '0' << endl;
   else if (r.n < r.d) {
       int wholeNum = r.n / r.d, newNum = r.n % r.d;
       os << wholeNum << ' ' << newNum << " / " << r.d << endl;
   }
   else os << r.n << " / " << r.d << endl;
   // Negative numbers should be printed the same way, but beginning with a minus sign
   return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts
istream& operator>>(istream& is, Rat& r) {
    is >> r.n >> r.d;
    return is;
}

int main() {
    Rat r1(5, 2), r2(3, 2);

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 < endl;
    cout << "r1 - r2: " << r1 - r2 < endl;
    cout << "r1 * r2: " << r1 * r2 < endl;
    cout << "r1 / r2: " << r1 / r2 < endl << endl;

    r1 = r2;
    r2 = r1 * r2;

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 < endl;
    cout << "r1 - r2: " << r1 - r2 < endl;
    cout << "r1 * r2: " << r1 * r2 < endl;
    cout << "r1 / r2: " << r1 / r2 < endl << endl;

    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;

    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 < endl;
    cout << "r1 - r2: " << r1 - r2 < endl;
    cout << "r1 * r2: " << r1 * r2 < endl;
    cout << "r1 / r2: " << r1 / r2 < endl;

    return 0;
}
