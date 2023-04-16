#include<iostream>
using namespace std;

class Moving_Van
{
protected:
    float payload, weight, mpg;
public:
    void initialize(float p_1, float w_1, float m_1)
    {
        payload = p_1;
        weight = w_1;
        mpg = m_1;
    }
    float efficiency()
    {
        return payload / (payload + weight);
    }
    float cost_per_ton(float fuel_cost)
    {
        return fuel_cost / (payload / 2000.0);
    }
};

class Driver
{
protected:
    float hourly_pay, weight;
public:
    void initialize(float h_1, float w_1)
    {
        hourly_pay = h_1;
        weight = w_1;
    }
    float cost_per_mile()
    {
        return hourly_pay / 55.0;
    }
    float drivers_weight()
    {
        return weight;
    }
};

class Driven_Truck : public Moving_Van, public Driver
{
public:
    void initialize(float mpg_2, float dWeight, float vWeight, float hPay, float pLoad)
    {
        Moving_Van::mpg = mpg_2;
        Driver::weight = dWeight;
        Moving_Van::weight = vWeight;
        Driver::hourly_pay = hPay;
        Moving_Van::payload = pLoad;
    }
    float cost_per_full_day(float cost_of_gas)
    {
        return (8.0 * hourly_pay + 8.0 * cost_of_gas * 55.0) / mpg;
    }
    float total_weight()
    {
        return Driver::weight + Moving_Van::weight;
    }

};

int main()
{
    Driven_Truck chuck_ford;
    chuck_ford.initialize(100, 70, 300, 1000, 50);
    chuck_ford.Driver::initialize(1000, 70);

    cout << chuck_ford.Moving_Van::efficiency() << endl;
    cout << chuck_ford.Driver::cost_per_mile() << endl;
    cout << chuck_ford.cost_per_full_day(148) << endl;
    cout << chuck_ford.total_weight() << endl;
    return EXIT_SUCCESS;
}