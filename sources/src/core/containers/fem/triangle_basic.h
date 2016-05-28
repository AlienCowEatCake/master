#if !defined(CONTAINERS_FEM_TRIANGLE_BASIC_H_INCLUDED)
#define CONTAINERS_FEM_TRIANGLE_BASIC_H_INCLUDED

#include <cassert>
#include <cstddef>

namespace core { namespace containers { namespace fem {

/**
 * @brief Класс треугольник
 */
template<typename point, typename edge, typename face, typename phys_area>
class triangle_basic
{
public:
    triangle_basic();

    const point & get_node(std::size_t i) const;
    point & get_node(std::size_t i);
    const point * get_node_ptr(std::size_t i) const;
    point * get_node_ptr(std::size_t i);
    void set_node(std::size_t i, point * new_node);
    void set_node(std::size_t i, point & new_node);

    const edge & get_edge(std::size_t i) const;
    edge & get_edge(std::size_t i);
    const edge * get_edge_ptr(std::size_t i) const;
    edge * get_edge_ptr(std::size_t i);
    void set_edge(std::size_t i, edge * new_edge);
    void set_edge(std::size_t i, edge & new_edge);

    const face & get_face() const;
    face & get_face();
    const face * get_face_ptr() const;
    face * get_face_ptr();
    void set_face(face * new_face);
    void set_face(face & new_face);

    const phys_area & get_phys_area() const;
    phys_area & get_phys_area();
    const phys_area * get_phys_area_ptr() const;
    phys_area * get_phys_area_ptr();
    void set_phys_area(phys_area * new_phys_area);
    void set_phys_area(phys_area & new_phys_area);

private:

    point * m_nodes[3];   // Узлы
    edge * m_edges[3];    // Ребра
    face * m_faces;       // Грани
    phys_area * m_phys;   // Физическая область
};

}}} // namespace core::containers::fem

#endif // CONTAINERS_FEM_TRIANGLE_BASIC_H_INCLUDED
