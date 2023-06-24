#include "gradebook.h"


GradeBook::GradeBook(std::vector<std::vector<std::pair<std::string,int>>> temp){
    this->gradebook = temp;
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
    int size = this->gradebook[category].size();
    for (int i = 0; i < size; i++) {
        if (this->gradebook[category][i].first == aname) {
            gradebook[category][i].second = grade;
        }
    }
}

void GradeBook::printGradebook(std::string name,std::fstream& txt){
    txt << "Student Name: " << name << std::endl;
    txt << "Class: " << "CSC212" << std::endl;
    txt << "Current Grade: " << "00" << std::endl << std::endl; //CHANGE LATER
    txt << "Projects: P1 0 P2 " << gradebook[0][1].second << std::endl << std::endl;
    txt << "Assignments: A1 0 A2 0 A3 0 A4 0" << std::endl << std::endl;
    txt << "Labs: L1 0 L2 0 L3 0 L4 0 L5 0 L6 0 L7 0 L8 0" << std::endl << std::endl;
    txt << "Final Exam: FE 00";
}