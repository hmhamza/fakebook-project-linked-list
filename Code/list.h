#include<conio.h>
#include <iostream>
#include <sstream>
#include<cstring>
#include<string>
#include<string.h>
#include "node.h"
#ifndef list_h
#define list_h
class list
{
private:
	node *head;
	int size;
public:
	list();
	list(node*,int);
	~list();
	node* gethead();
	void sethead(node*);
	node* id_search(int);
	node* name_search(string);
};
#endif