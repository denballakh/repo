// #include<iostream>

// template<class T>
// T sqrt(T s) {
//     T x = s;
//     for (int i = 0; i < 20; i += 1)
//         x = (x + s / x) / Point<double>(2, 2);
//     return x;
// }

// template<class T = double>
// class Point {
//     public:
//         T x; T y;
//         Point(): x(), y() {}
//         Point(T x, T y): x(x), y(y) {}
//         Point(const Point<T> &p): x(p.x), y(p.y) {}
//         Point<T> operator-() const { return Point<T>(-this->x, -this->y); }
//         Point<T> operator+() const { return *this; }
//         Point<T> operator+(const Point<T> r) const { return Point<T>(this->x + r.x, this->y + r.y); }
//         Point<T> operator-(const Point<T> r) const { return Point<T>(this->x - r.x, this->y - r.y); }
//         Point<T> operator*(const Point<T> r) const { return Point<T>(this->x * r.x, this->y * r.y); }
//         Point<T> operator/(const Point<T> r) const { return Point<T>(this->x / r.x, this->y / r.y); }
//         Point<T> operator*(const T r) const { return Point<T>(this->x * r, this->y * r); }
//         Point<T> operator/(const T r) const { return Point<T>(this->x / r, this->y / r); }
//         T dot(const Point<T> r) const { return this->x * r.x + this->y + r.y; }
//         T norm2() const { return this->x * this->x + this->y * this->y; }
//         Point<T> to_dec() const { return *this; }
//         Point<T> to_polar() const { return Point<T>(); }

//         bool operator==(const Point<T> r) { return this->x == r.x and this->y == r.y; }
//         bool operator!=(const Point<T> r) { return this->x != r.x or this->y != r.y; }


// };
// template<class T>
// std::ostream& operator<<(std::ostream& stream, const Point<T> p) {
//     stream << "Point(" << p.x << ", " << p.y << ")";
//     return stream;
// }

// #define log(expr) std::cout << #expr << " \t=> " << (expr) << std::endl;

// int main() {
//     Point<Point<>> p(Point(1, 2), Point(3, 4));
//     log(p);
//     log(-p);
//     log(+p);
//     log(p + p);
//     log(p - p);
//     log(p * p);
//     log(p * p.x);
//     log(p.x * 3.5);
//     log(p == p);
//     log(p != p);
//     log(sqrt(p));
// }



#include <math.h>

template<class T = double>
class Point {
    public:
        T x; T y;
        Point(): x(), y() {}
        Point(T x, T y): x(x), y(y) {}
        Point(const Point<T> &p): x(p.x), y(p.y) {}
        Point<T> operator+() const { return *this; }
        Point<T> operator-() const { return Point<T>(-this->x, -this->y); }
        Point<T> operator+(const Point<T> r) const { return Point<T>(this->x + r.x, this->y + r.y); }
        Point<T> operator-(const Point<T> r) const { return Point<T>(this->x - r.x, this->y - r.y); }
        Point<T> operator*(const Point<T> r) const { return Point<T>(this->x * r.x, this->y * r.y); }
        Point<T> operator/(const Point<T> r) const { return Point<T>(this->x / r.x, this->y / r.y); }
        Point<T> operator*(const T r) const { return Point<T>(this->x * r, this->y * r); }
        Point<T> operator/(const T r) const { return Point<T>(this->x / r, this->y / r); }
        T dot(const Point<T> r) const { return this->x * r.x + this->y * r.y; }
        T norm() const { return sqrt(this->dot(*this)); }
        bool operator==(const Point<T> r) { return this->x == r.x and this->y == r.y; }
        bool operator!=(const Point<T> r) { return this->x != r.x or this->y != r.y; }
};

// template<class T>
// std::ostream& operator<<(std::ostream& stream, const Point<T> p) {
//     stream << "Point(" << p.x << ", " << p.y << ")";
//     return stream;
// }

// #define log(expr) std::cout << #expr << " \t=> " << (expr) << std::endl;

// int main() {
//     Point p(1, 2);
//     log(p);
//     log(-p);
//     log(+p);
//     log(p + p);
//     log(p - p);
//     log(p * p);
//     log(p * p.x);
//     log(p.x * 3.5);
//     log(p == p);
//     log(p != p);
// }
