#include <iostream>

int main(void){
    int i;
    
    while(1){
        std::cout << "Enter number: ";
        std::cin  >> i;
        if( !std::cin.fail() ) break;
        std::cin.clear();    // エラーをリセットします。
        std::cin.ignore( 1024, '\n' );
    }
    
    std::cout << "your number is " << i << std::endl;

    return 0;
}
