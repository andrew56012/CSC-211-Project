#include "gradebook.h"
#include <vector>


GradeBook::GradeBook(std::vector<std::vector<std::pair<std::string,int>>> inputs){
    //Creating the weight for each of the categories
    //Labs = 20%
    weights.push_back(std::make_pair("Labs", .20));
    //Assignments = 20%
    weights.push_back(std::make_pair("Assignments", .20));
    //Projects = 50%
    weights.push_back(std::make_pair("Projects", .50));
    //Final Exam = 10%
    weights.push_back(std::make_pair("Final Exam", .10));

    this->gradebook = inputs;
}

GradeBook::~GradeBook(){

}

int GradeBook::getCatSize(int category){

    return this -> gradebook[category].size();

}

void GradeBook::FinalAverage(){
    double final_number;
    final_number = 0;
    std::string FinalAverage = " ";
    std::cout << "Input all of your scores please. " << std::endl;
    for(int i = 1; i < 15; i++){
        final_number += GradeBook[i];
    }
    final_number = final_number/1000;
    final_number = final_number * 100;

    if(final_number >= 93.0){
        FinalAverage = "A";
    }
    else if(final_number >= 90.0 || final_number < 94.0){
        FinalAverage = "A-";
    }
    else if(final_number >= 87.0 || final_number < 89.0){
        FinalAverage = "B+";
    }
    else if(final_number >= 83.0 || final_number < 87.0){
        FinalAverage = "B";
    }
    else if(final_number >= 80.0 || final_number < 83.0){
        FinalAverage = "B-";
    }
    else if(final_number >= 77.0 || final_number < 80.0){
        FinalAverage = "C+";
    }
    else if(final_number >= 73.0 || final_number < 77.0){
        FinalAverage = "C";
    }
    else if(final_number >= 70.0 || final_number < 73.0){
        FinalAverage = "C-";
    }
    else if(final_number >= 67.0 || final_number < 70.0){
        FinalAverage = "D+";
    }
    else if(final_number >= 60.0 || final_number < 67.0){
        FinalAverage = "D";
    }
    else {
        FinalAverage = "F";
    }

    std::cout << "\nFinal Average: " << FinalAverage << std::endl;
}

void GradeBook::CategoryAverage(int category){
if(selected == 1) {
    double number;
    number = 0;
    std::string CategoryAverage = " ";
    std::cout << "Input all of your scores please. " << std::endl;
    for(int i = 1; i < 2; i++){
        number += GradeBook[i];
    }
    number = number/500;
    number = number * 100;
    if(number >= 93.0){
        CategoryAverage = "A";
    }
    else if(number >= 90.0 || number < 94.0){
        CategoryAverage = "A-";
    }
    else if(number >= 87.0 || number < 89.0){
        CategoryAverage = "B+";
    }
    else if(number >= 83.0 || number < 87.0){
        CategoryAverage = "B";
    }
    else if(number >= 80.0 || number < 83.0){
        CategoryAverage = "B-";
    }
    else if(number >= 77.0 || number < 80.0){
        CategoryAverage = "C+";
    }
    else if(number >= 73.0 || number < 77.0){
        CategoryAverage = "C";
    }
    else if(number >= 70.0 || number < 73.0){
        CategoryAverage = "C-";
    }
    else if(number >= 67.0 || number < 70.0){
        CategoryAverage = "D+";
    }
    else if(number >= 60.0 || number < 67.0){
        CategoryAverage = "D";
    }
    else {
       CategoryAverage = "F";
    }
    std::cout << "\nProjects Average: " << CategoryAverage << std::endl;
    }
elseif(selected == 2) {
    double number;
    number = 0;
    std::string CategoryAverage = " ";
    std::cout << "Input all of your scores please. " << std::endl;
    for(int i = 1; i < 4; i++){
        number += GradeBook[i];
    }
    number = number/200;
    number = number * 100;
    if(number >= 93.0){
        CategoryAverage = "A";
    }
    else if(number >= 90.0 || number < 94.0){
        CategoryAverage = "A-";
    }
    else if(number >= 87.0 || number < 89.0){
        CategoryAverage = "B+";
    }
    else if(number >= 83.0 || number < 87.0){
        CategoryAverage = "B";
    }
    else if(number >= 80.0 || number < 83.0){
        CategoryAverage = "B-";
    }
    else if(number >= 77.0 || number < 80.0){
        CategoryAverage = "C+";
    }
    else if(number >= 73.0 || number < 77.0){
        CategoryAverage = "C";
    }
    else if(number >= 70.0 || number < 73.0){
        CategoryAverage = "C-";
    }
    else if(number >= 67.0 || number < 70.0){
        CategoryAverage = "D+";
    }
    else if(number >= 60.0 || number < 67.0){
        CategoryAverage = "D";
    }
    else {
       CategoryAverage = "F";
    }
    std::cout << "\nAssignments Average: " << CategoryAverage << std::endl;
        }
elseif(selected == 3) {
    double number;
    number = 0;
    std::string CategoryAverage = " ";
    std::cout << "Input all of your scores please. " << std::endl;
    for(int i = 1; i < 8; i++){
        number += GradeBook[i];
    }
    number = number/200;
    number = number * 100;
    if(number >= 93.0){
        CategoryAverage = "A";
    }
    else if(number >= 90.0 || number < 94.0){
        CategoryAverage = "A-";
    }
    else if(number >= 87.0 || number < 89.0){
        CategoryAverage = "B+";
    }
    else if(number >= 83.0 || number < 87.0){
        CategoryAverage = "B";
    }
    else if(number >= 80.0 || number < 83.0){
        CategoryAverage = "B-";
    }
    else if(number >= 77.0 || number < 80.0){
        CategoryAverage = "C+";
    }
    else if(number >= 73.0 || number < 77.0){
        CategoryAverage = "C";
    }
    else if(number >= 70.0 || number < 73.0){
        CategoryAverage = "C-";
    }
    else if(number >= 67.0 || number < 70.0){
        CategoryAverage = "D+";
    }
    else if(number >= 60.0 || number < 67.0){
        CategoryAverage = "D";
    }
    else {
       CategoryAverage = "F";
    }
    std::cout << "\nLabs Average: " << CategoryAverage << std::endl;
        }
else{
    double number;
    number = 0;
    std::string CategoryAverage = " ";
    std::cout << "Input all of your scores please. " << std::endl;
    for(int i = 1; i < 1; i++){
        number += GradeBook[i];
    }
    number = number/100;
    number = number * 100;
    if(number >= 93.0){
        CategoryAverage = "A";
    }
    else if(number >= 90.0 || number < 94.0){
        CategoryAverage = "A-";
    }
    else if(number >= 87.0 || number < 89.0){
        CategoryAverage = "B+";
    }
    else if(number >= 83.0 || number < 87.0){
        CategoryAverage = "B";
    }
    else if(number >= 80.0 || number < 83.0){
        CategoryAverage = "B-";
    }
    else if(number >= 77.0 || number < 80.0){
        CategoryAverage = "C+";
    }
    else if(number >= 73.0 || number < 77.0){
        CategoryAverage = "C";
    }
    else if(number >= 70.0 || number < 73.0){
        CategoryAverage = "C-";
    }
    else if(number >= 67.0 || number < 70.0){
        CategoryAverage = "D+";
    }
    else if(number >= 60.0 || number < 67.0){
        CategoryAverage = "D";
    }
    else {
       CategoryAverage = "F";
    }
    std::cout << "\nFinal Exam: " << CategoryAverage << std::endl;
}
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
