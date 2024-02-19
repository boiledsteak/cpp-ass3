#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string line = "Line2D, [5, 7], [3, 8]";
    std::istringstream iss(line);
    std::vector<int> numbers;
    char ch;

    while (iss >> ch) {
        if (std::isdigit(ch)) {
            iss.unget();
            int num;
            iss >> num;
            numbers.push_back(num);
        }
    }

    for (int num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
