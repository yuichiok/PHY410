#include "StudentRecord.h"
#include <fstream>
#include <vector>
#include <iostream>


StudentRecord::StudentRecord( std::string ln, std::string fn, float iscore ){
    
    lastname_ = ln;
    firstname_= fn;
    score_ = iscore;
    
}

StudentRecord::~StudentRecord(){};

void StudentRecord::print() const{
    
    std::cout << "Last name: " << lastname_ << std::endl;
    std::cout << "First name: " << firstname_ << std::endl;
    std::cout << "Score: " << score_ << std::endl;
    
}








std::string StudentRecord::last() const { return lastname_; }
std::string StudentRecord::first() const { return firstname_; }
float StudentRecord::score() const { return score_; }