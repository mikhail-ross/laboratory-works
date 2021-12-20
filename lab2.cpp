#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "pipe.h"
#include "utils.h"
#include "ks.h"
using namespace std;
//int id_pipe=0, id_ks=0, res_id=0;

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

void vvod_from_file(pipe &my_pipe, comp_st &c_st, unordered_map <int,pipe>& pipemap, unordered_map <int,comp_st>& ksmap)  //ввод данных из файла
{
	pipe NewPipe;
	comp_st NewKS;
	string result;
	cout<<"Введите название файла: "<<endl;
	cin>>ws;
	getline(cin,result);
    ifstream fin;
	fin.open(result);
    if (!fin.is_open())
        return;
	while(fin.peek()!='\n')
	{
	fin >> pipe::id_pipe;
	//int n = pipe::id_pipe;
	//if(pipe::id_pipe>n) pipe
	fin>>NewPipe;
	if(NewPipe.length<1 || NewPipe.diametr<=0||NewPipe.diametr>1420)
	{
	cout<<"Вы ввели недопустимые значения"<<endl;
		c_st={};
		my_pipe={};
		return;	
	}
	pipemap.insert ({pipe::id_pipe,my_pipe});
	}

	while(!fin.eof())
	{
	fin >> comp_st::id_ks;
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
	ksmap.insert ({comp_st::id_ks,c_st});
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

void delete_pipe(unordered_map <int,pipe>& pipemap, vector<int> vec_ind)
{
	for(auto &i:vec_ind)
		pipemap.erase(i);
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
    for(auto &pipeh : pipemap)
			{
				cout<<pipeh.first<<" "
					<<pipeh.second<<endl;
			}
}

void vivod_KS(const unordered_map <int,comp_st>& ksmap) //вывод данных о КС
{
    cout << endl << "Данные по КС" << endl;
    for(auto &ks : ksmap)
			{
				cout<<ks.first<<"  "
					<<ks.second<<endl;
			}
}

void save_file(const unordered_map <int,pipe>& pipemap, const unordered_map <int,comp_st>& ksmap)
{
	string result;
	cout<<"Введите название файла: "<<endl;
	cin>>ws;
	getline(cin,result);
    ofstream fout;
    fout.open(result);
    if(fout.is_open())
	{
		for(auto& pipeh : pipemap)
		{
			fout << pipeh.first << " "
				 << pipeh.second;
		/*fout << element.first << " "
			<< element.second.pipe_name << endl
    		<< element.second.length << " "
			<< element.second.diametr << " "
   			<< element.second.in_repair << " ";*/
		}
		fout<<endl;
		for(auto &ks : ksmap)
		{
		fout << ks.first << " "
	 		/*<< element.second.ks_name << endl
	 		<< element.second.ceh_amount << " "
	 		<< element.second.ceh_INwork_amount << " "
	 		<< element.second.efficency << " ";*/
			 << ks.second;
		}
        fout.close();
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
		cout<<"1. Редактировать данные"<<endl;
		bool number=GetNumber(0,1);
		if(number==1)
			for(auto&id : vec_ind)
				pipemap[id].repair_pipe();
		else 
			return;
	}
	else
	{
		int vibor_id;
		cout<<"Введите признак в ремонте"<<endl;
		bool bool_repair=GetNumber(0,1);
		vector<int> vec_ind = find_by_filter(pipemap, check_repair, bool_repair), vect_vibor;
		for(auto &id : vec_ind)
			cout<<id<<pipemap[id];
		cout<<"1. Редактировать данные"<<endl
			<<"2. Не редактировать"<<endl;
		int number=GetNumber(1,2);
		if(number==1)
			{
			cout<<"1. Редактировать отфильтрованные"<<endl
			<<"2. Редактировать выбранные"<<endl;
			int number1 = GetNumber(1,2);
			if(number1==1)
			{
			for(auto&id : vec_ind)
				pipemap[id].repair_pipe();
			}
			else
			{
				while(true)
				{
					cin>>vibor_id;
					if(vibor_id<=0) break;
					else vect_vibor.push_back(vibor_id);
				}
				for(auto&id : vect_vibor)
				{
					pipemap[id].repair_pipe();
				}
			}
			}
		else if (number==2)
		{
		cout<<"1.Удалить найденные трубы"<<endl
			<<"2.Удалить выбранные"<<endl
			<<"3. Не удалять"<<endl;
		int del_res=GetNumber(1,3);
		if(del_res==1)
			delete_pipe(pipemap,vec_ind);
		else if (del_res==3) return;
		else 
		{
		while(true)
			{
				cin>>vibor_id;
				if(vibor_id<=0) break;
				else vect_vibor.push_back(vibor_id);
			}
			delete_pipe(pipemap,vect_vibor);
		}
		}
		else return;
	}
}

void filter_ks(unordered_map<int, comp_st>& ksmap)
{
	if(ksmap.size()==0)
		return;
		cout<<"1. Фильтр по названию"<<endl
		<<"2. Фильтр по проценту рабочих цехов"<<endl;
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
	pipe NewPipe;
	comp_st NewKS;
	unordered_map <int,pipe> pipemap;
	unordered_map <int,comp_st> ksmap;
	while (true)
	{
    menu();
	switch (GetNumber(0, 11))
	{
    case 1:
			{
			++pipe::id_pipe;
			cin>>NewPipe;
			pipemap.insert({pipe::id_pipe, NewPipe});
			}
		break;
	case 2:
			{
			++comp_st::id_ks;
			cin>>NewKS;
			ksmap.insert({comp_st::id_ks,NewKS});
			}
		break;
	case 3:
	{
		if(pipe::id_pipe>0)
			vivod_pipe(pipemap);
		if(comp_st::id_ks>0)
            vivod_KS(ksmap);
		if (pipe::id_pipe==0 && comp_st::id_ks==0)
			cout<<"Выполните ввод данных"<<endl;
		break;
    }
	case 4:
		if(pipe::id_pipe==0)
			cout<<"Вы не ввели ни одной трубы для редактирования!"<<endl;
		else
			change_repair(pipemap);
		break;
	case 5:
        if (comp_st::id_ks==0)
            cout<<"Вы не ввели ни одной КС для редактирования!"<<endl;
        else
            change_KS(ksmap);
		break;
	case 6:
		if(pipe::id_pipe>0 && comp_st::id_ks>0)
			{
			save_file(pipemap, ksmap);
			}
		else
			cout<<"Вы ввели недостаточно данных для сохранения в файл"<<endl;	
		break;
	case 7:
		vvod_from_file(NewPipe, NewKS, pipemap, ksmap);
		break;
	case 8:
		//delete_pipe(pipemap);
		break;
	case 9:
		delete_ks(ksmap);
		break;
	case 10:
		filter_pipe(pipemap);
		break;
	case 11:
		filter_ks(ksmap);
		break;
	case 0:
        return 0;
		break;
	}
	system("read -p 'press enter to continue... ' var");
	}
	return 0;
}