#pragma once
#include <iostream>
#include <string>


class comp_st     // компрессорная станция
{
    public:
	int id, ceh_amount,ceh_INwork_amount;
	std::string ks_name;
	double efficency;
	friend std::istream& operator >> (std::istream& in, comp_st& c_st);
	friend std::ostream& operator << (std::ostream& out, const comp_st& NewKS);
    comp_st();
};