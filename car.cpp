#include <iostream>
#include <string.h>

using namespace std;

class car
{
	private:
		int yearModel;
		string make;
		int speed;
	public:
		car(int yearModel2, string make2)
		{
			yearModel = yearModel2;
			make = make2;
			speed = 0;	
		}	
		//Copy Constructor
		car(const car &obj)
		{
			yearModel = obj.yearModel;
			make = obj.make;
			speed = obj.speed;
		}	
		// Destructor
		~car()
		{
			cout << "Destructor Executed....." << endl;
		}
		
		// Setters
		
		void setyearModel(int yearModel3)
		{
			yearModel = yearModel3;
		}
		
		void setMake(int make3)
		{
			make = make3;
		}
		
		void setSpeed(int speed3)
		{
			speed = speed3;
		}
		
		// Getters
		
		int getYearModel()
		{
			return yearModel;
		}
		
		string getMake()
		{
			return make;
		}
		
		int getSpeed()
		{
			return speed;
		}
		
		// Member Functions
		
		void setCar(int yearModel4, string make4, int speed4)
		{
			yearModel = yearModel4;
			make = make4;
			speed  = speed4;
		}
		
		int accelerate()
		{
			return speed + 5;
		}
		
		int brake()
		{
			return speed - 5;
		}
		
		void putCar()
		{
			cout<< yearModel<< "\t" << make << "\t" << speed << endl;
		}
		
};
	
int main()
{
	car o1(2021, "Suzuki Alto");
	car o2 = o1;
	car o3 = o1;
	car o4 = o1;
	car o5 = o1;
	
	o1.setCar(2021, "Suzuki Alto", 40);
	o2.setCar(2015, "Toyota Camry", 45);
	o3.setCar(2011, "Honda Accord", 80);
	o4.setCar(2012, "Toyota Prius", 60);
	o5.setCar(2018, "Daihatsu Boon", 55);
	 
	o1.putCar();
	o2.putCar();
	o3.putCar();
	o4.putCar();
	o5.putCar();	
	
	return 0;
}
