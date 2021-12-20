#pragma once
#include <iostream>
#include <string>
#include <fstream>

class pipe
{
public:
    static int id_pipe;
    int /*id,*/ diametr;
    double length;
    bool in_repair;
    std::string pipe_name;
    pipe();
    friend std::istream& operator >> (std::istream& in, pipe& NewPipe);
	friend std::ostream& operator << (std::ostream& out, const pipe& pipeh);
    friend std::ifstream& operator >> (std::ifstream& fin, pipe& NewPipe);
    friend std::ofstream& operator << (std::ofstream& fout, const pipe& pipeh);
    void repair_pipe();
};