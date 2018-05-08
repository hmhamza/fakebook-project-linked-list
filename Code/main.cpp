#include<conio.h>
#include <iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include"list.h"
#include"node.h"
#include"user.h"
using namespace std;

void LOGIN()
{
	char username[100];
	char password[100];
	int i=0;
	ifstream fin("login.txt");
	fin.getline(username,99);
	fin.getline(password,99);
	char _username[100];
	char _password[100];
	char get;
	while(1)
	{
		system("cls");
		system("color 0b");
		for (i=0;i<12;i++)
			cout<<endl;
		cout<<"\t\tfaKeBook Username: ";
		cin>>_username;
		cout<<endl<<endl<<"\t\t         Password:";
		for(i=0;1;i++)
		{
			get=getch();
			if(get==13)
				break;
			cout<<"*";
			_password[i]=get;
		}
		_password[i]='\0';
		if( !(strcmp(username,_username))  &&  !(strcmp(password,_password)) )
			break;
		else
			for (int i=1;i<8;i++)
			{
				system("cls");
				system("color 0c");
				cout<<endl<<endl<<endl<<"\t\t\tERROR: Wrong Username or Password\a"<<endl;
				cout<<endl<<endl<<"\t\t\tPlease provide CORRECT Information"<<endl;
				Sleep(50);
			}
	}
}

struct mutual
{
	int mutual_friends;
	int id;
};

class fakebook
{
private:
	list allusers;
	node** friendinfo;
	int noofusers;
public:
	void load_users();
	void load_friendinfo();
	int getnoofusers();
	int male_count();
	int female_count();
	void printFakeBook();
	void listAllFriends(string);
	void addUser(const User&);
	void deleteUser(int);
	void addFriend(int,int);
	void removeFriend(int,int);
	bool isMutualFriend(int,int,int);
	void listAllMutualFriends(string,string);
	void print_friends();
	bool isFriend(int,int);
	void showThreeMostLikelyPeopleIknow(string);
	void printAllUsersBetweenAges(int,int);
	void printAllMalesBetweenAges(int,int);
	void printAllFemalesBetweenAges(int,int);
};

void fakebook::printAllUsersBetweenAges(int agelow,int agehigh)
{
	bool flag=false;
	node* _node=NULL;
	User* _user=NULL;
	_node=allusers.gethead();
	while(_node!=NULL)
	{
		_user=_node->getpuser();
		if( _user->getage()>=agelow && _user->getage()<=agehigh )
		{
			if(flag==false)
				cout<<endl<<"The users that lie in age range "<<agelow<<"-"<<agehigh<<" are"<<endl<<endl;
			cout<<"\t* "<<_user->getname()<<"( "<<_user->getage()<<" years old)"<<endl;
			flag=true;
		}
		_node=_node->getnext();
	}
	if(flag==false)
		cout<<endl<<"None of the user lies in the age range provided"<<endl<<endl;
	cout<<endl<<endl;
}

void fakebook::printAllMalesBetweenAges(int agelow,int agehigh)
{
	bool flag=false;
	node* _node=NULL;
	User* _user=NULL;
	_node=allusers.gethead();
	while(_node!=NULL)
	{
		_user=_node->getpuser();
		if( _user->getage()>=agelow && _user->getage()<=agehigh && _user->getgender()==true )
		{
			if(flag==false)
				cout<<endl<<"The male users that lie in age range "<<agelow<<"-"<<agehigh<<" are"<<endl<<endl;
			cout<<"\t* "<<_user->getname()<<"( "<<_user->getage()<<" years old)"<<endl;
			flag=true;
		}
		_node=_node->getnext();
	}
	if(flag==false)
		cout<<endl<<"None of the male user lies in the age range provided"<<endl<<endl;
}

