#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct pipe     //труба
{
	int id, diametr;
	double length;
	bool in_repair;
};

struct comp_st     // компрессорная станция
{
	int id, ceh_amount,ceh_INwork_amount;
	string ks_name;
	double efficency;
};


void vvod_pipe(pipe &my_pipe)
{
cout<<"Введите длину трубы"<<endl;
cin>>my_pipe.length;
cout<<"Введите диаметр трубы"<<endl;
cin>>my_pipe.diametr;

}

void vvod_KS(comp_st &c_st)
{
cout<<"Введите название КС"<<endl;
cin>>c_st.ks_name;
cout<<"Введите количество цехов"<<endl;
cin>>c_st.ceh_amount;
cout<<"Введите количество работающих цехов"<<endl;
cin>>c_st.ceh_INwork_amount;
}
/*
void func_repair(pipe &my_pipe)
{
	cout<<(my_pipe.in_repair?"да":"нет");
	//cout<<my_pipe.status_pipe<<endl;
	//return my_pipe;
}

void change_repair(pipe &my_pipe)
{

//if (my_pipe.in_repair==0) my_pipe.status_pipe="Труба находится в рабочем состоянии.";
//else my_pipe.status_pipe="Труба находится в нерабочем состоянии.";
//return my_pipe;
}
*/

//pipe add_pipe()
//{
//	my_pipe.id+=1;
//	return my_pipe;
//}

void vivod_pipe (pipe &my_pipe)
{
cout << "Данные, собранные по указанной пользователем трубе:" <<endl
	<< "Идентификатор трубы: " << my_pipe.id << endl
    << "Длина данной трубы: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр данной трубы: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Статус трубы: "<<(my_pipe.in_repair?"В ремонте":"Не в ремонте")<<endl;
	//func_repair();

//return my_pipe;
}

//pipe add_pipe()
//{
//	my_pipe.id+=1;
//	return my_pipe;
//}
/*
void vivod_pipe (pipe &my_pipe)
{
cout << "Данные, собранные по указанной пользователем трубе:" <<endl
	<< "Идентификатор трубы: " << my_pipe.id << endl
    << "Длина данной трубы: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр данной трубы: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Статус трубы: ";
	func_repair();

//return my_pipe;
}
*/
//comp_st add_KS()
//{
//c_st.id+=1;
//return c_st;
//}

void KS_efficency(comp_st &c_st)
{
	c_st.efficency=(c_st.ceh_INwork_amount*100)/c_st.ceh_amount;
	cout<<c_st.efficency<<" %"<<endl;
	//return c_st;
}


void vivod_KS(comp_st &c_st)
{
cout << endl << "Данные, собранные по указанной пользователем КС" << endl
	 << "Идентификатор КС: " << c_st.id << endl
	 << "Название КС: " << c_st.ks_name << endl
	 << "Количество цехов на данной КС: " << c_st.ceh_amount <<endl
	 << "Количество работающих цехов на данный момент: " << c_st.ceh_INwork_amount << endl
	 << "Эффективность КС: ";
	 KS_efficency(c_st);
//return c_st;
}
/*
void save_pipe(pipe &my_pipe)
{
ofstream out;
out.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt");
if(out.is_open())
	{
		out << vivod_pipe(my_pipe);
	}
	out.close();

}

void save_KS(comp_st &c_st)
{
ofstream out;
out.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt");
if(out.is_open())
	{
		out << vivod_KS();
	}
	out.close();

}
*/
void menu(pipe &my_pipe,comp_st &c_st)
{
	int x;
	while (true)
	{
		cout<< "1. Добавить трубу" << endl 
			<< "2. Добавить КС" << endl
			<< "3. Просмотр всех объектов" << endl
			<< "4. Редактировать трубу" << endl
			<< "5. Редактировать КС" << endl
			<< "6. Сохранить" << endl
			<< "7. Загрузить" << endl
			<< "0. Выход" << endl;
	cin>>x;
	switch (x) {
	case 1:
			if(my_pipe.id<1)
				++my_pipe.id;
			cout<<"Труба добавлена!";
		break;
	case 2:
			if(c_st.id<1)
				++c_st.id;
			cout<<"КС добавлена!";
		break;
	case 3:
		vivod_pipe(my_pipe);
		vivod_KS(c_st);
		break;
	case 4:
	cout<<"пока так";
			//change_repair();
		break;
	case 5:
			cout<<"КС отредактирована!";
		break;
	case 6:
		cout<<"Yt pyf.!";
		break;
	case 7:
			//save_pipe(my_pipe);
			//save_KS(c_st);
			cout<<"тоже так";
		break;
	case 0:
		cout<<"exit";
		break;
	default:
		cout<<"Ошибка при вводе!"<<endl;
		break;
	}
	}
}	


int main()
{	
	pipe my_pipe;
	comp_st c_st;

	//задекларировали в мэйне параметры трубы
	my_pipe.id=0, my_pipe.length=0.00, my_pipe.in_repair=0, my_pipe.diametr=0;
	//задекларировали в мэйне параметры кс
	c_st.id=0, c_st.ceh_amount=0, c_st.ceh_INwork_amount=0, c_st.efficency=0.00;

	
	vvod_pipe(my_pipe);
	//труба ввод на консоль
	//cout<<"Прошу ввести длину трубы"<<endl;
	//cin>>my_pipe.length;
	//cout<<"Прошу ввести диаметр трубы"<<endl;
	//cin>>my_pipe.diametr;
	vvod_KS(c_st);
	menu(my_pipe,c_st);
	//кс ввод на консоль
	//cout<<"Введите название КС"<<endl;
	//cin>>c_st.ks_name;
	//cout<<"Введите количество цехов"<<endl;
	//cin>>c_st.ceh_amount;
	//cout<<"Введите количество работающих цехов"<<endl;
	//cin>>c_st.ceh_INwork_amount;

	//запись в файл
	//ofstream out;
	//out.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt");
	//if(out.is_open())
	//{
	//	out << vivod_pipe();
	//	out << vivod_KS();
	//}
	//out.close();
	//cout << endl << "Данные были записаны в файл!";

	return 0;

}
