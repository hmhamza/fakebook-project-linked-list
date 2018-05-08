#include<cstring>
#include<conio.h>
#include <iostream>
#include <sstream>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
#ifndef user_h
#define user_h
class User
{ 
private:
	int id;
	string name;
	string city;
	bool gender;
	int age;
public:
	User();
	User(int,string,string,bool,int);
	int getid();
	string getname();
	string getcity();
	bool getgender();
	int getage();
	void print_user();
};
#endif