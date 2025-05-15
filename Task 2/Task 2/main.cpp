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
std::list<int> input_list(const std::string& name);

/**
 * @brief Функция для вывода списка на экран.
 * @param lst Список для вывода.
 */
void print_list(const std::list<int>& lst);

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main() {
    std::list<int> L1 = input_list("L1");

    if (L1.size() < 1 || L1.size() % 2 == 0) {
        std::cerr << "L1 должно содержать нечетное и положительное количество элементов." << std::endl;
        return 1;
    }

    std::list<int> L2 = input_list("L2");

    auto mid = L1.begin();
    std::advance(mid, L1.size() / 2);

    L2.splice(L2.end(), L1, mid);

    std::cout << "L1 после перемещения: ";
    print_list(L1);

    std::cout << "L2 после перемещения: ";
    print_list(L2);

    return 0;
}

std::list<int> input_list(const std::string& name) {
    std::list<int> lst;
    std::string line;

    std::cout << "Введите элементы для " << name << " (пустая строка для завершения):" << std::endl;
    while (std::getline(std::cin, line) && !line.empty()) {
        try {
            int value = std::stoi(line);
            lst.push_back(value);
        } catch (const std::invalid_argument&) {
            std::cout << "Ошибка: введите корректное число" << std::endl;
        }
    }

    return lst;
}

void print_list(const std::list<int>& lst) {
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
