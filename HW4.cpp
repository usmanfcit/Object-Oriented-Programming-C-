#include <iostream>
#include <cmath>

using namespace std;

class RationalNo
{
    int numerator;
	int denominator;

public :

//Setters
    void setNum(int n_1)
    {
        numerator = n_1;
    }

    void setDen(int d_1)
    {
        if(d_1 != 0)
        {
            denominator = d_1;
        }
        else
        {
            denominator = 1;
        }
    }

//Getters
    int getNum()
    {
        return numerator;
    }

    int getDen()
    {
        return denominator;
    }

//Parametrized Constructors
    RationalNo (int n_2, int d_2)
    {   
        setNum(n_2);
        setDen(d_2);
    }

    RationalNo (int n_3)
    {   
        setNum(n_3);
        setDen(1);
    }

// 3-Overloading "+" Operator
    RationalNo operator+ (const RationalNo& obj4)
    {
        return RationalNo (this->numerator * obj4.denominator + obj4.numerator * this->denominator , this->denominator * obj4.denominator);
    }

// 4-Overloading "-" Operator
    RationalNo operator- (const RationalNo& obj5)
    {
        return RationalNo (this->numerator * obj5.denominator - obj5.numerator * this->denominator , this->denominator * obj5.denominator);
    }

// 5-Overloading "*" Operator
    RationalNo operator *(const RationalNo& obj6)
    {
        return RationalNo(this->numerator * obj6.numerator , this->denominator * obj6.denominator);
    }

// 6-Overloading "/" Operator
    RationalNo operator /(const RationalNo& obj7)
    {
        return RationalNo(this->numerator * obj7.denominator , obj7.numerator * this->denominator);
    }

// 9-Overloading Unary "-" Operator
    RationalNo operator- ()
    {
        return RationalNo(-numerator , denominator);
    }

// 7-Overloading "<" Operator
    bool operator < (const RationalNo& obj8)
    {
        if( (this->numerator * obj8.denominator) < (this->denominator * obj8.numerator) )
            return true;

        else
            return false;
    }

// 8-Overloading "==" Operator
    bool operator == (const RationalNo& obj9)
    {
        if( (this->numerator * obj9.denominator) == (this->denominator * obj9.numerator) )
            return true;

        else
            return false;
    }

// 10-Overloading Unary "!" Operator
    bool operator ! ()
    {
        if (this->numerator < 0 ) 
            return true;

        else
            return false;
    }

// Making Global Functions Friend of Class
    friend ostream& operator<< (ostream& out, const RationalNo& obj);

    friend istream& operator>> (istream& in, RationalNo& obj2);

};

// 1- Overloading Stream-Insertion Operator
    ostream& operator<< (ostream& out, const RationalNo& obj)
    {
        out << obj.numerator << "/" << obj.denominator << endl;

        return out;
    }

// 2- Overloading Stream-extraction operator
    istream& operator>> (istream& in, RationalNo& obj2)
    {
        cout << "Enter Numerator and Then Denominator" << endl;
        in >> obj2.numerator;
        obj2.setNum(obj2.getNum());

        cout << "/";
        in >> obj2.denominator;
        obj2.setDen(obj2.getDen());

        return in;
    }

int main()
{
    RationalNo obj1(5, 7);

    RationalNo obj2(8);

    cin >> obj2;

    cout << endl << obj2 << endl;

    cout << "Obj1 + Obj2 = "<< obj1 + obj2 << endl;

    cout << "Obj1 - Obj2 = "<< obj1 - obj2 << endl;

    cout << "Obj1 * Obj2 = "<< obj1 * obj2 << endl;

    cout << "Obj1 / Obj2 = "<< obj1 / obj2 << endl;

    cout << "-Obj1 = " << -obj1 << endl; 


    return 0;
}