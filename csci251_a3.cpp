// due 28 Feb
// STL means standard library
// see slides S5B for template concept
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <limits>


using namespace std;

class Point2D 
{
    protected:
        int x;
        int y;
        double distFrOrigin;

    protected:
        // Setter for distFrOrigin
        void setDistFrOrigin() 
        {
            distFrOrigin = calculateDistance();
        }
        // Calculate distance from origin
        double calculateDistance() const 
        {
            // return sqrt(x * x + y * y);
            return 2.2; //placeholder value
        }

    public:
        // Constructor
        Point2D(int x_val, int y_val) : x(x_val), y(y_val) 
        {
            setDistFrOrigin();
        }

        // Getter for x
        int getX() const 
        {
            return x;
        }

        // Getter for y
        int getY() const 
        {
            return y;
        }

        // Getter for distFrOrigin
        double getScalarValue() const 
        {
            return distFrOrigin;
        }

        // Setter for x
        void setX(int x_val) 
        {
            x = x_val;
            // setDistFrOrigin();
        }

        // Setter for y
        void setY(int y_val) 
        {
            y = y_val;
            // setDistFrOrigin();
        }
};

class Line2D 
{
    private:
        Point2D pt1;
        Point2D pt2;

    protected:
        double length;

    protected:
        void setLength() 
        {
            length = calculateLength();
        }

        // Calculate length of the line
        double calculateLength() const 
        {
            // int deltaX = pt1.getX() - pt2.getX();
            // int deltaY = pt1.getY() - pt2.getY();
            // return sqrt(deltaX * deltaX + deltaY * deltaY);
            return 2.2; // placeholder value
        }

    public:
        // Constructor
        Line2D(Point2D pt1_val, Point2D pt2_val) : pt1(pt1_val), pt2(pt2_val) 
        {
            setLength();
        }

        // Getter for pt1
        Point2D getPt1() const 
        {
            return pt1;
        }

        // Getter for pt2
        Point2D getPt2() const 
        {
            return pt2;
        }

        // Getter for length
        double getScalarValue() const 
        {
            return length;
        }

        // Setter for pt1
        void setPt1(Point2D pt1_val) 
        {
            pt1 = pt1_val;
            // setLength();
        }

        // Setter for pt2
        void setPt2(Point2D pt2_val) 
        {
            pt2 = pt2_val;
            // setLength();
        }
};

class Point3D : public Point2D 
{
    private:
        int z;

    public:
        // Constructor
        Point3D(int x_val, int y_val, int z_val) : Point2D(x_val, y_val), z(z_val) {}

        // Getter for z
        int getZ() const 
        {
            return z;
        }

        // Setter for z
        void setZ(int z_val) 
        {
            z = z_val;
            // setDistFrOrigin(); // Call the inherited setDistFrOrigin method to update distFrOrigin
        }
};

class Line3D : public Line2D 
{
    public:
        // Constructor
        Line3D(Point3D pt1_val, Point3D pt2_val) : Line2D(pt1_val, pt2_val) {}
};
void menuprinter()
{
    cout << "\n\n\n";
    cout << "Student ID:" << "\t8750634\n";
    cout << "Student name:" << "\tTimothy Mah\n";
    cout << "------------------------------------------------------\n";
    cout << "Welcome to Assignment 3 program!\n\n";
    cout << "1)" << "\tRead in data\n"; 
    cout << "2)" << "\tSpecify filtering criteria (current: Point2D)\n";
    cout << "3)" << "\tSpecify sorting criteria (current: x-ordinate)\n"; 
    cout << "4)" << "\tSpecify sorting order (current: ASC) \n";
    cout << "5)" << "\tView data \n";
    cout << "6)" << "\tStore data \n";
    cout << "7)" << "\tExit \n";
    cout << "\n\nTell me what you want!\n\n";
}

int main()
{
    int progflow = 1;
    int menuchoice = 0;
    string invalidinp = "\nSorry I do not understand :( Please try again!\n\n";

    while (progflow == 1)
    {
        menuprinter();
        // input validation
        while (!(cin >> menuchoice) || cin.peek() != '\n') 
        {
            cout << invalidinp;
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            menuprinter();
        }

        switch (menuchoice)
        {
            case 1:
            {
                cout << ">>>>>>>>>>>>\t"<< "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                cout << "Please enter filename";
                

            }
            break;
            case 2:
            {
                cout << "hullo !";
            }
            break;
            case 3:
            {
                cout << "hullo !";
            }
            break;
            case 4:
            {
                cout << "hullo !";
            }
            break;
            case 5:
            {
                cout << "hullo !";
            }
            break;
            case 6:
            {
                cout << "hullo !";
            }
            break;
            case 7:
            {
                progflow = 0;
            }
            break;
            default:
            {
                cout << "\nWe don't have that option :( Please try again...\n\n";
            break;   
            }
        }
    }

    return 0;
}