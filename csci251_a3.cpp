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
#include <set>
#include <memory>
#include <variant>


using namespace std;

// ----------------------------------------------------class declarations
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






// OPERATOR OVERLOADS

template<typename PointType>
string formatPoint(const PointType& point) 
{
    ostringstream oss;
    oss << "["
        << setw(4) << right << static_cast<int>(point.getX()) << ", "
        << setw(4) << right << static_cast<int>(point.getY());  

    // For Point3D, also include the z-coordinate
    if constexpr (is_same_v<PointType, Point3D>) 
    {
        oss << ", " << setw(4) << right << static_cast<int>(point.getZ());
    }

    oss << "]";
    return oss.str();
}

ostream& operator<<(ostream& os, const Point2D& point) {
    os << formatPoint(point);
    return os;
}

ostream& operator<<(ostream& os, const Point3D& point) {
    os << formatPoint(point);
    return os;
}



// ----------------------------------------------------other template functions

// Template function to calculate the absolute difference between two scalar values
template<typename T1, typename T2>
double scalar_difference(const T1& value1, const T2& value2) 
{
    return abs(value1 - value2);
}

// Template function to check equality of two parameters
template<typename T>
bool equals(const T& value1, const T& value2) 
{
    return value1 == value2;
}




// ----------------------------------------------------IO manipulators
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






void successprint(string choice)
{
    cout << "\nFilter criteria successfuly set to " << choice << "\n";
}

void option4menu()
{
    cout << "\ta.\tASC (Ascending order)\n";
    cout << "\tb.\tDSC (Descending order)\n";
    cout << "\nPlease enter your criteria (a - b): ";
    
}

void option3menu()
{
    cout << "\ta.\tPt. 1's (x,y) values\n";
    cout << "\tb.\tPt. 2's (x,y) values\n";
    cout << "\tc.\tLength Value\n";
    cout << "\nPlease enter your criteria (a - c): ";
}

void option2menu()
{
    cout << "\ta.\tPoint 2D records\n";
    cout << "\tb.\tPoint 3D records\n";
    cout << "\tc.\tLine 2D records\n";
    cout << "\td. \tLine 3D records\n\n";
    cout << "\nPlease enter your criteria (a - d): ";
}

