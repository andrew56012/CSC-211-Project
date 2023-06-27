# Summary
Our program takes in a file from the user and adds the necessary information into a database to store the different categories, assignments, and grades of a single user.
Then, using a command line interface, the user can add, change, delete, or view different aspects of the gradebook. Once the user has made all the changes they desire, 
the program automatically saves the changes back to the original file. When the user wants to access the file again, theu just type in the name and all their previos changes
will appear. 

# Planning
To make sure all group members were on the same page, we held a zoom meeting before starting any code. As a group we made a list of the functions we would need, the purpose they had, their inputs and outputs, and who would work on them. These might not match exactly with the finished code.

<img width="406" alt="Functions table" src="https://github.com/andrew56012/CSC-211-Project/assets/123496094/305d4ec9-eed9-40f0-842c-fbeba769bcbe">

Then we came up with some psuedocode for how to store the gradebook data, which was going to be the hardest part.

![IMG-4603](https://github.com/andrew56012/CSC-211-Project/assets/123496094/d89bf322-5ef6-4e4f-83a0-dcaa868ea0f5)
![70822739607--E785EAD0-2C89-42EF-9175-1CC2984C516A](https://github.com/andrew56012/CSC-211-Project/assets/123496094/74b73019-9287-4dad-a71d-7259aa402cb0)

We decided to store all the data in a 2D vector that holds pairs, so we can have the assignment name and then the grade matched with it, almost like a map. This is separated by categories for easy access later. Then came the command line interface so the user could interact with the program, proceeded by the rest of the functions. Then, we reconviened as a group to split the remaining tasks, like creating the video, writing the report, and finishing the README. Through the whole process communication was kept up through text to make sure everyone was aware of everything happening. Whenever there was any changes to code, we made sure to submit to Github to make sure everyone had the most recent changes. 

# Compilation and Runtime Instructions
For accurate results, compile with c++ 14. The program does not require any arguments when compiling, it should be all set to run either by pressing play or from the terminal. When started, the program should ask for the name of the file you wouild like to open. Make sure this is a .txt file and is in the c-make-build-debug folder so the program can find it. The data file should look like this: 
<img width="249" alt="gradebook example" src="https://github.com/andrew56012/CSC-211-Project/assets/123496094/cdbae29a-93d9-4b19-9f3e-686eefa62394">

The setup of the file can not be changed, nor can the names of the categories. However, the names of the assignemnts and their grades can be edited, added to, or deleted.
Once the file has been opened, the program will automatically prompt you with different options to control the program. 

# Runtime Examples
The loading of a file into the program, and looking at a specific grade.
<img width="800" alt="working example 1" src="https://github.com/andrew56012/CSC-211-Project/assets/123496094/224dfcf8-ad3e-442f-8c86-2c7d57592240">

Editing the same grade in the file. 
<img width="750" alt="Working example 2" src="https://github.com/andrew56012/CSC-211-Project/assets/123496094/fcda22c8-55d9-4e90-b3fc-6d239afafa0e">

Working with the same file as shown above, you can see that the assignment grade and final grade have been updated according to our edits. 
<img width="237" alt="updated thing" src="https://github.com/andrew56012/CSC-211-Project/assets/123496094/ac8e60ef-6080-4499-8f99-f4a9354d749f">






