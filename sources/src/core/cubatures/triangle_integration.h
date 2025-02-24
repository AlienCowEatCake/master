#if !defined(CUBATURES_TRIANGLE_INTEGRATION_H_INCLUDED)
#define CUBATURES_TRIANGLE_INTEGRATION_H_INCLUDED

#include <cstddef>
#include <cassert>
#include "../containers/generic/array_t.h"
#include "../containers/generic/matrix_t.h"

namespace core { namespace cubatures {

/**
 * @brief Класс для хранения точек интегрирования на треугольниках
 */
class triangle_integration
{
public:
    triangle_integration(std::size_t order = 8);

    /**
     * @brief Получить количество точек интегрирования
     * @return Количество точек интегрирования
     */
    std::size_t get_gauss_num() const;

    /**
     * @brief Получить вес одной из точек интегрирования
     * @param[in] point_num
     * @return
     */
    double get_gauss_weight(std::size_t point_num) const;

    /**
     * @brief Получить одну из координат одной из точек интегрирования
     * @param[in] point_num Номер точки интегрирования
     * @param[in] coord_num Номер координаты интегрирования
     * @return Координата искомой точки интегрирования
     */
    double get_gauss_point_master(std::size_t point_num, std::size_t coord_num) const;

    /**
     * @brief Инициализация структуры для заданного порядка интегрирования
     * @param[in] order Порядок интегрирования
     */
    void init(std::size_t order);

private:

    /**
     * @brief Количество точек интегрирования
     */
    std::size_t m_gauss_num;

    /**
     * @brief Веса интегрирования
     */
    containers::generic::array_t<double> m_gauss_weights;

    /**
     * @brief Точки интегрирования на мастер-треугольнике, в каждой строке по 3 L-координаты
     */
    containers::generic::matrix_t<double> m_gauss_points_master;

    /**
     * @brief Конвертер для внутренних нужд
     */
    void set(std::size_t num, const double weights[], const double points[][3]);
};

}} // namespace core::cubatures

#endif // CUBATURES_TRIANGLE_INTEGRATION_H_INCLUDED
