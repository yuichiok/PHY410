#include <iostream>
#include <math.h>
#include <vector>

float magnitude(float x, float y);

int main(void){
    
    //declaration of variables and vectors
    std::vector<float> magvec, vecx, vecy;
    float xi = 0., yi = 0.;
    float magmin = std::numeric_limits<float>::max(), xmin = 0., ymin = 0.;
    float mag = 0;
    float magval = 0;
    int i = 0;
    int n_magvec =0;
    
    std::cout << "Enter vectors: ";
    
    //input
    while( std::cin >> xi >> yi ) {
        
        //if( std::cin.fail() ) break;
        std::cout << "{" << xi << ", " << yi << "}" << std::endl;
        vecx.push_back(xi); //push inputs to vector vecx
        vecy.push_back(yi); //push inputs to vector vecy
        mag = magnitude(xi,yi); //calculation of magnitude
        magvec.push_back(mag);
        
        if( mag < magmin ) magmin = mag;
        
        std::cout << "magnitude = " << mag << std::endl;
        
    }

    std::cout << std::string(60, '*') << std::endl;
    
    std::cout << "vectors:";
    
    n_magvec = magvec.size();
    
    
    for(int k=0; k<n_magvec; k++){
        
        magval = magvec[k];
        
        if(magmin == magval){
            std::cout << " {" << vecx[k] << ", " << vecy[k] << "}";
        }
    }
    
    std::cout << "\n" << "magnitude = " << magmin << std::endl;
    std::cout << "DONE!" << std::endl;
    
    return 0;
}

float magnitude(float x, float y){
    
    float magf = 0;
    
    magf = sqrt(x*x + y*y);
    
    return magf;
    
}



