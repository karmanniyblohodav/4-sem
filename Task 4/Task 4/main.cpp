#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <string>

/**
 * @brief Класс point представляет точку с координатами x, y и строковым значением s.
 */
class point {
private:
    int x, y;
    std::string s;

public:
    point() : x(0), y(0), s("") {}
    
    point(int x, int y, const std::string& s) : x(x), y(y), s(s) {}

    int getX() const { return x; }
    int getY() const { return y; }
    const std::string& getS() const { return s; }

    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    void setS(const std::string& newS) { s = newS; }

    /**
     * @brief Оператор чтения из входного потока
     * @param is входной поток
     * @param p структура, в которую считываются данные
     * @return ссылка на поток
     */
    friend std::istream& operator>>(std::istream& is, point& p) {
        return is >> p.x >> p.y >> p.s;
    }

    /**
     * @brief Оператор вывода в выходной поток
     * @param os выходной поток
     * @param p структура, которую нужно вывести
     * @return ссылка на поток
     */
    friend std::ostream& operator<<(std::ostream& os, const point& p) {
        return os << p.x << " " << p.y << " " << p.s;
    }

    /**
     * @brief Преобразование структуры в строку
     * @return строковое представление в формате "x y s"
     */
    operator std::string() const {
        return std::to_string(x) + " " + std::to_string(y) + " " + s;
    }

    /**
     * @brief Проверка, что координаты x и y положительные
     * @return true, если x > 0 и y > 0; иначе false
     */
    bool is_positive() const {
        return x > 0 && y > 0;
    }
};

/**
 * @brief Точка входа в программу
 * @return 0 в случае успеха, 1 при ошибке открытия файла
 */
int main() {
    std::string filename = "points.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::istream_iterator<point> start(file), end;
    std::ostream_iterator<std::string> output(std::cout, "\n");

    point replacement(0, 0, "A");

    std::replace_copy_if(
        start, end,          
        output,
        std::mem_fn(&point::is_positive),
        static_cast<std::string>(replacement)
    );

    return 0;
}