void fakebook::printAllFemalesBetweenAges(int agelow,int agehigh)
{
	bool flag=false;
	node* _node=NULL;
	User* _user=NULL;
	_node=allusers.gethead();
	while(_node!=NULL)
	{
		_user=_node->getpuser();
		if( _user->getage()>=agelow && _user->getage()<=agehigh && _user->getgender()==false )
		{
			if(flag==false)
				cout<<endl<<"The female users that lie in age range "<<agelow<<"-"<<agehigh<<" are"<<endl<<endl;
			cout<<"\t* "<<_user->getname()<<"( "<<_user->getage()<<" years old)"<<endl;
			flag=true;
		}
		_node=_node->getnext();
	}
	if(flag==false)
		cout<<endl<<"None of the female user lies in the age range provided"<<endl<<endl;
}

int fakebook::getnoofusers()
{
	return noofusers;
}

void fakebook::listAllFriends(string name)
{
	cout<<endl<<"Friends of "<<name;
	node* curr=NULL;
	User *h=new User;
	int id;
	curr=allusers.name_search(name);
	h=curr->getpuser();
	id=h->getid();
	curr=friendinfo[id]->getnext();
	cout<<" are ";
	while(curr!=NULL)
	{
		h=curr->getpuser();
		cout<<h->getname()<<",";
		curr=curr->getnext();
	}
	cout<<endl<<endl;
}

bool fakebook::isMutualFriend(int id1,int id2,int f)
{
	User* u_curr=NULL;
	User* id1_user=NULL;
	User* id2_user=NULL;
	User* u_f=NULL;
	node* curr=NULL;
	node* curr_1=NULL;
	node* curr_2=NULL;
	node* user_1=NULL;
	node* user_2=NULL;
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getid()==id1)
		{
			user_1=friendinfo[i];
			break;
		}
	}
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getid()==id2)
		{
			user_2=friendinfo[i];
			break;
		}
	}
	curr=allusers.id_search(f);
	u_f=curr->getpuser();
	curr_1=user_1->getnext();
	while(curr_1!=NULL)
	{
		id1_user=curr_1->getpuser();
		if(id1_user->getid()==f)                                   // --> if(id1_user->getid()==u_f->getid())
		{
			curr_2=user_2->getnext();
			while(curr_2!=NULL)
			{
				id2_user=curr_2->getpuser();
				if(id2_user->getid()==f)
					return true;
				curr_2=curr_2->getnext();
			}
		}
		curr_1=curr_1->getnext();
	}
	return false;
}

void fakebook::showThreeMostLikelyPeopleIknow(string name)
{
	cout<<"\nfaKeBook Suggestions for "<<name<<" are"<<endl<<endl;
	mutual *m=new mutual[noofusers-1];
	for (int i=0;i<(noofusers-1);i++)
	{
		m[i].mutual_friends=-1;
		m[i].id=0;
	}
	node* user_node=NULL;
	node* friend_node=NULL;
	node* curr=NULL;
	User* u_curr=NULL;
	User* u_f=NULL;
	User* u_u=NULL;
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getname()==name)
		{
			user_node=friendinfo[i];
			break;
		}
	}
	
	u_curr=user_node->getpuser();
	for (int i=0;i<(noofusers-1);i++)
	{
		u_u=user_node->getpuser();
		u_f=friendinfo[i]->getpuser();
		if(friendinfo[i]==user_node|| (u_u->getid()==u_f->getid()) )
			continue;
		m[i].mutual_friends=0;
		m[i].id=u_f->getid();
		curr=user_node->getnext();
		while(curr!=NULL)
		{
			u_u=curr->getpuser();
			if(   isMutualFriend( u_curr->getid(), m[i].id, u_u->getid())    )
				m[i].mutual_friends++;
			curr=curr->getnext();
		}
	}
	mutual temp;
	for (int i=0;i<(noofusers-1);i++)              //sorting
	{
		for (int j=0;j<(noofusers-1)-i;j++)
		{
			if(m[j].mutual_friends<m[j+1].mutual_friends)
			{
				temp=m[j];
				m[j]=m[j+1];
				m[j+1]=temp;
			}
		}
	}
	for (int i=0;i<3;i++)
	{
		if(m[i].mutual_friends<=0)
			continue;
		user_node=allusers.id_search(m[i].id);
		u_curr=user_node->getpuser();
		cout<<u_curr->getname()<<" (";
		if(m[i].mutual_friends==1)
			cout<<m[i].mutual_friends<<" Mutual Friend) "<<endl;
		else
			cout<<m[i].mutual_friends<<" Mutual Friends) "<<endl;
	}
}

