#if !defined(PHYS_H_INCLUDED)
#define PHYS_H_INCLUDED

#include "../common/common.h"

namespace consts
{
    static const double c = 299792458.0;                // Скорость света
    static const double mu0 = 4.0e-7 * M_PI;            // Магн. пр. вакуума
    static const double epsilon0 = 1.0 / (mu0 * c * c); // Диэл. пр. вакуума
}

// Класс физическая область
class phys_area
{
public:
    double omega;                // Циклическая частота
    double mu;                   // Магнитная проницаемость (относительная)
    array_t<evaluator_xyz<double>, 3> sigma;    // Электрическая проводимость
    double epsilon;              // Диэлектрическая проницаемость (относительная)
    size_t gmsh_num;             // Номер области в Gmsh
    size_t type_of_elem;         // Тип элементов
    size_t type_of_bounds;       // Тип краевого условия
    double J0;                   // Мощность источника
    double E0;                   // Электрическое поле от электрода
    phys_area();                 // Конструктор по умолчанию
};

// Класс для индексации физических областей
class phys_id
{
public:
    size_t type_of_element;
    size_t gmsh_num;
    phys_id();
    phys_id(size_t type_of_element, size_t gmsh_num);
    bool operator < (const phys_id & other) const;
};

// Класс для хранения параметров PML для одной физической области
class pml_config_parameter
{
public:
    complex<double> chi;
    double width;
    double m;
    pml_config_parameter(complex<double> n_chi = 1.0, double n_width = 100.0, double n_m = 3.0);
};

// Класс для хранения параметров PML
class phys_pml_area
{
public:
    double x0, x1;
    double y0, y1;
    double z0, z1;
    map<size_t, pml_config_parameter> params;
};

#endif // PHYS_H_INCLUDED
