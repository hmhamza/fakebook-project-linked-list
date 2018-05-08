#include<conio.h>
#include <iostream>
#include <sstream>
#include<cstring>
#include<string>
#include<string.h>
#include"user.h"
#ifndef node_h
#define node_h
class node
{
private:
	User* puser;
	int friends;
	node* next;
public:
	User* getpuser();
	void setpuser(User*);
	node* getnext();
	void setnext(node*);
	int getfriends();
	void setfriends(int);
};
#endif