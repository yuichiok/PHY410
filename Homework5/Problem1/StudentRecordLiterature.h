#ifndef StudentRecordLiterature_h
#define StudentRecordLiterature_h

#include "StudentRecord.h"

class StudentRecordLiterature : public StudentRecord {
    
public:
    
    StudentRecordLiterature();
    ~StudentRecordLiterature();
    
    virtual void print() const;
    
    virtual bool input( std::istream & in );
    
    virtual double scorerec() const;
};

#endif
