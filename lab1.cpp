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

void vvod_pipe(pipe &my_pipe)  //ввод данных о трубе с клавиатуры
{
cout<<"Введите длину трубы"<<endl;
cin>>my_pipe.length;
cout<<"Введите диаметр трубы"<<endl;
cin>>my_pipe.diametr;
if(my_pipe.diametr<0||my_pipe.diametr>1420) {cout<<"Вы ввели недопустимый диаметр трубы"<<endl;my_pipe.diametr=-1;exit(0);}
else if(my_pipe.length<1) {cout<<"Вы ввели недопустимую длину трубы"<<endl;my_pipe.length=-1;exit(0);}
}

void vvod_KS(comp_st &c_st)  //ввод данных о КС с клавиатуры
{
cout<<"Введите название КС"<<endl;
cin>>c_st.ks_name;
cout<<"Введите количество цехов"<<endl;
cin>>c_st.ceh_amount;
cout<<"Введите количество работающих цехов"<<endl;
cin>>c_st.ceh_INwork_amount;
if(c_st.ceh_amount<c_st.ceh_INwork_amount) {cout<<"Вы ввели недопустимые значения для цехов"<<endl;c_st.ceh_amount=-1;c_st.ceh_INwork_amount=-1;exit(0);}
if(c_st.ceh_amount<0||c_st.ceh_INwork_amount<0) {cout<<"Вы ввели недопустимые значения для цехов"<<endl;c_st.ceh_amount=-1;c_st.ceh_INwork_amount=-1;exit(0);}
}

void vvod(pipe &my_pipe, comp_st &c_st)  //ввод данных из файла
{
	int data;
	
	if(my_pipe.id==0) {system("clear"); cout<<"Вы не ввели ни одной трубы"<<endl; }
	else if(c_st.id==0) { system("clear"); cout<<"Вы не ввели ни одной КС"<<endl;}
	else
	{
	cout<<"1. Хочу ввести данные с клавиатуры" <<endl
	<<"2. Хочу ввести данные из файла" << endl
	<<"3. Хочу выйти в главное меню"<<endl;
	cin>>data;
	if(data==1)
	{
		vvod_pipe(my_pipe);
		vvod_KS(c_st);
		system("clear");
		cout<<"Данные введены!"<<endl;
	}
	else if(data==2)
	{
		ifstream fin;
fin.open("/home/mikhail/vim/semester3/laboratory-works/input_data.txt");
if (fin.is_open())
{
	fin>>my_pipe.length>>my_pipe.diametr>>c_st.ks_name>>c_st.ceh_amount>>c_st.ceh_INwork_amount;
	if(my_pipe.diametr<0||my_pipe.diametr>1420) {system("clear");cout<<"Вы ввели недопустимый диаметр трубы"<<endl;my_pipe.diametr=-1;}
	else if(my_pipe.length<1) {system("clear");cout<<"Вы ввели недопустимую длину трубы"<<endl;my_pipe.length=-1;}
	if(c_st.ceh_amount<c_st.ceh_INwork_amount) {system("clear");cout<<"Вы ввели недопустимые значения для цехов"<<endl;c_st.ceh_amount=-1;c_st.ceh_INwork_amount=-1;}
	if(c_st.ceh_amount<0||c_st.ceh_INwork_amount<0) {system("clear");cout<<"Вы ввели недопустимые значения для цехов"<<endl;c_st.ceh_amount=-1;c_st.ceh_INwork_amount=-1;}
}
fin.close();
	}
	else if(data==3) {system("clear");cout<<"Вы вышли в главное меню!"<<endl;}
	else {system("clear");cout<<"Введено неправильное значение"<<endl;}
	}
}

void change_repair(pipe &my_pipe) //редактирование трубы
{
	system("clear");
if (my_pipe.in_repair==0) {my_pipe.in_repair=1; cout<<"Труба отредактирована!"<<endl;}
else if(my_pipe.in_repair==1) {my_pipe.in_repair=0; cout<<"Труба отредактирована!"<<endl;}
else {system("clear");cout<<"Вы ввели неверное значение"<<endl;}
}

