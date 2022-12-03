#include<iostream>
#include<string>
using namespace std;
class Employee
{
private:
	string firstname, lastname, SSN;
public:
	Employee(string fname, string lname, string SSN_1)
	{
		firstname = fname;
		lastname = lname;
		SSN = SSN_1;
	}
//Getters
	string getfname()
	{
		return firstname;
	}
	string getlname()
	{
		return lastname;
	}
	string getSSN()
	{
		return SSN;
	}
//Setters
	void setfname(string fname_1)
	{
		firstname = fname_1;
	}
	void setlname(string lname_1)
	{
		lastname = lname_1;
	}
	void setSSN(string SSN_1)
	{
		SSN = SSN_1;
	}

	virtual void print()
	{
		cout << firstname << " " << lastname << "\t \t" << SSN << endl;
	}
	virtual double earnings() = 0;
};

class SalariedEmployee : public Employee
{
private:
	double weeklySalary;
public:
	SalariedEmployee(string fname, string lname, string SSN_1)
		: Employee(fname, lname, SSN_1)
	{
		weeklySalary = 0;
	}
	void setwS(double wS_1)
	{
		weeklySalary = wS_1;
	}
	double getwS()
	{
		return weeklySalary;
	}

	virtual void print()
	{
		cout << getfname() << " " << getlname() << "\t" << getSSN() << "\t" << weeklySalary << endl;
	}

	virtual double earnings()
	{
		return weeklySalary * 4;
	}
};

class HourlyEmployee : public Employee
{
private:
	double wage, hours;
public:
	HourlyEmployee(string fname, string lname, string SSN_1)
		: Employee(fname, lname, SSN_1)
	{
		wage = 0;
		hours = 0;
	}
	void setH(double h_1)
	{
		hours = h_1;
	}
	void setWage(double wage_1)
	{
		wage = wage_1;
	}
	double getH()
	{
		return hours;
	}
	double getWage()
	{
		return wage;
	}
	virtual void print()
	{
		cout << getfname() << " " << getlname() << "\t\t" << getSSN() << "\t" << wage << "\t" << hours << endl;
	}
	virtual double earnings()
	{
		return wage * hours;
	}
};

class CommissionEmployee : public Employee
{
private:
	double grossSales, commisionRate;
public:
	CommissionEmployee(string fname, string lname, string SSN_1)
		: Employee(fname, lname, SSN_1)
	{
		grossSales = 0;
		commisionRate = 0;
	}
	void setgS(double gS_1)
	{
		grossSales = gS_1;
	}
	void setcR(double cR_1)
	{
		commisionRate = cR_1;
	}
	double getgS()
	{
		return grossSales;
	}
	double getcR()
	{
		return commisionRate;
	}
	virtual void print()
	{
		cout << getfname() << " " << getlname() << "\t" << getSSN() << "\t" << grossSales << "\t" << commisionRate << endl;
	}
	virtual double earnings()
	{
		return grossSales * commisionRate;
	}
};

class BasePlusComissionEmployee : public CommissionEmployee
{
private:
	double baseSalary;
public:
	BasePlusComissionEmployee(string fname, string lname, string SSN_1)
		: CommissionEmployee(fname, lname, SSN_1)
	{
		baseSalary = 0;
	}
	double getbS()
	{
		return baseSalary;
	}
	void setbS(double bS_1)
	{
		baseSalary = bS_1;
	}
	virtual void print()
	{
		cout << getfname() << " " << getlname() << "\t" << getSSN() << "\t" << getgS() << "\t" << getcR() << "\t" << baseSalary << endl;
	}
	virtual double earnings()
	{
		double temp = CommissionEmployee::earnings() + baseSalary;
		return temp;
	}
};
int main()
{
	SalariedEmployee obj("Salaried", "Employee", "998");
	obj.setwS(10000);

	HourlyEmployee obj2("Hourly", "Employee", "1001");
	obj2.setH(24);
	obj2.setWage(500);

	CommissionEmployee obj3("Commissioned", "Employee", "1049");
	obj3.setcR(100);
	obj3.setgS(78);

	BasePlusComissionEmployee obj4("BasePlus", "ComissionedEmployee", "1066");
	obj4.setgS(50);
	obj4.setcR(100);
	obj4.setbS(50000.00);

	Employee* eptr[4] = { &obj, &obj2, &obj3, &obj4 };

	for (int i = 0; i < 4; i++)
	{
		eptr[i]->print();
		cout <<"Earnings : "<< eptr[i]->earnings() << endl;
		cout << endl;
	}

	return EXIT_SUCCESS;
}