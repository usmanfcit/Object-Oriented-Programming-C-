#include <iostream>
#include <cmath>

using namespace std;

class Cuboids
{
    private:
        float height;
        float width;
        float depth;

    public :
        // Setters
        void setHeight(float height1)
        {
            if((height1 > 0) && (height1 < 35))
                height = height1;
            else 
                height = 1;
        }

        void setwidth(float width1)
        {
            if((width1 > 0) && (width1 < 35))
                width = width1;
            else
                width = 1;
        }

        void setDepth(float depth1)
        {
            if((depth1 > 0) && (depth1 < 35))
                depth = depth1;
            else
                depth1 = 1;
        }

        // Getters

        float getHeight()
        {
            return height;
        }

        float getWidth()
        {
            return width;
        }

        float getDepth()
        {
            return depth;
        }

        // Parameterized Constructor
        Cuboids(float height2, float width2, float depth2)
        {
            if((height2 > 0) && (height2 < 35))
                height = height2;
            else
                height = 1;

            if((width2 > 0) && (width2 < 35))
                width = width2;
            else
                width = 1;

            if((depth2 > 0) && (depth2 < 35))
                depth = depth2;
            else
                depth = 1;
        }

        Cuboids(float height3, float width3)
        {
            height = height3;
            width = width3;
            depth = 1;
        }

        // Default Constrcutor
        Cuboids()
        {
            height = 1;
            width = 1;
            depth = 1;
        }

        // Copy Constructor
        Cuboids(const Cuboids &obj)
        {
            height = obj.height;
            width = obj.width;
            depth = obj.depth;
        }

        // Destructor
        ~Cuboids()
        {
            cout << "Destructor Executed....." << endl;
        }

        void setCuboids(float height4, float width4, float depth4)
        {
            if((height4 > 0) && (height4 < 35))
                height = height4;
            else
                height = 1;

            if((width4 > 0) && (width4 < 35))
                width = width4;
            else
                width = 1;

            if((depth4 > 0) && (depth4 < 35))
                depth = depth4;
            else
                depth = 1;
        }

        void getCuboids()
        {
            cout << "Enter Height : " << endl;
            cin >> height;

            if((height > 0) && (height < 35))
                height = height;
            else
                height = 1;

            cout << "Enter Width : " << endl;
            cin >> width;

            if((width > 0) && (width < 35))
                width = width;
            else
                width = 1;

            cout << "Enter Depth : " << endl;
            cin >> depth;

            if((depth > 0) && (depth < 35))
                depth = depth;
            else
                depth = 1;
        }

        void putCuboids()
        {
            cout << endl << "Height = " << height << endl;

            cout << "Width = " << width << endl;

            cout << "Depth = " << depth << endl;
        }

        float getSurfaceArea()
        {
            return 2 * (height * width) + 2 * (height * depth) + 2 * (width * depth);
        }

        float getVolume()
        {
            return height * width * depth;
        }

        float getSpaceDiagonal()
        {
            return sqrt((height * height) + (width * width) + (depth * depth));
        }

        void putCuboidsInfo()
        {
            putCuboids();

            cout << "Surface Area = " << getSurfaceArea() << endl << "Volume = " << getVolume() << endl << "Space Diagnol = " << getSpaceDiagonal() << endl;
        }

    };

int main()
{
    // Using Parameterized Constructor for Obj1 and Obj4
    Cuboids obj1(10, 10, 10);
    Cuboids obj4(15, 15);

    //Using Copy Constructor for Obj2
    Cuboids obj2 = obj1;

    // Using Setters to set data For obj2
    obj2.setDepth(20);
    obj2.setwidth(32);
    obj2.setHeight(2);

    // Taking Data from User for obj3 using getCuboids member Function
    Cuboids obj3;
    obj3.getCuboids();

    // Taking Data for obj5 using setCuboids member Function
    Cuboids obj5;
    obj5.setCuboids(14, 15.5, 32.9);

    // Displaying a CuboidsInfo
    obj3.putCuboidsInfo();
   
    return 0;

}