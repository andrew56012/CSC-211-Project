  #include "gradebook.h"

int main() {
    //get info from gradebook (entered by user)
    std::cout << "What file would you like to open?" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    std::fstream txt;
    txt.open(fileName,std::fstream::in | std::fstream::out);
    /* Testing
    if (txt.is_open()){
        std::cout << "Open successfully. The file name is " << fileName << std::endl;
    } else {
        std::cout << "Something went wrong" << std::endl;
    }
    */
    std::vector<std::vector<std::pair<std::string,int>>> inputs;
    std::vector<std::pair<std::string,int>> step1;
    std::vector<std::string> given;

    std::string enter;
    int count = 0;
    //put everything into a base vector
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
    given[1].erase(given[1].begin(),given[1].begin()+13);
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

    GradeBook Gbook(inputs);

    //Getting user inputs to direct the code

    bool fin = false;
    int selected = 0;

    std::cout << "Welcome to your gradebook editor! What can we help you with today?\nTo select one of the commands below please enter the number next to the command" << std::endl;

    while(fin == false) {
        std::cout << "1. Get Final Average  2. Get Section Average 3. Add an Assignment to a category 4. Output Category 5. Remove an Assignment from a category 6. Edit a Graded Assignment" << std::endl;
        std::cout << "If you would like to exit the editor and update your gradebook file please select 7" << std::endl;
        std::cin >> selected;

        //get final average
        if(selected == 1) {
            Gbook.FinalAverage();
        }

        //gets category average
        else if(selected == 2) {
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to print the average of?\n1. Projects 2. Assignments 3. Labs 4. Final Exam\n";

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.\n";
                }
            }
            cat--;

            if(Gbook.getCatSize(cat) == 0){
                std::cout << "No assignments exist in this category.\n";
                continue;
            }

            Gbook.CategoryAverage(cat);
        }

        //Add an assignment
        else if(selected == 3) {
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to add too?\n1. Projects 2. Assignments 3. Labs 4. Final Exam\n";

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.\n";
                }
            }
            cat--;

            //gets grade for assignment
            int grade = -1;
            std::cout << "What grade did this assignment recieve(Please input a positive number less than 200)?\n";

            //make sure grade is a valid value
            while (grade < 0 || grade > 200) {
                std::cin >> grade;
                if (grade < 0) {
                    std::cout << "Invalid character or value entered! Please try again.\n";
                }
            }

            //get name
            std::string aname;
            std::cout << "Please enter the assignment name.(This name cannot already exist in the category it will be added to!)\n";

            //ensure name does not already exist in category
            do{
                    if(Gbook.nameCheck(cat,aname) == true){
                        std::cout << "Assignment name already exists! Please try again.\n";
                    }
                    std::cin >> aname;
                }while(Gbook.nameCheck(cat,aname) == true);

            Gbook.addAssignment(cat, grade, aname);

        }

        //Prints category
        else if(selected == 4){
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to print?\n1. Projects 2. Assignments 3. Labs 4. Final Exam\n";
            std::cin >> cat;

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.\n";
                }
            }
            cat--;
            if(Gbook.getCatSize(cat) == 0){
                std::cout << "No assignments exist in this category.\n";
                continue;
            }

            Gbook.printCategory(cat);

        }

        //delete an assignment
        else if(selected == 5) {
            //gets category
            int cat = 0;
            std::cout << "Which category would you like to delete from?\n1. Projects 2. Assignments 3. Labs 4. Final Exam\n";
            std::cin >> cat;

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.\n";
                }
            }
            cat--;
            if(Gbook.getCatSize(cat) == 0){
                std::cout << "No assignments exist in this category.\n";
                continue;
            }

            //make sure name exists and get name
            std::string aname = "";
            std::cout << "Please enter the name of the assignment you would like deleted(Each assignments name is directly too the right of the assignment in the gradebook)\n";

            while(Gbook.nameCheck(cat,aname) == false){

                std::cin >> aname;

                if(Gbook.nameCheck(cat,aname) == false){
                    std::cout << "Invalid name entered! Please try again.\n";
                }

            }

            Gbook.removeAssignment(cat,aname);

        }

        //changes assignmnet grade
        else if(selected == 6){
            //gets category
            int cat = 0;
            std::cout << "Which category is the assignment you would like to change in?\n1. Projects 2. Assignments 3. Labs 4. Final Exam\n";

            //ensure valid category entered
            while (cat < 0 || cat > 4) {
                std::cin >> cat;
                if (cat < 0 || cat > 4) {
                    std::cout << "Invalid character or value entered! Please try again.\n";
                }
            }
            cat--;

            if(Gbook.getCatSize(cat) == 0){
                std::cout << "No assignments exist in this category.\n";
                continue;
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

            //make sure name exists and get name
            std::string aname = "";
            std::cout << "Please enter the name of the assignment you would like to change(Each assignments name is directly too the right of the assignment in the gradebook)\n";

            while(Gbook.nameCheck(cat,aname) == false){

                std::cin >> aname;

                if(Gbook.nameCheck(cat,aname) == false){
                    std::cout << "Invalid name entered! Please try again.\n";
                }

            }

            Gbook.changeAssignment(cat,aname,grade);
        }
        //end loop
        else if(selected == 7){
            fin = true;
            break;
        }
        //invalid command value entered
        else{
            std::cout << "Invalid character or value enetered! Please try again.\n";
            continue;
        }

    }

    txt.close();

    txt.open(fileName,std::fstream::out | std::fstream::trunc);

    //closing the program
    std::cout << "Now updating your file!\n";
    Gbook.printGradebook(name,txt);
    std::cout << "Thank you for using our gradebook editor!\n";

}