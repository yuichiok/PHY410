#include "StudentRecordPhysics.h"

StudentRecordPhysics::StudentRecordPhysics(){};
StudentRecordPhysics::~StudentRecordPhysics() {};

void StudentRecordPhysics::print( /*std::ostream & out*/  ) const  {
    std::cout << "Physics score : " << lastname_ << "," << firstname_
      << ", total: " << scorerec() << std::endl;
}

bool StudentRecordPhysics::input( std::istream & in )  {
  // First add name (last,first)
  double score1,score2=0.;
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  // Now get each score. Physics has two
  std::getline( in, line, ',' );
  score1 = std::atof( line.c_str() )*0.8;
  std::getline( in, line );
  score2 = std::atof( line.c_str() )*0.2;
    scorerec_ = score1 + score2;
  scores_.push_back( scorerec_ );
  if ( line == "") 
    return false;
  else {      
    compute_score();                     // Make sure to call compute_score in input!
    return true;
  }
}

double StudentRecordPhysics::scorerec() const { return scorerec_; }