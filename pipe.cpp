#include <iostream>
#include "pipe.h"
#include "utils.h"

using namespace std;

//int pipe::MaxId=0;

pipe::pipe()
{
    id=0;//MaxId++;
    length=0.00;
    diametr=0;
    in_repair=0;
}

/*void change_repair() //редактирование трубы
{
	auto result=pipemap.find(id);
	if(result != pipemap.end())
	{
	result->second.in_repair=!result->second.in_repair;	
	}
	else cout<<"выбранная труба не была найдена"<<endl;
}*/