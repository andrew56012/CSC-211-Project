# Summary
Our program takes in a file from the user and adds the necessary information into a database to store the different categories, assignments, and grades of a single user.
Then, using a command line interface, the user can add, change, delete, or view different aspects of the gradebook. Once the user has made all the changes they desire, 
the program automatically saves the changes back to the original file. When the user wants to access the file again, theu just type in the name and all their previos changes
will appear. 


# Planning
To make sure all group members were on the same page, we held a zoom meeting before starting any code. As a group we made a list of the functions we would need, the purpose they had, their inputs and outputs, and who would work on them. Then we came up with some psuedocode for how to store the gradebook data, which was going to be the hardest part.
We decided to store all the data in a 2D vector that holds pairs, so we can have the assignment name and then the grade matched with it, almost like a map. This is separated by categories for easy access later. Then came the command line interface so the user could interact with the program, proceeded by the rest of the functions. Then, we reconviened as a group to split the remaining tasks, like creating the video, writing the report, and finishing the README. Through the whole process communication was kept up through text to make sure everyone was aware of everything happening. Whenever there was any changes to code, we made sure to submit to Github to make sure everyone had the most recent changes. 

# Compilation and Runtime Instructions
For accurate results, compile with c++ 14. The program does not require any arguments when compiling, it should be all set to run either by pressing play or from the terminal. When started, the program should ask for the name of the file you wouild like to open. Make sure this is a .txt file and is in the c-make-build-debug folder so the program can find it. The data file should look like this: 
(Place picture here)

Once the file has been opened, the program will automatically prompt you with different options to control the program. 

# Runtime Examples



