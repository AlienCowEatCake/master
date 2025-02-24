#if !defined(CONFIG_H)
#define CONFIG_H

#include "../common/common.h"
#include "../common/evaluator_helmholtz.h"
#include "../vfem/phys.h"

using namespace std;

// Распределение вычислителей по тредам
namespace threads_config
{
    static const size_t matrix_full = 0;
    static const size_t matrix_ker  = 1;
    static const size_t right_part  = 2;
    static const size_t boundary    = 0;
    static const size_t analytical  = 0;
}

//                                  BASIS_ORDER BASIS_TYPE
// Первый порядок I типа (неполный)      1           1
// Первый порядок II типа (полный)       1           2
// Второй порядок I типа (неполный)      2           1
// Второй порядок II типа (полный)       2           2

// Конфигурация базиса
struct basis_type
{
    // Количество базисных функций на тетраэдрах
    size_t tet_bf_num;
    // Количество базисных функций ядра на тетраэдрах
    size_t tet_ker_bf_num;
    // Количество базисных функций на треугольниках
    size_t tr_bf_num;
    // Количество базисных функций ядра на треугольниках
    size_t tr_ker_bf_num;
    // Порядок базиса
    size_t order;
    size_t type;
    // Интегрирование
    tetrahedron_integration tet_int;
    triangle_integration tr_int;
};

// Вычислитель для вычисляемых значений
class evaluator3
{
public:
    evaluator3();
    // Вычислители по физическим областям
    map<size_t, array_t<evaluator_helmholtz, 3> > values;
    // Вычислители по умолчанию
    array_t<evaluator_helmholtz, 3> default_value;
    // Тип JIT-компилятора в вычислителях
    enum jit_types
    {
        JIT_DISABLE,
        JIT_INLINE,
        JIT_EXTCALL
    };
};

// Конфигурация 1D постпроцессора
struct postprocessor_1d
{
    char line_var1_name;
    double line_var1_value;
    char line_var2_name;
    double line_var2_value;
    char var_name;
    double var_from;
    double var_to;
    size_t var_num;
};

// Конфигурация 2D постпроцессора
struct postprocessor_2d
{
    char slice_var_name;
    double slice_var_value;
    char var1_name;
    double var1_from;
    double var1_to;
    size_t var1_num;
    char var2_name;
    double var2_from;
    double var2_to;
    size_t var2_num;
};

// Общая конфигурация постпроцессора
class postprocessor
{
public:
    unsigned char type;
    string filename;
    bool timestamp;
    union
    {
        postprocessor_1d param_1d;
        postprocessor_2d param_2d;
    };
    postprocessor();
};

// Класс конфигурации
class config_type
{
public:
    config_type();
    // Загрузка значений из файла
    bool load(const string & filename);
    bool load_pml(const string & filename);

    // ===== VFEM =====

    // Конфигурация базиса
    basis_type basis;
    // Точность решения СЛАУ
    double eps_slae;
    // Точность решения СЛАУ для краевых
    double eps_slae_bound;
    // Включен V-цикл или нет
    bool v_cycle_enabled;
    // Точность начального решения перед запуском v-цикла
    double gamma_v_cycle_0;
    // Точность решения на полном пространстве
    double gamma_v_cycle_full;
    // Точность решения на пространстве ядра
    double gamma_v_cycle_ker;
    // Максимальное количество итераций для не V-цикловых решателей
    size_t max_iter;
    // Максимальное локальное число итераций V-цикла
    size_t max_iter_v_cycle_local;
    // Решатель для обычной СЛАУ
    string solver_name;
    // Решатель для СЛАУ с краевыми
    string solver_name_bound;
    // Решатель для СЛАУ на полном пространстве
    string solver_name_v_cycle_full;
    // Решатель для СЛАУ на пространстве ядра
    string solver_name_v_cycle_ker;
    // Сетка
    string filename_mesh;
    // Параметры физических областей
    string filename_phys;
    // Куда сохранять веса решения
    string filename_slae;
    // Тип JIT-компилятора в вычислителях
    evaluator3::jit_types jit_type;

    // ===== Boundary =====

    evaluator3 boundary;
    bool boundary_enabled;

    // ===== Right =====

    evaluator3 right;
    bool right_enabled;

    // ===== Analytical =====

    evaluator3 analytical;
    bool analytical_enabled;

    // ===== Postprocessing =====

    map<size_t, postprocessor> post;

    // ===== PML =====

    phys_pml_area phys_pml;
    string filename_pml;

protected:
    // Загрузка значений по-умолчанию
    void load_defaults();
    // Пост-загрузочная инициализация
    bool init(bool status);
};

#endif // CONFIG_H

