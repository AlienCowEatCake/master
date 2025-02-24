#if !defined(TETRAHEDRON_H_INCLUDED)
#define TETRAHEDRON_H_INCLUDED

#include "../common/common.h"
#include "../common/config.h"
#include "../elements/edge.h"
#include "../vfem/phys.h"

typedef cvector3(* eval_func)(const point &, phys_area &, void *);

// Индексы для построения базисных функций на тетраэдрах
namespace tet_basis_indexes
{
    // Edges (Ребра) // k, l : k < l
    extern const size_t ind_e[6][2];
    // Faces (Грани) // j, k, l : j < k < l
    extern const size_t ind_f[4][3];
}

// Класс тетраэдр (абстрактный)
class tetrahedron_base : public tetrahedron_basic_3d<edge, face, phys_area>
{
public:
    void init(const basis_type * basis);

    const basis_type * basis;   // Параметры базиса

    // Базисные функции
    vector3 w(size_t i, const point & p) const;
    // Дивергенции базисных функций
    double divw(size_t i, const point & p) const;
    // Роторы базисных функций
    vector3 rotw(size_t i, const point & p) const;
    // Базисные функции ядра
    vector3 kerw(size_t i, const point & p) const;

    trio<double, vector3, cvector3>
    diff_normL2(const array_t<complex<double> > & q, eval_func func, void * data);
    trio<double, vector3, cvector3>
    diff_normL2(const array_t<complex<double> > & q, const array_t<complex<double> > & q_true);
    trio<double, vector3, cvector3>
    normL2(eval_func func, void * data);
    trio<double, vector3, cvector3>
    normL2(const array_t<complex<double> > & q_true);
};

// Класс тетраэдр (обычный)
class tetrahedron : public tetrahedron_base
{
public:
    // Локальная правая часть
    array_t<complex<double> > rp(eval_func func, void * data);
    // Локальная матрица полного пространства
    matrix_t<complex<double> > MpG();
    // Локальная матрица ядра
    matrix_t<complex<double> > K();
};

// Класс тетраэдр (для работы с PML-краевыми)
class tetrahedron_pml : public tetrahedron
{
public:
    tetrahedron_pml();
    // Инициализация PML-координат
    void init_pml(cvector3(* get_s)(const point &, const tetrahedron_pml *, const phys_pml_area *),
                  const phys_pml_area * phys_pml, const cpoint * nodes_pml);

    // Локальная правая часть
    array_t<complex<double> > rp(eval_func func, void * data);
    // Локальная матрица полного пространства
    matrix_t<complex<double> > MpG();
    // Локальная матрица ядра
    matrix_t<complex<double> > K();

    // Получить указатель на обычный тетраэдр
    const tetrahedron * to_std() const;
    tetrahedron * to_std();

protected:
    cvector3(* get_s)(const point &, const tetrahedron_pml *, const phys_pml_area *);
    const phys_pml_area * phys_pml;

    // Матрица L-координат (в PML)
    matrix_t<complex<double> > L_pml;
    // Градиент L-координаты (в PML)
    cvector3 grad_lambda_pml(size_t i) const;
    // L-координаты (в PML)
    complex<double> lambda_pml(size_t i, const cpoint & p) const;

    // Точки Гаусса (в PML)
    array_t<cpoint> gauss_points_pml;
    // Якобиан (в PML)
    complex<double> jacobian_pml;

    // Базисные функции (в PML)
    cvector3 w_pml(size_t i, const cpoint & p) const;
    // Роторы базисных функций (в PML)
    cvector3 rotw_pml(size_t i, const cpoint & p, const point & p_non_PML) const;
    // Базисные функции ядра (в PML)
    cvector3 kerw_pml(size_t i, const cpoint & p, const point & p_non_PML) const;
};

#endif // TETRAHEDRON_H_INCLUDED
