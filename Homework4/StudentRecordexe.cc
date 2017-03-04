#include <fstream>
#include <iostream>
#include "StudentRecord.h"

/*bool input ( std::istream & in ) {
    std::string line;
    std::getline( in, line, ',');
    firstname_ = line;
    std::getline( in, line, ',');
    lastname_ = line;
    std::getline( in, line );
    score_ = std::atof( line.c_str() );
    if ( line == "")
        return false;
    else
        return true;
}*/

int main( int argc, char * argv[] ){
    
    std::ifstream in( argv[1] );
    
    std::string first,last;
    float score=0.;
    
    while (in.is_open()){
        
        std::string line;
        std::cout << "Last name: " << last << std::endl;
        std::getline( in, line, ',');
        last = line;
        
        std::getline( in, line, ',');
        first = line;
        std::getline( in, line );
        score = std::atof( line.c_str() );
        
        if (line == ""){
            in.close();
        }
    }
    
    std::cout << "Out of loop" << std::endl;
    
    
    
    
    
    
    
    //StudentRecord p1( line );
    
    //std::cout << " Last name: " << p1.last() << "\n First name: " << p1.first() << std::endl;
    
    //p1.print();
    
    return 0;
    
}






















