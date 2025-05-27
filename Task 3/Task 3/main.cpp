#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>

using namespace std;

/**
 * @brief Получает последнюю цифру числа
 * @param num Входное число
 * @return Последняя цифра числа по модулю
 */
int getLastDigit(int num);

/**
 * @brief Точка входа в программу
 * @return 0 в случае успеха
 */
int main() {
    vector<int> V;
    string line;
    
    cout << "Введите элементы вектора (для завершения ввода введите пустую строку):\n";
    std::vector<int> V((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());
    }
    
    if (V.empty()) {
        cout << "Вектор пуст!\n";
        return 1;
    }
    
    multimap<int, int> M;
    transform(V.begin(), V.end(), 
             inserter(M, M.begin()),
             [](int x) { return make_pair(getLastDigit(x), x); });
    
    map<int, int> sums;
    for (int digit = 0; digit < 10; ++digit) {
        auto range = M.equal_range(digit);
        if (range.first != range.second) {
            multimap<int, int>::iterator next_it = next(range.first);
            sums[digit] = accumulate(next_it, range.second, 0,
                                   [](int sum, const pair<const int, int>& p) {
                                       return sum + p.second;
                                   });
        }
    }
    
    cout << "\nСуммы групп (исключая первый элемент в каждой группе):\n";
    for_each(sums.begin(), sums.end(),
             [&M](const pair<const int, int>& p) {
                 if (M.count(p.first) > 0) {
                     cout << "Цифра " << p.first << ": сумма = " << p.second << endl;
                 }
             });
    
    cout << "\nСодержимое мультиотображения:\n";
    for_each(M.begin(), M.end(),
             [](const pair<const int, int>& p) {
                 cout << "Ключ: " << p.first << ", Значение: " << p.second << endl;
             });
    
    return 0;
}

int getLastDigit(int num) {
    return abs(num % 10);
}
