#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

/**
* @brief Получает последнюю цифру числа
* @param num Входное число
* @return Последняя цифра числа по модулю
*/
int getLastDigit(int num) {
    return abs(num % 10);
}

/**
* @brief Точка входа в программу
* @return 0 в случае успеха
*/
int main() {
    vector<int> V;
    int n, x;
    
    cout << "Введите количество элементов: ";
    cin >> n;
    
    cout << "Введите " << n << " элементов:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }
    
    multimap<int, int> M;
    
    for (vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        M.insert(make_pair(getLastDigit(*it), *it));
    }
   
    map<int, int> sums;
    
    for (int i = 0; i < 10; i++) {
        sums[i] = 0;
    }
    
    for (int digit = 0; digit < 10; digit++) {
        bool isFirst = true;
        auto range = M.equal_range(digit);
        for (auto it = range.first; it != range.second; ++it) {
            if (!isFirst) {
                sums[digit] += it->second;
            }
            isFirst = false;
        }
    }
    
    cout << "\nСуммы групп (исключая первый элемент в каждой группе):\n";
    for (const auto& pair : sums) {
        if (M.count(pair.first) > 0) {
            cout << "Цифра " << pair.first << ": сумма = " << pair.second << endl;
        }
    }
    
    cout << "\nСодержимое мультиотображения:\n";
    for (multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << "Ключ: " << it->first << ", Значение: " << it->second << endl;
    }
    
    return 0;
}
