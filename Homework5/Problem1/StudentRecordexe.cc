#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"
#include "StudentRecordHistory.h"

int main( int argc, char * argv[] ){
    
    //declare variables
    std::string line,sub;
    
    StudentRecordPhysics phy;
    StudentRecordLiterature lit;
    StudentRecordHistory hist;
    std::vector<StudentRecordPhysics> vecphy;
    std::vector<StudentRecordLiterature> veclit;
    std::vector<StudentRecordHistory> vechist;
    
    //input
    std::ifstream in( argv[1] );
    
    while( getline(in,line,'\n') ){
        
        std::istringstream sline( line );
        getline(sline,sub,',');
        if ( sub.compare("Physics") == 0 ) {
            phy.input(sline);
            phy.print();
        }else if( sub.compare("Literature") == 0 ){
            lit.input(sline);
            lit.print();
        }else if( sub.compare("History") == 0 ){
            hist.input(sline);
            hist.print();
        }
        
    }
    
    std::cout << std::endl;
    std::cout << "Overall Average" << std::endl;
    std::cout << "Physics: " << phy.score() << std::endl;
    std::cout << "Literature: " << lit.score() << std::endl;
    std::cout << "History: " << hist.score() << std::endl;
    
    
    return 0;
    
}