bool fakebook::isFriend(int id1,int id2)
{
	node* user_node=NULL;
	node* friend_node=NULL;
	node* curr=NULL;
	User* u_curr=NULL;
	User* f_curr=NULL;
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getid()==id1)
		{
			user_node=friendinfo[i];
			break;
		}
	}
	friend_node=allusers.id_search(id2);
	f_curr=friend_node->getpuser();
	curr=user_node->getnext();
	u_curr=curr->getpuser();
	while(curr->getnext()!=NULL)                       // ???  while(curr!=NULL)
	{
		if(u_curr->getid()==f_curr->getid())
			return true;
		curr=curr->getnext();
		u_curr=curr->getpuser();
	}
	return false;
}

void fakebook::listAllMutualFriends(string name1,string name2)
{
	User* u_curr=NULL;
	User* u_1=NULL;
	User* u_2=NULL;
	node* curr=NULL;
	node* curr_1=NULL;
	node* curr_2=NULL;
	node* user_1=NULL;
	node* user_2=NULL;
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getname()==name1)
		{
			user_1=friendinfo[i];
			break;
		}
	}
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getname()==name2)
		{
			user_2=friendinfo[i];
			break;
		}
	}
	curr_1=user_1->getnext();
	while(curr_1!=NULL)
	{
		u_1=curr_1->getpuser();
		curr_2=user_2->getnext();
		while(curr_2!=NULL)
		{
			u_2=curr_2->getpuser();
			if(u_1->getid()==u_2->getid())
				cout<<u_2->getname()<<endl;
			curr_2=curr_2->getnext();
		}
		curr_1=curr_1->getnext();
	}
}

void fakebook::print_friends()
{
	node* curr=NULL;
	User *h=new User;                                   //friend info
	for(int i=0;i<noofusers;i++)
	{
		h=friendinfo[i]->getpuser();
		cout<<"Friends of "<<h->getname();
		curr=friendinfo[i]->getnext();
		cout<<" are ";
		while(curr!=NULL)
		{
			h=curr->getpuser();
			cout<<h->getname()<<",";
			curr=curr->getnext();
		}
		cout<<endl<<endl;
	}
}

void fakebook::addFriend(int id1,int id2)
{
	node* curr=NULL;
	User* u_curr=NULL;
	node* user_node=NULL;
	node* friend_node=new node;;
	curr=allusers.id_search(id2);
	friend_node->setpuser(curr->getpuser());           // ??? friend_node=allusers.idserach(id2);
	friend_node->setnext(NULL);
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getid()==id1)
		{
			user_node=friendinfo[i];
			break;
		}
	}
	curr=user_node;
	while(curr->getnext()!=NULL)
		curr=curr->getnext();
	curr->setnext(friend_node);
}

void fakebook::removeFriend(int id1,int id2)
{
	node* curr=NULL;
	node* prev=NULL;
	User* u_curr=NULL;
	User* f_curr=NULL;
	node* user_node=NULL;
	for (int i=0;i<noofusers;i++)
	{
		u_curr=friendinfo[i]->getpuser();
		if(u_curr->getid()==id1)
		{
			user_node=friendinfo[i];
			break;
		}
	}
	curr=user_node->getnext();
	prev=user_node;
	f_curr=curr->getpuser();
	while(f_curr->getid()!=id2)
	{
		prev=curr;
		curr=curr->getnext();
		f_curr=curr->getpuser();
	}
	prev->setnext(curr->getnext());
	prev->setnext(NULL);
	curr->setnext(NULL);
}

