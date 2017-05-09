#include "nacl.hpp"

int main()
{
    string name("Na2Cl2");      // for output files
    
    const double pi = 4 * atan(1.0);
    
    //n = 3
    //const int nNa = 3, nCl = 3, dim = 3;
    //n = 4
    const int nNa = 4, nCl = 4, dim = 4;
    
    const int n = nNa + nCl;
    double a = 0.2;
    
    //hexa
    double ar3 = a * sqrt(3);
    //octa
    double ar2 = a / sqrt(2);
    //str1_L
    double ar23 = a * sqrt(3) / 2;
    //str2_R
    double x = sqrt(25 - 10 * sqrt(5)) * a / 10;
    double h = a+a*cos(pi/5);
    double y = a*sin(0.2*pi);
    
    //n = 3
    //hexa
    //double r_Na[nNa][3] = { { 0, 0, 0 }, { 3*a, ar3, 0 }, { 3*a, -ar3, 0 } };
    //double r_Cl[nCl][3] = { { a, ar3, 0 }, { a, -ar3, 0 }, { 4*a, 0, 0 } };
    //line
    //double r_Na[nNa][3] = { { 0, 0, 0 }, { 2*a, 0, 0 }, { 4*a, 0, 0 } };
    //double r_Cl[nCl][3] = { { a, 0, 0 }, { 3*a, 0, 0 }, { 5*a, 0, 0 } };
    
    //n = 4
    //cube
    //double r_Na[nNa][3] = { { 0, 0, 0 }, { a, a, 0 }, { 0, a, a }, { a, 0, a } };
    //double r_Cl[nCl][3] = { { a, 0, 0 }, { 0, a, 0 }, { 0, 0, a }, { a, a, a } };
    //octa
    //double r_Na[nNa][3] = { { 0, 0, 0 }, { ar2, a+ar2, 0 }, { a+2*ar2, a, 0 }, { a+ar2, -ar2, 0 } };
    //double r_Cl[nCl][3] = { { 0, a, 0 }, { a+ar2, a+ar2, 0 }, { a+2*ar2, 0, 0 }, { ar2, -ar2, 0 } };
    //rectangle
    //double r_Na[nNa][3] = { { 0, 0, 0 }, { a, a, 0 }, { 2*a, 0, 0 }, { 3*a, a, 0 } };
    //double r_Cl[nCl][3] = { { 0, a, 0 }, { a, 0, 0 }, { 2*a, a, 0 }, { 3*a, 0, 0 } };
    //strange1_L
    //double r_Na[nNa][3] = { { ar23, a/2, 0 }, { ar23, -a/2, 0 }, { ar3+a, 0, a/2 }, { ar3+a, 0, -a/2 } };
    //double r_Cl[nCl][3] = { { 0, 0, 0 }, { ar3, 0, a/2 }, { ar3, 0, -a/2 }, { 3*ar23+a, 0, 0 } };
    //strange1_R
    //double r_Na[nNa][3] = { { ar23, -ar23, ar23 }, { ar23, -ar23, -ar23 }, { ar3+a*cos(pi/10), a*sin(pi/10), 0 }, { ar3, 1.6*a, 0 } };
    //double r_Cl[nCl][3] = { { 0, 0, 0 }, { ar3, 0, 0 }, { ar3+1.6*a*cos(pi*0.3), 1.6*a*sin(pi*0.3), 0 }, { ar3-1.6*a*cos(pi*0.3), 1.6*a*sin(pi*0.3), 0 } };
    //strange2_L
    //double r_Na[nNa][3] = { { 0, 0, 0 }, { a, a, 0 }, { 0.8*a*cos(pi/4) , 0.8*a*sin(pi/4), y }, { -0.5*a*cos(pi/4) , -0.5*a*sin(pi/4), h } };
    //double r_Cl[nCl][3] = { { a, 0, 0 }, { 0, a, 0 }, { -0.8*a*cos(pi/4) , -0.8*a*sin(pi/4), y }, { 0.5*a*cos(pi/4) , 0.5*a*sin(pi/4), h } };
    //strange2_R
    double r_Na[nNa][3] = { { 0, 0, 0 }, { a, a, 0 }, { 0.8*a*cos(pi/4) , 0.8*a*sin(pi/4), y }, { -0.5*a*cos(pi/4) , -0.5*a*sin(pi/4), h } };
    double r_Cl[nCl][3] = { { a, 0, 0.01 }, { 0, a, 0.01 }, { -0.8*a*cos(pi/4) , -0.8*a*sin(pi/4), y }, { 0.5*a*cos(pi/4) , 0.5*a*sin(pi/4), h } };

    
    
    
    
    
    // Initialize the cluster, add guesses at the
    // minimum arrangement. 
    Cluster cluster;
    for (int i = 0; i < nNa; i++) {
        Matrix<double,1> r(3, r_Na[i]);
        cluster.add(Na(r));
    }
    for (int i = 0; i < nCl; i++) {
        Matrix<double,1> r(3, r_Cl[i]);
        cluster.add(Cl(r));
    }
    cout << " " << name << " cluster" << endl
         << " Initial potential energy = "
         << cluster.potential_energy() << endl;


    // Minimize the function
    int iterations = 0;
    double accuracy = 1e-6;
    double pe = cluster.minimize( accuracy, iterations );


    // Print out resulting files to be plotted in
    // either matplotlib or gnuplot. 
    cout << " Minimized potential energy = " << pe << "\n"
         << " Binding energy of cluster  = " << pe / dim << " eV\n"
         << " Number of iterations = " << iterations << endl;

    string file_name = name + ".data";
    ofstream file(file_name.c_str());
    for (int i = 0; i < nNa + nCl - 1; i++) {
        for (int j = i + 1; j < nNa + nCl; j++) {
	    Matrix<double,1> rij = cluster.ion(i).r - cluster.ion(j).r;
            double dr = sqrt(dot(rij, rij));
            string s = "(" + cluster.ion(i).name + ")-(" +
	      cluster.ion(j).name + ")";
            cout << " " << s << " r_" << i << j << " = " << dr << " nm\n";
        }
    }
    file << cluster;
    file.close();
    cout << " xyz coordinates in " << file_name << endl;

    file_name = name + ".gnu";
    file.open(file_name.c_str());
    file << "set title \"(NaCl)_4 Energy = " << pe / dim << " eV\"\n"
         << "set hidden3d\n"
         << "unset key\n"
         << "splot \"na2cl2.data\" with points lt 3 pt 7 ps 8\n"
         << "pause -1 \"Hit return to continue \"\n";
    file.close();
    cout << " Gnuplot script in " << file_name << endl;
}
