#include "list.h"
#include "node.h"
#include<conio.h>
#include <iostream>
#include <sstream>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
list::list()
{
	head=NULL;
	size=0;
}
list::list(node*h,int s)
{
	head=h;
	size=s;
}
list::~list()
{
	node* prev;
	node* curr;
	curr= head;	
	while ( curr->getnext()!= NULL ) 
	{
		prev = curr;
		curr = curr->getnext();
		prev = NULL;
	}
	curr= NULL;
}
node* list::gethead()
{
	return head;
}
void list::sethead(node *p)
{
	head=p;
}
node* list::id_search(int id)
{
	User* u=new User;
	u=head->getpuser();
	if(u->getid()==id)
	{
		return head;
	}
	else
	{
		node* curr=head;
		u=curr->getpuser();
		while(u->getid()!=id)
		{
			curr=curr->getnext();
			u=curr->getpuser();
		}
		return curr;
	}
}
node* list::name_search(string name)
{
	User* u=new User;
	u=head->getpuser();
	if(u->getname()==name)
	{
		return head;
	}
	else
	{
		node* curr=head;
		u=curr->getpuser();
		while(u->getname()!=name)
		{
			curr=curr->getnext();
			u=curr->getpuser();
		}
		return curr;
	}
}