int fakebook::male_count()
{
	int males=0;
	node* curr=new node;
	curr=allusers.gethead();
	User* m=new User;
	while(curr!=NULL)
	{
		m=curr->getpuser();
		if(m->getgender()==true)
			males++;
		curr=curr->getnext();
	}
	return males;
}

int fakebook::female_count()
{
	int females=0;
	node* curr=new node;
	curr=allusers.gethead();
	User* f=new User;
	while(curr!=NULL)
	{
		f=curr->getpuser();
		if(f->getgender()==false)
			females++;
		curr=curr->getnext();
	}
	return females;
}

void fakebook::printFakeBook()
{
	int friends=0;
	cout<<"Total Users: "<<noofusers<<"\tMales: "<<male_count()<<"\tFemales: "<<female_count()<<endl<<endl;
	node* current=allusers.gethead();
	User* a=new User;
	User* b=new User;
	while(current!=NULL)
	{
		a=current->getpuser();
		a->print_user();
		cout<<" , "<<current->getfriends()<<" friends"<<endl<<endl;	
		current=current->getnext();
	}
}

void fakebook::load_users()
{
	noofusers=0;
	string name,city,input,age_string;
	char gen_char;
	bool gender;
	int age,name_end,city_end,str_len,age_len;
	ifstream fin("allusers.txt");
	while(!fin.eof())
	{
		getline(fin,input);
		str_len=input.length();
		name_end=input.find("#",0);
		name=input.substr(0,name_end);
		name_end++;
		city_end=input.find("#",name_end);
		city_end=city_end-name_end;
		city=input.substr(name_end,city_end);
		city_end=city_end+name_end;
		city_end++;
		gen_char=input.at(city_end);
		if(gen_char=='M')
			gender=true;
		else
			gender=false;
		city_end+=2;
		age_string=input.substr(city_end,str_len);
		age_len=age_string.length();
		int temp;
		age=0;
		for (int i=0;i<age_len;i++)
		{
			temp=age_string.at(i)-48;
			for (int j=0;j<(age_len-i-1);j++)
				temp=temp*10;
			age=age+temp;
		}
		User *newuser=new User(noofusers,name,city,gender,age);
		node *newnode=new node;
		newnode->setpuser(newuser);
		newnode->setnext(NULL);
		noofusers++;
		if(allusers.gethead()==NULL)
		{
			allusers.sethead(newnode);
		}
		else
		{
			node* current=new node;
			current=allusers.gethead();
			node* prev=new node;
			prev=NULL;
			while(current->getnext()!=NULL)
				current=current->getnext();
			current->setnext(newnode);
		}
	}
	string n;
	node* chk=new node;
	User* u=new User;
}

void fakebook::load_friendinfo()
{
	char input;
	int i=0,user_id,friend_id,f=0;
	friendinfo=new node*[noofusers];
	for (int a=0;a<noofusers;a++)
		friendinfo[a]=NULL;
	node* user_node=NULL;
	node* friend_node=new node;
	node* curr=new node;
	ifstream fin("friends.txt");
	
	
	while(!fin.eof())
	{
		node* user_node=NULL;
		user_id=0;
		fin.get(input);
		if(fin.eof())
			break;
		while(input>='0'&&input<='9')
		{
			user_id=(user_id*10)+(input-48);
			fin.get(input);
		}
		user_node=allusers.id_search(user_id);
		friendinfo[i]=new node;
		friendinfo[i]->setpuser(user_node->getpuser());     //  ??? friendinfo[i]=id_node
		friendinfo[i]->setnext(NULL);
		
		
		user_node->setfriends(0);
		while(input!='\n')
		{
			friend_id=0;
			fin.get(input);
			if(input=='\n')
				break;
			while(input>='0'&&input<='9')
			{
				friend_id=(friend_id*10)+(input-48);
				fin.get(input);
			}


			f=user_node->getfriends();
			f++;
			user_node->setfriends(f);


			friend_node=new node;
			curr=new node;
			curr=allusers.id_search(friend_id);
			friend_node->setpuser(curr->getpuser());           //  ??? fid_node=allusers.id_search(4)
			friend_node->setnext(NULL);
			curr=friendinfo[i];
			while(curr->getnext()!=NULL)
				curr=curr->getnext();
			curr->setnext(friend_node);
		}
		i++;
	}
}

