// due 28 Feb
// STL means standard template library
// see slides S5B for template concept
// function template ability : pass the datatype as a parameter and return different data type based on parameter
// It is possible in C++ to get a special behavior for a particular data type. This is called template specialization
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <limits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cerrno> 
#include <cstring>  


using namespace std;

// class declarations
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
            return sqrt((x * x) + (y * y));
        }

    public:
        // Constructor
        Point2D(int x_val, int y_val) : x(x_val), y(y_val) 
        {
            // distFrOrigin = calculateDistance();
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
            // distFrOrigin = calculateDistance();
        }

        // Setter for y
        void setY(int y_val) 
        {
            y = y_val;
            // distFrOrigin = calculateDistance();
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
            int deltaX = pt1.getX() - pt2.getX();
            int deltaY = pt1.getY() - pt2.getY();
            return sqrt(deltaX * deltaX + deltaY * deltaY);
        }

    public:
        // Constructor
        Line2D(Point2D pt1_val, Point2D pt2_val) : pt1(pt1_val), pt2(pt2_val) 
        {
            length = calculateLength();
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
            // length = calculateLength();
        }

        // Setter for pt2
        void setPt2(Point2D pt2_val) 
        {
            pt2 = pt2_val;
            // length = calculateLength();
        }
};

class Point3D : public Point2D 
{
    private:
        int z;
        //inherited member x. shares same value as Point2D. changes in here, will change there
        //inherited member y. shares same value as Point2D. changes in here, will change there
        //inherited member distFrOrigin. shares same value as parent class distFrOrigin. parent class being Point2D. shares same value as Point2D. changes in here, will change there

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
        }

        // Method to calculate distance from origin
        void setDistFrOrigin() 
        {
            double distFrOrigin = sqrt(x * x + y * y + z * z);        
        }
};

class Line3D : public Line2D 
{
    private:
        Point3D pt1;
        Point3D pt2;
        //inherited member of length from Line2D. Shares same value of length as Line2D. shares same value as Line2D. changes in here, will change there

    protected:
        // Method to set the length
        void setLength() 
        {
            double length = calculateLength();
        }

        // Calculate length of the line
        double calculateLength() const 
        {
            return sqrt(
                ((pt1.getX()-pt2.getX())*(pt1.getX()-pt2.getX())) +
                ((pt1.getY()-pt2.getY())*(pt1.getY()-pt2.getY())) +
                ((pt1.getZ()-pt2.getZ())*(pt1.getZ()-pt2.getZ()))
                );
        }

    public:
        // Constructor. Line3D inherits all the members of Line2D
        Line3D(Point3D pt1_val, Point3D pt2_val) : Line2D(Point2D(0,0), Point2D(0,0)), pt1(pt1_val), pt2(pt2_val) {}

        // Getter for pt1
        Point3D getPt1() const 
        {
            return pt1;
        }

        // Getter for pt2
        Point3D getPt2() const 
        {
            return pt2;
        }

        // Setter for pt1
        void setPt1(Point3D pt1_val) 
        {
            pt1 = pt1_val;
        }

        // Setter for pt2
        void setPt2(Point3D pt2_val) 
        {
            pt2 = pt2_val;
        }
};


// points namespace is to use << for Point3D or Point2D
namespace points
{
    // Overloading << for PointType. Formats the coordinates nicely
    template<typename PointType>
    ostream& operator<<(ostream& os, const PointType& point) 
    {
        os << "["
        << setw(4) << right << static_cast<int>(point.getX()) << ", "
        << setw(4) << right << static_cast<int>(point.getY());  // <--- Add semicolon here

        // For Point3D, also include the z-coordinate
        if constexpr (is_same_v<PointType, Point3D>) 
        {
            os << ", " << setw(4) << right << static_cast<int>(point.getZ());
        }

        os << "]";
        return os;
    }
}

// lines namespace is to use << for Line3D and Line2D
namespace lines 
{
    // Define operator<< for Line3D and Line2D
    template<typename LineType>
    ostream& operator<<(ostream& os, const LineType& line) 
    {
        os << "[" << line.getPt1() << "]   [" << line.getPt2() << "]";
        return os;
    }
}










// I/O manipulators
// formats to 2 Decimal places
ostream& twodec(ostream& os) 
{
    os << fixed << setprecision(2);
    return os;
}

// formats to 3 Decimal places
ostream& threedec(ostream& os) 
{
    os << fixed << setprecision(3);
    return os;
}





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
                string filename;
                string line;
                

                cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                cout << "Please enter filename: ";                
                // cin >> filename; // No input validation for filename
                filename = "messy.txt";
                fstream file(filename, ios::in);
                if (file.is_open()) 
                {
                    while (getline(file >> ws, line)) 
                    {
                        istringstream iss(line);
                        int num;
                        while (iss >> num) 
                        {
                            cout << "Read number: " << num << endl;
                        }
                    }

                    file.close();
                }
                else 
                {
                    cout << filename << "\n";
                    cerr << "Failed to open the file." << endl;
                    cerr << "Error code: " << errno << ", " << strerror(errno) << endl;
                }
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