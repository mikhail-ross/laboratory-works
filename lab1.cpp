#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct pipe     //труба
{
	int id=0, diametr=0;
	double length=0.00;
	bool in_repair=0;
};

struct comp_st     // компрессорная станция
{
	int id=0, ceh_amount=0,ceh_INwork_amount=0;
	string ks_name;
	double efficency=0.00;
};

template <typename T>
T GetNumber(T min, T max)
{
    T x;
    while(!(cin>>x) || x< min || x> max)
        {
        cin.clear();
        cin.ignore(10000,'\n');
        system("clear");
        cout<<"Введён неверный символ, введите заново"<<endl;
        }
        return x;
}

void vvod_pipe (pipe &my_pipe)	//проверка типа и ввод данных трубы
{
    ++my_pipe.id;
	//проверка длины
	cout<<"Введите длину трубы"<<endl;
	my_pipe.length = GetNumber(100.0, 1500.0);
	system("clear");
	//проверка диаметра
	cout<<"Введите диаметр трубы"<<endl;
	my_pipe.diametr = GetNumber( 100, 1420);

}

void vvod_KS (comp_st &c_st) //проверка типа и ввод данных КС
{
    ++c_st.id;
    string name_input;
    cout<<"Введите название КС"<<endl;
    while(true)
    {
    getline(cin, name_input);
    name_input.erase(0, name_input.find_first_not_of(" \n\r\t"));
    name_input.erase(name_input.find_last_not_of(" \n\r\t")+1); //https://stackoveflow.com/a/33099753
    if (name_input.length()>0)
        {
        c_st.ks_name=name_input;
        break;
        }
        else
            cout<<"Введите нормальное имя"<<endl;
    }
	cout<<"Введите количество цехов"<<endl;
	c_st.ceh_amount=GetNumber(1,500);
	system("clear");
	cout<<"Введите количество работающих цехов"<<endl;
	c_st.ceh_INwork_amount=GetNumber(0,c_st.ceh_amount);
	system("clear");
	cout<<"Введите эффективность"<<endl;
	c_st.efficency=GetNumber(0.0,100.0);
	system("clear");
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
	if(c_st.ceh_amount<c_st.ceh_INwork_amount || c_st.ceh_amount<=0||c_st.ceh_INwork_amount<0 || c_st.efficency < 0.0 || c_st.efficency > 100.0
            || my_pipe.length<1 || my_pipe.diametr<=0||my_pipe.diametr>1420)
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
if (my_pipe.in_repair==0)
    my_pipe.in_repair=1;
else if(my_pipe.in_repair==1)
    my_pipe.in_repair=0;

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
			if(c_st.efficency>100.0 || c_st.efficency<0.0)
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

void save_file(const pipe &my_pipe, const comp_st &c_st)  //запись данных о трубе в файл
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

void menu()  //меню
{
    pipe my_pipe;
	comp_st c_st;
	string S;
	int x;
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
	cin.ignore(10000,'\n');
	if(S=="1"||S=="2"||S=="3"||S=="4"||S=="5"||S=="6"||S=="7"||S=="0")
	{
        x=atoi(S.c_str());  //преобразование string в integer, поскольку switch не работает с string
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
				my_pipe.id=0;
				vvod_pipe(my_pipe);
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
				c_st.id=0;
				vvod_KS(c_st);
				}
		break;
	case 3:
		if(my_pipe.id>0 && c_st.id==0)
            vivod_pipe(my_pipe);
		else if(c_st.id>0 && my_pipe.id==0)
            vivod_KS(c_st);
		else if (c_st.id>0 && my_pipe.id>0)
		{
			vivod_pipe(my_pipe);
			vivod_KS(c_st);
		}
		else
		{
			system("clear");
			cout<<"Выполните ввод данных"<<endl;
		}
		break;
	case 4:
		if(my_pipe.id==0)
		{
			system("clear");
			cout<<"Вы не ввели ни одной трубы для редактирования!"<<endl;
		}
		else
		{
			change_repair(my_pipe);
			system("clear");
			cout<<"Труба отредактирована!"<<endl;
		}
		break;
	case 5:
        if (c_st.id==0)
        {
            system("clear");
            cout<<"Вы не ввели ни одной КС для редактирования!"<<endl;
        }
        else
        {
            change_KS(c_st);
            system("clear");
            cout<<"КС отредактирована!"<<endl;
        }
		break;
	case 6:
		if(my_pipe.id>0 && c_st.id>0 && my_pipe.length>0 && my_pipe.diametr>0 && c_st.ceh_amount>0 && c_st.ceh_INwork_amount>0 && c_st.efficency>0)
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
	system("clear");
	menu();
	return 0;
}
