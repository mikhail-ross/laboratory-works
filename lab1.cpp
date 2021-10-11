#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
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

void type_pipe (pipe &my_pipe)	//проверка типа и ввод данных трубы
{	//инициализация
	double input_double=my_pipe.length;
	int input=my_pipe.diametr;
	while(true)
	{
	//проверка длины
	cout<<"Введите длину трубы"<<endl;
	while(!(cin>>input_double) || input_double <0)
	{
	cin.clear();
	cin.ignore(10000,'\n');
	system("clear");
	cout<<"Введён неверный символ, введите длину заново"<<endl;	
	}
	system("clear");
	cout<<"Длина введена"<<endl;
	my_pipe.length=input_double;
	cin.ignore(10000,'\n');
	system("clear");
	//проверка диаметра
	cout<<"Введите диаметр трубы"<<endl;
	while(!(cin>>input) || input <0 || input>1420)
	{
	cin.clear();
	cin.ignore(10000,'\n');
	system("clear");
	cout<<"Введён неверный символ, введите диаметр заново"<<endl;
	}
	system("clear");
	cout<<"Диаметр введён"<<endl;
	my_pipe.diametr=input;
	break;
}
}

void type_KS (comp_st & c_st) //проверка типа и ввод данных КС
{	
	//инициализация
	int ceh_input, ceh_INwork_input;
	double efficency_input;
	//string name_prov;

	//проверка цехов
	cout<<"Введите количество цехов"<<endl;
	while(true)
	{
	while(!(cin>>ceh_input) || ceh_input<0)
	{
	cin.clear();
	cin.ignore(10000,'\n');
	system("clear");
	cout<<"Введён неверный символ, введите количество цехов заново"<<endl;	
	}
	cout<<"Количество цехов введено"<<endl;
	c_st.ceh_amount=ceh_input;
	cin.ignore(10000,'\n');
	system("clear");
	//проверка цехов в работе
	cout<<"Введите количество работающих цехов"<<endl;
	while(!(cin>>ceh_INwork_input) || ceh_INwork_input<0 || ceh_INwork_input>ceh_input)
	{
	cin.clear();
	cin.ignore(10000,'\n');
	system("clear");
	cout<<"Введён неверный символ, введите количество работающих цехов заново"<<endl;	
	}
	cout<<"Количество работающих цехов введено"<<endl;
	c_st.ceh_INwork_amount=ceh_INwork_input;
	cin.ignore(10000,'\n');
	system("clear");

	cout<<"Введите эффективность"<<endl;
	while(!(cin>>efficency_input) || efficency_input<0.0 || efficency_input >100.0)
	{
	cin.clear();
	cin.ignore(10000,'\n');
	system("clear");
	cout<<"Введён неверный символ, введите эффективность заново"<<endl;	
	}
	cout<<"Эффективность введена"<<endl;
	c_st.efficency=efficency_input;
	cin.ignore(10000,'\n');
	system("clear");
	break;
	}
}

void vvod_pipe(pipe &my_pipe)  //ввод данных о трубе с клавиатуры
{
++my_pipe.id;
type_pipe(my_pipe);
}

void vvod_KS(comp_st &c_st)  //ввод данных о КС с клавиатуры
{
++c_st.id;
cout<<"Введите название КС"<<endl;
cin.ignore(10000,'\n');
while(true)
{
getline(cin,c_st.ks_name);
while(true)
{
	int i=0;
if (c_st.ks_name[i]==' ')
{
	c_st.ks_name.erase(i,i+1);
	++i;
}
else break;
}
if(c_st.ks_name.empty())
{
cin.clear();
cin.ignore(10000,'\n');
system("clear");
cout<<"Введите адекватное название"<<endl;
}
else break;
}
cin.clear();
type_KS(c_st);
}

void vvod(pipe &my_pipe, comp_st &c_st)  //ввод данных из файла
{
		ifstream fin;
		fin.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt");
if (fin.is_open())
{
	fin >> my_pipe.id >> my_pipe.length >> my_pipe.diametr >> my_pipe.in_repair
		>> c_st.id;
	fin.ignore(10000,'\n');
	getline(fin,c_st.ks_name); 
	fin >> c_st.ceh_amount >> c_st.ceh_INwork_amount >> c_st.efficency;
	if(my_pipe.diametr<=0||my_pipe.diametr>1420) 
	{
		fin.clear();
		system("clear");
		cout<<"Вы ввели недопустимый диаметр трубы"<<endl;
		}
	else if(my_pipe.length<1) 
	{
		fin.clear();
		system("clear");
		cout<<"Вы ввели недопустимую длину трубы"<<endl;
		}
	else if(c_st.ceh_amount<c_st.ceh_INwork_amount || c_st.ceh_amount<0||c_st.ceh_INwork_amount<0 || c_st.efficency < 0.0 || c_st.efficency > 100.0) 
	{
		fin.clear();
		system("clear");
		cout<<"Вы ввели недопустимые значения"<<endl;
		}
}
fin.close();
system("clear");
cout<<"Данные введены"<<endl;
	}

void change_repair(pipe &my_pipe) //редактирование трубы
{
system("clear");
if(my_pipe.id>0)
{
if (my_pipe.in_repair==0) 
{
	my_pipe.in_repair=1; 
	cout<<"Труба отредактирована!"<<endl;
	}
else if(my_pipe.in_repair==1) 
{
	my_pipe.in_repair=0; 
	cout<<"Труба отредактирована!"<<endl;
	}
}
}

