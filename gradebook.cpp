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

void GradeBook::printAssignment(int category,std::string aname){

    for(int i = 0; i < this -> getCatSize(category); i++){

        if(this-> gradebook[category][i].first == aname){
            std::cout << gradebook[category][i].first << " " << gradebook[category][i].second << "\n";
            return;
        }

    }


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
    int size;

    txt << "Student Name: " << name << std::endl;
    txt << "Class: " << "CSC212" << std::endl;
    txt << "Current Grade: " << "00" << std::endl << std::endl; //CHANGE LATER

    for (int i = 0; i < 4; i++) {
        switch(i) {
            case 0:
                txt << "Projects:";
                break;
            case 1:
                txt << "Assignments:";
                break;
            case 2:
                txt << "Labs:";
                break;
            case 3:
                txt << "Final Exam:";
                break;
            default:
                std::cout << "Error: printGradebook switch" << std::endl;
        }

        size = this->gradebook[i].size();

        for (int j = 0; j < size; j++) {
            txt << " " << gradebook[i][j].first << " " << gradebook[i][j].second;
        }

        if (i != 3) {
            txt << std::endl << std::endl;
        }
    }
}