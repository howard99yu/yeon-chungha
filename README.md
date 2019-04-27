# Accounting System for Personal Use

## Problem statement
Thanks to the development of mobile payment apps, we are able to keep track of our incomes and expenses. Personal accounting apps have easen the individual budget management through convenient access and eidetic interface. We can now easily record daily financial status with various information and can edit the information anytime as well. For our project, we decided to create an personal accounting program through c++.  Our program is able to view user’s statistical report of financial status drastically helps the manage of budget and can set up new function where it can import raw datas and export processed outputs in different type of files.   

## Problem setting

We will start with making the flowchart of the algorithm followed by setting up multiple source files with the use of linux os system and c/cpp programming language, We will then use makefile function in linux to process these files as a program. Lastly, preparation of sample inputs to test if the program works without defect is needed.
Our general assumption of the program includes the following:
- All user inputs are valid(i.e, input of non-existing dates are not allowed)
- Input are pre-sorted according to date (latest on top)
- User is only allowed to import one input file per program running
## Features

- Record incomes and expenses (with basic information)
- Records can be easily edited
- Records can be searched through different information(via date,types,amount)
- Statistical report of user’s financial state is provided
- Can set budget usage monthly and display available amount for the month 
- Import and export of csv files

## Input and Output specifications

The user first needs to load a valid csv file whether empty or not. Then, user can choose to input additional informations manually. User lastly requires to save the file in various file type (i.e, .csv, .txt) before quiting the program only so the changes made are saved.

## Compilation and execution Instructions

The user needs to put all files (source files, make file, sample inputs) to the same directory. 
Then user inputs "make main" in the shell program to compile the source files.
Lastly user inputs "./main" to run the program. 

Once the program is running, user first needs to load the input file before carrying on any other functions. 
Quiting the program without saving will not save any changes made during the program.

 

