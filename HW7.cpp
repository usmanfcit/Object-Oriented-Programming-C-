#include <iostream>
#include <string>

using namespace std;

class Package
{
private:

    string nSender;
    string nReceiver;
    string aSender;
    string aReceiver;
    string cSender;
    string cReceiver;
    float weight;
    float costPerOunce;

public:

    Package(string nSender_1, string nReceiver_1, string aSender_1, string aReceiver_1, string cSender_1, string cReceiver_1, float w_1, float cPo_1)
    {
        nSender = nSender_1;
        nReceiver = nReceiver_1;
        aSender = aSender_1;
        aReceiver = aReceiver_1;
        cSender = cSender_1;
        cReceiver = cReceiver_1;

        if(w_1 > 0 )
            weight = w_1;
        else 
            weight = 0;
        
        if(cPo_1 > 0)
            costPerOunce = cPo_1;
        else
            costPerOunce = 0;
    }

    float calculateCost()
    {
        return weight * costPerOunce;
    }

    float getcPo()
    {
        return costPerOunce;
    }

    float getWeight()
    {
        return weight;
    }
};

class TwoDayPackage : Package
{
    private:

        float flatFee;

    public:

        TwoDayPackage(string nSender_1, string nReceiver_1, string aSender_1, string aReceiver_1, string cSender_1, string cReceiver_1, float w_1, float cPo_1, float fFee)
            : Package(nSender_1, nReceiver_1, aSender_1, aReceiver_1, cSender_1,  cReceiver_1,  w_1, cPo_1)
        {
            if(fFee > 0)
                flatFee = fFee;
            else
                flatFee = 0;
        }

        float calculateCost()
        {
            return flatFee + Package::calculateCost();
        }
};

class OvernightPackage : Package
{
private:
    float feePerOunce;

public:
    OvernightPackage(string nSender_1, string nReceiver_1, string aSender_1, string aReceiver_1, string cSender_1, string cReceiver_1, float w_1, float cPo_1, float fPo)
        : Package(nSender_1, nReceiver_1, aSender_1, aReceiver_1, cSender_1,  cReceiver_1,  w_1, cPo_1)
    {
        if(fPo > 0)
            feePerOunce = fPo;
        else
            feePerOunce = 0;
    }
   
    float calculateCost()
    {
        return ( feePerOunce + getcPo() ) * getWeight();
    }
};

int main()
{
    TwoDayPackage obj("Usman", "Ali", "Colony", "Block", "Lahore", "Karachi", 7.5, 200, 1000);
    cout << "Cost For Two Day Package : " << obj.calculateCost() << endl;

    OvernightPackage obj1("Usman", "Ali", "Colony", "Block", "Lahore", "Karachi", 8.5, 200, 50);
    cout << "Cost For Overnight Package : " << obj1.calculateCost() << endl;

    return EXIT_SUCCESS;

}