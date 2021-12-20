#include <iostream>
#include "ks.h"
#include "utils.h"

using namespace std;

int comp_st::id_ks=0;

comp_st::comp_st()
{
    //id=0;
    ceh_amount=0;
    ceh_INwork_amount=0;
    efficency=0.00;
}

ostream &operator<<(ostream &out, const comp_st& ks)
{
    out<<ks.ks_name<<endl
        <<ks.ceh_amount<<"  "
        <<ks.ceh_INwork_amount<<"  "
        <<ks.efficency<<endl;
        return out;
}
ofstream &operator<<(ofstream &fout, const comp_st& ks)
{
    fout<<ks.ks_name<<endl
        <<ks.ceh_amount<<"  "
        <<ks.ceh_INwork_amount<<"  "
        <<ks.efficency<<" ";
        return fout;
}
istream &operator>>(istream &in, comp_st& NewKS)
{
    cout<<"Введите название КС"<<endl;
    cin>>ws;
    getline(in, NewKS.ks_name);
	cout<<"Введите количество цехов"<<endl;
	NewKS.ceh_amount=GetNumber(1,500);
	cout<<"Введите количество работающих цехов"<<endl;
	NewKS.ceh_INwork_amount=GetNumber(0,NewKS.ceh_amount);
	cout<<"Введите эффективность"<<endl;
	NewKS.efficency=GetNumber(0.0,100.0);
    return in;
}
ifstream &operator>>(ifstream &fin, comp_st& NewKS)
{
    fin>>ws;
    getline(fin, NewKS.ks_name);
	fin>>NewKS.ceh_amount>>NewKS.ceh_INwork_amount>>NewKS.efficency;
    return fin;
}
