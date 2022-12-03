#include <iostream>

using namespace std;

class Collection
{
	int* data;
	int size;
	
public:
	
	Collection(int s)
	{
		this->size = s;
		data = new int[size];
		
		for(int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}
	
	Collection(int arr[], int s2)
	{
		this->size = s2;
		
		data = new int[size];
		
		for(int i = 0; i < size; i++)
		{
			data[i] = arr[i];
		}
	}
	
	Collection(const Collection& obj)
	{
		this->size = obj.size;
		
		data = new int[size];
		
		for(int i = 0; i < size; i++)
		{
			data[i] = obj.data[i];
		}
	}
	
	~Collection()
	{
		delete[] data;
	}
	
	int getSize()
	{
		return sizeof(int) * size + sizeof(size) ;
	}
	
	void setElement(int k, int i)
	{
		if(i >= 0 && i < size)
		{
			data[i] = k;
		}
		
		cout << "Invalid Index" << endl;
	}
	
	int countElement(int key)
	{
		int count = 0;
		
		for(int i = 0; i < size; i++)
		{
			if(data[i] == key)
			{
				count++;
			}
		}
		
		if(count == 0)
		{
			cout << "key Does Not Exist" << endl;
			return -1;
		}
		
		return count;
	}
	
	Collection operator=(const Collection& obj)
	{
		if(this != &obj)
		{
			if(size != obj.size)
			{
				size = obj.size;
				
				delete[] data;
				
				data = new int[size];
			}
		}
		
		for(int i = 0; i < size; i++)
		{
			data[i] = obj.data[i];
		}
		
		return *this;
	}
	
	Collection getSubCollection(int start_index, int end_index)
	{
		Collection temp(5);
		
		delete[] temp.data;
		
		temp.size = size;
		
		temp.data = new int[temp.size];
		
		int count = 0;
		
		if(start_index >=0 && end_index < size)
		{
			for(int i = start_index; i <= end_index; i++)
			{
				temp.data[i] = data[i];
				count++;
			}
		}
		else
		{
			cout << "Index Invalid" << endl;
		}
		
		temp.size = count;
		return temp;
	}
	
	Collection operator+(const Collection& obj)
	{
		Collection temp(this->size);
		
		if(size != obj.size)
		{
			cout << "Size diffrent ... + not Possible";
			exit(0);
		}
		
		else
		{
			for(int i =0; i < size; i++)
			{
				temp.data[i] = this->data[i] + obj.data[i];
			}
			
			return temp;
		}	
	}
	
	bool operator==(const Collection& obj)
	{
		if(size != obj.size)
		{
			return false;
		}
		
		else
		{
			for(int i = 0; i < size; i++)
			{
				if(this->data[i] == obj.data[i])
				{
					continue;
				}
				
				else
				{
					return false;
				}
			}
		}
	}
	
	bool operator-()
	{
		for(int i =0; i < size; i++)
		{
			if(this->data[i] != 0)
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	
	int& operator[](int index)
	{
		if(index >= 0 && index < size)
		{
			return this->data[index];
		}
		
		cout << "Index Invalid " << endl;
		exit(0);
	}
	
	int operator[](int index) const
	{
		if(index >= 0 && index < size)
		{
			return this->data[index];
		}
		
		cout << "Index Invalid " << endl;
		exit(0);
	}
	
	friend ostream& operator<< (ostream& out, const Collection& obj);
	friend istream& operator>> (istream& in, Collection& obj);
	
};

ostream& operator<< (ostream& out, const Collection& obj)
{
	for(int i = 0; i < obj.size; i++)
	{
		out << obj.data[i] << "\t";
	}
	out << endl;
	return out;
}

istream& operator>> (istream& in, Collection& obj)
{

	for(int i = 0; i < obj.size; i++)
	{
		cout << "Enter Data for Index " << i << " : "; 
		in >> obj.data[i];
	}
	
	return in;
}

int main()
{
	
	int ar[] = {6, 5, 4, 4, 2, 1};
	
	Collection obj1(10); 
	
	Collection obj2(ar, 6);
	
	Collection obj3 = obj2;
	
	Collection obj4(5);
	
	Collection obj5(3);
	
	cin >> obj5;
	
	obj4 = obj2.getSubCollection(0, 3);

	cout << obj1 << endl;
	cout << obj2 << endl;
	cout << obj3 << endl;
	cout << obj4 << endl;
	cout << obj5 << endl;
	cout << "obj2 + obj2 : "<< obj2 + obj2 << endl; 
	
	if(obj2 == obj3)
		cout << "obj2 = obj3" << endl;
		
	else
		cout << "obj1 != obj3 Not equal" << endl; 
		
	/*	if(-obj1)
		cout << "obj2 = obj3" << endl;
		
	else
		cout << "Not equal" << endl; */
	
//	cout << obj2.countElement(1) << endl;
	
	return 0;
}