void fakebook::addUser(const User& u)
{
	node* newnode=new node;
	node* curr=new node;
	User* now=new User;
	*now=u;
	newnode->setpuser(now);
	newnode->setfriends(0);
	newnode->setnext(NULL);
	curr=allusers.gethead();
	while(curr->getnext()!=NULL)
		curr=curr->getnext();
	curr->setnext(newnode);
		
	node** t=new node*[noofusers];
	for (int k=0;k<noofusers;k++)
	{
		t[k]=new node;
		t[k]->setpuser(friendinfo[k]->getpuser());
		t[k]->setnext(friendinfo[k]->getnext());
	}
	for (int i=(noofusers-1);i>=0;i--)
	{
		friendinfo[i]->setnext(NULL);
		delete friendinfo[i];
	}
	delete friendinfo;
	
	friendinfo=new node*[noofusers+1];
	for (int a=0;a<noofusers;a++)
		friendinfo[a]=NULL;
	for (int k=0;k<noofusers;k++)
	{
		friendinfo[k]=new node;
		friendinfo[k]->setpuser(t[k]->getpuser());
		friendinfo[k]->setnext(t[k]->getnext());
	}
	for (int i=(noofusers-1);i>=0;i--)
	{
		t[i]->setnext(NULL);
		delete t[i];
	}
	delete t;
	friendinfo[noofusers]=new node;
	friendinfo[noofusers]->setpuser(newnode->getpuser());
	friendinfo[noofusers]->setnext(NULL);
	noofusers++;

}

void  fakebook::deleteUser(int id)
{
	for(int i=0;i<noofusers;i++)
	{
		if(i==id)
			continue;
		if(isFriend(i,id))
			removeFriend(i,id);
	}
	
	int m=0;
	User* check=new User;
	node** t=new node*[noofusers];
	for (int k=0;k<noofusers;k++)
	{
		t[k]=new node;
		t[k]->setpuser(friendinfo[k]->getpuser());
		t[k]->setnext(friendinfo[k]->getnext());
	}
	for (int i=(noofusers-1);i>=0;i--)
	{
		friendinfo[i]->setnext(NULL);
		delete friendinfo[i];
	}
	delete friendinfo;
	
	friendinfo=new node*[noofusers-1];
	for (int k=0;k<noofusers;k++)
	{
		check=t[k]->getpuser();
		if(check->getid()==id)
		{
			m=1;
			continue;
		}
		friendinfo[k-m]=new node;
		friendinfo[k-m]->setpuser(t[k]->getpuser());
		friendinfo[k-m]->setnext(t[k]->getnext());
	}
	for (int i=(noofusers-1);i>=0;i--)
	{
		t[i]->setnext(NULL);
		delete t[i];
	}
	delete t;
	
	node* prev=NULL;
	node* curr=NULL;
	User* u_curr=new User;
	curr=allusers.gethead();
	u_curr=curr->getpuser();
	while (u_curr->getid()!=id)
	{
		prev=curr;
		curr=curr->getnext();
		u_curr=curr->getpuser();
	}
	prev->setnext(curr->getnext());
	curr->setnext(NULL);
	
	noofusers--;
}

