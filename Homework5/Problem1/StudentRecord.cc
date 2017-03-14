#include "StudentRecord.h"
#include <fstream>
#include <vector>
#include <iostream>

StudentRecord::StudentRecord(){}
StudentRecord::~StudentRecord(){}

std::string StudentRecord::last() const { return lastname_; }
std::string StudentRecord::first() const { return firstname_; }
double StudentRecord::score() const { return score_; }

void StudentRecord::compute_score(void) {
    
    if ( scores_.size() == 0 ) {
        return ;
    }
    
    score_ = 0.0;
    for ( unsigned int i = 0; i < scores_.size(); ++i ) {
        double iscore = scores_[i];
        score_ += iscore;
    }
    score_ /= scores_.size();
    
}