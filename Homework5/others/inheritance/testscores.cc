#include <iostream>
#include <fstream>
#include <vector>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"


int main(void) {
  std::vector<StudentRecord *> records; 
  StudentRecordPhysics p1,p2,p3; 
  StudentRecordLiterature p4,p5;

  std::cout << "Enter first physics student and 2 test scores" << std::endl;
  p1.input( std::cin );
  std::cout << "Enter second physics student and 2 test scores" << std::endl;
  p2.input( std::cin );
  std::cout << "Enter third physics student and 2 test scores" << std::endl;
  p3.input( std::cin );
  std::cout << "Enter first literature student and 3 test scores" << std::endl;
  p4.input( std::cin );
  std::cout << "Enter second literature student and 3 test scores" << std::endl;
  p5.input( std::cin );

  records.push_back( &p1 );
  records.push_back( &p2 );
  records.push_back( &p3 );
  records.push_back( &p4 );
  records.push_back( &p5 );

  double totalavg = 0.;
  for ( std::vector<StudentRecord *>::const_iterator i = records.begin();
	i != records.end(); ++i) {
    (*i)->print(std::cout);
    totalavg += (*i)->score();
  }
  totalavg /= records.size();

  std::cout << "Total GPA for this class is " << totalavg << std::endl;

  return 0; 
}
