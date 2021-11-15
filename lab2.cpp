#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "pipe.h"
#include "utils.h"
#include "ks.h"
using namespace std;

int id_pipe=0, id_ks=0, res_id=0;

/*using Filter = bool(*)(const unordered_map<int,pipe> &pipemap, bool param);
bool CheckByRepair(const unordered_map<int,pipe> &pipemap, bool param)
{
	return pipemap.second.in_repair=param;
}

unordered_map<int,pipe> find_by_filter(const pipe& my_pipe, const unordered_map<int,pipe> &pipemap, Filter f, bool repair)
{
	unordered_map<int,pipe> res;
	for(pair<int,pipe> elm : pipemap)
	{
		if(f(elm,repair))
		{
			res_id=elm.first;
			res.insert({res_id,my_pipe});
		}
	} 
	return res;
}
*/

template <typename T, typename T_param>
using Filter = bool(*)(const T &map, T_param param);
bool pipe_check_name(const pipe &my_pipe, string param)
{
	return my_pipe.pipe_name==param;
}
bool check_repair(const pipe &my_pipe, bool param)
{
	return my_pipe.in_repair==param;
}
bool ks_check_name(const comp_st& c_st, string param)
{
	return c_st.ks_name==param;
}
bool check_by_ceh_INwork(const comp_st& c_st, double param)
{
	return (c_st.ceh_INwork_amount/c_st.ceh_amount)*100==param;
}

template<typename T, typename T_param>
vector<int> find_by_filter(const unordered_map<int, T> &map, Filter<T,T_param> f, T_param param)
{
	vector<int> res;
	for (auto & elm:map)
		if(f(elm.second,param))
			res.push_back(elm.first);
	return res;
}

void vvod_pipe (pipe &my_pipe)	//проверка типа и ввод данных трубы
{
	cout<<"Введите название трубы"<<endl;
    cin>>ws;
    getline(cin, my_pipe.pipe_name);
	cout<<"Введите длину трубы"<<endl;
	my_pipe.length = GetNumber(100.0, 1500.0);
	cout<<"Введите диаметр трубы"<<endl;
	my_pipe.diametr = GetNumber( 100, 1420);
}

void vvod_KS (comp_st &c_st) //проверка типа и ввод данных КС
{
    cout<<"Введите название КС"<<endl;
    cin>>ws;
    getline(cin, c_st.ks_name);
	cout<<"Введите количество цехов"<<endl;
	c_st.ceh_amount=GetNumber(1,500);
	cout<<"Введите количество работающих цехов"<<endl;
	c_st.ceh_INwork_amount=GetNumber(0,c_st.ceh_amount);
	cout<<"Введите эффективность"<<endl;
	c_st.efficency=GetNumber(0.0,100.0);
}

void vvod_from_file(pipe &my_pipe, comp_st &c_st, unordered_map <int,pipe>& pipemap, unordered_map <int,comp_st>& ksmap)  //ввод данных из файла
{
	//int id_pipe, id_ks;
    ifstream fin;
	fin.open("/home/mikhail/vim/semester3/laboratory-works/info_lab.txt");
    if (!fin.is_open())
        return;
	while(fin.peek()!='\n')
	{
	fin >> id_pipe;
	fin>>ws;
	getline(fin,my_pipe.pipe_name);
	fin >> my_pipe.length >> my_pipe.diametr >> my_pipe.in_repair;
	
	if(my_pipe.length<1 || my_pipe.diametr<=0||my_pipe.diametr>1420)
	{
	cout<<"Вы ввели недопустимые значения"<<endl;
		c_st={};
		my_pipe={};
		return;	
	}
	pipemap.insert ({id_pipe,my_pipe});
	}

	while(!fin.eof())
	{
	fin >> id_ks;
	fin>>ws;
	getline(fin,c_st.ks_name);
	fin >> c_st.ceh_amount >> c_st.ceh_INwork_amount >> c_st.efficency;
	
	if(c_st.ceh_amount<c_st.ceh_INwork_amount || c_st.ceh_amount<=0||c_st.ceh_INwork_amount<0 ||
		 c_st.efficency < 0.0 || c_st.efficency > 100.0)
	{
		cout<<"Вы ввели недопустимые значения"<<endl;
		c_st={};
		my_pipe={};
		return;
    }
	ksmap.insert ({id_ks,c_st});
    }
	fin.close();
}

