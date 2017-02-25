#include <iostream>
#include <math.h>
#include <vector>

float magnitude(float x, float y);

int main(void){
    
    //enter n
    //unsigned int n=0;
    
    /*
    while(1){
        std::cout << "Enter an interger between 0 to 20: ";
        std::cin >> n;
        if( !std::cin.fail() ) break; //breaks when undesired input has been entered
        std::cout << "Error: Number must be between 0 to 20 \n";
        std::cin.clear();    //reset cin value
        std::cin.ignore( 1024, '\n' ); //disregard strings
    }*/
    
    float xi = 0., yi = 0.;
    float magmin = std::numeric_limits<float>::max(), xmin = 0., ymin = 0.;
    float mag = 0;
    int i = 0;
    
    std::cout << "Enter vectors: ";
    
    while( std::cin >> xi >> yi ) {
        
        if( std::cin.fail() ) break;
        std::cout << "{" << xi << ", " << yi << "}" << std::endl;
        mag = magnitude(xi,yi);
        if(mag < magmin){
            magmin = mag;
            xmin = xi;
            ymin = yi;
        }else if(mag == magmin){
            
            
        }
        std::cout << "magnitude = " << mag << std::endl;
        
    }
    
    std::cout << std::string(60, '*') << std::endl;
    
    std::cout << "vector with min magnitude: {" << xmin << ", " << ymin << "}" << std::endl;
    
    
    std::cout << "DONE!" << std::endl;
    return 0;
}

float magnitude(float x, float y){
    
    float magf = 0;
    
    magf = sqrt(x*x + y*y);
    
    return magf;
    
}



