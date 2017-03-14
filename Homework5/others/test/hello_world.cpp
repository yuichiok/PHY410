#include <fstream>
#include <vector>
#include <iostream>

#include <sstream>

int main( int argc, char * argv[] ){

    std::ifstream in(argv[1]);

    std::string line = "";

    while( std::getline(in,line,'\n')  ){

std::istringstream sline(line);
std::string line2;
std::getline(sline,line2,',');
        
std::cout << "1." << line2 << std::endl;

getline(sline,line2,',');

std::cout << "2." << line2 << std::endl;

getline(sline,line2,'\n');

std::cout << "3." << line2 << std::endl;
        
//        if(line == "") in.close();
    }

    //std::string line1 = "Hello World!";
    //std::string sub   = "";

    //std::getline(line1,sub);

    //std::cout << "we have: " << sub << std::endl;
    

    
    return 0;
    
}
