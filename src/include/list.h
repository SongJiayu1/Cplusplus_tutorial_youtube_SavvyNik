/*
.h stands for header file.
*/
#include <iostream>
#include <vector>

class List{
     
private:
protected:
public:
     List(){
          // constructor, 
     }
     ~List(){
          // destructor
     }

     // Define a globale variable 'name_vector' to save the names. It's datatype is 'vector'.
     // How to define: vector<datatype> vector_name
     std::vector<std::string> name_vector;  // name_vector contains all the items of a specific user.
     std::vector<std::vector<std::string> > mainList;
     std::string name;                    // Define globale variable 'name'.
     int currUserIndex;

     // Declare all the functions.
     void print_menu();
     void print_list();
     void add_item();
     void delete_item();
     bool find_userList();
     void save_list();

};