void change_repair(unordered_map <int,pipe>& pipemap) //редактирование трубы
{
	int id;
	cout<<"Введите id"<<endl;
	cin>>id;
	auto result=pipemap.find(id);
	if(result != pipemap.end())
	{
	result->second.in_repair=!result->second.in_repair;	
	}
	else cout<<"выбранная труба не была найдена"<<endl;
}

void change_KS(unordered_map <int,comp_st>& ksmap) //редактирование КС
{
	int x;
	cout<<"Введите id кс"<<endl;
	cin>>x;
	auto result=ksmap.find(x);
	if(result != ksmap.end())
	{
		cout<<"1. Хочу изменить количество работающих цехов"<<endl
			<<"2. Хочу изменить значение эффективности КС"<<endl;
	int t = GetNumber(1,2);
	if(t==1)
	{
			cout<<"Введите изменённое количество работающих цехов"<<endl;
			result->second.ceh_INwork_amount = GetNumber(0, result->second.ceh_amount);
    }
	else if (t==2)
	{
			cout<<"Введите изменённую эффективность"<<endl;
			result->second.efficency = GetNumber(0.0,100.0);
	}
	}
	else cout<<"Объект не найден"<<endl;
}

void delete_pipe(unordered_map <int,pipe>& pipemap)
{
	int x=0;
	cout<<"Введите id трубы"<<endl;
	cin>>x;
	auto result=pipemap.find(x);
	if(result != pipemap.end())
	{
	pipemap.erase(result);	
	}
	else cout<<"выбранная труба не была найдена"<<endl;	
}



void delete_ks(unordered_map <int,comp_st>& ksmap)
{
	int x=0;
	cout<<"Введите id КС"<<endl;
	cin>>x;
	auto result=ksmap.find(x);
	if(result != ksmap.end())
	{
	ksmap.erase(result);	
	}
	else cout<<"выбранная кс не была найдена"<<endl;
}

void vivod_pipe (const unordered_map <int,pipe>& pipemap) //вывод данных о трубе
{	cout << "Данные по трубе:" <<endl;
    for(pair<int,pipe> element : pipemap)
			{
				cout<<element.first<<endl
				<<element.second.pipe_name<<"		"
				<<element.second.length<<' '<< "км "
				<<element.second.diametr<<' '<< "мм "
				<<(element.second.in_repair?"подключён":"Не подключён")<<endl;
			}
}

void vivod_KS(const unordered_map <int,comp_st>& ksmap) //вывод данных о КС
{
    cout << endl << "Данные по КС" << endl;
    for(pair<int,comp_st> element : ksmap)
			{
				cout<<element.first<<endl
				<<element.second.ks_name<<"		"
				<<element.second.ceh_amount<<' '
				<<element.second.ceh_INwork_amount<<' '
				<<element.second.efficency<<"%"<<endl;
			}
}

void save_file(const unordered_map <int,pipe>& pipemap, const unordered_map <int,comp_st>& ksmap)
{
    ofstream out;
    out.open("/home/mikhail/vim/semester3/laboratory-works/info_lab.txt");
    if(out.is_open())
	{
		for(pair<int, pipe> element : pipemap)
		{
		out << element.first << " "
			<< element.second.pipe_name << endl
    		<< element.second.length << " "
			<< element.second.diametr << " "
   			<< element.second.in_repair << " ";
		}
		for(pair<int, comp_st> element : ksmap)
		{
		out << element.first << " "
	 		<< element.second.ks_name << endl
	 		<< element.second.ceh_amount << " "
	 		<< element.second.ceh_INwork_amount << " "
	 		<< element.second.efficency << " ";
		}
        out.close();
	}
}

