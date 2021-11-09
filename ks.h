#pragma once
#include <iostream>
#include <string>


class comp_st     // компрессорная станция
{
    public:
	int id, ceh_amount,ceh_INwork_amount;
	std::string ks_name;
	double efficency;
    comp_st();
};