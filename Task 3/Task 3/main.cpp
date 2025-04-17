#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

// Функция для получения последней цифры числа
int getLastDigit(int num) {
    return abs(num % 10);
}

int main() {
    // Ввод вектора
    vector<int> V;
    int n, x;
    
    cout << "Введите количество элементов: ";
    cin >> n;
    
    cout << "Введите " << n << " элементов:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        V.push_back(x);
    }
    
    // Создание мультиотображения для группировки
    multimap<int, int> M;
    
    // Заполнение мультиотображения элементами, сгруппированными по последней цифре
    for (vector<int>::iterator it = V.begin(); it != V.end(); ++it) {
        M.insert(make_pair(getLastDigit(*it), *it));
    }
    
    // Вычисление сумм для каждой группы (исключая первый элемент)
    map<int, int> sums;
    
    // Инициализация сумм нулями
    for (int i = 0; i < 10; i++) {
        sums[i] = 0;
    }
    
    // Вычисление сумм для каждой группы
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
    
    // Вывод результатов
    cout << "\nСуммы групп (исключая первый элемент в каждой группе):\n";
    for (const auto& pair : sums) {
        if (M.count(pair.first) > 0) {
            cout << "Цифра " << pair.first << ": сумма = " << pair.second << endl;
        }
    }
    
    // Вывод содержимого мультиотображения
    cout << "\nСодержимое мультиотображения:\n";
    for (multimap<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
        cout << "Ключ: " << it->first << ", Значение: " << it->second << endl;
    }
    
    return 0;
}
