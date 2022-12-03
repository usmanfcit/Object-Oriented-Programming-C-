#include <iostream>
#include <string.h>

using namespace std;

class Item
{	
	private:
	
	int id;
	string name;
	int quantity;
	float cost;	
	
	public :
		
		//Setters
		
		void setID(int id_1)
		{
			if( id_1 > 0)
				id = id_1;
				
			else
				id = 0;
		}
		
		void setQ(int q_1)
		{
			if( q_1 > 0)
				quantity = q_1;
				
			else
				quantity = 0;
		}
		
		void setName(string n_1)
		{
			name = n_1;
		}
		
		void setCost(float c_1)
		{
			if( c_1 > 0)
				cost = c_1;
				
			else
				cost = 0;
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
		
		int getQ()
		{
			return quantity;
		}
		
		float getCost()
		{
			return cost;
		}
		
		//Parameterized Constructors
		
		Item(int i_2, string n_2, int q_2, float c_2)
		{
			id = i_2;
			setID(i_2);
			
			name = n_2;
			
			quantity  = q_2;
			setQ(q_2);
			
			cost = c_2;
			setCost(c_2);
		}
		
		Item(int i_3, string n_3, int q_3)
		{
			id = i_3;
			setID(i_3);
			
			name = n_3;
			
			quantity  = q_3;
			setQ(q_3);
			
			cost = 0;
		}
		
		Item(int i_4, string n_4, float c_4)
		{
			id = i_4;
			setID(i_4);
			
			name = n_4;
			
			quantity  = 0;
			
			cost = c_4;
			setCost(c_4);
		}
		
		// Copy Constrcutor
		
		Item(const Item &obj)
		{
			id = obj.id;
			name = obj.name;
			quantity  = obj.quantity;
			cost = obj.cost;
		}
		
		// Default Constructor
		
		Item()
		{
			id = 0;
			name = "";
			cost = 0;
			quantity = 0;
		}
		
		// Destructor
		
		~Item()
		{
			cout << "Destructor Executed....." << endl;
		}
		
		//Member Functions
		
		void setItem(int i_5, string n_5, int q_5, float c_5)
		{	
		//	id = i_5;
			setID(i_5);
			
			name = n_5;
			
		//	quantity  = q_5;
			setQ(q_5);
			
		//	cost = c_5;
			setCost(c_5);
			
		}
		
		void getItem(int i_6, string n_6, int q_6, float c_6)
		{
			cout << " Enter ID : " << endl;
			cin >> i_6;
			setID(i_6);
			
			cout << " Enter Name : " << endl;
			cin >> n_6;
			setName(n_6);
			
			cout << " Enter Cost : " << endl;
			cin >> c_6;
			setCost(c_6);
			
			cout << " Enter Quantity : " << endl;
			cin >> q_6;
			setQ(q_6);
		}
		
		void putItem()
		{
			cout << "ID : " << id << endl;
			cout << "Name : " << name << endl;
			cout << "Quantity : " << quantity << endl;
			cout << "Cost : " << cost << endl;
			cout << "Total Cost : " << this->getTotalCost() << endl;
		}
		
		float getTotalCost()
		{
			float TotalCost = cost * quantity;
		
			if(quantity >= 1)
				return TotalCost;
				
			else
				return 0;
		}
		
		bool isEqual(const Item &obj0)
		{
			if( (this->id == obj0.id) && (this->name == obj0.name) && (this->quantity == obj0.quantity) && (this->cost == obj0.cost) )
				return true;
				
			else
				false;
		}
		
		Item getMinimumCostItem(Item temp[3], int size)
		{
			float mincost = temp[0].cost;
			int minIndex;
			
			for(int i = 0; i < size; i++)
			{
				for(int j = i+1 ; j < size; j++)
				{
					if(temp[j].cost < temp[i].cost)
						{
						mincost = temp[j].cost;
						minIndex = j;
						}
				}	
			}
			return temp[minIndex];	
		}
		
		void getAveragePrice(Item arx[], int size)
		{
			for(int i=0; i < size; i++)
			{
				this->cost += arx[i].cost; 
			}
			this->cost = this->cost/size;
		}
		
		void updateName(Item ary[], int size)
		{
			for(int i=0; i < size; i++)
			{
				if(ary[i].id == this->id)
				{
					ary[i].name = this->name;
				}
			}
		}
};

int main()
{
	Item obj1(14, "Bike", 10, 50);
	
	Item obj2(60, "Car", 5, 5000);
	
	Item arr[3];
	
	arr[0].setItem(14, "Boat", 2, 30000);
	
	arr[1].setItem(100, "Yacht", 3, 20000);
	
	arr[2].setItem(14, "House", 1, 90000);
	
	obj1.updateName(arr, 3);
	
	arr[0].putItem();
	
	
//	Item obj4;
//	obj4.getAveragePrice(arr, 3);
//	obj4.putItem();
	
//	Item obj3 = obj1.getMinimumCostItem(arr, 3);
//	obj3.putItem();

	return 0;
}