void ASK(fakebook obj)
{
	char input[100];
	int action,id1,id2,age;
	bool gender;
	char gen;
	string name1,name2;
	ifstream fin;
	while(1)
	{
		system("cls");
		fin.open("actions.txt");
		while(!fin.eof())
		{
			fin.getline(input,99);
			cout<<input<<endl;
		}
		cout<<endl;
		cin>>action;
		system("cls");

		if(action==1)
		{
			obj.printFakeBook();
			cout<<endl<<endl;
		}

		if(action==2)
		{
			obj.print_friends();
			cout<<endl<<endl;
		}
		if(action==3)
		{
			cout<<"Enter the Name of the User whose friends you want to see"<<endl;
			cin.ignore();
			getline(cin,name1);
			obj.listAllFriends(name1);
		}

		if(action==4)
		{
			cout<<"Enter the names of the Users whose Mutual Friends you want to see\n\nName of first User:";
			cin.ignore();
			getline(cin,name1);
			cout<<endl<<"Name of second User:";
		    getline(cin,name2);
			obj.listAllMutualFriends(name1,name2);
		}

		if(action==5)
		{
			cout<<"Enter the Name oh the User whose faKeBook Suggestions you want to check"<<endl;
			cin.ignore();
			getline(cin,name1);
			obj.showThreeMostLikelyPeopleIknow(name1);
		}

		if(action==6)
		{
			cout<<"Enter Name of the new user ";
			cin.ignore();
			getline(cin,name1);
			cout<<"Enter new user's gender   ( 'M' for male or 'F' for female ) ";
			cin>>gen;
			if(gen=='M'||gen=='m')
				gender=true;
			else
				gender=false;
			if(gender==true)
			{
				cout<<"To which City he belongs? ";
				cin.ignore();
				getline(cin,name2);
				cout<<"Enter his age ";
				cin>>age;
			}
			else
			{
				cout<<"To which City she belongs? ";
				cin.ignore();
				getline(cin,name2);
				cout<<"Enter her age ";
				cin>>age;
			}
 			User u(obj.getnoofusers(),name1,name2,gender,age);
			obj.addUser(u);
		}

		if(action==7)
		{
			cout<<"Enter the id of the User whom you want to delete ";
			cin>>id1;
			obj.deleteUser(id1);
		}

		if(action==8)
		{
			cout<<"Enter the ID of the person who is to be made friend  ";
			cin>>id1;
			cout<<"Enter the ID of the person with whom the User is made friend ";
			cin>>id2;
			obj.addFriend(id1,id2);
			cout<<endl<<"Friends have been successfully made"<<endl<<endl;
		}
		if(action==9)
		{
			cout<<"Enter the ID of the first person to be unfriend ";
			cin>>id1;
			cout<<"Enter the ID of the second person ";
			cin>>id2;
			obj.removeFriend(id1,id2);
			obj.addFriend(id1,id2);
			cout<<endl<<"The two people have been made unfriend successfully"<<endl<<endl;
		}
		if(action==10)
		{
			cout<<"Please enter the low age ";
			cin>>id1;
			cout<<"Please enter the high age ";
			cin>>id2;
			obj.printAllUsersBetweenAges(id1,id2);
		}
		if(action==11)
		{
			cout<<"Please enter the low age ";
			cin>>id1;
			cout<<"Please enter the high age ";
			cin>>id2;
			obj.printAllMalesBetweenAges(id1,id2);
		}
		if(action==12)
		{
			cout<<"Please enter the low age ";
			cin>>id1;
			cout<<"Please enter the high age ";
			cin>>id2;
			obj.printAllFemalesBetweenAges(id1,id2);
		}
		if(action==13)
		{
			cout<<"Thanks for using faKeBook\n\n";
			break;
		}
		fin.close();
		system("pause");
	}
}

int main()
{
	LOGIN();
	fakebook fast;
	fast.load_users();
	fast.load_friendinfo();
	ASK(fast);
	system("pause");
	return 0;
}