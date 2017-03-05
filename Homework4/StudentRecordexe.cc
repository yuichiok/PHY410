#include <fstream>
#include <vector>
#include <iostream>
#include "StudentRecord.h"

int main( int argc, char * argv[] ){
    
    std::ifstream in( argv[1] );
    
    //std::string first,last;
    float score=0.;
    
    std::vector<std::string> first,last;
    std::vector<float> scorevec;
    
    
    
    while (in.is_open()){
        
        std::string line;
        
        std::getline( in, line, ',');
        
        if (line == ""){
            in.close();
        }else{
            
            last.push_back(line);
            std::getline( in, line, ',');
            first.push_back(line);
            std::getline( in, line );
            score = std::atof( line.c_str() );
            scorevec.push_back(score);
            
        }
        
    }
    
    std::cout << "Out of loop" << std::endl;
    
    int ivec = 0;
    
    ivec = last.size();
    
    for(int j = 0; j < ivec; j++){
        std::cout << "row " << j+1 << std::endl;
        std::cout << "last name: " << last[j] << std::endl;
        std::cout << "first name: " << first[j] << std::endl;
        std::cout << "score: " << scorevec[j] << std::endl;
    }
    
    
    //StudentRecord p1( line );
    
    //std::cout << " Last name: " << p1.last() << "\n First name: " << p1.first() << std::endl;
    
    //p1.print();
    
    return 0;
    
}






















