#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "StudentRecord.h"

float calculate_average(std::vector<StudentRecord> *rcd);

int main( int argc, char * argv[] ){
    
    StudentRecord testrec;
    
    std::vector<StudentRecord> record;
    
    std::ifstream in( argv[1] );
    
    while(testrec.input(in)){
        
        record.push_back(testrec);
        
    }
    
    int ivec = 0;
    ivec = record.size();
    
    if( argc == 2 ){
        for(int j = 0; j < ivec; j++){
            
            std::cout << std::endl;
            std::cout << "Subject " << j+1 << std::endl;
            record.at(j).print();
            
        }
    }else if( argc == 3 ){
        
        int index = 0;
        index = atoi(argv[2])-1;
        
        if (index > ivec-1) {
            std::cout << std::endl;
            std::cout << "Error: your index is larger than number of subjects.\n";
        }else{
            std::cout << std::endl;
            std::cout << "Subject " << index+1 << std::endl;
            record.at(index).print();
        }
        
    }
    
    double result =0;
    
    result = calculate_average( &record );
    
    std::cout << "\navg = " << result << "\n" << std::endl;
    
    return 0;
    
}

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

