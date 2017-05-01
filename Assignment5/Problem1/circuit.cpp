#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

double parallel(std::vector<double> *res){
	int size = 0;
	double R_rev = 0;
	size = res->size();

	for(int i=0; i < size; i++){
		
		if( res->at(i) > 0 ) R_rev += 1/res->at(i);
	}

	return 1/R_rev;

}



int main(){

	using namespace std;

	//part 1
	vector<double> G1 (3,1), G2 (6,1), G3 (3,1);

	double R_T = 0, R1 = 0, R2 = 0, R3 = 0;

	R1 = parallel( &G1 );
	R2 = parallel( &G2 );
	R3 = parallel( &G3 );

	R_T = R1 + R2 + R3;

	cout << "R_T = " << R_T << endl;

	//part 2
	double R4 = 0, R5 = 0, R6 = 0;
	double R_sub1 = 0, R_sub2 = 0, R_sub3 = 0;

	G1[1] = -1;
	R4 = parallel( &G1 );
    R_sub1 = R2 + R3;

	G2[1] = -1;
	R5 = parallel( &G2 );
	R_sub2 = R1 + R3;

	G3[1] = -1;
	R6 = parallel( &G3 );
	R_sub3 = R1 + R2;

	ofstream script_file("circuit.gnu");
	script_file << "f(x)=x/((" << 1/R4 << ")*x+1)+" << R_sub1 << '\n'
				<< "g(x)=x/((" << 1/R5 << ")*x+1)+" << R_sub2 << '\n'
				<< "h(x)=x/((" << 1/R6 << ")*x+1)+" << R_sub3 << '\n'
	            << "set title \'Equivalent resistance vs Resistor\'" << '\n'
				<< "set xlabel \'Resistance R\'" << '\n'
				<< "set ylabel \'Equivalent resistance R_eq\'" << '\n'
				<< "set xrange [0:100]" << '\n'
				<< "plot f(x) title \'G1\',"
				<< "g(x) title \'G2\',"
				<< "h(x) title \'G3\'"  << '\n';

	script_file.close();







	return 0;
}
