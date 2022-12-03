#include <iostream>
#include <string.h>

using namespace std;

class Date
{
private:
	
	int day;
	int month;
	int year;	
	
public:
	//Setters
	
	void setD(int d_1)
	{
		if( (d_1 >= 1) && (d_1 <=31) )
		{
			day = d_1;
		}
		else
		day = 1;
	}
	
	void setM(int m_1)
	{
		if( (m_1 >= 1) && (m_1 <=12) )
		{
			month = m_1;
		}
		else
			month = 1;
	}
	
	void setY(int y_1)
	{
		if( y_1 >= 1900 )
		{
			year = y_1;
		}
		else 
			year = 1900;
	}
	
	// Getters
	
	int getD()
	{
		return day;
	}
	
	int getM()
	{
		return month;
	}
	
	int getY()
	{
		return year;
	}
	
	//Constructors
	
	Date(int d_2, int m_2, int y_2)
	{
		setD(d_2);
		
		setM(m_2);
		
		setY(y_2);
	}
	
	Date(int m_3, int y_3)
	{
		day = 1;  
		
		setM(m_3);
		
		setY(y_3);
	}
	
	Date()
	{
		day = 1;
		month = 1;
		year = 1;
	}
	
	~Date()
	{
		
	}
	
	//Pre-Increment Overload
	Date operator++()
	{
		return Date(++this->day, this->month, this->year);
	}
	
	//Post-Increment Overload
	Date operator++(int)
	{
		return Date(this->day++, this->month, this->year);
	}
	
	//Pre-Decrement Overload
	Date operator--()
	{
		return Date(--this->day, this->month, this->year);
	}
	
	//Post-Decrement Overload
	Date operator--(int)
	{
		return Date(this->day--, this->month, this->year);
	}
	
	bool operator+()
	{
		if((this->day == 5) && (this->month == 2))
			return true;
			
		if((this->day == 23) && (this->month == 3))
			return true;
			
		if((this->day == 1) && (this->month == 5))
			return true;
			
		else
			return false;
		
	}
	
	int operator-(const Date& obj)
	{
		int x = this->day - obj.day;
		int y = this->month - obj.month;
		int z = this->year - obj.year;
		
		return x + y*31 + z*365;
		
	}
	
	
	friend istream& operator>>(istream& in, Date& obj);
	
	friend ostream& operator<<(ostream& out, Date& obj);
};

//Stream Extraction Overload

istream& operator>>(istream& in, Date& obj)
{
	cout << "Enter Date in the Following Format dd/mm/yyyy" << endl;
	int d1, m1, y1;
	
	in >> d1;
	obj.setD(d1);
	
	in >> m1;
	obj.setM(m1);
	
	in >> y1;
	obj.setY(y1);
}

//Stream Insertion Overload

ostream& operator<<(ostream& out, Date& obj)
{
	string arr[13] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	out << arr[obj.getM()] << " " << obj.getD() << ", " << obj.getY(); 
}

int main()
{
	Date obj1(30, 11, 2021);
	Date obj2;
	
	
	cin >> obj2;
	
	obj2--;
	
	cout << endl << "Diffrence Between Two Dates : " << obj1 - obj2;
	
	
	return 0;
}
