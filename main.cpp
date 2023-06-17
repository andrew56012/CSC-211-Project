#include "gradebook.h"

int main() {
    //get info from gradebook
    std::fstream txt;
    txt.open("gradebook.txt",std::fstream::in | std::fstream::out);

    std::vector<std::vector<std::pair<std::string,int>>> inputs;
    std::vector<std::pair<std::string,int>> step1;
    std::vector<std::string> given;

    std::string enter;
    int count = 0;
    //put everting into a base vector
    while(std::getline(txt,enter)){
        given.push_back(enter);
    }

    //get student name
    std::string name = given[0];
    name.erase(name.begin(),name.begin()+14);

    //delete unnecessary information from base (name, class name, current grade and spaces in between) (Leaves the graded categories)
    given.erase(given.begin(),given.begin()+4);
    given.erase(given.begin()+5);
    given.erase(given.begin()+3);
    given.erase(given.begin()+1);

    //delete unnecessary info from individual vectors left(name of category and initial spaces)
    given[0].erase(given[0].begin(),given[0].begin()+10);
    given[1].erase(given[1].begin(),given[1].begin()+14);
    given[2].erase(given[2].begin(),given[2].begin()+6);
    given[3].erase(given[3].begin(),given[3].begin()+12);

    std::pair<std::string,int> pair;

    //takes the info from the base vector and converts it into pairs of info with the assignment name and grade
    for(int i = 0; i < given.size(); i++){

        std::stringstream convert(given[i]);

        while(convert >> enter){
            if(count == 0){
                pair.first = enter;
                count++;
            }
            else{
                pair.second = std::stoi(enter);
                step1.push_back(pair);
                count--;
            }
        }

        inputs.push_back(step1);
        step1.clear();

    }

    //Output of above statement will look like (the
    //P1 0 P2 0
    //A1 0 A2 0 A3 0 A4 0
    //L1 0 L2 0 L3 0 L4 0 L5 0 L6 0 L7 0 L8 0
    //FE 0

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

            //get name
            std::string aname;
            std::cout << "Please enter the assignment name.\n";
            std::cin >> aname;

            Gbook.addAssignment(cat, grade, aname);

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