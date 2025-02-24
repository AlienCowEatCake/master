#if !defined(SLAE_H_INCLUDED)
#define SLAE_H_INCLUDED

#include "../common/common.h"

// Класс СЛАУ
class SLAE
{
public:
    SLAE();
    ~SLAE();
    void solve(const string & name, double eps, size_t max_iter);
    void init(const string & name);
    void step_solve(complex<double> * solution, const complex<double> * rp_s,
                           double eps, size_t max_iter);
    void alloc_all(size_t n_size, size_t gg_size);
    void dealloc_all();
    void add(size_t i, size_t j, const complex<double> & elem);
    complex<double> * gg, * di, * rp, * x;
    size_t * ig, * jg;
    size_t n;
    bool dump(const string & filename) const;
    bool restore(const string & filename);
    bool dump_x(const string & filename) const;
    bool restore_x(const string & filename);
private:
    preconditioner_interface<complex<double>, size_t> * precond;
    symmetric_solver_interface<complex<double>, size_t> * solver;
};

#endif // SLAE_H_INCLUDED
