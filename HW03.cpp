#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
    private:

        int x;
        int y;
        float radius;
        const double PI = 3.14159;

        public:
        
        // Setters

        void setX(int x_1)
        {
            if((x_1 >= -50) && (x_1 <= 50))
            {
                x = x_1;
            }
            else
            {
                x = 0;
            }
        }

        void setY(int y_1)
        {
            if((y_1 >= -50) && (y_1 <= 50))
            {
                y = y_1;
            }
            else
            {
                y = 0;
            }
        }

        void setRadius(float r_1)
        {
            if((r_1 >= 1) && (r_1 <= 10))
            {
                radius = r_1;
            }
            else
            {
                radius = 5;
            }
        }

        // Getters

        int getX() 
        {
            return x;
        }

        int getY() 
        {
            return y;
        }

        float getRadius() 
        {
            return radius;
        }

        double getPI() 
        {
            return PI;
        }

        // Parameterized Constructor

        Circle(int x_2, int y_2, float r_2)
        {
            x = x_2;
            y = y_2;
            radius = r_2;
        }

        Circle(int x_3, int y_3)
        {
            x = x_3;
            y = y_3;
            radius = 5;
        }

        Circle(int x_4, float r_4)
        {
            x = x_4;
            y = 0;
            radius = r_4;
        }

        // Default Constructor

        Circle()
        {
            x = 0;
            y = 0;
            radius = 5;
        }

        // Copy Constructor

        Circle(const Circle &objX)
        {
            x = objX.x;
            y = objX.y;
            radius = objX.radius;
        }

        // Destructor

        ~Circle()
        {
            cout << "Destructor executed…" << endl;
        }

        // Member Functions

        void setCircle(int x_5, int y_5, float r_5)
        {
            setX(x_5);
            setY(y_5);
            setRadius(r_5);
        }

        void getCircle()
        {
            cout << "Enter x-Coordinate : " << endl;
            cin >> x;
            setX(x);

            cout << "Enter y-Coordinate : " << endl;
            cin >> y;
            setY(y);

            cout << "Enter Radius : " << endl;
            cin >> radius;
            setRadius(radius);

        }

        void putCircle() const
        {
            cout << "\\\\ Displaying Information ////" << endl;
            cout << "x-Coordinate : " << x << endl << "y-Coordinate : " << y << endl << "Radius : " << radius << endl;
            cout << "Area : " << getArea() << endl << "Diameter : " << getDiameter() << endl << "Circumference :"  << getCircumference() << endl;
        }

        float getArea() const
        {
            return PI * ( radius * radius );
        }

        float getDiameter() const
        {
            return radius * 2;
        }

        float getCircumference() const
        {
            return 2 * PI * radius;
        }

        Circle addCircle(const Circle &a, const Circle &b)
        {
            Circle temp;
            temp.x = a.x + b.x;
            temp.y = a.y + b.y;
            temp.radius = a.radius + b.radius;

            return temp;
        }

        bool isEqual(const Circle &a, const Circle &b) const
        {
            if((a.x == b.x) && (a.y == b.y) && (a.radius == b.radius))
            return true;

            else
            return false;
        }

        int findCircle(const Circle obj[], int size)
        {
            for (int i = 0; i < size; i++)
            {
              if(this->isEqual(*this, obj[i]))
                return i;
            }

            return -1;
        }

        void updateObjects(Circle temp[], int size)
        {
            for(int i=0; i < size; i++)
            {
                if((temp[i].x == this->x) && (temp[i].y == this->y))
                {
                    temp[i].radius = this->radius;
                }
            }
        }
};

int main()
{
    //Declaring and Initializing Array Of Objects
    Circle arr[3];
    arr[0].setCircle(2, 2, 2.22);
    arr[1].setCircle(10, 10, 4.22);
    arr[2].setCircle(10, 10, 3.22);

    //Declaring and Initializing Object 1 with User Values
    Circle obj1;
    obj1.getCircle();
    obj1.putCircle();

    // Adding two Objects Using addCircle Member Function
    Circle obj2 = obj1.addCircle(arr[0], arr[1]);

    //Finding Circles with same values and Getting its index using findCircle member Function
    obj1.findCircle(arr, 3);

    // Using Update objects members function
    obj1.updateObjects(arr, 3);

    return 0;
}