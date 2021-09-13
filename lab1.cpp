#include <iostream>
using namespace std;

struct pipe
{
	int id, diametr;
	double length;
	bool in_repair;
};

pipe my_pipe;

//pipe func_repair()
//{
//	if (my_pipe.in_repair == 1) 
//}

pipe vivod_func ()
{
cout << my_pipe.length << ' ' << "метров" << endl
   	<< my_pipe.id << endl
	<< my_pipe.in_repair <<endl
	;
return my_pipe;
}


int main()
{
	//pipe my_pipe;
	my_pipe.id=0, my_pipe.length=0.00, my_pipe.in_repair=0;
	cout<<"Прошу ввести длину трубы"<<endl;
	cin>>my_pipe.length;
	cout <<"Прошу указать, находится ли труба в состоянии ремонта"<< endl;
	cin>>my_pipe.in_repair;
	vivod_func();
	return 0;

}
