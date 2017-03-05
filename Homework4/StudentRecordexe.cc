#include <fstream>
#include <vector>
#include <iostream>
#include "StudentRecord.h"

float calculate_average(std::vector<StudentRecord> *rcd){
    
    int size = 0;
    double sum,avg = 0;
    size = rcd->size();
    
    for (int n = 0; n < size; n++) {
        
        sum += rcd->at(n).score();
        
    }
    
    avg = sum / size;
    
    return avg;
    
}

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
    
    //std::cout << "Out of loop" << std::endl;
    
    int ivec = 0;
    
    ivec = last.size();
    
    for(int j = 0; j < ivec; j++){
        
        std::cout << std::endl;
        std::cout << "Subject " << j+1 << std::endl;
        StudentRecord p(last[j],first[j],scorevec[j]);
        p.print();
        record.push_back(p);
        
    }
    
    double result =0;
    
    result = calculate_average( &record );
    
    std::cout << "avg = " << result << std::endl;
    
    
    return 0;
    
}






















