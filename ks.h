#pragma once
#include <iostream>
#include <string>
#include <fstream>

class comp_st     // компрессорная станция
{
    public:
	static int id_ks;
	int /*id,*/ ceh_amount,ceh_INwork_amount;
	std::string ks_name;
	double efficency;
	friend std::istream& operator >> (std::istream& in, comp_st& NewKS);
	friend std::ostream& operator << (std::ostream& out, const comp_st& ks);
	friend std::ifstream& operator >> (std::ifstream& fin, comp_st& NewKS);
	friend std::ofstream& operator << (std::ofstream& fout, const comp_st& ks);
    comp_st();
};