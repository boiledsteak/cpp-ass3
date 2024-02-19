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
#include <type_traits>


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
            distFrOrigin = calculateDistance();
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

// IO manipulator for formatting PointType coordinates
template<typename PointType>
string formatPoint(const PointType& point) 
{
    ostringstream oss;
    oss << "["
        << setw(4) << right << static_cast<int>(point.getX()) << ", "
        << setw(4) << right << static_cast<int>(point.getY());  

    // // For Point3D, also include the z-coordinate
    // if constexpr (is_same_v<PointType, Point3D>) 
    // {
    //     oss << ", " << setw(4) << right << static_cast<int>(point.getZ());
    // }

    oss << "]";
    return oss.str();
}

namespace MyNamespace {
    // Overloading << for PointType. Delegates formatting to the IO manipulator
    template<typename PointType>
    ostream& operator<<(ostream& os, const PointType& point) 
    {
        os << formatPoint(point);
        return os;
    }
}


int main()
{
    Point2D obj(10,20);

    cout << "\n\nlets see if this works\n\n";

    std::cout << "\nPoint2D object: " << MyNamespace::operator<<(std::cout, obj) << "\n\n";
    
    return 0;
}