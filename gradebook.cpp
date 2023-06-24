#include "gradebook.h"


GradeBook::GradeBook(std::vector<std::vector<std::pair<std::string,int>>>){

}

GradeBook::~GradeBook(){

}

int GradeBook::getCatSize(int category){

    return this -> gradebook[category].size();

}

void GradeBook::FinalAverage(){

}

void GradeBook::CategoryAverage(int category){

}

void GradeBook::printCategory(int category){

    std::cout << "The grades in this category are as follows\n";

    for(int i = 0; i < getCatSize(category);i++){

        std::cout << gradebook[category][i].first << " " << gradebook[category][i].second << " ";

    }

    std::cout << std::endl;

}

bool GradeBook::nameCheck(int category,std::string aname){
    //checks if given name exists in category and returns true or false appropriately

    for(int i = 0; i < this -> getCatSize(category); i++){

        if(this-> gradebook[category][i].first == aname){
            return true;
        }

    }

    return false;

}

void GradeBook::addAssignment(int category,int grade,std::string aname){
    //create new pair and add it to the end of the category
    std::pair<std::string,int> newA (aname,grade);
    this->gradebook[category].push_back(newA);

}

void GradeBook::removeAssignment(int category,std::string aname){
    //finds the desired assignment in the gradebook and deletes it
    for(int i = 0; i < this -> getCatSize(category); i++){

        if(this-> gradebook[category][i].first == aname){
            this -> gradebook[category].erase(gradebook[category].begin()+i);
            break;
        }

    }

}

void GradeBook::changeAssignment(int category,std::string aname, int grade){

}

void GradeBook::printGradebook(std::string name,std::fstream& txt){

}