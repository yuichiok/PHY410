#include "StudentRecord.h"
#include <fstream>
#include <vector>
#include <iostream>


StudentRecord::StudentRecord( std::vector<std::string> ln, std::vector<std::string> fn, std::vector<float> iscore ){
    
    lastname_ = ln;
    firstname_= fn;
    score_ = iscore;
    
}

StudentRecord::~StudentRecord(){};

void StudentRecord::print() const{
    
    std::cout << "Last name: " << lastname_[0] << std::endl;
    std::cout << "First name: " << firstname_[0] << std::endl;
    
}

/*void input( char textfile ){
    
    std::ifstream in( textfile );
    
}*/







std::string StudentRecord::last() const { return lastname_[0]; }
std::string StudentRecord::first() const { return firstname_[0]; }
float StudentRecord::score() const { return score_[0]; }