void filter_pipe(unordered_map<int, pipe> &pipemap)
{
	if(pipemap.size()==0)
			return;
	cout<<"1. Фильтр по названию"<<endl
		<<"2. Фильтр по признаку 'в ремонте'"<<endl;
	int result=GetNumber(1,2);
	string name;
	if(result==1)
	{
		cin>>ws;
		getline(cin,name);
		vector<int> vec_ind = find_by_filter(pipemap, pipe_check_name, name);
		for(auto &id : vec_ind)
			cout<<id<<pipemap[id];
	}
	else
	{
		bool bool_repair=GetNumber(0,1);
		vector<int> vec_ind = find_by_filter(pipemap, check_repair, bool_repair);
		for(auto &id : vec_ind)
			cout<<id<<pipemap[id];
	}
}

void filter_ks(unordered_map<int, comp_st>& ksmap)
{
	if(ksmap.size()==0)
		return;
	int result=GetNumber(1,2);
	string name;
	if(result==1)
	{
		cin>>ws;
		getline(cin,name);
		vector<int> vec_ind = find_by_filter(ksmap, ks_check_name, name);
		for(auto &id : vec_ind)
			cout<<id<<ksmap[id];
	}
	else
	{
		double percent_INwork = GetNumber(0.0,100.0);
		vector<int> vec_ind = find_by_filter(ksmap,check_by_ceh_INwork, percent_INwork);
		for(auto &id : vec_ind)
			cout<<id<<ksmap[id];
	}
}

void menu()
{
	system("clear");
		cout<< "1. Добавить трубу" << endl
			<< "2. Добавить КС" << endl
			<< "3. Просмотр всех объектов" << endl
			<< "4. Редактировать трубу" << endl
			<< "5. Редактировать КС" << endl
			<< "6. Сохранить данные в файл" << endl
			<< "7. Ввести данные" << endl
			<< "8. Удалить трубу" << endl
			<< "9. Удалить КС" << endl
			<< "10. Фильтрация труб" << endl
			<< "11. Фильтрация КС" << endl
			<< "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	system("clear");
	pipe my_pipe;
	comp_st c_st;
	unordered_map <int,pipe> pipemap;
	unordered_map <int,comp_st> ksmap;
	while (true)
	{
    menu();
	switch (GetNumber(0, 11))
	{
    case 1:
			{
			++id_pipe;
			vvod_pipe(my_pipe);
			pipemap.insert({id_pipe, my_pipe});
			}
		break;
	case 2:
			{
			++id_ks;
			vvod_KS(c_st);
			ksmap.insert({id_ks,c_st});
			}
		break;
	case 3:
	{
		if(id_pipe>0)
		vivod_pipe(pipemap);
		if(id_ks>0)
            vivod_KS(ksmap);
		if (id_pipe==0 && id_ks==0)
			cout<<"Выполните ввод данных"<<endl;
		break;
    }
	case 4:
		if(id_pipe==0)
			cout<<"Вы не ввели ни одной трубы для редактирования!"<<endl;
		else
			change_repair(pipemap);
		break;
	case 5:
        if (id_ks==0)
            cout<<"Вы не ввели ни одной КС для редактирования!"<<endl;
        else
            change_KS(ksmap);
		break;
	case 6:
		if(id_pipe>0 && id_ks>0)
			save_file(pipemap, ksmap);
		else
			cout<<"Вы ввели недостаточно данных для сохранения в файл"<<endl;	
		break;
	case 7:
		vvod_from_file(my_pipe, c_st, pipemap, ksmap);
		break;
	case 8:
		delete_pipe(pipemap);
		break;
	case 9:
		delete_ks(ksmap);
		break;
	case 10:
		filter_pipe(pipemap);
		break;
	case 11:
		//filter_ks(ksmap);
		break;
	case 0:
        return 0;
		break;
	}
	system("read -p 'press enter to continue... ' var");
	}
	return 0;
}