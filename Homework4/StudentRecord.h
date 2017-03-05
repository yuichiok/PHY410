#ifndef StudentRecord_h
#define StudentRecord_h

#include <fstream>
#include <vector>
#include <iostream>

class StudentRecord {
 public:
    StudentRecord( std::vector<std::string> ln, std::vector<std::string> fn, std::vector<float> iscore );
    ~StudentRecord();
    
    void print() const;
    
    //bool input( std::istream & inp );
    
    //void input( char textfile );
    
    std::string last() const;
    std::string first() const;
    float score() const;
    
 private:
    std::vector<std::string> lastname_;
    std::vector<std::string> firstname_;
    std::vector<float> score_;
    //std::ifstream read_;

};

#endif

