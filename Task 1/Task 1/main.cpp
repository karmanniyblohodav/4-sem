#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main() {
    std::string filename = "name.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::istream_iterator<int> start(file), end;

    std::ostream_iterator<int> output(std::cout, " ");

    std::copy(start, end, output);
    std::cout << std::endl;

    return 0;
}
