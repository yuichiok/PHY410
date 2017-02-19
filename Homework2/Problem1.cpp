#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <limits>

int main(void){
    
    //enter x1,x2,y1,y2
    double x1,x2,y1,y2;
    std::cout << "Enter x1: ";
    std::cin >> x1;
    std::cout << "Enter y1: ";
    std::cin >> y1;
    std::cout << "Enter x2: ";
    std::cin >> x2;
    std::cout << "Enter y2: ";
    std::cin >> y2;
    
    std::cout << "Points (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") entered." << std::endl;
    
    //calculate slope, midpoint
    double m,x_half,y_half;
    m = (y2-y1)/(x2-x1);
    x_half = x1 + (x2-x1)/2;
    y_half = y1 + (y2-y1)/2;
    
    
    
    if(std::abs(m - 0) < std::numeric_limits<double>::epsilon()){
        m = 0;
    }
    
    std::cout << "m = " << m << std::endl;
    
    //print midpoint
    std::cout << "Midpoint = (" << x_half << ", " << y_half << ")" << std::endl;
    
    //error messages
    if((std::abs(x1 - x2) < std::numeric_limits<double>::epsilon())&&(std::abs(y1 - y2) < std::numeric_limits<double>::epsilon())){
        std::cout << "Fatal Error: You need two distinct points to form linear equation.";
    }else if((std::abs(x1 - x2) < std::numeric_limits<double>::epsilon())){
        std::cout << "Error: x1 = x2. Slope is infinity." << "\n";
        std::cout << "Linear equation: x = " << x1 << "\n";
        std::cout << "Perpendicular equation at (" << x1 << ", " << y1 << "): ";
        std::cout << "y = " << y1;
    }else if((std::abs(y1 - y2) < std::numeric_limits<double>::epsilon())){
        std::cout << "Error: y1 = y2. Perpendicular slope is infinity." << "\n";
        std::cout << "Linear equation: y = " << y1 << "\n";
        std::cout << "Perpendicular equation at (" << x1 << ", " << y1 << "): ";
        std::cout << "x = " << x1;
    }else{
        
        std::cout << "Slope: " << m << "\n";
        
        //calculate intercept
        double b,mp,pb;
        b = y1-m*x1;
        mp = -1/m;
        pb = y1-mp*x1;
        
        std::cout << "y intercept: " << b << "\n";
        
        //write linear equation
        std::cout << "Linear equation: y = ";
        if(std::abs(m - 1) < std::numeric_limits<double>::epsilon()){
            std::cout << "x";
        }else if(std::abs(m - (-1)) < std::numeric_limits<double>::epsilon()){
            std::cout << "-x";
        }else if(m<0||m>0){
            std::cout << m << "x";
        }
        
        if(m!=0){
            if(b<0){
                std::cout << " - " << -b;
            }else if(b>0){
                std::cout << " + " << b;
            }
        }
        
        //write perpendicular equation
        std::cout << "\n"<< "Perpendicular equation at (" << x1 << ", " << y1 << "): ";
        if(std::abs(mp - 1) < std::numeric_limits<double>::epsilon()){
            std::cout << "y = x";
        }else if(std::abs(mp - (-1)) < std::numeric_limits<double>::epsilon()){
            std::cout << "y = -x";
        }else if(mp<0||mp>0){
            std::cout << "y = " << mp << "x";
        }
        
        if(mp!=0){
            if(pb<0){
                std::cout << " - " << -pb;
            }else if(pb>0){
                std::cout << " + " << pb;
            }
        }
    }
    std::cout << "\n" << "DONE!" << std::endl;
    return 0;
}