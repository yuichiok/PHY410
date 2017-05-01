#include <iostream>
using namespace std;

#include "linalg.hpp"
using namespace cpt;

int main()
{
    double m_O = 15.9994, m_C = 12.0107;

    // Matrix with masses as the diagonal elements
    Matrix<double,2> M(5, 5);
    M(0,0) = m_O;
    M(1,1) = m_C;
    M(2,2) = m_C;
	M(3,3) = m_C;
	M(4,4) = m_O;
    cout << "M =\n" << M;


    Matrix<double,2> Minv(5,5);
    inverse(M, Minv);
    cout << "Minv=" << endl << Minv << endl;

    // "Spring" constants affecting each mass
    double k_CO = 14.5, k_CC = 12.4;
    double Lagrange[5][5] = {
        {	k_CO,	-k_CO,			0,				0,				0		},
        {   -k_CO,	k_CO + k_CC,	-k_CC,			0,				0		},
        {   0,		-k_CC,			2*k_CC,			-k_CC,			0		},
		{	0,		0,				-k_CC,			k_CO + k_CC,	-k_CO	},
		{	0,		0,				0,				-k_CO,			k_CO	}
    };
    Matrix<double,2> K(5, 5);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            K(i,j) = Lagrange[i][j];
    cout << "K =\n" << K;

    // Solve with generalized eigenvector solution
    Matrix<double,1> eigenvalues = solve_eigen_generalized(K, M, true);

    cout << "Eigenvalues =\n" << eigenvalues << endl
         << "Eigenvectors =\n" << K;


}
