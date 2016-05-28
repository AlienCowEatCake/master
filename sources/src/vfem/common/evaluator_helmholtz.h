#if !defined(EVALUATOR_HELMHOLTZ_H)
#define EVALUATOR_HELMHOLTZ_H

#include "../common/common.h"

// Вычислитель, заточенный под параметры уравнения Гельмгольца
class evaluator_helmholtz : public evaluator<std::complex<double> >
{
public:
    evaluator_helmholtz();
    evaluator_helmholtz(const std::string & str);
    evaluator_helmholtz(const evaluator_helmholtz & other);
    const evaluator_helmholtz & operator = (const evaluator_helmholtz & other);
    void set_x(const std::complex<double> & x);
    void set_y(const std::complex<double> & y);
    void set_z(const std::complex<double> & z);
    void set_J0(const std::complex<double> & J0);
    void set_omega(const std::complex<double> & omega);
    void set_epsilon(const std::complex<double> & epsilon);
    void set_sigma(const std::complex<double> & sigma);
    void set_mu(const std::complex<double> & mu);
    void set_k2(const std::complex<double> & k2);

private:
    std::complex<double> * m_x, * m_y, * m_z;
    std::complex<double> * m_J0, * m_omega, * m_epsilon, * m_sigma, * m_mu, * m_k2;
    void update_cache();
};

#endif // EVALUATOR_HELMHOLTZ_H

