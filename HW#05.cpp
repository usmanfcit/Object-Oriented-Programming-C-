#include <iostream>

using namespace std;

class IntegerSet
{
    int *a;
    const int mSize;

public:
//Constructor
    IntegerSet(int s) : mSize(s)
    {
        a = new int[s];
        for (int i = 0; i < mSize; i++)
        {
            a[i] = 0;
        }
    }
//Getters
    int* getArr()
    {
        return a;
    }

    int getSize()
    {
        return mSize;
    }
//2-"=" Operator Overloading 
    IntegerSet operator=(const IntegerSet& obj)
    {
        if(this != &obj)
        {
            if(this->mSize == obj.mSize)
            {
                for(int i = 0; i < obj.mSize; i++)
                {
                    this->a[i] = obj.a[i];
                }
            }
            else
            {
                cout << "Diffrent Array Sizes, Assignment not Possible" << endl;
            }
        }
        return *this;
    } 
//3-"==" Operator Overloading 
    bool operator==(const IntegerSet& obj)
    {
        if(this->mSize != obj.mSize)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < mSize; i++)
            {
                if(a[i] != obj.a[i])
                {
                    return false;
                }
            }
            return true;
        }
    }
//4-"Logical !" Operator Overloading 
    IntegerSet operator!()
    {
        IntegerSet temp(10);
        for (int i = 0; i < this->mSize; i++)
        {
            temp.a[i] = !a[i];
        }
        return temp;
    }

// Copy Constructor
    IntegerSet(const IntegerSet& obj) : mSize(obj.mSize)
    {
        a = new int[obj.mSize];

        for (int i = 0; i < mSize; i++)
        {
            a[i] = obj.a[i];
        }
    }

// Destructor
    ~IntegerSet()
    {
        delete[] a;
    }

//Member Functions
    void insertElement(int k)
    {
        a[k] = 1;
    }

    void deleteElement(int k)
    {
        a[k] = 0;
    }

    IntegerSet unionOfSets(const IntegerSet& obj)
    {
        
        if(this->mSize != obj.mSize)
        {
            cout << "Union not possible, Array Sizes diffrent" << endl;
            return EXIT_FAILURE;
        }
        else
        {
            IntegerSet temp(mSize);
            for (int i = 0; i < mSize; i++)
            {
                 temp.a[i] = this->a[i] | obj.a[i];
            }
            return temp;
        }
    }

     IntegerSet intersectionOfSets(const IntegerSet& obj)
    {
        if(this->mSize != obj.mSize)
        {
            cout << "Intersection not possible, Array Sizes diffrent" << endl;
            return EXIT_FAILURE;
        }
        else
        {
            IntegerSet temp(mSize);
            for (int i = 0; i < mSize; i++)
            {
                temp.a[i] = this->a[i] & obj.a[i];
            }
            return temp;
        }
    }

    bool isNullSet()
    {
        for (int i = 0; i < mSize; i++)
        {
            if(a[i] != 0)
                return false;
        }
        return true;
    }

    bool findElement(int key)
    {
        if(a[key] == 1)
            return true;
        else
            return false;
    }

friend ostream& operator<<(ostream& out, IntegerSet& obj);

};

ostream& operator<<(ostream& out, IntegerSet& obj)
{
    int *arr = obj.getArr();
    if(obj.isNullSet() == true)
    {
        out << "---" << endl;
    }
    else
    {
        for (int i = 0; i < obj.getSize(); i++)
        {
            if (arr[i] == 1)
            {
                out << i << "\t" ;
            }
        }
    }
    return out;
}

int main()
{

    IntegerSet obj1(10);
    IntegerSet obj2(10);
    IntegerSet obj3(10);
    IntegerSet obj4(10);
    IntegerSet obj5(10);
    
    obj1.insertElement(0);
    obj1.insertElement(1);
    obj1.insertElement(2);
    obj1.insertElement(3); 

    obj2.insertElement(3);
    obj2.insertElement(4);
    obj2.insertElement(5);
    obj2.insertElement(6);
    
    cout << "Obj1 : " << obj1 << endl;
    obj5 = !obj1;
    cout << "!obj1 : " << obj5 << endl;

    cout << "Obj2 : " << obj2 << endl;

    obj3 = obj1.unionOfSets(obj2);

    cout <<"obj1 Union obj2 : " << obj3 << endl;

    obj4 = obj1.intersectionOfSets(obj2);

    cout <<"obj1 Intersection obj2 : " << obj4 << endl;

    if(obj1 == obj2)
        cout << "obj1 and obj2 Are Equal" << endl;
    else
        cout << "obj1 and obj2 Are Not Equal" << endl;

    obj2.deleteElement(3);

    cout << "obj2 After deleting Element: " << obj2;

    return EXIT_SUCCESS;
}