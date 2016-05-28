#if !defined(CONTAINERS_GEOMETRY_EDGE_BASIC_H_INCLUDED)
#define CONTAINERS_GEOMETRY_EDGE_BASIC_H_INCLUDED

#include <cassert>
#include <cstddef>

namespace core { namespace containers { namespace geometry {

/**
 * @brief Структура ребро из двух узлов
 */
template<typename point>
struct edge_basic
{
    point * nodes[2];   ///< Узлы ребра
    std::size_t num;    ///< Номер ребра

    edge_basic(const edge_basic & f);
    edge_basic(point * beg_ = NULL, point * end_ = NULL, std::size_t num_ = 0);
    edge_basic(point & beg_, point & end_, std::size_t num_ = 0);

    point & operator [] (std::size_t i);
    const point & operator [] (std::size_t i) const;

    bool operator < (const edge_basic & t) const;
    bool operator == (const edge_basic & t) const;
    edge_basic & operator = (const edge_basic & other);
};

}}} // namespace core::containers::geometry

#endif // CONTAINERS_GEOMETRY_EDGE_BASIC_H_INCLUDED
