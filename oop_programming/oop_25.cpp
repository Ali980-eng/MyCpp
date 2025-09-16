#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::fstream myfile;
    myfile.open("fstream_file.txt", std::ios::out); // write
    if (myfile.is_open())
    {
        myfile << "fstream lesson\n";
        myfile << "This is second line\n";
        myfile.close();
    }
    myfile.open("fstream_file.txt", std::ios::in); // read
    if (myfile.is_open())
    {
        std::string current_line;
        while (getline(myfile, current_line))
        {
            std::cout << current_line << std::endl;
        }
        myfile.close();
    }
    return 0;
}