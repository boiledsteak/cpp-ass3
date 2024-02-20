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
#include <map>
#include <any>


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
        }

        // Setter for y
        void setY(int y_val) 
        {
            y = y_val;
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
        Point3D(int x_val, int y_val, int z_val) : Point2D(x_val, y_val), z(z_val) 
        {
            setDistFrOrigin();
        }

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

// Class Line2D
class Line2D {
private:
    Point2D pt1;
    Point2D pt2;
    double length;

    // Calculate length of the line
    double calculateLength() const {
        int deltaX = pt1.getX() - pt2.getX();
        int deltaY = pt1.getY() - pt2.getY();
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }

public:
    // Constructor
    Line2D(Point2D pt1_val, Point2D pt2_val) : pt1(pt1_val), pt2(pt2_val) {
        length = calculateLength();
    }

    // Getter for pt1
    Point2D getPt1() const {
        return pt1;
    }

    // Getter for pt2
    Point2D getPt2() const {
        return pt2;
    }

    // Getter for length
    double getScalarValue() const {
        return length;
    }
};

// Class Line3D
class Line3D {
private:
    Point3D pt1;
    Point3D pt2;

    // Calculate length of the line
    double calculateLength() const {
        return sqrt(
            ((pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX())) +
            ((pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY())) +
            ((pt1.getZ() - pt2.getZ()) * (pt1.getZ() - pt2.getZ()))
        );
    }

public:
    // Constructor
    Line3D(Point3D pt1_val, Point3D pt2_val) : pt1(pt1_val), pt2(pt2_val) {}

    // Getter for pt1
    Point3D getPt1() const {
        return pt1;
    }

    // Getter for pt2
    Point3D getPt2() const {
        return pt2;
    }

    // Getter for length
    double getScalarValue() const {
        return calculateLength();
    }
};




// ----------------------------------------------------OPERATOR OVERLOADS

// ------------FOR POINTS



template<typename PointType>
string formatPoint(const PointType& point) 
{
    ostringstream oss;
    oss << "["
        << setw(4) << right  << static_cast<int>(point.getX()) << ", "
        << setw(4) << right  << static_cast<int>(point.getY());  

    // For Point3D, also include the z-coordinate
    if constexpr (is_same_v<PointType, Point3D>) 
    {
        oss << ", " << setw(4) << static_cast<int>(point.getZ());
    }

    oss << "]";
    return oss.str();
}

template<typename PointType>
bool comparePoints(const PointType& p1, const PointType& p2) 
{
    bool answer;
    answer = p1.getX() == p2.getX() && p1.getY() == p2.getY();

    // For Point3D, also include the z-coordinate
    if constexpr (is_same_v<PointType, Point3D>) 
    {
        answer = p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ();
    }

    return answer;
}

template<typename PointType>
double diff(const PointType& p1, const PointType& p2) 
{
    return p1.getScalarValue() - p2.getScalarValue();
}

ostream& operator<<(ostream& os, const Point2D& point) 
{
    os << formatPoint(point);
    return os;
}

ostream& operator<<(ostream& os, const Point3D& point) 
{
    os << formatPoint(point);
    return os;
}

bool operator==(Point2D &p1, Point2D &p2)
{

    return comparePoints(p1, p2);
}

bool operator==(Point3D &p1, Point3D &p2)
{
    return comparePoints(p1, p2);
}

bool operator-(Point2D &p1, Point2D &p2)
{

    return diff(p1, p2);
}

bool operator-(Point3D &p1, Point3D &p2)
{
    return diff(p1, p2);
}



// ------------FOR LINES

template<typename LineType>
string formatLine(const LineType& line) 
{
    ostringstream oss;
    oss <<  line.getPt1() << "   " << line.getPt2();
    return oss.str();
}

ostream& operator<<(ostream& os, const Line2D& line) 
{
    os << formatLine(line);
    return os;
}

ostream& operator<<(ostream& os, const Line3D& line) 
{
    os << formatLine(line);
    return os;
}


bool operator==(Line2D &l1, Line2D &l2)
{
    return l1 == l2;
}

bool operator==(Line3D &l1, Line3D &l2)
{
    return l1 == l2;
}

double operator-(Line2D &l1, Line2D &l2)
{
    return diff(l1,l2);
}

double operator-(Line3D &l1, Line3D &l2)
{
    return diff(l1,l2);
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





// Function to print objects based on mode2
void printObjects(const string& mode2, const vector<Point2D>& point2Dobjects,const vector<Point3D>& point3Dobjects, const vector<Line2D>& line2Dobjects, const vector<Line3D>& line3Dobjects) 
{
    if (mode2 == "Point2D") 
    {
        cout 
        << " " << setw(4) << right << "X" 
        << "  " << setw(4) << right << "Y"
        << "   "
        << " Length"
        << "\n";
        for (int i = 0; i < 27; ++i) 
        {
            cout << "- ";
        }
        cout << "\n";
        for (const auto& point : point2Dobjects) 
        {
            cout << point << "   "  << fixed << setprecision(3) << point.getScalarValue() << "\n";
        }
    } 
    else if (mode2 == "Point3D") 
    {
        cout 
        << " " << setw(4) << right << "X" 
        << "  " << setw(4) << right << "Y"
        << "  " << setw(4) << right << "Z"
        << "   "
        << " Length"
        << "\n";
        for (int i = 0; i < 27; ++i) 
        {
            cout << "- ";
        }
        cout << "\n";
        for (const auto& point : point3Dobjects) 
        {
            cout << point << "   "  << fixed << setprecision(3) << point.getScalarValue() << "\n";
        }
    } 
    else if (mode2 == "Line2D") 
    {
        cout 
        << " " << setw(4) << right << "P1-X" 
        << "  " << setw(4) << right << "P1-Y"
        << "   "
        << "  " << setw(4) << right << "P2-X" 
        << "  " << setw(4) << right << "P2-Y"
        << "   "
        << " Length"
        << "\n";
        for (int i = 0; i < 27; ++i) 
        {
            cout << "- ";
        }
        cout << "\n";
        for (const auto& line : line2Dobjects) 
        {
            cout << line << "   "  << fixed << setprecision(3) << line.getScalarValue() << "\n";
        }
    } 
    else if (mode2 == "Line3D") 
    {
        cout 
        << " " << setw(4) << right << "P1-X" 
        << "  " << setw(4) << right << "P1-Y"
        << "  " << setw(4) << right << "P1-Z"
        << "   "
        << "  " << setw(4) << right << "P2-X" 
        << "  " << setw(4) << right << "P2-Y"
        << "  " << setw(4) << right << "P2-Z"
        << "   "
        << " Length"

        << "\n";
        for (int i = 0; i < 27; ++i) 
        {
            cout << "- ";
        }
        cout << "\n";
        for (const auto& line : line3Dobjects) 
        {
            cout << line << "   "  << fixed << setprecision(3) << line.getScalarValue() << "\n";
        }
    } else {
        cout << "Invalid mode specified.\n";
    }
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
    vector<Point2D> point2Dobjects;
    vector<Point2D> temppoint2Dobjects;
    vector<Point3D> point3Dobjects;
    vector<Point3D> temppoint3Dobjects;
    vector<Line2D> line2Dobjects;
    vector<Line3D> line3Dobjects;

    // Define a map to associate mode2 values with my vectors of objects
    map<string, pair<string, any>> modeToContainer = 
    {
        {"Point2D", {"Point2D", &point2Dobjects}},
        {"Point3D", {"Point3D", &point3Dobjects}},
        {"Line2D", {"Line2D", &line2Dobjects}},
        {"Line3D", {"Line3D", &line3Dobjects}}
    };
    

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
                    
                    
                    // check what type each line is
                    for (const auto& line : lines) 
                    {
                        istringstream iss(line);
                        string type;
                        iss >> type;

                        if (type == "Point2D,") 
                        {
                            int x, y;
                            char ch;
                            char comma;
                            // Ignore characters until '[' is found
                            while (iss >> ch && ch != '[');
                            // Extract numbers until ']' is found
                            while (iss >> x >> comma >> y >> ch && ch == ']') 
                            {
                                Point2D obj(x, y);
                                point2Dobjects.emplace_back(obj);
                                // Ignore characters until '[' is found for the next pair
                                while (iss >> ch && ch != '[');
                            }
                        } 
                        else if (type == "Point3D,") 
                        {
                            int x, y, z;
                            char ch;
                            char comma;
                            // Ignore characters until '[' is found
                            while (iss >> ch && ch != '[');
                            // Extract numbers until ']' is found
                            while (iss >> x >> comma >> y >> comma >> z >> ch && ch == ']') 
                            {
                                Point3D obj(x, y, z);
                                point3Dobjects.emplace_back(obj);
                                // Ignore characters until '[' is found for the next pair
                                while (iss >> ch && ch != '[');
                            }
                        } 
                        else if (type == "Line2D,") 
                        {
                            temppoint2Dobjects.clear(); // Clear the temporary vector
                            int x, y;
                            char ch;
                            char comma;
                            // Ignore characters until '[' is found
                            while (iss >> ch && ch != '[');
                            // Extract numbers until ']' is found
                            while (iss >> x >> comma >> y >> ch && ch == ']')
                            {
                                Point2D obj(x, y);
                                temppoint2Dobjects.emplace_back(obj);
                                // Ignore characters until '[' is found for the next pair
                                while (iss >> ch && ch != '[');
                            }                                                        
                            Line2D lobj(temppoint2Dobjects[0],temppoint2Dobjects[1]);
                            line2Dobjects.emplace_back(lobj);
                        } 
                        else if (type == "Line3D,") 
                        {
                            temppoint3Dobjects.clear(); // Clear the temporary vector
                            int x, y, z;
                            char ch;
                            char comma;
                            // Ignore characters until '[' is found
                            while (iss >> ch && ch != '[');
                            // Extract numbers until ']' is found
                            while (iss >> x >> comma >> y >> comma >> z >> ch && ch == ']') 
                            {
                                Point3D obj(x, y, z);
                                temppoint3Dobjects.emplace_back(obj);
                                // Ignore characters until '[' is found for the next pair
                                while (iss >> ch && ch != '[');
                            }
                            Line3D lobj(temppoint3Dobjects[0],temppoint3Dobjects[1]);
                            line3Dobjects.emplace_back(lobj);
                        }
                    }

                    cout << "\n\nContents of point2Dobjects:\n";
                    for (const auto& point : point2Dobjects) 
                    {
                        cout << point << "   "  << fixed << setprecision(3) << point.getScalarValue() << "\n";
                    }

                    cout << "\n\nContents of point3Dobjects:\n";
                    for (const auto& point : point3Dobjects) {
                        cout << point << "   "  << fixed << setprecision(3) << point.getScalarValue() << "\n";
                    }

                    cout << "\n\n\nContents of LINE 2D :\n";
                    for (const auto& thing : line2Dobjects) {
                        cout << thing << "   "  << fixed << setprecision(3) << thing.getScalarValue() << "\n";
                    }

                    cout << "\n\nContents of LINE 3Dobjects:\n";
                    for (auto& line : line3Dobjects) 
                    {
                        cout << line << "   "  << fixed << setprecision(3) << line.getScalarValue() << "\n";
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
                cout << "\n\n[View Data...]\n\n";
                cout << "filtering criteria: " << mode2 << "\n";
                cout << "sorting criteria: " << mode3 << "\n";
                cout << "sorting order: " << mode4 << "\n\n";
                printObjects(mode2, point2Dobjects, point3Dobjects, line2Dobjects, line3Dobjects);
                cout << "\n";
            }
            break;

            break;
            case 6: 
            {
                cout << "Saving data to a text file...\n";
                string filename = mode2 + ".txt"; // Construct the file name based on mode2 value
                ofstream outputFile(filename); // Open the file for writing
                if (!outputFile.is_open()) {
                    cout << "Error: Unable to open file for writing.\n";
                    break;
                }

                // Redirect standard output to the file
                streambuf* original_cout = cout.rdbuf(); // Save original cout buffer
                cout.rdbuf(outputFile.rdbuf()); // Redirect cout to file

                // Call the printing function to print objects to the file
                printObjects(mode2, point2Dobjects, point3Dobjects, line2Dobjects, line3Dobjects);

                // Restore standard output
                cout.rdbuf(original_cout); // Restore original cout buffer
                outputFile.close(); // Close the file

                cout << "Data saved to file: " << filename << "\n";
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