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
    friend std::istream& operator >> (std::istream& in, pipe& my_pipe);
	friend std::ostream& operator << (std::ostream& out, const pipe& NewPipe);
    //void change_repair();
};