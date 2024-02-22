#ifndef MY_OP_OVERLOADS_H
#define MY_OP_OVERLOADS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <type_traits>
#include "MyClasses.h"

using namespace std;

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
double diff(const PointType p1, const PointType p2) 
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

bool operator==(Point2D p1, Point2D p2)
{
    return comparePoints(p1, p2);
}

bool operator==(Point3D p1, Point3D p2)
{
    return comparePoints(p1, p2);
}

double operator-(Point2D p1, Point2D p2)
{
    return diff(p1, p2);
}

double operator-(Point3D p1, Point3D p2)
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


bool operator==(Line2D l1, Line2D l2)
{
    return (l1.getPt1() == l2.getPt1()) && (l1.getPt2() == l2.getPt2());
}

bool operator==(Line3D l1, Line3D l2)
{
    return (l1.getPt1() == l2.getPt1()) && (l1.getPt2() == l2.getPt2());
}

double operator-(Line2D l1, Line2D l2)
{
    return diff(l1,l2);
}

double operator-(Line3D l1, Line3D l2)
{
    return diff(l1,l2);
}

#endif
