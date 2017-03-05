#include <fstream>
#include <vector>
#include <iostream>
#include "StudentRecord.h"















int main( int argc, char * argv[] ){
    
    std::ifstream in( argv[1] );
    
    float score=0.;
    
    std::vector<std::string> first,last;
    std::vector<float> scorevec;
    std::vector<StudentRecord> record;
    
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
        
        //std::cout << "row " << j+1 << std::endl;
        StudentRecord p(last[j],first[j],scorevec[j]);
        //p.print();
        record.push_back(p);
        
    }
    
    //record.at(1).print();
    
    int irecord = 0;
    
    irecord = record.size();
    
    for (int k = 0; k < irecord; k++) {
        
        std::cout << "Score for person " << k+1 << " is ";
        std::cout << record.at(k).score() << std::endl;
        
    }
    
    
    
    return 0;
    
}






















