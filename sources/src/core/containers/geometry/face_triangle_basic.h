#if !defined(CONTAINERS_GEOMETRY_FACE_TRIANGLE_BASIC_H_INCLUDED)
#define CONTAINERS_GEOMETRY_FACE_TRIANGLE_BASIC_H_INCLUDED

#include <cassert>
#include <cstddef>

namespace core { namespace containers { namespace geometry {

/**
 * @brief Структура треугольная грань из трех узлов
 */
template<typename point>
struct face_triangle_basic
{
    point * nodes[3];   ///< Узлы грани
    std::size_t num;    ///< Номер грани

    face_triangle_basic();
    face_triangle_basic(const face_triangle_basic & f);
    face_triangle_basic(point * p1, point * p2, point * p3, std::size_t num_ = 0);
    face_triangle_basic(point & p1, point & p2, point & p3, std::size_t num_ = 0);

    point & operator [] (size_t i);
    const point & operator [] (size_t i) const;

    bool operator < (const face_triangle_basic & t) const;
    bool operator == (const face_triangle_basic & t) const;
    face_triangle_basic & operator = (const face_triangle_basic & other);
};

}}} // namespace core::containers::geometry

#endif // CONTAINERS_GEOMETRY_FACE_TRIANGLE_BASIC_H_INCLUDED
