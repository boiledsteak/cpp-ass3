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


using namespace std;

int main()
{
    string line;
    string filename = "messy.txt";
    fstream file(filename, fstream::in);
    if (!file.fail()) 
    {
        cout << "it works \n";
        while (getline(file >> ws, line)) 
        {
            istringstream iss(line);
            int num;
            while (iss >> num) 
            {
                cout << "Read number: " << num << endl;
            }
        }

        file.close();
    }
    else 
    {
        cout << filename << "\n";
        cerr << "Failed to open the file." << endl;
        cerr << "Error code: " << errno << ", " << strerror(errno) << endl;
    }
    return 0;
}