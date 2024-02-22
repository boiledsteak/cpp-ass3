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
#include <cstdio>
#include "MyTemplates.h"
#include "MyOpOverloads.h"
#include "MyClasses.h"
#include "NormalFunctions.h"

using namespace std;

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
                cin >> filename; // No input validation for filename
                // filename = "messy.txt";
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
                    // all cases reset mode3 back to default
                    case 'a':
                        {
                            mode2 = "Point2D";
                            mode3 = "x-ordinate";
                            successprint(mode2);
                            


                        }
                        break;
                    case 'b':
                        {
                            mode2 = "Point3D";
                            mode3 = "x-ordinate";
                            successprint(mode2);
                        }
                        break;
                    case 'c':
                        {
                            mode2 = "Line2D";
                            mode3 = "Pt. 1";
                            successprint(mode2);
                        }
                        break;
                    case 'd':
                        {
                            mode2 = "Line3D";
                            mode3 = "Pt. 1";
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
                option3menu(mode2);
                while (!(cin >> option) || cin.peek() != '\n' || (option != 'a' && option != 'b' && option != 'c' && option != 'd')) 
                {
                    cout << invalidinp;
                    cin.clear();  // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    option3menu(mode2);
                }

                if (mode2=="Point2D")
                {
                    switch (option)
                    {
                        case 'a':
                            {
                                // X coord of point2d
                                mode3 = "x-ordinate";
                                successprint(mode3);
                            }
                            break;
                        case 'b':
                            {
                                // y coord of point2d
                                mode3 = "y-ordinate";
                                successprint(mode3);
                            }
                            break;
                        case 'c':
                            {
                                // distance from origin value
                                mode3 = "dist";
                                successprint(mode3);
                            }
                            break;
                        
                        default:
                            cout << "\nWe don't have that option :( Please try again...\n\n";
                            break;
                    }
                }

                else if (mode2=="Point3D")
                {
                    switch (option)
                    {
                        case 'a':
                            {
                                // X coord of point3d
                                mode3 = "x-ordinate";
                                successprint(mode3);
                            }
                            break;
                        case 'b':
                            {
                                // y coord of point3d
                                mode3 = "y-ordinate";
                                successprint(mode3);
                            }
                            break;
                        case 'c':
                            {
                                // z coord of point3d
                                mode3 = "z-ordinate";
                                successprint(mode3);
                            }
                            break;
                        case 'd':
                            {
                                // distance from origin value
                                mode3 = "dist";
                                successprint(mode3);
                            }
                            break;
                        
                        default:
                            cout << "\nWe don't have that option :( Please try again...\n\n";
                            break;
                    }
                }

                else if (mode2=="Line3D" || mode2=="Line2D")
                {
                    switch (option)
                    {
                        case 'a':
                            {
                                // X and Y coord of pt1
                                mode3 = "Pt. 1";
                                successprint(mode3);
                            }
                            break;
                        case 'b':
                            {
                                // X and Y coord of pt2
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
                if (mode2 == "Point2D")
                {
                    sortObjects(point2Dobjects, mode3, mode4);
                    printObjects(mode2, point2Dobjects);
                }
                else if (mode2 == "Point3D")
                {
                    sortObjects(point3Dobjects, mode3, mode4);
                    printObjects(mode2, point3Dobjects);
                }
                else if (mode2 == "Line2D")
                {
                    sortObjects(line2Dobjects, mode3, mode4);
                    printObjects(mode2, line2Dobjects);
                }
                else if (mode2 == "Line3D")
                {
                    sortObjects(line3Dobjects, mode3, mode4);   
                    printObjects(mode2, line3Dobjects);
                }
                cout << "\nPress any key to go back to main menu...";
                cout << "\n";
                cin.ignore(); // Ignore any characters in the input buffer
                // Loop until the something is pressed
                while (true) 
                {
                    char ch = cin.get();
                    string str(1, ch); // get from input
                    if (!str.empty()) 
                    {
                        // something entered. break out of the loop
                        break;
                    }
                }
                
            }
            break;
            case 6:
            {
                string filename;
                cout << "\n\nEnter the filename to save data: \n";
                cin >> filename;

                ofstream outputFile(filename); // Open the file for writing

                if (!outputFile.is_open()) {
                    cout << "Error: Unable to open file for writing.\n";
                    break;
                }

                // Redirect standard output to the file
                streambuf* original_cout = cout.rdbuf(); // Save original cout buffer
                cout.rdbuf(outputFile.rdbuf()); // Redirect cout to file

                // Call the printing function to print objects to the file
                if (mode2 == "Point2D")
                {
                    sortObjects(point2Dobjects, mode3, mode4);
                    printObjects(mode2, point2Dobjects);
                }
                else if (mode2 == "Point3D")
                {
                    sortObjects(point3Dobjects, mode3, mode4);
                    printObjects(mode2, point3Dobjects);
                }
                else if (mode2 == "Line2D")
                {
                    sortObjects(line2Dobjects, mode3, mode4);
                    printObjects(mode2, line2Dobjects);
                }
                else if (mode2 == "Line3D")
                {
                    sortObjects(line3Dobjects, mode3, mode4);   
                    printObjects(mode2, line3Dobjects);
                }

                // Restore standard output
                cout.rdbuf(original_cout); // Restore original cout buffer
                outputFile.close(); // Close the file

                // Print the number of objects printed
                cout << "\n";
                if (mode2 == "Point2D")
                    cout << point2Dobjects.size();
                else if (mode2 == "Point3D")
                    cout << point3Dobjects.size();
                else if (mode2 == "Line2D")
                    cout << line2Dobjects.size();
                else if (mode2 == "Line3D")
                    cout << line3Dobjects.size();
                cout << " records output successfully!\n\n";
                cout << "Going back to main menu...\n\n";
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