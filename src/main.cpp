/*
The goal of this program is to create a list that saves names from user.
User can add/delete items or print the current items in the list.
*/

#include "include/list.h"

// Main function
int main(int arg_count, char *args[])
{
    if(arg_count > 1){
        List simpleList;  // define a class List
        std::cout << "Username supplied" << std::endl;
        simpleList.name = std::string(args[1]);  // Convert charactor 'args[1]' into string and give it to 'name'.
        simpleList.print_menu();
    }
    else{
        std::cout << "Username not supplied...exiting the program." << std::endl;
    }
    return 0;
}

