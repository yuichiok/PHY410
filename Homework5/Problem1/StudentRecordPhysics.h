#ifndef StudentRecordPhysics_h
#define StudentRecordPhysics_h

#include "StudentRecord.h"

class StudentRecordPhysics : public StudentRecord {
  
 public:

    StudentRecordPhysics();
    ~StudentRecordPhysics();

  virtual void print() const;

  virtual bool input( std::istream & in );
    
    virtual double scorerec() const;
};

#endif
