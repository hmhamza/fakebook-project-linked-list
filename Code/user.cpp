#include"user.h"
#include<conio.h>
#include <iostream>
#include <sstream>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
User::User()
{
	id=0;
	name="";
	city="";
	gender=false;
	age=0;
}
User::User(int i,string n,string c,bool g,int a)
{
	id=i;
	name=n;
	city=c;;
	gender=g;
	age=a;
}
int User::getid()
{
	return id;
}
string User::getname()
{
	return name;
}
int User::getage()
{
	return age;
}
bool User::getgender()
{
	return gender;
}
void User::print_user()
{
	cout<<name<<" (ID: "<<id<< "), "<<city<<" , ";
	if(gender==true)
		cout<<"Male, ";
	else
		cout<<"Female, ";
	cout<<age<<" yrs old ";
}
