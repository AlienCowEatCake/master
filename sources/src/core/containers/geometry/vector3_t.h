#if !defined(CONTAINERS_GEOMETRY_VECTOR3_T_H_INCLUDED)
#define CONTAINERS_GEOMETRY_VECTOR3_T_H_INCLUDED

#include <cstring>
#include <fstream>
#include <complex>

#include "point3_t.h"
#include "../generic/array_t.h"
#include "../generic/matrix_t.h"

namespace core { namespace containers { namespace geometry {

// Структура трехмерный вектор
template<typename T>
struct vector3_t
{
    // Элементы
    T x, y, z;
    // Конструктор по-умолчанию
    vector3_t();
    // Конструктор из трех элементов
    template<typename U, typename V, typename R>
    vector3_t(U n_x, V n_y, R n_z);
    // Конструктор из точки
    template<typename U>
    vector3_t(const point3_t<U> & p);
    // Конструктор из двух точек - начала и конца
    template<typename U>
    vector3_t(const point3_t<U> & beg, const point3_t<U> & end);
    // Конструктор из другого вектора
    template<typename U>
    vector3_t(const vector3_t<U> & v);
    // Кастование к точке
    point3_t<T> to_point() const;
    // Операторы типа "скобка"
    T & operator [] (std::size_t i);
    const T & operator [] (std::size_t i) const;
    // Скалярное произведение
    T operator * (const vector3_t<T> & other) const;
    // Векторное произведение
    vector3_t<T> cross(const vector3_t<T> & other) const;
    // Получение сопряженного вектора
    vector3_t<T> conj() const;
    // Норма вектора
    double norm() const;
    // Квадрат нормы вектора
    double norm2() const;
    // Сложение и вычитание векторов
    vector3_t<T> operator + (const vector3_t<T> & other) const;
    vector3_t<T> operator - (const vector3_t<T> & other) const;
    vector3_t<T> & operator += (const vector3_t<T> & other);
    vector3_t<T> & operator -= (const vector3_t<T> & other);
    // Деление вектора на число
    vector3_t<T> operator / (const T & a) const;
    // Умножение вектора на число
    vector3_t<T> operator * (const T & a) const;
    vector3_t<T> & operator *= (const T & a);
    // Умножение числа на вектор
    template<typename U>
    friend vector3_t<U> operator * (const U & a, const vector3_t<U> & vec);
    // Умножение матрицы на вектор
    template<typename U, typename V>
    friend vector3_t<U> operator * (const generic::matrix_t<V, 3, 3> & matr, const vector3_t<U> & vec);
    // Вывод
    template<typename U>
    friend std::ostream & operator << (std::ostream & os, const vector3_t<U> & a)
    // Умножение числа на вектор
    template<typename U, typename V, typename R>
    friend R operator * (const U & a, const vector3_t<V> & vec);
    // Скалярное произведение
    template<typename U, typename V, typename R>
    friend R operator * (const vector3_t<U> & left, const vector3_t<V> & right);
    // Сложение и вычитание векторов
    template<typename U, typename V, typename R>
    friend R operator + (const vector3_t<U> & left, const vector3_t<V> & right);
    template<typename U, typename V, typename R>
    friend R operator - (const vector3_t<U> & left, const vector3_t<V> & right);
};

}}} // namespace core::containers::geometry

#endif // CONTAINERS_GEOMETRY_VECTOR3_T_H_INCLUDED
