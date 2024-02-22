#ifndef NORMALFUNCTIONS_H
#define NORMALFUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

// Function to print objects based on mode2
void printObjects(const string& mode2, auto objects) 
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
        for (const auto& point : objects) 
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
        for (const auto& point : objects) 
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
        for (const auto& line : objects) 
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
        for (const auto& line : objects) 
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

void option3menu(string mode2)
{
    if (mode2=="Point2D")
    {
        cout << "\ta.\tX-ordinate value\n";
        cout << "\tb.\tY-ordinate value\n";
        cout << "\tc.\tDistance From Origin Value\n";
        cout << "\nPlease enter your criteria (a - c): ";
    }

    else if (mode2=="Point3D")
    {
        cout << "\ta.\tX-ordinate value\n";
        cout << "\tb.\tY-ordinate value\n";
        cout << "\tc.\tZ-ordinate value\n";
        cout << "\td.\tDistance From Origin Value\n";
        cout << "\nPlease enter your criteria (a - d): ";
    }

    else if (mode2=="Line3D" || mode2=="Line2D")
    {
        cout << "\ta.\tPt. 1's (x,y) values\n";
        cout << "\tb.\tPt. 2's (x,y) values\n";
        cout << "\tc.\tLength Value\n";
        cout << "\nPlease enter your criteria (a - c): ";
    }
    
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

#endif
