#include <iostream>
using namespace std;

template <typename T>
T GetNumber(T min, T max)
{
    T x;
    while(!(cin>>x) || x < min || x > max)
        {
        cin.clear();
        cin.ignore(10000,'\n');
        system("clear");
        cout<<"Введён неверный символ, введите заново"<<endl;
        }
        return x;
}