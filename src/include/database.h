/*
.h stands for header file.
*/
#include <iostream>
#include <vector>
#include <fstream>


/*
The header fstream includes three classes: ofstream, ifstream, and fstream.
ofstream: write
ifstream: read
fstream: write and read
*/

class Database{
     
private:
protected:
public:
     Database(){
          // constructor 构造函数
     }
     ~Database(){
          // destructor 析构函数
     }

     // Define a globale variable 'name_vector' to save the names. It's datatype is 'vector'.
     // How to define: vector<datatype> vector_name
     std::vector<std::vector<std::string>> mainList;  // define a 2D vector
     std::string name;                    // Define globale variable 'name'.
    
     // Declare all the functions.
     void write(std::vector<std::vector<std::string> > mainList);  // 函数的输入为一个二维 vector
     std::vector<std::vector<std::string> > read();

};