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
//按值找地址 
Lnode *Get_address(Linklist L,Elemtype e){

	Lnode *p=L->next;
//	for(int c=0;c<length;c++){
//		if(p->data==e){
//			return p;
//		}
//		p=p->next;
//	}
	while(p&&p->data!=e){//找结束循环是什么情况 
		p=p->next;
	}
	return p;
}
//按值找位序
int Get_position(Linklist L,Elemtype e){
	Lnode *p=L->next;
	int j=1;
	while(p&&p->data!=e){
		p=p->next;
		j++;
	}
	return j;
} 
//按位查找
Status Get_pos(Linklist L,int i,Elemtype &e){
//	Lnode *p=L;
//	for(int c=1;c<=i;c++){
//		p=p->next;
//	}
	Lnode *p=L->next;
	int j=1;
	while(p&&j<i){
		p=p->next;
	}
	if(!p||i<1)	return ERROR;
	e=p->data;
	return OK;
}
//第i个节点前插入 
Status Insert(Linklist &L,int i,Elemtype e){
	Lnode *p=L;
	int j=0;
	while(p&&j<i-1){//找到第i个节点前的节点 
		p=p->next;
		j++;
	}
	if(i<1||!p) return ERROR;
	Lnode *s=new Lnode; 
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
//删除第i个节点
Status Delete(Linklist &L,int i){
	Lnode *p=L;
	int j=0;
	while(p->next&&j<i-1){//找到第i个节点前的节点 
		p=p->next;
		j++;
	}
	if(i<1||!p->next) return ERROR;
	Lnode *q=p->next;
	p->next=q->next;
	delete q;
	return OK;
}
void print(Linklist L){
	Lnode *p=L->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
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
	Insert(L,1,100);
	cout<<Length(L)<<endl;
	print(L);
	Insert(L,2,200);
	print(L);
	Delete(L,1);
	print(L);
	return 0;
}
