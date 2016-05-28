#if !defined(CONTAINERS_FEM_TETRAHEDRON_BASIC_3D_H_INCLUDED)
#define CONTAINERS_FEM_TETRAHEDRON_BASIC_3D_H_INCLUDED

#include <cmath>
#include "tetrahedron_basic.h"
#include "../generic/array_t.h"
#include "../generic/matrix_t.h"
#include "../geometry/point3_t.h"
#include "../geometry/vector3_t.h"
#include "../../cubatures/tetrahedron_integration.h"

namespace core { namespace containers { namespace fem {

/**
 * @brief Класс тетраэдр в трехмерном пространстве
 */
template<typename edge, typename face, typename phys_area>
class tetrahedron_basic_3d
    : public tetrahedron_basic<geometry::point3_t<double>, edge, face, phys_area>
{
public:
    tetrahedron_basic_3d()
    {
        m_jacobian = 0.0;
    }

    /**
     * @brief Инициализация для работы в трехмерном пространстве
     * @param[in] tet_integration Параметры интегрирования
     */
    void init_3d(const cubatures::tetrahedron_integration & tet_integration);

    /**
     * @brief Определить, внутри тетраэдра точка или нет
     * @param[in] p Точка
     * @return true, если внутри ; false, если иначе
     */
    bool inside(const geometry::point3_t<double> & p) const;

    /**
     * @brief Определить, внутри тетраэдра точка или нет
     * @param[in] x Координата x точки
     * @param[in] y Координата y точки
     * @param[in] z Координата z точки
     * @return true, если внутри ; false, если иначе
     */
    bool inside(double x, double y, double z) const;

    /**
     * @brief Определить, лежит ли тетраэдр внутри куба или нет
     * @param[in] x0 Координата x начала куба
     * @param[in] x1 Координата x конца куба
     * @param[in] y0 Координата y начала куба
     * @param[in] y1 Координата y конца куба
     * @param[in] z0 Координата z начала куба
     * @param[in] z1 Координата z конца куба
     * @return true, если внутри ; false, если иначе
     */
    bool in_cube(double x0, double x1, double y0, double y1, double z0, double z1) const;

    /**
     * @brief Получить барицентр тетраэдра
     * @return Барицентр тетраэдра
     */
    const geometry::point3_t<double> & get_barycenter() const;

    /**
     * @brief Получить градиент L-координаты
     * @param[in] i Номер L-координаты
     * @return Градиент L-координаты
     */
    geometry::vector3_t<double> grad_lambda(std::size_t i) const;

    /**
     * @brief Получить значение L-координаты
     * @param[in] i Номер L-координаты
     * @param[in] p Точка, в которой нужно узнать значение
     * @return Значение L-координаты
     */
    double lambda(std::size_t i, const geometry::point3_t<double> & p) const;

    /**
     * @brief Получить якобиан для интегрирования
     * @return Якобиан
     */
    double get_jacobian() const;

    /**
     * @brief Получить точку интегрирования (точку Гаусса)
     * @param[in] i Номер точки интегрирования
     * @return Точка интегрирования
     */
    const geometry::point3_t<double> & get_gauss_point(std::size_t i) const;

private:

    /**
     * @brief Барицентр тетраэдра
     */
    geometry::point3_t<double> m_barycenter;

    /**
     * @brief Матрица L-координат
     */
    generic::matrix_t<double> m_L;

    /**
     * @brief Точки Гаусса
     */
    generic::array_t<geometry::point3_t<double> > m_gauss_points;

    /**
     * @brief Якобиан
     */
    double m_jacobian;

    /**
     * @brief Параметры прямых для дерева
     */
    generic::matrix_t<double> m_edges_a, m_edges_b;
};

}}} // namespace core::containers::fem

#endif // CONTAINERS_FEM_TETRAHEDRON_BASIC_3D_H_INCLUDED
