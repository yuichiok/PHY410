#ifndef StudentRecord_h
#define StudentRecord_h

#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>

class StudentRecord {
    
public:
    StudentRecord();
    ~StudentRecord();
    
    virtual void print() const = 0;
    virtual bool input ( std::istream & in ) = 0;
    virtual double scorerec() const = 0;
    
    std::string last() const;
    std::string first() const;
    double score() const;
    
protected:
    std::string subject_;
    std::string lastname_;
    std::string firstname_;
    std::vector<double> scores_;
    double score_;
    double scorerec_;
    
    void compute_score(void);
    
};

#endif

