#include "node.h"
#include "user.h"
#include<conio.h>
#include <iostream>
#include <sstream>
#include<cstring>
#include<string>
#include<string.h>
User* node::getpuser()
{
	return puser;
}
void node::setpuser(User*p)
{
	puser=p;
}
node* node::getnext()
{
	return next;
}
void node::setnext(node*p)
{
	next=p;
}
int node::getfriends()
{
	return friends;
}
void node::setfriends(int f)
{
	friends=f;
}

