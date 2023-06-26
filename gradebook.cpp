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

    double GradeBook::FinalAverage(){
        int size;
        double sum, fin = 0;
        for (int i = 0; i < 4; i++) {
            size = gradebook[i].size();
            sum = 0;
            for (int j = 0; j < size; j++) {
                if(i!=0) {
                    sum += gradebook[i][j].second;
                }
                else if(j==0){
                    //first project
                    sum += gradebook[i][j].second*.3;
                }
                else{
                    //second project
                    sum += gradebook[i][j].second*.7;
                }
            }
            if(i!=0){
                sum /= size;
            }

            switch (i) {
                case 0:
                    //Projects are worth half of your grade
                    sum /= 2;
                    break;
                case 1:
                    //Assignments are worth a fifth of your grade
                    sum /= 5;
                    break;
                case 2:
                    //Labs are worth a fifth of your grade
                    sum /= 5;
                    break;
                case 3:
                    //Exams are worth a tenth of your grade
                    sum /= 10;
                    break;
            }
            fin += sum;

        }
        return fin;

    }

    double GradeBook::CategoryAverage(int cat) {
        if (cat == 1) {
            int size = gradebook[cat].size();
            double sum = 0;
            //first project
            sum += gradebook[0][0].second*.3;
            //second project
            sum += gradebook[0][1].second*.7;
            return sum;
        } else if (cat == 2) {
            int size = gradebook[cat].size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                sum += gradebook[1][i].second;
            }
            sum /= size;
            return sum;
        } else if (cat == 3) {
            int size = gradebook[cat].size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                gradebook[2][i].second;
            }
            sum /= size;
            return sum;
        } else {
            int size = gradebook[cat].size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                gradebook[3][i].second;
            }
            sum /= size;
            return sum;
        }
    }

    void GradeBook::printCategory(int category) {

        std::cout << "The grades in this category are as follows\n";

        for (int i = 0; i < getCatSize(category); i++) {

            std::cout << gradebook[category][i].first << " " << gradebook[category][i].second << " ";

        }

        std::cout << std::endl;

    }

    void GradeBook::printAssignment(int category, std::string aname) {

        for (int i = 0; i < this->getCatSize(category); i++) {

            if (this->gradebook[category][i].first == aname) {
                std::cout << gradebook[category][i].first << " " << gradebook[category][i].second << "\n";
                return;
            }

        }

    }

    bool GradeBook::nameCheck(int category, std::string aname) {
        //checks if given name exists in category and returns true or false appropriately

        for (int i = 0; i < this->getCatSize(category); i++) {

            if (this->gradebook[category][i].first == aname) {
                return true;
            }

        }

        return false;

    }

    void GradeBook::addAssignment(int category, int grade, std::string aname) {
        //create new pair and add it to the end of the category
        std::pair<std::string, int> newA(aname, grade);
        this->gradebook[category].push_back(newA);

    }

    void GradeBook::removeAssignment(int category, std::string aname) {
        //finds the desired assignment in the gradebook and deletes it
        for (int i = 0; i < this->getCatSize(category); i++) {

            if (this->gradebook[category][i].first == aname) {
                this->gradebook[category].erase(gradebook[category].begin() + i);
                break;
            }

        }

    }

    void GradeBook::changeAssignment(int category, std::string aname, int grade) {
        //Find how many assignments are in the category then check each assignment
        int size = this->gradebook[category].size();
        for (int i = 0; i < size; i++) {
            //All assignments that have the name the user input will change to the value the user input
            if (this->gradebook[category][i].first == aname) {
                gradebook[category][i].second = grade;
            }
        }
    }

    void GradeBook::printGradebook(std::string name, std::fstream &txt) {
        int size;
        //Starts by just printing the student name, class and current grade
        txt << "Student Name: " << name << std::endl;
        txt << "Class: " << "CSC212" << std::endl;
        txt << "Current Grade: " << this->FinalAverage() << std::endl << std::endl; //CHANGE LATER
        //Cycles through all prints all categories
        for (int i = 0; i < 4; i++) {
            switch (i) {
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
            //Cycles through and prints all grades for category
            for (int j = 0; j < size; j++) {
                txt << " " << gradebook[i][j].first << " " << gradebook[i][j].second;
            }

            if (i != 3) {
                txt << std::endl << std::endl;
            }
        }
    }
