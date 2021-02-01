/*
The goal of this program is to create a list that saves names from user.
User can add/delete items or print the current items in the list.
*/

#include "include/list.h"
#include "include/database.h"

// Main function
int main(int arg_count, char *args[])  // arg_count: argument count, the number of argument into main function.
// *args[]: the argument list or vector into main function.
{
    List simpleList;  // define a class List
    Database data;    // Database is a class

    if(arg_count > 1){
        
        std::cout << "Username supplied" << std::endl;
        simpleList.name = std::string(args[1]);  // Convert charactor 'args[1]' into string and give it to 'name'.
        simpleList.mainList = data.read();  // the read function in database.cpp is to read the list and return mainList
        simpleList.find_userList();  // search the user names in mainList, if user name equals simpleList.name
        simpleList.print_menu();
        data.write(simpleList.mainList);
    }
    else{
        std::cout << "Username not supplied...exiting the program." << std::endl;
    }
    
    return 0;
    
}

