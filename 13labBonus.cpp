#include<iostream>
#include<string.h>
using namespace std;

class Ship
{
    string name, year;
public:
    Ship()
    {
        name = " ";
        year = " ";
    }
    Ship(string n_1, string y_1)
    {
        name  = n_1;
        year  = y_1;
    }
    string getyear()
    {
        return year;
    }
    string getname()
    {
        return name;
    }
    void setyear(string y_2)
    {
        year  = y_2;
    }
    void setname(string n_2)
    {
        name = n_2;
    }

    virtual void print()
    {
        cout << name << "\t" << year << endl;
    }
};

class CruiseShip : public Ship
{
    int passengers;
public:
    CruiseShip(string n_1, string y_1, int p_1) : Ship(n_1, y_1)
    {
        passengers = p_1;
    }
    void setPassengers(int p_2)
    {
        passengers = p_2;
    }

    int getPassengers()
    {
        return passengers;
    }
    virtual void print()
    {
        cout << getname() << "\t" << getyear() << "\t" << passengers << endl;
    }
};

class CargoShip: public Ship
{
    int capacity;
public:
    CargoShip(string n_1, string y_1, int c_1) : Ship(n_1, y_1)
    {
        capacity = c_1;
    }
    void setCapacity(int c_2)
    {
        capacity = c_2;
    }
    int getCapacity()
    {
        return capacity;
    }
    virtual void print()
    {
        cout << getname() << "\t" << getyear() << "\t" << capacity << endl;
    }
};
class BattleShip: public Ship
{
    int missiles;
public:
    BattleShip(string n_1, string y_1, int m_1) : Ship(n_1, y_1)
    {
        missiles = m_1;
    }
    void setMissiles(int m_2)
    {
        missiles = m_2;
    }
    int getMissiles()
    {
        return missiles;
    }
    virtual void print()
    {
        cout << getname() << "\t" << getyear() << "\t" << missiles << endl;
    }
};
int main()
{
    Ship *p[4];
    p[0] = new Ship("Simple Ship", "1980");
    p[1] = new CruiseShip("Cruise Ship", "1990", 100);
    p[2] = new CargoShip("Cargo Ship", "2000", 250);
    p[3] = new BattleShip("Battle Ship", "2010", 68);

    for (int i = 0; i < 4; i++)
    {
        p[i]->print();
    }
    
    delete[] p;

    return EXIT_SUCCESS;
}