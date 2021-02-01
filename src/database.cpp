#include "include/database.h"


void Database::write(std::vector<std::vector<std::string>> mainList)  // 定义类 Database 的方法
{
    std::ofstream db;
    db.open("db/lists.sl");
    
    if (db.is_open())
    {
        for (int user_index = 0; user_index < int(mainList.size()); user_index++)  
        // mainList[user_index] is already a vector.
        {
            for (int list_index = 0; list_index < int(mainList[user_index].size()); list_index++)
            {
                if (list_index == 0)  // The first line of each userList is the user name in form of "#name".
                {
                    db << "#" << mainList[user_index][list_index] << "\n";
                }
                else
                {
                    db << mainList[user_index][list_index] << "\n";
                }
            }
            db << "%" << "\n";  // End of each list.
        }
    }
    else
    {
        std::cout << "Cannot open file for writing.\n";
    }
    
    db.close();

}

std::vector<std::vector<std::string>> Database::read() 
{
    std::string line;
    std::fstream db;  // 实例化一个 fstream 类，类名为 db

    std::vector<std::string> userList;   // 定义一个 元素为 string 型的 vector

    db.open("db/lists.sl");

    if (db.is_open())
    {   
        while (getline(db, line, '\n'))  // getline() 函数传入三个参数：fstream 类， line， 行结束的标志符(char 型，用单引号)
        // 按行读取 db 中的内容，并将每一行内容赋给 line（string 类型）
        // 注意：C++ 中字符串型 string，用双引号
        {
            if(line.size() == 0)  // If the line is empty, pass.
            {
                continue;
            }
            if(line.front() == '#')
            {
                std::cout << "Found a Hashtag: " << line << "\n";
                line.erase(line.begin());  // erase the first char.
                
                userList.push_back(line);  // 将 姓名 存入列表 userList
            }
            else if(line.front() == '%')  // If find '%', save the userList as an element in mainList, then clear it.
            {
                std:: cout << "Found a Percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            }
            else
            {
                std::cout << "Found a item: " << line << "\n";
                userList.push_back(line);  // 将 item 存入列表
            }
            
        }
    }   
    else
    {
        std::cout << "Cannot open file for reading. \n";
    }
    db.close();
    
    return mainList;
}
