#include "iostream"

using namespace std;

class FeetInches
{
private:
	int feet;			// To hold a number of feet
	int inches;			// To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches & right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator + (const FeetInches & right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator - (const FeetInches & right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator * (const FeetInches & right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator ++ ()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator ++ (int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator -- ()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator -- (int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator > (const FeetInches & right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator < (const FeetInches & right)
	{
		return !(*this > right);
	}

	bool operator >= (const FeetInches & right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator <= (const FeetInches & right)
	{
		return !(*this >= right);
	}

	bool operator == (const FeetInches & right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator != (const FeetInches & right)
	{
		return !(*this == right);
	}

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);
};

ostream& operator << (ostream & out, const FeetInches & obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator >> (istream & in, FeetInches & obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

class RoomDimension
{
	FeetInches length;
	FeetInches width;

public:

	RoomDimension(const FeetInches& length1, const FeetInches& width1 ) : length(0, 0), width(0, 0)
	{
		length.setFeet(length1.getFeet());
		length.setInches(length1.getInches());

		width.setFeet(width1.getFeet());
		width.setInches(width1.getInches());
	} 

	FeetInches getL()
	{
		return length;
	}
	void setL(const FeetInches& length2)
	{
		length.setFeet(length2.getFeet());
		length.setInches(length2.getInches());
	}

	FeetInches getW()
	{
		return width;
	}

	void setW(const FeetInches& width2)
	{
		width.setFeet(width2.getFeet());
		width.setInches(width2.getInches());
	}

	FeetInches aR()
	{

		return length * width;

	}

	void disp()
	{
		cout << "Length (Feet): " << length.getFeet() << endl;
		
		cout << "Width (Feet): " << width.getFeet() << endl;
	}
};

class RoomCarpet
{
	RoomDimension roomSize;
	float costPerSquareFoot;

public:

	RoomCarpet(RoomDimension& obj, float cost) : roomSize( obj.getL(), obj.getW() )
	{
		costPerSquareFoot = cost;
	}

	RoomDimension getSize()
	{
		return roomSize;
	}

	void setSize( RoomDimension& obj)
	{
		roomSize.setL( obj.getL() );
		roomSize.setW( obj.getW() );
	}

	float getCost()
	{
		return costPerSquareFoot;
	}

	void setCost(float f)
	{
		costPerSquareFoot = f;
	}

	void show()
	{
		cout << "CostPerSqaureFeet : " << costPerSquareFoot << endl;
		roomSize.disp();
	}
	int totalCost()
	{
		return costPerSquareFoot * ( this->roomSize.aR().getFeet() );
	}
};

int main()
{
	FeetInches obj1;
	FeetInches obj2;
	cin >> obj1;
	cin >> obj2;
	RoomDimension obj3(obj1, obj2);

	cout << endl;

	RoomCarpet obj4(obj3, 80);

	obj4.show();

	cout << "Total Cost : " << obj4.totalCost() << endl;

	return EXIT_SUCCESS;
}