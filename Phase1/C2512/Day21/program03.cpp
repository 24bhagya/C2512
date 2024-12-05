#include <iostream>
#include <cstring>
using namespace std;

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction { //a/b , here a = numerator , b = denominator
    private:
        //attr 
        int numerator;
        int denominator;
    public:
        // constructor 
        Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) { }
        /*Fraction Add(const Fraction& other) {
            Fraction third(0, 1);
            third.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
            third.denominator = this->denominator * other.denominator;
            //
            int gcd = findGCD(third.numerator, third.denominator);
            third.numerator = third.numerator / gcd;
            third.denominator = third.denominator / gcd;
            //
            return third;
        }*/

        //operator
        friend ostream& operator<<(ostream& output, const Fraction& fraction);
        Fraction operator+(const Fraction& other) {
            //cout << "Inside member\n";
            Fraction third(0,1);
            third.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
            third.denominator = this->denominator * other.denominator;
            //
            int gcd = findGCD(third.numerator, third.denominator);
            third.numerator = third.numerator / gcd;
            third.denominator = third.denominator / gcd;
            //
            return third;
        }
        Fraction operator+() {
            Fraction result = *this;
            return result;
        }
        Fraction operator-() {
            Fraction result = *this;
            result.numerator = -result.numerator;
            return result;
        }
        friend Fraction operator+(const Fraction& first, const Fraction& second);

        bool operator<(const Fraction& other) {
            return ((float)this->numerator / (float)this->denominator) < ((float)other.numerator / (float)other.denominator);
        }
        bool operator==(const Fraction& other) {
            return ((float)this->numerator / (float)this->denominator) == ((float)other.numerator / (float)other.denominator);
        }
        bool operator>(const Fraction& other) {
            return !(*this < other);
        }
        bool operator<=(const Fraction& other) {
            return (*this < other) || (*this == other);
            //return ((float)this->numerator / (float)this->denominator) <= ((float)other.numerator / (float)other.denominator);
        }
        bool operator>=(const Fraction& other) {
            return (*this > other) || (*this == other);
        }
        bool operator!=(const Fraction& other) {
            return !(*this == other);
        }
};

ostream& operator<<(ostream& output, const Fraction& fraction) { //non member op <<
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}
/*Fraction operator+(const Fraction& first, const Fraction& second) {
    //cout << "Inside non-member\n";
    Fraction third(0,1);
    third.numerator = (first.numerator * second.denominator) + (second.numerator * first.denominator);
    third.denominator = first.denominator * second.denominator;
    //
    int gcd = findGCD(third.numerator, third.denominator);
    third.numerator = third.numerator / gcd;
    third.denominator = third.denominator / gcd;
    //
    return third;
}*/


int main() {
    // Create two fraction objects
    Fraction f1(1, 2); // Represents 1/2

    cout << "+f1: " << +f1 << endl; // +f1 is same as f1.operator+()
    cout << "-f1: " << -f1 << endl; // -f1 is same as f1.operator-()

    Fraction f2(2, 3); // Represents 2/3

    cout << "f1 < f2: " << (f1 < f2) << endl; 
    cout << "f2 < f1: " << (f2 < f1) << endl; 
    cout << "f1 > f2: " << (f1 > f2) << endl; 
    cout << "f2 > f1: " << (f2 > f1) << endl; 

    cout << "f1 == f2: " << (f1 == f2) << endl;
    cout << "f1 != f2: " << (f1 != f2) << endl;
    cout << "f1 < f2: " << (f1 < f2) << endl;
    cout << "f1 > f2: " << (f1 > f2) << endl;
    cout << "f1 <= f2: " << (f1 <= f2) << endl;
    cout << "f1 >= f2: " << (f1 >= f2) << endl;
    // Add two fractions
    //Fraction result = f1.Add(f2);
    Fraction result = f1 + f2; // f1.operator+(f2) //LATER::or opearator+(f1, f2)
    cout << "sum of " << f1 << " and " << f2 << " is " << result << "." << endl; // Expected output: 7/6 (in reduced form)

    // Create a third fraction
    Fraction f3(3, 4); // Represents 3/4

    // Add three fractions
    //Fraction result2 = f1.Add(f2.Add(f3));
    Fraction result2 = (f1 + (f2 + f3)); // f1.operator+(f2).operator+(f3) //LATER::or operator+(operator+(f1, f2), f3)

    cout << "sum of " << f1 << ", " << f2 << " and " << f3 << " is " << result2 << "." << endl; // Expected output: 23/12 (in reduced form)

    return 0;
}
