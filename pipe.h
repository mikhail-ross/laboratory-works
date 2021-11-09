#pragma once
#include <iostream>
#include <string>

class pipe
{
public:
    int id, diametr;
    double length;
    bool in_repair;
    std::string pipe_name;
    pipe();
    //friend std::ifstream& operator >> (std::ifstream& fin, pipe& my_pipe);
	//friend std::ostream& operator << (std::ostream& out, const pipe& my_pipe);
    //void change_repair();
};