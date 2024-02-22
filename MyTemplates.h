#ifndef MY_TEMPLATES_H
#define MY_TEMPLATES_H

#include <cmath> // Include <cmath> for the abs function
#include <vector>
#include "MyOpOverloads.h"

using namespace std;

// Template function to calculate the absolute difference between two scalar values
template<typename T1, typename T2>
double scalar_difference(const T1& value1, const T2& value2) 
{
    return abs(value1 - value2); // Use abs from std namespace
}

// Template function to check equality of two parameters
template<typename T>
bool equals(const T& value1, const T& value2) 
{
    return value1 == value2;
}

// Template function to sort objects based on mode3 and mode4
template<typename ObjectType>
void sortObjects(vector<ObjectType>& objects, const string& mode3, const string& mode4) 
{
    
    if (mode3 == "x-ordinate")
    {
        if constexpr (is_same<ObjectType, Point2D>::value || is_same<ObjectType, Point3D>::value)
        {
            if (mode4 == "ASC") 
            {
                // Sort based on X in ascending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {               
                    if (obj1.getX() == obj2.getX()) 
                    {
                        // If X values are equal, compare by Y values
                        return obj1.getY() < obj2.getY();
                    }
                    return obj1.getX() < obj2.getX();
                });
            } 
            else if (mode4 == "DSC") 
            {
                // Sort based on X in descending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {                
                    if (obj1.getX() == obj2.getX()) 
                    {
                        // If X values are equal, compare by Y values
                        return obj1.getY() > obj2.getY();
                    }
                    return obj1.getX() > obj2.getX();
                });
            }
        }
    }
    else if (mode3 == "y-ordinate")
    {
        if constexpr (is_same<ObjectType, Point2D>::value || is_same<ObjectType, Point3D>::value)
        {
            if (mode4 == "ASC") 
            {
                // Sort based on Y in ascending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {               
                    if (obj1.getY() == obj2.getY()) 
                    {
                        // If Y values are equal, compare by X values
                        return obj1.getX() < obj2.getX();
                    }
                    return obj1.getY() < obj2.getY();
                });
            } 
            else if (mode4 == "DSC") 
            {
                // Sort based on Y in descending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {                
                    if (obj1.getX() == obj2.getX()) 
                    {
                        // If Y values are equal, compare by X values
                        return obj1.getY() > obj2.getY();
                    }
                    return obj1.getX() > obj2.getX();
                });
            }
        }
        
    }
    else if (mode3 == "z-ordinate")
    {
        if constexpr (is_same<ObjectType, Point3D>::value)
        {
            if (mode4 == "ASC") 
            {
                // Sort based on Z in ascending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {               
                    return obj1.getZ() < obj2.getZ();
                });
            } 
            else if (mode4 == "DSC") 
            {
                // Sort based on Z in descending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {                
                    return obj1.getZ() > obj2.getZ();
                });
            }
        }
        
    }
    else if (mode3 == "Pt. 1")
    {
        if constexpr (is_same<ObjectType, Line2D>::value || is_same<ObjectType, Line3D>::value)
        {
            if (mode4 == "ASC") 
            {
                // Sort based on Pt. 1 in ascending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {
                    auto pt1 = obj1.getPt1();
                    auto pt2 = obj2.getPt1();
                    
                    if (pt1.getX() == pt2.getX()) 
                    {
                        // If X values are equal, compare by Y values
                        return pt1.getY() < pt2.getY();
                    }
                    return pt1.getX() < pt2.getX();
                });
            } 
            else if (mode4 == "DSC") 
            {
                // Sort based on Pt. 1 in descending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {
                    auto pt1 = obj1.getPt1();
                    auto pt2 = obj2.getPt1();
                    
                    if (pt1.getX() == pt2.getX()) 
                    {
                        // If X values are equal, compare by Y values
                        return pt1.getY() > pt2.getY();
                    }
                    return pt1.getX() > pt2.getX();
                });
            }
        }
        
    } 
    else if (mode3 == "Pt. 2")
    {
        if constexpr (is_same<ObjectType, Line2D>::value || is_same<ObjectType, Line3D>::value)
        {
            if (mode4 == "ASC") 
            {
                // Sort based on Pt. 2 in ascending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {
                    auto pt1 = obj1.getPt2();
                    auto pt2 = obj2.getPt2();
                    
                    if (pt1.getX() == pt2.getX()) 
                    {
                        // If X values are equal, compare by Y values
                        return pt1.getY() < pt2.getY();
                    }
                    return pt1.getX() < pt2.getX();
                });
            } 
            else if (mode4 == "DSC") 
            {
                // Sort based on Pt. 2 in descending order
                sort(objects.begin(), objects.end(), []( auto obj1, auto obj2) 
                {
                    auto pt1 = obj1.getPt2();
                    auto pt2 = obj2.getPt2();
                    
                    if (pt1.getX() == pt2.getX()) 
                    {
                        // If X values are equal, compare by Y values
                        return pt1.getY() > pt2.getY();
                    }
                    return pt1.getX() > pt2.getX();
                });
            }
        }
        
    } 
    else if (mode3 == "Length" || mode3 == "dist") 
    {
        if (mode4 == "ASC") 
        {
            // Sort based on Length in ascending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) 
            {
                return obj1.getScalarValue() < obj2.getScalarValue();
            });
        } 
        else if (mode4 == "DSC") 
        {
            // Sort based on Length in descending order
            sort(objects.begin(), objects.end(), [](const auto& obj1, const auto& obj2) 
            {
                return obj1.getScalarValue() > obj2.getScalarValue();
            });
        }
    }
}


#endif 
