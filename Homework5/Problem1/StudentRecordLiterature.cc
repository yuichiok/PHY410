#include "StudentRecordLiterature.h"

StudentRecordLiterature::StudentRecordLiterature(){};
StudentRecordLiterature::~StudentRecordLiterature() {};

void StudentRecordLiterature::print( /*std::ostream & out*/ ) const  {
    std::cout << "Literature score : " << lastname_ << "," << firstname_
      << ", total: " << scorerec() << std::endl;
}

bool StudentRecordLiterature::input( std::istream & in )  {
  // First add name (last,first)
  std::string line;
  double score1,score2,score3=0.;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  // Now get each score. Literature has three, with weights 0.4, 0.4, 0.2
  std::getline( in, line, ',' );
  score1 = std::atof( line.c_str() )*0.4;
  std::getline( in, line, ',' );
  score2 = std::atof( line.c_str() )*0.4;
  std::getline( in, line );
  score3 = std::atof( line.c_str() )*0.2;
    scorerec_ = score1 + score2 + score3;
  scores_.push_back( scorerec_ );
  if ( line == "") 
    return false;
  else {
    compute_score();
    return true;
  }
}

double StudentRecordLiterature::scorerec() const { return scorerec_; }