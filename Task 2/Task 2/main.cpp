#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <locale>

/**
 * @brief Функция для ввода списка с клавиатуры.
 * @param count Количество элементов в списке.
 * @param name Имя списка (для отображения в подсказке).
 * @return Список, заполненный пользователем.
 */
std::list<int> input_list(int count, const std::string& name) {
    std::list<int> lst;
    int value;
    std::cout << "Введите " << count << " элементов для " << name << ":" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> value;
        lst.push_back(value);
    }
    return lst;
}

/**
 * @brief Функция для вывода списка на экран.
 * @param lst Список для вывода.
 */
void print_list(const std::list<int>& lst) {
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main() {
    setlocale(LC_ALL, "RU");
    int n1, n2;

    std::cout << "Введите количество элементов в L1 (нечетное): ";
    std::cin >> n1;

    if (n1 < 1 || n1 % 2 == 0) {
        std::cerr << "Количество элементов в L1 должно быть нечетным и положительным." << std::endl;
        return 1;
    }

    std::list<int> L1 = input_list(n1, "L1");

    std::cout << "Введите количество элементов в L2: ";
    std::cin >> n2;
    std::list<int> L2 = input_list(n2, "L2");

    auto mid = L1.begin();
    std::advance(mid, n1 / 2);

    L2.splice(L2.end(), L1, mid);

    std::cout << "L1 после перемещения: ";
    print_list(L1);

    std::cout << "L2 после перемещения: ";
    print_list(L2);

    return 0;
}
