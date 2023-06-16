#include "gradebook.h"

int main() {
    std::fstream txt;
    txt.open("gradebook.txt",std::fstream::in | std::fstream::out);

    std::vector<std::vector<std::pair<std::string,int>>> inputs;

    bool fin = false;
    int selected = 0;

    GradeBook Gbook(inputs);

    std::cout << "Welcome to your gradebook editor! What can we help you with today?\nTo select one of the commands below please enter the number next to the command" << std::endl;

    while(fin == false) {
        std::cout << "1. Get Final Average  2. Get Section Average 3. Add an Assignment to a category 4. Remove an Assignment from a category 5. Edit a Graded Assignment" << std::endl;
        std::cout << "If you would like to exit the editor and update your gradebook file please select 6" << std::endl;
        std::cin >> selected;

        //get final average
        if(selected == 1) {
            Gbook.FinalAverage();
        }

        //gets category average
        else if(selected == 2) {
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to print the average of?\n1. Projects 2. Assignments 3. Labs 4. Final Exam";

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            Gbook.CategoryAverage(cat);
        }

        //Add an assignment
        else if(selected == 3) {
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to print the average of?\n1. Projects 2. Assignments 3. Labs 4. Final Exam";

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            //gets grade for assignment
            int grade = -1;
            std::cout << "What grade did this assignment recieve(Please input a positive number less than 200)?\n";

            //make sure grade is a valid value
            while (grade < 0 || grade > 200) {
                std::cin >> grade;
                if (grade < 0) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            Gbook.addAssignment(cat, grade);

        }

        //delete an assignment
        else if(selected == 4) {
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to print the average of?\n1. Projects 2. Assignments 3. Labs 4. Final Exam";
            std::cin >> cat;

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            //get index to delete
            int idx = 0;
            std::cout << "Please enter the index of the number you would like to delete (0-" << Gbook.getCatSize(cat)-1 << ")\n";

            //make sure idx is within bounds
            while (idx < 0 || idx > Gbook.getCatSize(cat)-1) {
                std::cin >> idx;
                if (idx < 0 || idx > Gbook.getCatSize(cat)-1) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            Gbook.removeAssignment(cat,idx);

        }

        //changes assignmnet grade
        else if(selected == 5){
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to print the average of?\n1. Projects 2. Assignments 3. Labs 4. Final Exam";

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            //gets grade for assignment
            int grade = -1;
            std::cout << "What grade did this assignment recieve(Please input a positive number less than 200)?\n";

            //make sure grade is a valid value
            while (grade < 0 || grade > 200) {
                std::cin >> grade;
                if (grade < 0) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            //get index to change
            int idx = 0;
            std::cout << "Please enter the index of the number you would like to delete (0-" << Gbook.getCatSize(cat)-1 << ")\n";

            //make sure idx is within bounds
            while (idx < 0 || idx > Gbook.getCatSize(cat)-1) {
                std::cin >> idx;
                if (idx < 0 || idx > Gbook.getCatSize(cat)-1) {
                    std::cout << "Invalid character or value entered! Please try again.";
                }
            }

            Gbook.changeAssignment(cat,grade,idx);
        }
        //end loop
        else if(selected == 6){
            fin = true;
            break;
        }
        else{
            std::cout << "Invalid character or value enetered! Please try again.\n";
            continue;
        }

    }

    std::cout << "Now updating your file!\n";
    Gbook.printGradebook();
    std::cout << "Thank you for using our gradebook editor!\n";

}

