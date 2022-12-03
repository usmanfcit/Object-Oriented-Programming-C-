#include <iostream>
#include <string.h>

using namespace std;

class Student
{
	private:
		
	int regNo;
	string firstName;
	string lastName;
	string program;
	float cgpa;
	
	public :
		
		// Setters
		
		void setReg(int reg_1)
		{
			if((reg_1>= 501) && (reg_1 <= 565))
			regNo = reg_1;
			
			else
			regNo = 0;
		}
		
		void setfName(string f_1)
		{
			firstName = f_1;
		}
		
		void setlName(string l_1)
		{
			firstName = l_1;
		}
		
		void setProgram(string p_1)
		{
			program = p_1;
		}
		
		void setCgpa(float c_1)
		{
			if((c_1 >= 0.0) && (c_1 <= 4.00))
			cgpa = c_1;
			
			else
			cgpa = -1;
		}
		
		// Getters
		
		int getReg()
		{
			return regNo;
		}
		
		string getfName()
		{
			return firstName;
		}
		
		string getlName()
		{
			return lastName;
		}
		
		float getCgpa()
		{
			return cgpa;
		}
		
		// Parameterized Constructor
		
		Student(int r_2, string f_2, string l_2, string p_2)
		{
			setReg(r_2);
			firstName = f_2;
			lastName = l_2;
			program = p_2;
			cgpa = -1;
		}
		
		Student(int r_3, string f_3, string p_3)
		{
			lastName = "";
			cgpa = -1;
			regNo = r_3;
			firstName = f_3;
			program = p_3;
		}
		
		Student(int r_4, string f_4, string l_4, string p_4, float c_4)
		{
			setReg(r_4);
			setCgpa(c_4);
			firstName = f_4;
			lastName = l_4;
			program = p_4;
		}
		
		// Copy Constrcutor
		
		Student(const Student &obj)
		{
			regNo = obj.regNo;
			firstName = obj.firstName;
			lastName = obj.lastName;
			program = obj.program;
			cgpa = obj.cgpa;
		}
		
		// Destructor
		
		~Student()
		{
			cout << "Destructor Executed...." << endl;
		}
		
		// Member Functions
		
		void setStudent(int r_5, string f_5, string l_5, string p_5, float c_5)
		{
			setReg(r_5);
			setCgpa(c_5);
			firstName = f_5;
			lastName = l_5;
			program  = p_5;
		}
		
		void readStudent()
		{
			cout << "Enter Registration Number : ";
			cin >> regNo;
			setReg(regNo);
			
			cout << "Enter First Name : ";
			cin >> firstName;
			
			cout << "Enter Last Name : ";
			cin >> lastName;
			
			cout << "Enter Program : ";
			cin >> program;
			
			cout << "Enter CGPA : ";
			cin >> cgpa;
			setCgpa(cgpa);
		}
		
		void writeStudent()
		{
			cout << "Reg No. : " << regNo << endl;
			cout << "First Name : " << firstName << endl;
			cout << "Last Name : " << lastName << endl;
			cout << "cgpa : " << cgpa << endl;
			cout << "Program : " << program << endl;
			cout << "Percentage : " << getPercentage() << endl;
			cout << "is First Semester : " << isFirstSemester() << endl;
			cout << "is Promoted : " << isPromoted() << endl;
		}
		
		bool isFirstSemester()
		{
			if(cgpa == -1)
			return true;
			
			else
			return false;
		}
		
		float getPercentage()
		{
			if(cgpa >= 0.0)
			return cgpa/4.00*100;
			
			else 
			return -1;
		}
		
		bool isPromoted()
		{
			if(cgpa >= 2.00)
			return true;
			
			else
			return -1;
		}
};

int main()
{
	Student obj1(569, "Ahmad", "Bashir", "IT");
	obj1.readStudent();
	obj1.writeStudent();
	
	return 0;
}