void menuprinter(string mode2, string mode3, string mode4)
{
    cout << "\n\n\n";
    cout << "Student ID:" << "\t8750634\n";
    cout << "Student name:" << "\tTimothy Mah\n";
    cout << "------------------------------------------------------\n";
    cout << "Welcome to Assignment 3 program!\n\n";
    cout << "1)" << "\tRead in data\n"; 
    cout << "2)" << "\tSpecify filtering criteria (current: "<< mode2 <<")\n";
    cout << "3)" << "\tSpecify sorting criteria (current: "<< mode3 <<")\n"; 
    cout << "4)" << "\tSpecify sorting order (current: "<< mode4 <<") \n";
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
    string mode2 = "Point2D";
    string mode3 = "x-ordinate";
    string mode4 = "ASC";
    vector<string> lines; // Vector to store unique lines from the file
    

    while (progflow == 1)
    {
        menuprinter(mode2, mode3, mode4);
        // input validation
        while (!(cin >> menuchoice) || cin.peek() != '\n') 
        {
            cout << invalidinp;
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            menuprinter(mode2, mode3, mode4);
        }

        switch (menuchoice)
        {
            case 1:
            {
                string filename;            

                cout << ">>>>>>>>>>>>\t" << "Option\t" << menuchoice << "\t>>>>>>>>>>>>\n\n";
                // ----------- reading file into vector
                cout << "Please enter filename: ";                
                // cin >> filename; // No input validation for filename
                filename = "messy.txt";
                ifstream file(filename); // Open file for reading

                                if (file.is_open()) // Check if file is successfully opened
                {

                    set<string> seenLines; // Set to keep track of seen lines
                    string line;

                    // Read each line from the file
                    while (getline(file, line))
                    {
                        // Check if the line is unique
                        if (seenLines.insert(line).second)
                        {
                            // If the line is unique, push it into the vector
                            lines.push_back(line);
                        }
                    }
                    // Close the file after reading
                    file.close();
                    // Display the unique lines read from the file
                    cout << "\n\nUnique lines read from 'messy.txt':\n";
                    for (const auto& l : lines)
                    {
                        cout << l << endl;
                    }
                    // Print the number of rows after duplicates have been removed
                    cout << lines.size() << " records read in successfully\n";
                    
                    vector<Point2D> point2Dobjects;
                    vector<Point3D> point3Dobjects;
                    vector<Line2D> line2Dobjects;
                    vector<Line3D> line3Dobjects;
                    // check what type each line is
                    for (const auto& line : lines) 
                    {
                        istringstream iss(line);
                        string type;
                        iss >> type;

                        if (type == "Point2D,") 
                        {
                            cout << "Yep, this is Point2D\n";
                            int x, y;
                            char c;
                            iss >> c >> x >> c >> y >> c;
                            point2Dobjects.emplace_back(x, y);
                        } 
                        else if (type == "Point3D,") 
                        {
                            cout << "Yep, this is Point3D\n";
                            int x, y, z;
                            char c;
                            iss >> c >> x >> c >> y >> c >> z >> c;
                            point3Dobjects.emplace_back(x, y, z);
                        } 
                        else if (type == "Line2D,") 
                        {
                            cout << "Yep, this is Line2D\n";
                            int x1, y1, x2, y2;
                            char c;
                            iss >> c >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c;
                            Point2D pt1(x1, y1);
                            Point2D pt2(x2, y2);
                            line2Dobjects.emplace_back(pt1, pt2);
                        } 
                        else if (type == "Line3D,") 
                        {
                            cout << "Yep, this is Line3D\n";
                            int x1, y1, z1, x2, y2, z2;
                            char c;
                            iss >> c >> x1 >> c >> y1 >> c >> z1 >> c >> x2 >> c >> y2 >> c >> z2 >> c;
                            Point3D pt1(x1, y1, z1);
                            Point3D pt2(x2, y2, z2);
                            line3Dobjects.emplace_back(pt1, pt2);
                        }
                    }

                    cout << "\n\nContents of point2Dobjects:\n";
                    for (const auto& point : point2Dobjects) 
                    {
                        cout << point << endl;
                    }

                    cout << "\n\nContents of point3Dobjects:\n";
                    for (const auto& point : point3Dobjects) {
                        cout << point << endl;
                    }



                    


                    cout << "Going back to main menu...";
                }      
            }
            break;

            case 2:
            {
                char option;
                cout << "\n[Specifying filtering criteria (current: "<<mode2<<")]\n";
                option2menu();
                while (!(cin >> option) || cin.peek() != '\n' || (option != 'a' && option != 'b' && option != 'c' && option != 'd')) 
                {
                    cout << invalidinp;
                    cin.clear();  // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    option2menu();
                }
                switch (option)
                {
                    case 'a':
                        {
                            mode2 = "Point2D";
                            successprint(mode2);
                        }
                        break;
                    case 'b':
                        {
                            mode2 = "Point3D";
                            successprint(mode2);
                        }
                        break;
                    case 'c':
                        {
                            mode2 = "Line2D";
                            successprint(mode2);
                        }
                        break;
                    case 'd':
                        {
                            mode2 = "Line3D";
                            successprint(mode2);
                        }
                        break;
                    
                    default:
                        cout << "\nWe don't have that option :( Please try again...\n\n";
                        break;
                }

            }
            break;
            case 3:
            {
                char option;
                cout << "\n[Specifying sorting criteria (current: "<<mode3<<")]\n";
                option3menu();
                while (!(cin >> option) || cin.peek() != '\n' || (option != 'a' && option != 'b' && option != 'c')) 
                {
                    cout << invalidinp;
                    cin.clear();  // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    option3menu();
                }
                switch (option)
                {
                    case 'a':
                        {
                            mode3 = "Pt. 1";
                            successprint(mode3);
                        }
                        break;
                    case 'b':
                        {
                            mode3 = "Pt. 2";
                            successprint(mode3);
                        }
                        break;
                    case 'c':
                        {
                            mode3 = "Length";
                            successprint(mode3);
                        }
                        break;
                    
                    default:
                        cout << "\nWe don't have that option :( Please try again...\n\n";
                        break;
                }
            }
            break;
            case 4:
            {
                char option;
                cout << "\n[Specifying sorting order (current: "<<mode4<<")]\n";
                option4menu();
                while (!(cin >> option) || cin.peek() != '\n' || (option != 'a' && option != 'b')) 
                {
                    cout << invalidinp;
                    cin.clear();  // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    option4menu();
                }
                switch (option)
                {
                    case 'a':
                        {
                            mode4 = "ASC";
                            successprint(mode4);
                        }
                        break;
                    case 'b':
                        {
                            mode4 = "DSC";
                            successprint(mode4);
                        }
                        break;
                    
                    default:
                        cout << "\nWe don't have that option :( Please try again...\n\n";
                        break;
                }
            }
            break;
            case 5:
            {
                cout << "\n[View Data...]\n";
                cout << "filteria criteria: " << mode2 << "\n";
                cout << "sorting criteria: " << mode3 << "\n";
                cout << "sorting order: " << mode4 << "\n";
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