#ifndef MYCLASSES_H
#define MYCLASSES_H

#include <cmath>

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

class Line2D 
{
private:
    Point2D pt1; 
    Point2D pt2;
protected:
    double length; 

    // Calculate length of the line
    void setLength() 
    {
        int deltaX = pt1.getX() - pt2.getX();
        int deltaY = pt1.getY() - pt2.getY();
        length = sqrt(deltaX * deltaX + deltaY * deltaY);
    }

public:
    // Constructor
    Line2D(Point2D pt1_val, Point2D pt2_val) : pt1(pt1_val), pt2(pt2_val) 
    {
        setLength(); // Calculate length for Line2D
    }

    // Getter for length
    double getScalarValue() const 
    {
        return length;
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

    // Setter for pt1
    void setPt1(Point2D pt1_val) 
    {
        pt1 = pt1_val;
    }

    // Setter for pt2
    void setPt2(Point2D pt2_val) 
    {
        pt2 = pt2_val;
    }
};

class Line3D : public Line2D 
{
private:
    Point3D pt1; 
    Point3D pt2;

protected:
    // Calculate length of the line for Line3D
    void setLength() 
    {
        length = sqrt(
            ((pt1.getX() - pt2.getX()) * (pt1.getX() - pt2.getX())) +
            ((pt1.getY() - pt2.getY()) * (pt1.getY() - pt2.getY())) +
            ((pt1.getZ() - pt2.getZ()) * (pt1.getZ() - pt2.getZ()))
        );
    }

public:
    // Constructor
    Line3D(Point3D pt1_val, Point3D pt2_val) : Line2D(pt1_val, pt2_val), pt1(pt1_val), pt2(pt2_val) 
    {
        setLength();
    }

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

    // inherited function from line2d -> getscalarvalue
};

#endif // MYCLASSES_H
