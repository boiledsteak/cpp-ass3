#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Input string
    string input = "Line2D, [5, 7], [3, 8]";

    // Vector to store the extracted numbers
    vector<pair<int, int>> numbers;

    // Create a stringstream from the input string
    stringstream ss(input);

    // Ignore characters until '[' is found
    char ch;
    while (ss >> ch && ch != '[');

    // Extract numbers until ']' is found
    int num1, num2;
    char comma;
    while (ss >> num1 >> comma >> num2 >> ch && ch == ']') {
        numbers.emplace_back(num1, num2);

        // Ignore characters until '[' is found for the next pair
        while (ss >> ch && ch != '[');
    }

    // Display the extracted numbers
    for (const auto& pair : numbers) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
