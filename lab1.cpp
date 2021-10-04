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



void vvod(pipe &my_pipe, comp_st &c_st)
{
	int data;
	cout<<"1. Хочу ввести данные с клавиатуры" <<endl
		<<"2. Хочу ввести данные из файла" << endl;
	if(my_pipe.id==0) cout<<"Вы не ввели ни одной трубы"<<endl;
	else if(c_st.id==0) cout<<"Вы не ввели ни одной КС"<<endl;
	else
	{
	cin>>data;
	if(data==1)
	{
		vvod_pipe(my_pipe);
		vvod_KS(c_st);
	}
	else if(data==2)
	{
		ifstream fin;
fin.open("/home/mikhail/vim/semester3/laboratory-works/input_data.txt");
if (fin.is_open())
{
	fin>>my_pipe.length>>my_pipe.diametr>>c_st.ks_name>>c_st.ceh_amount>>c_st.ceh_INwork_amount;
}
fin.close();
	}
	else {cout<<"Введено неправильное значение"<<endl;exit(0);}
	}
}
/*
void func_repair(pipe &my_pipe)
{
	cout<<(my_pipe.in_repair?"да":"нет");
	//cout<<my_pipe.status_pipe<<endl;
	//return my_pipe;
}
*/
void change_repair(pipe &my_pipe)
{

if (my_pipe.in_repair==0) my_pipe.in_repair=1;
else if(my_pipe.in_repair==1) my_pipe.in_repair=0;
else {cout<<"Вы ввели неверное значение"<<endl; exit(0);}
}

void change_KS(comp_st &c_st)
{
	int t,result,amount_down,amount_up,result_eff;
	double amount_eff_up,amount_eff_down;
	cout<<"1. Хочу изменить количество работающих цехов"<<endl
		<<"2. Хочу изменить значение эффективности КС"<<endl;
	cin>>t;
	if(t==1)
	{
		cout<<"1. Хочу увеличить количество работающих цехов"<<endl
			<<"2. Хочу уменьшить количество работающих цехов"<<endl;
		cin>>result;
		if(result==1) 
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_up;
			c_st.ceh_INwork_amount=c_st.ceh_INwork_amount+amount_up;
		}
		else if (result==2)
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_down;
			c_st.ceh_INwork_amount=c_st.ceh_INwork_amount-amount_down;
		}
		else {cout<<"Вы ввели неправильное значение!"<<endl; exit(0);}
	}
	else if (t==2)
	{
	cout<<"1. Хочу увеличить эффективность"<<endl
			<<"2. Хочу уменьшить эффективность"<<endl;
		cin>>result_eff;
		if(result_eff==1) 
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_eff_up;
			c_st.efficency=c_st.efficency+amount_eff_up;
		}
		else if (result_eff==2)
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_eff_down;
			c_st.efficency=c_st.efficency-amount_eff_down;
		}
		else {cout<<"Вы ввели неправильное значение!"<<endl; exit(0);}
	}
}

void vivod_pipe (pipe &my_pipe)
{
cout << "Данные, собранные по указанной пользователем трубе:" <<endl
	<< "Идентификатор трубы: " << my_pipe.id << endl
    << "Длина данной трубы: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр данной трубы: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Статус трубы: "<<(my_pipe.in_repair?"В ремонте":"Не в ремонте")<<endl;
}


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

/*void KS_efficency(comp_st &c_st)
{
	c_st.efficency=(c_st.ceh_INwork_amount*100)/c_st.ceh_amount;
	cout<<c_st.efficency<<" %"<<endl;
	//return c_st;
}
*/

void vivod_KS(comp_st &c_st)
{
cout << endl << "Данные, собранные по указанной пользователем КС" << endl
	 << "Идентификатор КС: " << c_st.id << endl
	 << "Название КС: " << c_st.ks_name << endl
	 << "Количество цехов на данной КС: " << c_st.ceh_amount <<endl
	 << "Количество работающих цехов на данный момент: " << c_st.ceh_INwork_amount << endl
	 << "Эффективность КС: "<<c_st.efficency;
	// KS_efficency(c_st);
//return c_st;
}

void save_pipe(pipe &my_pipe)
{
ofstream out;
out.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt",ios::app);
if(out.is_open())
	{
		out << "Данные, собранные по указанной пользователем трубе:" <<endl
	<< "Идентификатор трубы: " << my_pipe.id << endl
    << "Длина данной трубы: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр данной трубы: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Статус трубы: "<<(my_pipe.in_repair?"В ремонте":"Не в ремонте")<<endl;
	}
	out.close();

}

void save_KS(comp_st &c_st)
{
ofstream out;
out.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt",ios::app);
if(out.is_open())
	{
		out << endl << "Данные, собранные по указанной пользователем КС" << endl
	 << "Идентификатор КС: " << c_st.id << endl
	 << "Название КС: " << c_st.ks_name << endl
	 << "Количество цехов на данной КС: " << c_st.ceh_amount <<endl
	 << "Количество работающих цехов на данный момент: " << c_st.ceh_INwork_amount << endl
	 << "Эффективность КС: "<<c_st.efficency;
	}
	out.close();

}

void menu(pipe &my_pipe,comp_st &c_st)
{
	int x,y;
	while (true)
	{
		cout<< "1. Добавить трубу" << endl 
			<< "2. Добавить КС" << endl
			<< "3. Просмотр всех объектов" << endl
			<< "4. Редактировать трубу" << endl
			<< "5. Редактировать КС" << endl
			<< "6. Сохранить данные в файл" << endl
			<< "7. Ввести данные" << endl
			<< "0. Выход" << endl;
	cin>>x;
	switch (x) {
	case 1:
			if(my_pipe.id<1)
			{++my_pipe.id;
				cout<<"Труба добавлена!"<<endl;}
			else cout<<"Было добавлено максимальное количество труб!"<<endl;
		break;
	case 2:
			if(c_st.id<1)
			{++c_st.id;
			cout<<"КС добавлена!"<<endl;}
			else cout<<"Добавлено максимальное количество КС"<<endl;
		break;
	case 3:
		cout<<endl;
		vivod_pipe(my_pipe);
		vivod_KS(c_st);
		cout << endl;
		break;
	case 4:
		change_repair(my_pipe);
		break;
	case 5:
			change_KS(c_st);
			cout<<"КС отредактирована!";
		break;
	case 6:
		save_KS(c_st);
		save_pipe(my_pipe);
		
		break;
	case 7:
		vvod(my_pipe,c_st);	
		break;
	case 0:
		if(x==0) 
		cout<<"Вы уверены, что хотите выйти из программы?"<<endl;
		 cin>>y;
		 if(y==1) exit(0);
		 else break;
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
	c_st.id=0, c_st.ceh_amount=0, c_st.ceh_INwork_amount=0, c_st.efficency=75.2;

//	vvod_pipe(my_pipe);
//	vvod_KS(c_st);
	menu(my_pipe,c_st);
	return 0;

}