void change_KS(comp_st &c_st) //редактирование КС
{
	int t,result,amount_down,amount_up,result_eff;
	double amount_eff_up,amount_eff_down;
	cout<<"1. Хочу изменить количество работающих цехов"<<endl
		<<"2. Хочу изменить значение эффективности КС"<<endl
		<<"3. Хочу выйти в главное меню"<<endl;
	cin>>t;
	if(t==1)
	{
		cout<<"1. Хочу увеличить количество работающих цехов"<<endl
			<<"2. Хочу уменьшить количество работающих цехов"<<endl
			<<"3. Хочу выйти в главное меню"<<endl;
		cin>>result;
		if(result==1) 
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_up;
			c_st.ceh_INwork_amount=c_st.ceh_INwork_amount+amount_up;
			if(c_st.ceh_INwork_amount>c_st.ceh_amount) {system("clear");cout<<"Произошла ошибка"<<endl; c_st.ceh_INwork_amount=-1;}
		}
		else if (result==2)
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_down;
			c_st.ceh_INwork_amount=c_st.ceh_INwork_amount-amount_down;
			if(c_st.ceh_INwork_amount<0) {system("clear");cout<<"Ошибка в параметре"<<endl; c_st.ceh_INwork_amount=-1;}
		}
		else if(result==3) {system("clear");cout<<"Вы вышли в главное меню!"<<endl;}
		else {system("clear");cout<<"Вы ввели неправильное значение!"<<endl;}
	}
	else if (t==2)
	{
	cout<<"1. Хочу увеличить эффективность"<<endl
			<<"2. Хочу уменьшить эффективность"<<endl
			<<"3. Хочу выйти в главное меню"<<endl;
		cin>>result_eff;
		if(result_eff==1) 
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_eff_up;
			c_st.efficency=c_st.efficency+amount_eff_up;
			if(c_st.efficency>100.0) {system("clear");cout<<"Произошла ошибка"<<endl;c_st.efficency=-1;}
		}
		else if (result_eff==2)
		{
			cout<<"На сколько?"<<endl;
			cin>>amount_eff_down;
			c_st.efficency=c_st.efficency-amount_eff_down;
			if(c_st.efficency<0.0) {system("clear");cout<<"Произошла ошибка"<<endl;c_st.efficency=-1;}
		}
		else if(result_eff==3) {system("clear");cout<<"Вы вышли в главное меню"<<endl;}
		else {system("clear");cout<<"Вы ввели неправильное значение!"<<endl;}
	}
	else if(t==3) {system("clear"); cout<<"Вы вышли в главное меню!"<<endl;}
	else {system("clear");cout<<"Вы ввели неправильное значение!"<<endl;}
}

void vivod_pipe (pipe &my_pipe) //вывод данных о трубе
{
	system("clear");
cout << "Данные, собранные по указанной пользователем трубе:" <<endl
	<< "Идентификатор трубы: " << my_pipe.id << endl
    << "Длина данной трубы: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр данной трубы: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Статус трубы: "<<(my_pipe.in_repair?"В ремонте":"Не в ремонте")<<endl;
}


void vivod_KS(comp_st &c_st) //вывод данных о КС
{
cout << endl << "Данные, собранные по указанной пользователем КС" << endl
	 << "Идентификатор КС: " << c_st.id << endl
	 << "Название КС: " << c_st.ks_name << endl
	 << "Количество цехов на данной КС: " << c_st.ceh_amount <<endl
	 << "Количество работающих цехов на данный момент: " << c_st.ceh_INwork_amount << endl
	 << "Эффективность КС: "<<c_st.efficency;
}

void save_pipe(pipe &my_pipe)  //запись данных о трубе в файл
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

void save_KS(comp_st &c_st)  //запись данных о КС в файл
{
system("clear");
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

void menu(pipe &my_pipe,comp_st &c_st)  //меню
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
			system("clear");
			cout<<"Труба добавлена!"<<endl;}
			else {system("clear"); cout<<"Было добавлено максимальное количество труб!"<<endl;}
		//system("clear");
		break;
	case 2:
	
			if(c_st.id<1)
			{++c_st.id;
			system("clear");
			cout<<"КС добавлена!"<<endl;}
			else {system("clear");cout<<"Добавлено максимальное количество КС"<<endl;}
		//system("clear");
		break;
	case 3:
	if(my_pipe.diametr==0 && my_pipe.length==0 && c_st.ceh_amount==0 && c_st.ceh_INwork_amount==0) {system("clear");cout<<"Выполните ввод данных"<<endl;}
	else	
	{	cout<<endl;
		if(my_pipe.diametr!=-1 && my_pipe.length!=-1 && c_st.ceh_amount!=-1 && c_st.ceh_INwork_amount!=-1)
		{vivod_pipe(my_pipe);
		vivod_KS(c_st);
		cout << endl<<endl;}
		else {system("clear");cout<<"Были неправильно введены данные, перезайдите в программу"<<endl;}
	}
		break;
	case 4:
	
		change_repair(my_pipe);
		break;
	case 5:
	
	if(c_st.efficency!=-1 && c_st.ceh_INwork_amount!=-1 && c_st.efficency!=0 && c_st.ceh_INwork_amount!=0)
		{change_KS(c_st);
		system("clear");
		cout<<"КС отредактирована!"<<endl;}
		else {system("clear"); cout<<"Вы ввели неправильные данные"<<endl;}
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
		cout<<"Вы уверены, что хотите выйти из программы?"<<endl
			<<"1. Да "<<endl
			<<"2. Нет"<<endl;
		 cin>>y;
		 if(y==1) exit(0);
		 else if (y==2) system("clear");
		 else {cout<<"Было введено неправильное значение"<<endl;}
		break;
	default:
		cout<<"Ошибка при вводе!"<<endl;
		break;
	}
	//system("clear");
	}
}	

int main()
{	
	setlocale(LC_ALL,"Russian");
	pipe my_pipe;
	comp_st c_st;

	//задекларировали в мэйне параметры трубы
	my_pipe.id=0, my_pipe.length=0.00, my_pipe.in_repair=0, my_pipe.diametr=0;
	//задекларировали в мэйне параметры кс
	c_st.id=0, c_st.ceh_amount=0, c_st.ceh_INwork_amount=0, c_st.efficency=75.2;
	//вызов меню
	menu(my_pipe,c_st);
	return 0;
}