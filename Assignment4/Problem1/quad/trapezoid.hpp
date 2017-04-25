#include <iostream>
#include <math.h>
#include <assert.h>

//Approximates the definite integral of f from a to b by
//the composite trapezoidal rule, using n subintervals.
//From http://en.wikipedia.org/wiki/Trapezoidal_rule
double trapezoid(            // performs trapezoid quadrature
    double (*f)(double),     // function to be integrated
    double a,                // lower limit of integration
    double b,                // upper limit of integration
    unsigned n)              // number of subintervals
{
  assert ( n > 0 );
  double h = (b-a) / n;
  double s = f(a) + f(b);
  for ( unsigned i = 1; i < n; ++i ) {
    s += 2 * f(a + i*h);
  }
  return s * h / 2.0;
}

double adaptive_trapezoid(   // performs iterative trapezoid quadrature
    double (*f)(double),     // function to be integrated
    double a,                // lower limit of integration
    double b,                // upper limit of integration
    double acc,              // desired accuracy
    bool output=true)       // output on each iteration if output == true
{
    double old_sum = 1e30;
    double h = b - a;
    int n = 1;
    double sum = (f(a) + f(b)) / 2;
    if (output) {
        std::cout << "N = " << n+1 << ",  Integral = " << h*sum << std::endl;
	std::cout << "R = " << h * (old_sum - sum/2) << std::endl;
	std::cout << "acc = " << acc << std::endl;
    }
    while (fabs(h * (old_sum - sum/2)) > acc) {
        old_sum = sum;
        for (int i = 0; i < n; i++)
            sum += f(a + (i + 0.5) * h);
        n *= 2;
        h /= 2;
	if (output) {
	  std::cout << "N = " << n+1 << ",  Integral = " << h*sum << std::endl;
	  std::cout << "R = " << h * (old_sum - sum/2) << std::endl;
	  std::cout << "acc = " << acc << std::endl;
	}

    }
   return h * sum;
}
