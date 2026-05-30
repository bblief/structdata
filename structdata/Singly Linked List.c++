#include<iostream>
#define ERROR 0
#define OK 1
using namespace std;
/*
存储学号、姓名、成绩的单链表定义方式： 
typedef struct{
	char num[8];
	char name[8];
	int score;
}Elemtype; 
typedef struct Lnode{
	Elemtype data;
	struct Lnode *next;
}Lnode,*Linklist;
 */
typedef int Elemtype;
typedef int Status;
typedef struct Lnode{
	Elemtype data;
	struct Lnode *next;
}Lnode,*Linklist;
Status Initlist(Linklist &L){
	L=new Lnode;//L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
	return OK;
}
int Empty(Linklist L){
	if(L->next)
		return 0;
	else
		return 1;
}
Status Clearlist(Linklist &L){
	Lnode *p,*q;
//	while(L->next){
//		p=L->next;
//		L->next=p->next;
//		delete p;
//	}
//
//	p=L->next;
//	q=p->next;
//	while(q){
//		delete p;
//		p=q;
//		q=p->next;
//	}
	p=L->next;
	while(p){
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;
	return OK;
}
int Length(Linklist &L){
	int c=0;
	Lnode *p;
	p=L;
	while(p->next){
		p=p->next;
		c++;
	}
	return c;
}
Status Destroylist(Linklist &L){
	Lnode *p;
	while(L){
		p=L;
		L=L->next;
		delete p;
	}
	return OK;
}
int main(){
	Linklist L;//Lnode *L;
	Initlist(L);
	if(Empty(L)) cout<<"start:"<<endl;
	cout<<Length(L)<<endl;
	return 0;
}