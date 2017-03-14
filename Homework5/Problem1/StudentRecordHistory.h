#ifndef StudentRecordHistory_h
#define StudentRecordHistory_h

#include "StudentRecord.h"

class StudentRecordHistory : public StudentRecord {
  
 public:

    StudentRecordHistory();
    ~StudentRecordHistory();

  virtual void print() const;

  virtual bool input( std::istream & in );
    
  virtual double scorerec() const;
};

#endif
