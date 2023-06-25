#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>

#ifndef CSC211P_GRADEBOOK_H
#define CSC211P_GRADEBOOK_H

class GradeBook {
private:
    std::vector<std::vector<std::pair<std::string,int>>> gradebook;


public:
    //constructor given the vector of info from the
    GradeBook(std::vector<std::vector<std::pair<std::string,int>>>);
    //deconstructor
    ~GradeBook();
    //gets the size of a categor in the gradebook
    int getCatSize(int category);
    //outputs the final average
    void FinalAverage();
    //given the category to output
    void CategoryAverage(int category);
    //prints category
    void printCategory(int category);
    //prints assignment
    void printAssignment(int category,std::string aname);
    //checks if name of assignment is in category
    bool nameCheck(int category,std::string aname);
    //given the category to add an assignment too
    void addAssignment(int category,int grade,std::string aname);
    //given the category to remove from and the assignment number to remove
    void removeAssignment(int category,std::string aname);
    //given the category and assignment number of grade to be changed
    void changeAssignment(int category,std::string aname, int grade);
    //Outputs the edited gradebook
    void printGradebook(std::string name,std::fstream& txt);

};

#endif //CSC211P_GRADEBOOK_H
