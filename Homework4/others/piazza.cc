#include <fstream>
#include <iostream>

int main(){
     std::ifstream  input("inputfile.txt");
     std::string line, wrld = "";
     std::getline( input, line, ',');
     wrld = line;
     std::cout << "hello " << wrld << std::endl;
}
