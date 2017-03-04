#include "StudentRecord.h"

StudentRecord::StudentRecord( std::string ln, std::string fn, float iscore ){
    
    lastname_ = ln;
    firstname_= fn;
    score_ = iscore;
    
}

StudentRecord::~StudentRecord(){};

void StudentRecord::print() const{
    
    std::cout << "Last name: " << lastname_ << std::endl;
    std::cout << "First name: " << firstname_ << std::endl;
    
}

/*bool StudentRecord::input ( std::istream & inp ) {
    std::string line;
    std::getline( inp, line, ',');
    firstname_ = line;
    std::getline( inp, line, ',');
    lastname_ = line;
    std::getline( inp, line );
    score_ = std::atof( line.c_str() );
    if ( line == "")
        return false;
    else
        return true;
}*/





std::string StudentRecord::last() const { return lastname_; }
std::string StudentRecord::first() const { return firstname_; }
float StudentRecord::score() const { return score_; }
