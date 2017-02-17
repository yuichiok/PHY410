#include <iostream>
int main() {
    int value1;
    std::cout << "Please enter an integer from 1-20: ";
    std::cin >> value1;
    if(value1 == 19){
    std::cout << "You're correct!" << '\n';
    }else{std::cout << "You're wrong!" << '\n';}
}
