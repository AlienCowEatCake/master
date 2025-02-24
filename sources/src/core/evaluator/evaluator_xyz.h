#if !defined(EVALUATOR_XYZ_H)
#define EVALUATOR_XYZ_H

/*
// Usage example:
//
// #include "evaluator/evaluator_xyz.h"
// ...
// evaluator_xyz<double> e;
// if(!e.parse("exp(-(0.5-x)*(0.5-x)-(0.5-z)*(0.5-z))"))
//     cerr << e.get_error() << endl;
// else if(!e.simplify()) // simplify is optional step
//     cerr << e.get_error() << endl;
// else
// {
//     if(!e.compile()) // compile is optional step
//         cerr << e.get_error() << endl;
//     e.set_x(0.4);
//     e.set_z(0.8);
//     double result;
//     if(!e.calculate(result))
//         cerr << e.get_error() << endl;
//     else
//         cout << result << endl;
// }
*/

#include "evaluator.h"

// Reference example: Evaluator(x,y,z), takes O(1) time for setting x, y or z
template<typename T> class evaluator_xyz : public evaluator<T>
{
public:

    // Constructors
    evaluator_xyz();
    evaluator_xyz(const std::string & str);
    evaluator_xyz(const evaluator_xyz & other);

    // Copying from another evaluator
    const evaluator_xyz & operator = (const evaluator_xyz & other);

    // Set new value 'x' for variable with name 'x'
    void set_x(const T & x);

    // Set new value 'y' for variable with name 'y'
    void set_y(const T & y);

    // Set new value 'z' for variable with name 'z'
    void set_z(const T & z);

private:

    // Cached pointers for x, y and z
    T * m_x, * m_y, * m_z;

    // Update cached pointers
    void update_cache();
};

#endif // EVALUATOR_XYZ_H

