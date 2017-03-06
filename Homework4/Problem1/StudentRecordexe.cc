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
    
    StudentRecord testrec;
    
    std::vector<StudentRecord> record;
    
    std::ifstream in( argv[1] );
    
    while(testrec.input(in)){
        
        record.push_back(testrec);
        
    }
    
    int ivec = 0;
    ivec = record.size();
    
    for(int j = 0; j < ivec; j++){
        std::cout << std::endl;
        std::cout << "Subject " << j+1 << std::endl;
        record.at(j).print();
    }
    
    double result =0;
    
    result = calculate_average( &record );
    
    std::cout << "\navg = " << result << std::endl;
    
    return 0;
    
}

