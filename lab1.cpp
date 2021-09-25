#include <iostream>
#include <string>
using namespace std;

struct pipe     //труба
{
	int id, diametr;
	double length;
	bool in_repair;
	string status_pipe, in_repair_str;
};

struct comp_st     // компрессорная станция
{
	int id, ceh_amount,ceh_INwork_amount;
	string name;
	double efficency;
};

//задаю глобально тк используется в других функциях помимо main
pipe my_pipe;
comp_st c_st;


pipe func_repair()
{
	if (my_pipe.in_repair == 1) my_pipe.status_pipe="Труба находится в ремонте";
	else if (my_pipe.in_repair == 0) my_pipe.status_pipe="Труба находится в рабочем состоянии";
	cout<<my_pipe.status_pipe<<endl;
	return my_pipe;
}

pipe vivod_func ()
{
cout <<"Данные, собранные по указанной пользователем трубе:"<<endl
    << "Длина данной трубы: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр данной трубы: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Номер данной трубы: " <<  my_pipe.id << endl << "Статус трубы: ";
	func_repair();//  <<endl;
return my_pipe;
}


int main()
{
	my_pipe.id=0, my_pipe.length=0.00, my_pipe.in_repair=0, my_pipe.diametr=0;


	cout<<"Прошу ввести длину трубы"<<endl;
	cin>>my_pipe.length;
	Cout<<"Прошу ввести диаметр трубы"<<endl;
	cin>>my_pipe.diametr;
	cout <<"Прошу указать, находится ли труба в состоянии ремонта"<< endl;	
	cin>>my_pipe.in_repair;
	if (my_pipe.in_repair_str == "Да" && my_pipe.in_repair_str == "ДА" && my_pipe.in_repair_str == "да" && my_pipe.in_repair_str == "дА") 
	{my_pipe.in_repair = 0;}
	else if (my_pipe.in_repair_str == "Нет" && my_pipe.in_repair_str == "НЕТ" && my_pipe.in_repair_str == "нет" && my_pipe.in_repair_str == "нЕт" && my_pipe.in_repair_str == "неТ" && my_pipe.in_repair_str == "НЕт" 
			&& my_pipe.in_repair_str == "нЕТ" && my_pipe.in_repair_str == "НеТ") {my_pipe.in_repair = 1;}
	vivod_func();
	return 0;

}
