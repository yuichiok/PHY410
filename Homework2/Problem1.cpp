#include <iostream>
#include <stdlib.h>

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
    
    //calculate slope
    double m;
    m = (y2-y1)/(x2-x1);
    
    //error messages
    if(x1==x2&&y1==y2){
        std::cout << "Fatal Error: You need two distinct points to form linear equation." << std::endl;
    }else if(x1==x2){
        std::cout << "Error: x1 = x2" << "\n";
    }else{
        
        std::cout << "m = " << m << "\n";
        
        //calculate intercept
        double b;
        b = y1-m*x1;
        
        std::cout << "b = " << b << "\n";
        
        //write down equation
        std::cout << "y = ";
        if(m==1){
            std::cout << "x";
        }else if(m==-1){
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
        
        if(m==0){
            if(b==0){
                std::cout << "0";
            }else if(b!=0){
                std::cout << b;
            }
        }
        
        
        std::cout << "\n" << "DONE!" << std::endl;
    }
    return 0;
}