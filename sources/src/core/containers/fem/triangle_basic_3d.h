#if !defined(CONTAINERS_FEM_TRIANGLE_BASIC_3D_H_INCLUDED)
#define CONTAINERS_FEM_TRIANGLE_BASIC_3D_H_INCLUDED

#include <cmath>
#include "triangle_basic.h"
#include "../generic/array_t.h"
#include "../generic/matrix_t.h"
#include "../geometry/point3_t.h"
#include "../geometry/vector3_t.h"
#include "../../cubatures/triangle_integration.h"

namespace core { namespace containers { namespace fem {

/**
 * @brief Класс треугольник в трехмерном пространстве
 */
template<typename edge, typename face, typename phys_area>
class triangle_basic_3d
    : public virtual triangle_basic<geometry::point3_t<double>, edge, face, phys_area>
{
public:
    triangle_basic_3d();

    /**
     * @brief Инициализация для работы в трехмерном пространстве
     * @param[in] tr_integration Параметры интегрирования
     */
    void init_3d(const cubatures::triangle_integration & tr_integration);

    /**
     * @brief Получить значение L-координаты
     * @param[in] i Номер L-координаты
     * @param[in] p Точка, в которой нужно узнать значение
     * @return Значение L-координаты
     */
    double lambda(std::size_t i, const geometry::point3_t<double> & p) const;

    /**
     * @brief Получить градиент L-координаты (в глобальных координатах)
     * @param[in] i Номер L-координаты
     * @return Градиент L-координаты в глобальных координатах
     */
    geometry::vector3_t<double> grad_lambda(std::size_t i) const;

    /**
     * @brief Перевод точки в локальную систему координат треугольника
     * @param[in] p Точка в глобальной системе координат
     * @return Точка в локальной системе координат
     */
    geometry::point3_t<double> to_local(const geometry::point3_t<double> & p) const;

    /**
     * @brief Перевод точки в глобальную систему координат
     * @param[in] p Точка в локальной системе координат
     * @return Точка в глобальной системе координат
     */
    geometry::point3_t<double> to_global(const geometry::point3_t<double> & p) const;

    /**
     * @brief Перевод вектора в глобальную систему координат
     * @param[in] p Вектор в локальной системе координат
     * @return Вектор в глобальной системе координат
     */
    geometry::vector3_t<double> to_global(const geometry::vector3_t<double> & v) const;

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
     * @brief Матрица L-координат
     */
    generic::matrix_t<double> m_L;

    /**
     * @brief Матрица перехода между локальной и глобальной с.к.
     */
    generic::matrix_t<double, 3, 3> m_transition_matrix;

    /**
     * @brief Точки Гаусса
     */
    generic::array_t<geometry::point3_t<double> > m_gauss_points;

    /**
     * @brief Якобиан
     */
    double m_jacobian;
};

}}} // namespace core::containers::fem

#endif // CONTAINERS_FEM_TRIANGLE_BASIC_3D_H_INCLUDED
