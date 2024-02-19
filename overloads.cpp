// IO manipulator for formatting PointType coordinates
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

// Overloading << for PointType. Delegates formatting to the IO manipulator
template<typename PointType>
ostream& operator<<(ostream& os, const PointType& point) 
{
    os << formatPoint(point);
    return os;
}

// Overloading == for PointType. Allows obj == obj for Point2D or Point3D
template<typename PointType>
bool operator==(const PointType& p1, const PointType& p2)
{
    bool answer;
    answer = p1.getX() == p2.getX() && p1.getY() == p2.getY();

    // For Point3D, also include the z-coordinate
    if constexpr (std::is_same_v<PointType, Point3D>) 
    {
        answer = p1.getX() == p2.getX() && p1.getY() == p2.getY() && p1.getZ() == p2.getZ();
    }

    return answer;
}









// IO manipulator for formatting LineType
template<typename LineType>
string formatLine(const LineType& line) 
{
    ostringstream oss;
    oss << "[" << line.getPt1() << "]   [" << line.getPt2() << "]";
    return oss.str();
}

// Overloading << for LineType. Delegates formatting to the IO manipulator
template<typename LineType>
ostream& operator<<(ostream& os, const LineType& line) 
{
    os << formatLine(line);
    return os;
}

// Overloading == for LineType. Allows obj == obj for Line2D or Line3D
template<typename LineType>
bool operator==(const LineType& line1, const LineType& line2)
{
    return line1.getPt1() == line2.getPt1() && line1.getPt2() == line2.getPt2();
}