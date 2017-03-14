#include "StudentRecordHistory.h"

StudentRecordHistory::StudentRecordHistory(){};
StudentRecordHistory::~StudentRecordHistory() {};

void StudentRecordHistory::print( /*std::ostream & out*/  ) const  {
    std::cout << "History score : " << lastname_ << "," << firstname_
      << ", total: " << scorerec() << std::endl;
}

bool StudentRecordHistory::input( std::istream & in )  {
  // First add name (last,first)
  double score1,score2=0.;
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  // Now get each score. History has two
  std::getline( in, line, ',' );
  score1 = std::atof( line.c_str() );
  std::getline( in, line );
  score2 = std::atof( line.c_str() );
    if (score1 <= score2) {
        score1 *= 0.4;
        score2 *= 0.6;
    }else if(score1 > score2){
        score1 *= 0.6;
        score2 *= 0.4;
    }
    scorerec_ = score1 + score2;
  scores_.push_back( scorerec_ );
  if ( line == "") 
    return false;
  else {      
    compute_score();                     // Make sure to call compute_score in input!
    return true;
  }
}

double StudentRecordHistory::scorerec() const { return scorerec_; }
