#include <iostream>
#include <string.h>

using namespace std;

class NumDays
{
    int wHours;

public:
    NumDays(int h)
    {
        wHours = h;
    }

    NumDays()
    {
        wHours = 0;
    }

    void setH(int h_1)
    {
        wHours = h_1;
    }

    int getH()
    {
        return wHours;
    }

    float getD()                  //Days will be Automatically calculated from workHours (8 work Hours = 1 working day)
    {
        float days = (float)this->wHours/8;
        return days;
    }

    void setD(float d_1)         //work hours will be automatically calculated from days (1 working day = 8 work hours)
    {
        wHours = d_1 * 8;
    }

    int operator+(const NumDays& obj)
    {
        int temp = this->wHours + obj.wHours;
        return temp;
    }

    int operator-(const NumDays& obj)
    {
        int temp = this->wHours - obj.wHours;
        return temp;
    }

    void operator++()           //Prefix-Increment
    {
        ++(this->wHours);
    }

    void operator++(int)        //Postfix-Increment
    {
        (this->wHours)++;
    }

    void operator--()           //Prefix-Decrement
    {
        --(this->wHours);
    }

    void operator--(int)        //Postfix-Decrement
    {
        (this->wHours)--;
    }
};

class TimeOff
{
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;
    string eName;
    string id;

public:
    TimeOff() : maxSickDays(0), sickTaken(0), maxVacation(0), vacTaken(0), maxUnpaid(0), unpaidTaken(0) 
    {
        eName = " ";
        id = " ";
    }

    void setMV(float mv_1)
    {
        if(mv_1*8 <= 240)
            maxVacation.setD(mv_1);
        else
        {
            maxVacation.setH(240);
        }
    }

    float getMV()
    {
        return maxVacation.getD();
    }

    void setMSD(int MSD_1)
    {
        maxSickDays.setD(MSD_1);
    }

    float getMSD()
    {
       return maxSickDays.getD();
    }

    void setST(float st_1)
    {
        sickTaken.setD(st_1);
    }

    float getST()
    {
        return sickTaken.getD();
    }

    void setVT(float vt_1)
    {
        vacTaken.setD(vt_1);
    }

    float getVT()
    {
        return vacTaken.getD();
    }

    void setUT(float UT_1)
    {
        unpaidTaken.setD(UT_1);
    }

    float getUT()
    {
       float uLeave =  maxSickDays - sickTaken;

       if(uLeave < 0)
       {
           uLeave = -uLeave;
           unpaidTaken.setH(uLeave);
           return unpaidTaken.getD();
       }
       else
       {
           return 0;
       }
    }

    void setMU(float MU_1)
    {
        maxUnpaid.setD(MU_1);
    }

    float getMU()
    {
       float mUnpaid =  maxVacation - vacTaken;

       if(mUnpaid < 0)
       {
           mUnpaid = -mUnpaid;
           maxUnpaid.setH(mUnpaid);
           return maxUnpaid.getD();
       }
       else
       {
           return 0;
       }
    }
};

int main()
{
    int months;
    cout << "Enter Number of months the employee has worked : ";
    cin >> months;

    TimeOff obj;

    cout << endl;

    obj.setMV(months*1.5);
    cout <<"Employee's maximum days of paid vacation : " << obj.getMV() << endl;

    obj.setMSD(months);
    cout <<"Employee's maximum sick leave days : " << obj.getMSD() << endl;

    cout << endl;

    obj.setST(7);                  //number of days on Sick Leave(Sicktaken)
    cout <<"Unpaid Sick Leaves Taken by Employee : " << obj.getUT() << endl;

    obj.setVT(3);                  //number of days on Vacation(VacationTaken)
    cout<< "Unpaid Vacations Taken by Employee : "<< obj.getMU(); 

    cout << endl;

    return EXIT_SUCCESS;
}