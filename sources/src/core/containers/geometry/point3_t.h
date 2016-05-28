#if !defined(CONTAINERS_GEOMETRY_POINT3_T_H_INCLUDED)
#define CONTAINERS_GEOMETRY_POINT3_T_H_INCLUDED

#include <cstring>
#include <cassert>
#include <fstream>

namespace core { namespace containers { namespace geometry {

// Структура трехмерная точка
template<typename T>
struct point3_t
{
    // Координаты
    T x, y, z;
    // Номер точки
    std::size_t num;
    // Конструктор по-умолчанию
    point3_t();
    // Конструктор по трем координатам и номеру
    template<typename U>
    point3_t(U n_x, U n_y, U n_z, std::size_t n_num = 0);
    // Конструктор из другой точки
    template<typename U>
    point3_t(const point3_t<U> & p);
    // Операторы типа "скобка"
    T & operator [] (std::size_t i);
    const T & operator [] (std::size_t i) const;
    // Оператор меньше (по номеру)
    template<typename U>
    bool operator < (const point3_t<U> & t) const;
    // Оператор равенства (по номеру)
    template<typename U>
    bool operator == (const point3_t<U> & t) const;
    // Оператор присваивания
    point3_t<T> & operator = (const point3_t<T> & other);
    template<typename U>
    point3_t<T> & operator = (const point3_t<U> & other);
    // Вывод
    template<typename U>
    friend std::ostream & operator << (std::ostream & os, const point3_t<U> & a);
    // Проверка, лежит ли точка внутри параллелепипеда (для дерева)
    bool inside(double x0, double x1, double y0, double y1, double z0, double z1) const;
};

}}} // namespace core::containers::geometry

#endif // CONTAINERS_GEOMETRY_POINT3_T_H_INCLUDED
