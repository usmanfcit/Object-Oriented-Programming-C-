#include <iostream>
#include <string.h>

using namespace std;

class Employee
{
    string name;
    int id;
    string department;
    string position;

public :
    //Parametrized Constructors
    Employee(string name1, int id1, string department1, string position1)
    {
        name = name1;
        id = id1;
        department = department1;
        position = position1;
    }

    Employee(string name2, int id2)
    {
        name = name2;
        id = id2;
        department = "";
        position = "";
    }

    //Default Constructor
    Employee()
    {
        name = "";
        department = "";
        position = "";
        id = 0;
    }

    // Copy Constructor
    Employee(const Employee &obj)
    {
        name = obj.name;
        id = obj.id;
        department = obj.department;
        position = obj.position; 
    }

    // Destructor
    ~Employee()
    {
        cout << "Destructor executed..." << endl;
    }

    // Member Functions
    void setInfo(string name5, int id5, string department5, string position5)
    {
        name = name5;
        id = id5;
        department = department5;
        position = position5;
    }

    void putInfo()
    {
        cout << name << "\t" << id << "\t\t" << department << "\t" << position << endl;
    }

    void getInfo()
    {
        cout<< "Enter Employee Name = " << endl;
        getline(cin,name);

        cout<< "Enter Employee Id = " << endl;
        cin>>id;

        cin.sync();

        cout << "Enter Position = " << endl;
        getline(cin, position); 
        
        cout << "Enter Department = " << endl;
        getline(cin,department);

     }

    // Setters
    void setID(int id3)
    {
        id = id3;
    }

    void setName(string name3)
    {
        name = name3;
    }

    void setDepartment(string department3)
    {
        department = department3;
    }

    void setPosition(string position3)
    {
        position = position3;
    }

   // Getters
    int getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getDepartment()
    {
        return department;
    }

    string getPosition()
    {
        return position;
    }

};

int main()
{
    // 4 Parameter Constructor Used for Object 1
    Employee o1("Naveed Ali", 1230, "Computer Science", "Assistant Professor");
  
    // Using setInfo Function for Object 4
    Employee o4;
    o4.setInfo("Naeem Ahmad", 1241, "Computer Science", "Lecturer");

    // 2 Parameter Constructor
    Employee o2("NULL", 0);

    // Copy Constructor Used for Object 3
    Employee o3 = o1;
    
    // Default Constructor
    Employee o5;

    // Setters Used for Object 2
    o2.setID(1231);
    o2.setName("Nouman Abdullah");
    o2.setPosition("Lecturer");
    o2.setDepartment("Software Engineering");

    // getInfo method to initialize the data of an employee taken from the user
    cout << "Enter Details For Object 5" << endl;
    o5.getInfo();

    // Information Headings ( Formatting )
    cout << endl << "Name \t\t" << "Id Number \t" << "Department \t\t" << "Position \t" << endl;

    // Displaying Information
    o1.putInfo();
    o2.putInfo();
    o3.putInfo();
    o4.putInfo();
    o5.putInfo();
    
    return 0; 
}