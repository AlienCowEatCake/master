#if !defined(EVALUATOR_OPERATIONS_H)
#define EVALUATOR_OPERATIONS_H

#include <cmath>
#include <complex>
#include <utility>
#include <map>
#include <string>
#include "evaluator_internal/var_container.h"
#include "evaluator_internal/type_detection.h"

namespace evaluator_internal
{
    // All fultions (must NOT be inline).
    template<typename T> T eval_sin(const T & ar);
    template<typename T> T eval_cos(const T & ar);
    template<typename T> T eval_tan(const T & ar);
    template<typename T> T eval_sinh(const T & ar);
    template<typename T> T eval_cosh(const T & ar);
    template<typename T> T eval_tanh(const T & ar);
    template<typename T> T eval_log(const T & ar);
    template<typename T> T eval_log10(const T & ar);
    template<typename T> T eval_exp(const T & ar);
    template<typename T> T eval_sqrt(const T & ar);
    template<typename T> T eval_log2(const T & ar);
    template<typename T> T eval_asinh(const T & ar);
    template<typename T> T eval_acosh(const T & ar);
    template<typename T> T eval_atanh(const T & ar);
    template<typename T> std::complex<T> eval_abs(const std::complex<T> & ar);
    template<typename T> std::complex<T> eval_asin(const std::complex<T> & ar);
    template<typename T> std::complex<T> eval_acos(const std::complex<T> & ar);
    template<typename T> std::complex<T> eval_atan(const std::complex<T> & ar);
    template<typename T> std::complex<T> eval_imag(const std::complex<T> & ar);
    template<typename T> std::complex<T> eval_real(const std::complex<T> & ar);
    template<typename T> std::complex<T> eval_conj(const std::complex<T> & ar);
    template<typename T> std::complex<T> eval_arg(const std::complex<T> & ar);
    template<typename T> T eval_abs(const T & ar);
    template<typename T> T eval_asin(const T & ar);
    template<typename T> T eval_acos(const T & ar);
    template<typename T> T eval_atan(const T & ar);
    template<typename T> T eval_imag(const T & ar);
    template<typename T> T eval_real(const T & ar);
    template<typename T> T eval_conj(const T & ar);
    template<typename T> T eval_arg(const T & ar);

    // Add function pointers into container.
    template<typename T>
    void init_functions(std::map<std::string, T(*)(const T &)> & funcs_map);

    // All operators (must NOT be inline).
    template<typename T> T eval_plus(const T & larg, const T & rarg);
    template<typename T> T eval_minus(const T & larg, const T & rarg);
    template<typename T> T eval_mult(const T & larg, const T & rarg);
    template<typename T> T eval_div(const T & larg, const T & rarg);
    template<typename T> T eval_pow(const T & larg, const T & rarg);

    // Add operators pointers into container.
    template<typename T>
    void init_operators(std::map<char, std::pair<unsigned short int, 
                                                 T(*)(const T &, const T &)> > & opers_map);

    // Init default constant values.
    template<typename T>
    void init_constants(std::map<std::string, T> & consts_map);

} // namespace evaluator_internal

#endif // EVALUATOR_OPERATIONS_H

