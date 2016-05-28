#if !defined(CONTAINERS_TREE_OCTREE_H_INCLUDED)
#define CONTAINERS_TREE_OCTREE_H_INCLUDED

#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

namespace core { namespace containers { namespace tree {

template<class element_type>
class octree
{
public:
    void make(double x0, double x1, double y0, double y1, double z0, double z1,
              std::vector<element_type> & elements);
    element_type * find(double x, double y, double z) const;
    void clear();

private:

    class octree_node
    {
    public:
        octree_node();
        ~octree_node();
        void clear();
        void init_node(double x0, double x1, double y0, double y1, double z0, double z1,
                       std::size_t split_constant, std::size_t level_barier);
        void add_element(std::vector<element_type *> & added_elements);
        bool add_element(element_type * added_element);
        element_type * find(double x, double y, double z) const;

        std::size_t level;

    private:
        bool point_in_node(double x, double y, double z) const;
        bool split_condition();
        void split();

        std::vector<element_type *> elements;
        octree_node * sub_nodes;
        double x0, x1, y0, y1, z0, z1;
        double eps_x, eps_y, eps_z;
        std::size_t split_constant;
        std::size_t level_barier;
    };

    octree_node root;
};

}}} // core::containers::tree

#endif // CONTAINERS_TREE_OCTREE_H_INCLUDED
