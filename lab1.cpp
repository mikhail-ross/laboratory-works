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
    my_pipe.id=1;
	cout<<"Введите длину трубы"<<endl;
	my_pipe.length = GetNumber(100.0, 1500.0);
	cout<<"Введите диаметр трубы"<<endl;
	my_pipe.diametr = GetNumber( 100, 1420);
}

void vvod_KS (comp_st &c_st) //проверка типа и ввод данных КС
{
    c_st.id=1;
    cout<<"Введите название КС"<<endl;
    cin>>ws;
    getline(cin, c_st.ks_name);
   // name_input.erase(0, name_input.find_first_not_of(" \n\r\t"));
    //name_input.erase(name_input.find_last_not_of(" \n\r\t")+1); //https://stackoveflow.com/a/33099753
	cout<<"Введите количество цехов"<<endl;
	c_st.ceh_amount=GetNumber(1,500);
	cout<<"Введите количество работающих цехов"<<endl;
	c_st.ceh_INwork_amount=GetNumber(0,c_st.ceh_amount);
	cout<<"Введите эффективность"<<endl;
	c_st.efficency=GetNumber(0.0,100.0);
}

void vvod(pipe &my_pipe, comp_st &c_st)  //ввод данных из файла
{
    ifstream fin;
	fin.open("/home/mikhail/vim/semester3/laboratory-works/info_lab1.txt");
    if (!fin.is_open())
        return;

	fin >> my_pipe.id >> my_pipe.length >> my_pipe.diametr >> my_pipe.in_repair;

	fin >> c_st.id;
	fin>>ws;
	getline(fin,c_st.ks_name);
	fin >> c_st.ceh_amount >> c_st.ceh_INwork_amount >> c_st.efficency;

    fin.close();
    system("clear");

	if(c_st.ceh_amount<c_st.ceh_INwork_amount || c_st.ceh_amount<=0||c_st.ceh_INwork_amount<0 || c_st.efficency < 0.0 || c_st.efficency > 100.0
            || my_pipe.length<1 || my_pipe.diametr<=0||my_pipe.diametr>1420)
	{
		cout<<"Вы ввели недопустимые значения"<<endl;
		c_st={};
		my_pipe={};
		return;
    }
    cout<<"Данные введены"<<endl;
}

void change_repair(pipe &my_pipe) //редактирование трубы
{
    my_pipe.in_repair=!my_pipe.in_repair;
}

void change_KS(comp_st &c_st) //редактирование КС
{
	cout<<"1. Хочу изменить количество работающих цехов"<<endl
		<<"2. Хочу изменить значение эффективности КС"<<endl;
	int t = GetNumber(1,2);
	if(t==1)
	{
			cout<<"Введите изменённое количество работающих цехов"<<endl;
			c_st.ceh_INwork_amount = GetNumber(0, c_st.ceh_amount);
    }
	else if (t==2)
	{
			cout<<"Введите изменённую эффективность"<<endl;
			c_st.efficency = GetNumber(0.0,100.0);
	}
}

void vivod_pipe (pipe &my_pipe) //вывод данных о трубе
{
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

        out.close();
	}
}

void menu()  //меню
{
    pipe my_pipe;
	comp_st c_st;
	while (true)
	{
        system("clear");
		cout<< "1. Добавить трубу" << endl
			<< "2. Добавить КС" << endl
			<< "3. Просмотр всех объектов" << endl
			<< "4. Редактировать трубу" << endl
			<< "5. Редактировать КС" << endl
			<< "6. Сохранить данные в файл" << endl
			<< "7. Ввести данные" << endl
			<< "0. Выход" << endl;
		switch (GetNumber(0, 7))
		{
        case 1:
			{
			vvod_pipe(my_pipe);
			cout<<"Труба добавлена!"<<endl;
			}
		break;
	case 2:
			{
			vvod_KS(c_st);
			cout<<"КС добавлена!"<<endl;
			}
		break;
	case 3:
	{
		if(my_pipe.id>0)
            vivod_pipe(my_pipe);
		if(c_st.id>0)
            vivod_KS(c_st);
		if (c_st.id==0 && my_pipe.id==0)
			cout<<"Выполните ввод данных"<<endl;
        system("read -p 'press enter to continue... ' var");
		break;
    }
	case 4:
		if(my_pipe.id==0)
			cout<<"Вы не ввели ни одной трубы для редактирования!"<<endl;
		else
		{
			change_repair(my_pipe);
			cout<<"Труба отредактирована!"<<endl;
		}
		break;
	case 5:
        if (c_st.id==0)
            cout<<"Вы не ввели ни одной КС для редактирования!"<<endl;
        else
        {
            change_KS(c_st);
            cout<<"КС отредактирована!"<<endl;
        }
		break;
	case 6:
		if(my_pipe.id>0 && c_st.id>0 && my_pipe.length>0 && my_pipe.diametr>0 && c_st.ceh_amount>0 && c_st.ceh_INwork_amount>0 && c_st.efficency>0)
		{
		save_file(my_pipe, c_st);
            cout<<"Данные сохранены"<<endl;
		}
		else
		{
			cout<<"Вы ввели недостаточно данных для сохранения в файл"<<endl;
		}
		break;
	case 7:
		vvod(my_pipe,c_st);
		break;
	case 0:
        return;
		break;
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
