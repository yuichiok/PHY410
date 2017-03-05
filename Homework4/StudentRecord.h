#ifndef StudentRecord_h
#define StudentRecord_h

#include <fstream>
#include <vector>
#include <iostream>

class StudentRecord {
    
public:
    StudentRecord( std::string ln = "", std::string fn = "", float iscore = 0. );
    ~StudentRecord();
    
    void print() const;
    
    std::string last() const;
    std::string first() const;
    float score() const;
    
    bool input ( std::istream & in );
    
private:
    std::string lastname_;
    std::string firstname_;
    float score_;
    
};

#endif

