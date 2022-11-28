// CSCI 1300 Fall 2022
// Author: Jacey Fischer
// Recitation: 302 – Michelle Ramsahoye
// Homework 3 - Problem 5

#include <iostream>
using namespace std;

// could've put switch statements within each other and made the code look more put together and more effective
int main() 
{
    int department, class_cs=0, class_m=0, class_s = 0; // declaring variables for switch statments for each class
    int section_cs_sc=0, section_cs_ds=0, section_cs_a=0, section_m_c1=0, section_m_c2=0, section_m_la=0, section_s_gc=0, section_s_p = 0; // declaring variables for each section within each class
    cout << "Select a department: (1)Computer Science (2)Math (3)Science" << endl;
    cin >> department;
    
    switch (department) // switch statment for choosing a class within each department 
    {
        case 1: cout << "Select a class: (1)Starting Computing (2)Data Structures (3)Algorithms" << endl; cin >> class_cs; break;
        case 2: cout << "Select a class: (1)Calculus 1 (2)Calculus 2 (3)Linear Algebra" << endl; cin >> class_m; break;
        case 3: cout << "Select a class: (1)General Chemistry 1 (2)Physics 1" << endl; cin >> class_s; break;
        default: cout << "Please enter a valid input." << endl; break;
    }
    if (department <=3 && department >0 ) // don't need this if statment here anymore, but taking it out would mean I would have to reformat everything 
    {
        switch (class_cs) // switch statement for the sections in the computer science classes
        {   
            case 0: break;
            case 1: cout << "Select a section: (1)Section 100 (2)Section 200" << endl; cin >> section_cs_sc; break;
            case 2: cout << "Select a section: (1)Section 101 (2)Section 201" << endl; cin >> section_cs_ds; break;
            case 3: cout << "Select a section: (1)Section 102 (2)Section 202" << endl; cin >> section_cs_a; break;
            default: cout << "Please enter a valid input." << endl; break;
            
        }
        switch(section_cs_sc) // to print out what the user chose for the starting computing class
        {  
            case 0: break;
            case 1: cout << "You've been enrolled in Section 100 of Starting Computing!" << endl; break;
            case 2: cout << "You've been enrolled in Section 200 of Starting Computing!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        switch(section_cs_ds) // to print out what the user chose for the data structures class
        {
            case 0: break;
            case 1: cout << "You've been enrolled in Section 101 of Data Structures!" << endl; break;
            case 2: cout << "You've been enrolled in Section 201 of Data Structures!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        switch(section_cs_a) // to print out what the user chose for the algorithms class
        {
            case 0: break;
            case 1: cout << "You've been enrolled in Section 102 of Algorithms!" << endl; break;
            case 2: cout << "You've been enrolled in Section 202 of Algorithms!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        
           
    }
        switch (class_m) // switch statment for each math class section
        {
            case 0: break;
            case 1: cout << "Select a section: (1)Section 400 (2)Section 500" << endl; cin >> section_m_c1; break;
            case 2: cout << "Select a section: (1)Section 401 (2)Section 501" << endl; cin >> section_m_c2; break;
            case 3: cout << "Select a section: (1)Section 402 (2)Section 502" << endl; cin >> section_m_la; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        
        switch(section_m_c1) // to print out user input for calc 1
        {  
            case 0: break;
            case 1: cout << "You've been enrolled in Section 400 of Calculus 1!" << endl; break;
            case 2: cout << "You've been enrolled in Section 500 of Calculus 1!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        switch(section_m_c2) // to print out user input for calc 2
        {
            case 0: break;
            case 1: cout << "You've been enrolled in Section 401 of Calculus 2!" << endl; break;
            case 2: cout << "You've been enrolled in Section 501 of Calculus 2!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        switch(section_m_la) // to print out user input for linear algebra 
        {
            case 0: break;
            case 1: cout << "You've been enrolled in Section 402 of Linear Algebra!" << endl; break;
            case 2: cout << "You've been enrolled in Section 502 of Linear Algebra!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
    
        switch (class_s) // switch statment for sections in the science department classes
        {
            case 0: break;
            case 1: cout << "Select a section: (1)Section 700 (2)Section 800" << endl; cin >> section_s_gc; break;
            case 2: cout << "Select a section: (1)Section 701 (2)Section 801" << endl; cin >> section_s_p; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        
        switch(section_s_gc) // to print out user input for general chemistry 
        {
            case 0: break;
            case 1: cout << "You've been enrolled in Section 700 of General Chemistry 1!" << endl; break;
            case 2: cout << "You've been enrolled in Section 800 of General Chemistry 1!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
        switch(section_s_p) // to print out user input for physics
        {
            case 0: break;
            case 1: cout << "You've been enrolled in Section 701 of Physics 1!" << endl; break;
            case 2: cout << "You've been enrolled in Section 801 of Physics 1!" << endl; break;
            default: cout << "Please enter a valid input." << endl; break;
        }
           
        
    return 0;
}





