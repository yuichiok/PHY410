// pendul - Program to compute the motion of a simple pendulum
// using the Euler or Verlet method
#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "nonlin.hpp"
#include "diffeq.hpp"
#include <sys/time.h>



using namespace std;
using namespace cpt;

class PendulumFunction {
    public :
    PendulumFunction( double isigma=0, double ibeta=0, double irho=0 ) :
    sigma(isigma), beta(ibeta), rho(irho)
    {
    }
    
    protected :
    double sigma;
    double beta;
    double rho;
    
};

class PendulumDiffEq : public PendulumFunction {
    public :
    
    PendulumDiffEq( double isigma=0, double ibeta=0, double irho=0 ) :
    PendulumFunction( isigma, ibeta, irho ) {}
    
    Matrix<double,1> operator()( Matrix<double,1> const & p) const {
        double x = p[0], y = p[1], z = p[2];
        
        Matrix<double,1> out(3);
        out[0] = sigma*(y-x);
        out[1] = x*(rho-z)-y;
        out[2] = x*y-beta*x;
        
        return out;
    }
    
};


int main() {
    
    cout << "Choose a numerical method : RK4 (0), or Adaptive RK4 (1): ";
    int method; cin >> method;
    cout << "Enter initial x: ";
    double x0; cin >> x0;               // Set the initial x
    cout << "Enter initial y: ";
    double y0; cin >> y0;               // Set the initial y
    cout << "Enter initial z: ";
    double z0; cin >> z0;               // Set the initial z
    
    cout << "Enter time step: ";
    double tau; cin >> tau;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    
    PendulumDiffEq pendulumDiffEq( 10, 8/3, 28 );
    
    double accuracy = 1e-6;
    cout << "Enter number of time steps: ";
    int nStep;  cin >> nStep;
    
    Matrix<double,1> xv(3);
    xv[0] = x0;
    xv[1] = y0;
    xv[2] = z0;
    
    std::vector<double> x_plot;
    std::vector<double> y_plot;
    std::vector<double> z_plot;
    //std::vector<double> period;
    double dt_min = tau;
    double dt_max = tau;
    int iStep;
    for( iStep=0; iStep<nStep; iStep++ ) {
        
        x_plot.push_back( xv[0] );
        y_plot.push_back( xv[1] );
        z_plot.push_back( xv[1] );
        
        if( method == 0 ) {
            cpt::RK4_step( xv, tau, pendulumDiffEq );
        } else if ( method == 1) {
            
            tau = cpt::RK4_adaptive_step(xv, tau, pendulumDiffEq, accuracy);
            dt_min = min(tau, dt_min);
            dt_max = max(tau, dt_max);
        }
        
    }
    
    int i;
    ofstream solOut("solution_plot.txt");
    for( i=0; i< x_plot.size(); i++ ) {
        solOut << x_plot[i] << " "  << y_plot[i] << " " << z_plot[i] << endl;
    }
    solOut.close();
    
    gettimeofday(&end, NULL);
    double elapsed = ((end.tv_sec - start.tv_sec) * 1000) + (end.tv_usec / 1000 - start.tv_usec / 1000);
    
    cout << endl;
    cout << "Elapsed = " << elapsed/1000 << " sec"<< endl;
    
    return 0;
}










