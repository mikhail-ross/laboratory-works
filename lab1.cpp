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
	string ks_name;
	double efficency;
};

//задаю глобально тк используется в других функциях помимо main
pipe my_pipe;
comp_st c_st;


pipe func_repair()
{
	if (my_pipe.in_repair_str == "Да" || my_pipe.in_repair_str == "ДА" || my_pipe.in_repair_str == "да" || my_pipe.in_repair_str == "дА") 
	{my_pipe.status_pipe="Труба находится в ремонте.";}
	else if (my_pipe.in_repair_str == "Нет" || my_pipe.in_repair_str == "НЕТ" || my_pipe.in_repair_str == "нет" || my_pipe.in_repair_str == "нЕт" || my_pipe.in_repair_str == "неТ" || my_pipe.in_repair_str == "НЕт" 
			|| my_pipe.in_repair_str == "нЕТ" || my_pipe.in_repair_str == "НеТ") {my_pipe.status_pipe="Труба находится в рабочем состоянии.";}
	cout<<my_pipe.status_pipe<<endl;
	return my_pipe;
}

pipe vivod_pipe ()
{
cout << "Данные, собранные по указанной пользователем трубе:" <<endl
	<< "Идентификатор трубы: " << my_pipe.id << endl
    << "Длина данной трубы: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр данной трубы: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Статус трубы: ";
	func_repair();//  <<endl;

return my_pipe;
}


comp_st KS_efficency()
{
	c_st.efficency=(c_st.ceh_INwork_amount*100)/c_st.ceh_amount;
	cout<<c_st.efficency<<" %"<<endl;
	return c_st;
}


comp_st vivod_KS()
{
cout << endl << "Данные, собранные по указанной пользователем КС" << endl
	 << "Идентификатор КС: " << c_st.id << endl
	 << "Название КС: " << c_st.ks_name << endl
	 << "Количество цехов на данной КС: " << c_st.ceh_amount <<endl
	 << "Количество работающих цехов на данный момент: " << c_st.ceh_INwork_amount << endl
	 << "Эффективность КС: ";
	 KS_efficency();
return c_st;
}

int main()
{
	my_pipe.id=0, my_pipe.length=0.00, my_pipe.in_repair=0, my_pipe.diametr=0;

	c_st.id=1, c_st.ceh_amount=0, c_st.ceh_INwork_amount=0, c_st.efficency=0.00;


	//труба ввод
	cout<<"Прошу ввести длину трубы"<<endl;
	cin>>my_pipe.length;
	cout<<"Прошу ввести диаметр трубы"<<endl;
	cin>>my_pipe.diametr;
	cout <<"Находится ли труба в состоянии ремонта"<< endl;	
	cin>>my_pipe.in_repair_str;

	//кс ввод
	cout<<"Введите название КС"<<endl;
	cin>>c_st.ks_name;
	cout<<"Введите количество цехов"<<endl;
	cin>>c_st.ceh_amount;
	cout<<"Введите количество работающих цехов"<<endl;
	cin>>c_st.ceh_INwork_amount;

	//вывод данных
	vivod_pipe();
	vivod_KS();
	return 0;

}
