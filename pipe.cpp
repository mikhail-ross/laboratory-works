#include <iostream>
#include "pipe.h"
#include "utils.h"

using namespace std;

int pipe::id_pipe=0;

pipe::pipe()
{
    //id=0;
    length=0.00;
    diametr=0;
    in_repair=0;
}

ostream &operator<<(ostream &out, const pipe& pipeh)
{
	out<<pipeh.pipe_name<<endl
		<<pipeh.length<<"  "
		<<pipeh.diametr<<"  "
		<<(pipeh.in_repair?"подключён":"Не подключён")<<endl;
		return out;
}
istream &operator>>(istream &in, pipe& NewPipe)
{
	cout<<"Введите название трубы"<<endl;
    cin>>ws;
    getline(in, NewPipe.pipe_name);
	cout<<"Введите длину трубы"<<endl;
	NewPipe.length = GetNumber(100.0, 1500.0);
	cout<<"Введите диаметр трубы"<<endl;
	NewPipe.diametr = GetNumber( 100, 1420);
	return in;
}
ofstream &operator<<(ofstream &fout, const pipe& pipeh)
{
	fout<<pipeh.pipe_name<<endl
		<<pipeh.length<<"  "
		<<pipeh.diametr<<"  "
		<<pipeh.in_repair<<" ";
		return fout;
}
ifstream &operator>>(ifstream &fin, pipe& NewPipe)
{
    fin>>ws;
    getline(fin, NewPipe.pipe_name);
	fin >> NewPipe.length >> NewPipe.diametr >> NewPipe.in_repair;
	return fin;
}
void pipe::repair_pipe()
{
	in_repair=!in_repair;
}