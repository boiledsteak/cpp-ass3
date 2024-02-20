#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
double operator-(T &obj1, T &obj2) {
    return obj1.diff(obj2);
}

class Point2D {
private:
    double x, y;
public:
    Point2D(double x, double y) : x(x), y(y) {}
    double diff(Point2D &p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

class Point3D {
private:
    double x, y, z;
public:
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    double diff(Point3D &p) {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) + (z - p.z) * (z - p.z));
    }
};

class Line2D {
private:
    Point2D p1, p2;
public:
    // Constructor accepting Point2D objects
    Line2D(Point2D p1, Point2D p2) : p1(p1), p2(p2) {}

    // Constructor accepting Point3D objects
    Line2D(Point3D p1, Point3D p2) : p1(Point2D(p1.getX(), p1.getY())), p2(Point2D(p2.getX(), p2.getY())) {}
    
    // Rest of the class definition...
};


class Line3D {
private:
    Point3D p1, p2;
public:
    Line3D(Point3D p1, Point3D p2) : p1(p1), p2(p2) {}
    double diff(Line3D &l) {
        return p1 - l.p1;
    }
};

int main() {
    Point2D p1(0, 0);
    Point2D p2(3, 4);
    Point3D p3(0, 0, 0);
    Point3D p4(1, 1, 1);
    Line2D l1(p1, p2);
    Line2D l2(p2, p3);
    Line3D l3(p3, p4);
    Line3D l4(p4, p1);

    std::cout << "Distance between p1 and p2: " << (p1 - p2) << std::endl;
    std::cout << "Distance between p3 and p4: " << (p3 - p4) << std::endl;
    std::cout << "Distance between l1 and l2: " << (l1 - l2) << std::endl;
    std::cout << "Distance between l3 and l4: " << (l3 - l4) << std::endl;

    return 0;
}
