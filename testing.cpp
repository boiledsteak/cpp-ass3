#include <iostream>
using namespace std;

int main() {
    int option1, option2, option3;
    
    // Nested loops to generate all permutations
    for (option1 = 1; option1 <= 3; ++option1) {
        for (option2 = 1; option2 <= 3; ++option2) {
            for (option3 = 1; option3 <= 3; ++option3) {
                
                // Output the current permutation
                cout << "Permutation: " << option1 << ", " << option2 << ", " << option3 << endl;
                
                // Switch statement to handle each permutation
                switch (option1 * 100 + option2 * 10 + option3) {
                    case 123:
                        cout << "Option 1, Option 2, Option 3" << endl;
                        break;
                    case 132:
                        cout << "Option 1, Option 3, Option 2" << endl;
                        break;
                    case 213:
                        cout << "Option 2, Option 1, Option 3" << endl;
                        break;
                    case 231:
                        cout << "Option 2, Option 3, Option 1" << endl;
                        break;
                    case 312:
                        cout << "Option 3, Option 1, Option 2" << endl;
                        break;
                    case 321:
                        cout << "Option 3, Option 2, Option 1" << endl;
                        break;
                    default:
                        cout << "Invalid permutation" << endl;
                        break;
                }
            }
        }
    }
    
    return 0;
}