void change_KS(comp_st &c_st) //редактирование КС
{
	int t;
	cout<<"1. Хочу изменить количество работающих цехов"<<endl
		<<"2. Хочу изменить значение эффективности КС"<<endl;
	cin>>t;
	if(t==1)
	{
		while (true)
		{
			cout<<"Введите изменённое количество работающих цехов"<<endl;
			cin>>c_st.ceh_INwork_amount;
			if(c_st.ceh_INwork_amount>c_st.ceh_amount || c_st.ceh_INwork_amount<0) 
			{
				cin.clear();
				cin.ignore(10000,'\n');
				system("clear");
				cout<<"Произошла ошибка"<<endl; 
				}
			else break;
		}	
		}
	else if (t==2)
	{
		while (true)
		{
			cout<<"Введите изменённую эффективность"<<endl;
			cin>>c_st.efficency;
			if(c_st.efficency>100.0) 
			{
				cin.clear();
				cin.ignore(10000,'\n');
				system("clear");
				cout<<"Произошла ошибка"<<endl;
				}
			else if(c_st.efficency<0.0) 
			{
				cin.clear();
				cin.ignore(10000,'\n');
				system("clear");
				cout<<"Произошла ошибка"<<endl;
				}
			else break;
		}
	}
	else 
	{
		system("clear");
		cout<<"Вы ввели неправильное значение!"<<endl;
		}
}


void vivod_pipe (pipe &my_pipe) //вывод данных о трубе
{
	system("clear");
cout << "Данные по трубе:" <<endl
	<< "Идентификатор: " << my_pipe.id << endl
    << "Длина: " << my_pipe.length << ' ' << "метров" << endl
	<< "Диаметр: " << my_pipe.diametr << ' ' << "миллиметров" <<endl
   	<< "Статус: "<<(my_pipe.in_repair?"подключён":"Не подключён")<<endl;
}


void vivod_KS(comp_st &c_st) //вывод данных о КС
{
cout << endl << "Данные по КС" << endl
	 << "Идентификатор: " << c_st.id << endl
	 << "Название: " << c_st.ks_name << endl
	 << "Общее количество цехов: " << c_st.ceh_amount <<endl
	 << "Количество работающих цехов: " << c_st.ceh_INwork_amount << endl
	 << "Эффективность: "<<c_st.efficency <<" %"<< endl;
}

void save_file(pipe &my_pipe, comp_st &c_st)  //запись данных о трубе в файл
{
ofstream out;
out.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt");
if(out.is_open())
	{
		out << my_pipe.id << endl
    		<< my_pipe.length << endl
			<< my_pipe.diametr << endl
   			<< my_pipe.in_repair << endl;
	    out << c_st.id << endl
	 		<< c_st.ks_name << endl
	 		<< c_st.ceh_amount <<endl
	 		<< c_st.ceh_INwork_amount << endl
	 		<<c_st.efficency <<endl;
	}
	out.close();

}

void menu(pipe &my_pipe,comp_st &c_st)  //меню
{
	string S;
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
	cin>>S;
	if(S=="1"||S=="2"||S=="3"||S=="4"||S=="5"||S=="6"||S=="7"||S=="0")
	{	x=atoi(S.c_str());  //преобразование string в integer, поскольку switch работает с integer
		switch (x) {
	case 1:
	
			if(my_pipe.id<1)
			{
			system("clear");
			vvod_pipe(my_pipe);
			cout<<"Труба добавлена!"<<endl;
			}
			else 
			{
				system("clear"); 
				cout<<"Было добавлено максимальное количество труб!"<<endl;
			}
		break;
	case 2:
	
			if(c_st.id<1)
			{
			system("clear");
			vvod_KS(c_st);
			cout<<"КС добавлена!"<<endl;
			}
			else 
			{
				system("clear");
				cout<<"Добавлено максимальное количество КС"<<endl;
				}
		break;
	case 3:
	if(my_pipe.diametr==0 && my_pipe.length==0 && c_st.ceh_amount==0 && c_st.ceh_INwork_amount==0) 
	{
		system("clear");
		cout<<"Выполните ввод данных"<<endl;
	}
	else	
	{	if(my_pipe.id>0) vivod_pipe(my_pipe);
		if(c_st.id>0) vivod_KS(c_st);
	}
		break;
	case 4:
		if(my_pipe.id==0)
		{
			system("clear");
			cout<<"Вы не ввели ни одной трубы для редактирования!"<<endl;
		}
		else
			change_repair(my_pipe);
		break;
	case 5:
		change_KS(c_st);
		system("clear");
		cout<<"КС отредактирована!"<<endl;
		break;
	case 6:
		if(my_pipe.id>0 && c_st.id>0 && my_pipe.length>0 && my_pipe.diametr>0 && c_st.ceh_amount>0 && c_st.ceh_INwork_amount>0)
		{
		save_file(my_pipe, c_st);
		system("clear");
		cout<<"Данные сохранены"<<endl;
		}
		else 
		{
			system("clear"); 
			cout<<"Вы ввели недостаточно данных для сохранения в файл"<<endl;
		}
		break;
	case 7:
		vvod(my_pipe,c_st);	
		break;
	case 0:
		exit(0);
		break;
	default:
		system("clear");
		cout<<"Ошибка при вводе!"<<endl;
		break;
	}
	}
	else 
	{
		system("clear");
		cout<<"Вы ввели неверные данные!"<<endl;
	}
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
	c_st.id=0, c_st.ceh_amount=0, c_st.ceh_INwork_amount=0, c_st.efficency=0.0;
	//вызов меню
	system("clear");
	menu(my_pipe,c_st);
	return 0;
}