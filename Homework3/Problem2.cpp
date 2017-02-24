#include <iostream>

double factorial(unsigned int x);

int main(void){
    
    //enter n
    unsigned int n=0;
    double calc = 0;
    
    while(1){
        std::cout << "Enter an interger between 0 to 20: ";
        std::cin >> n;
        if( !std::cin.fail()&& n <= 20 ) break; //breaks when undesired input has been entered
        std::cout << "Error: Number must be between 0 to 20 \n";
        std::cin.clear();    //reset cin value
        std::cin.ignore( 1024, '\n' ); //disregard strings
    }
    
    std::cout << std::string(60, '*') << std::endl;
    
    std::cout << "n  = " << n << std::endl;
    
    if(n == 0){
        std::cout << "n! = 1" << std::endl;
    }else{
        calc = factorial(n);
        std::cout << "n! = " << calc << std::endl;
    }
    
    std::cout << "\n" << "DONE!" << std::endl;
    return 0;
}

double factorial(unsigned int x){
    
    double facto = 1;
    int temp = 0;
    
    for (int i=0; i < x; i++) {
        temp = x - i;
        facto = facto*temp;
        //std::cout << "facto = " << facto << std::endl;
    }
    
    return facto;
    
}
