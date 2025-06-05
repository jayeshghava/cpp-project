#include<iostream>
using namespace std;
class base
{
	public:
		int a=15;
};      

class derived: public base
{
	public:
		int b=20;
}; 
int main()
{
	derived d;
	cout<<"value a: "<<d.a<<endl;
	cout<<"value b:"<<d.b<<endl;
}