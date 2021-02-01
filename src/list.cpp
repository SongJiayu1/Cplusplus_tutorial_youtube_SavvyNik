#include "include/list.h"

// Define a function to print the main menu.
void List::print_menu()
{
    int choice;

    std::cout << "********************\n" << std::endl;
    std::cout << "1 - Print list.\n";
    std::cout << "2 - Add to list.\n";
    std::cout << "3 - Delete from list.\n";
    std::cout << "4 - Save list.\n";
    std::cout << "5 - Quit\n";
    std::cout << "Enter your choice and press return: ";

    std::cin >> choice;

    if(choice == 5){
        std::cout << "You have exit the app!\n";
        return;  // 不带返回值的 return 语句，用于中断返回值为 void 类型的函数的执行
        // return 0：带返回值的 return 语句，不可以用于 void 类型的函数
    }
    else if(choice == 4)
    {
        save_list();
    }
    else if(choice == 1)
    {
        print_list();
    }
    else if(choice == 2)
    {
        add_item();
    }
    else if(choice == 3)
    {
        delete_item();
    }
    else{
        std::cout << "Sorry, choice is not implemented yet.\n";
    }
}


// Define a function to print the current SimpleList.
void List::print_list()
{
    
    if(name_vector.size() == 0)
    {
        std::cout << "The list is empty!" << std::endl;
    }
    else
    {
        for(int i = 0; i < int(name_vector.size()); i++)  // name_vector.size() datatype: 'long unsigned int'
        {
            std::cout << " * " << name_vector[i] << std::endl;
        }
    }
    std::cout << "M - Menu" << std::endl;
    std::string choice;
    std::cin >> choice;
    if(choice == "M" || choice == "m")
    {
        print_menu();
    }
}


// Define a function to add new item from user to the vector (list).
void List::add_item()
{
    std::cout << "\n\n\n\n";
    std::cout << "*** Add Item ***\n";
    std::cout << "Tpye in an item and press enter: ";
    
    std::string new_name;
    //std::cin >> new_name;
    std::string str;
    str = "\n";
    getline(std::cin, str);
    getline(std::cin, new_name);
    name_vector.push_back(new_name);  // name_vector is a vector(datatype: string), new_name is a string.

    std::cout<< "Successfully added an item to the list. \n\n\n\n";
    std::cin.clear();  // Clear the input from the console buffer.

    print_menu();

}


// To delete item from list.
void List::delete_item()
{
    std::cout << "\n\n\n\n";
    std::cout << "*** Delete Item ***\n";
    std::cout << "Select an item index number to delete: \n";

    std::int16_t index_to_delete; 

    if(name_vector.size())  // If the name_vector is not empty.
    {
        for(int i = 0; i < int(name_vector.size()); i++)  // name_vector.size() datatype: 'long unsigned int'
        {
            std::cout << i << ": " << name_vector[i] << std::endl;
        }
        
        std::cin >> index_to_delete;  
        std::cout << "'"<< name_vector[index_to_delete] << "'" << " is deleted!" << std::endl;
        name_vector.erase(name_vector.begin() + index_to_delete);  
        // Erase the index_to_delete -th element.
    }
    else
    {
        std::cout << "The List is empty, can not delete." << std::endl;
    }

    print_menu();

}


bool List::find_userList()
{
    
    bool userFound = false;  // set a flag to show if the user is found.
    std::cout << "\n\n\n\n";
    std::cout << "*** Welcome " << name << " ***\n";

    for (int user_index=0; user_index < (int)mainList.size(); user_index++)
    {
        if (mainList[user_index][0] == name)
        {
            std::cout << "User has been found: " << mainList[user_index][0] << std::endl;
            name_vector = mainList[user_index];
            currUserIndex = user_index;
            userFound = true;
            break;
        }
    }

    if (userFound == false)
    {
        std::cout << "User does not exist, add to list." << std::endl;
        
        name_vector.push_back(name);
        mainList.push_back(name_vector);
        currUserIndex = int(mainList.size()) - 1;
        

    }

    return userFound;
}

void List::save_list()
{
    std::cout << "Saving the list..." << "\n";
    mainList[currUserIndex] = name_vector;

    print_menu();
}