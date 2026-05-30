#include <iostream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define Maxsize 100
using namespace std; 
typedef int Elemtype;
typedef int Status;
typedef struct{
	Elemtype *elem;
	int length;
}Sqlist; 
Status Initlist(Sqlist &L){
	L.elem=new Elemtype[Maxsize];
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	return OK;
}
Status Pushback(Sqlist &L,Elemtype e){
	if(L.length==Maxsize) return ERROR;
	L.elem[L.length]=e;
	L.length++;
	return OK;
}
Status Insert(Sqlist &L,int i,Elemtype e){
	if(i<1||i>L.length+1||L.length==Maxsize) return ERROR;
//	for(int j=L.length;j>=i;j--){
//		L.elem[j]=L.elem[j-1];
//	}
	for(int j=L.length-1;j>=i-1;j--){
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i-1]=e;
	L.length++;
	return OK;
} 
//删除第i个元素
Status Deletelem(Sqlist &L,int i){
	if(i<1||i>L.length) return ERROR;
	for(int j=i-1;j<L.length;j++){
		L.elem[j]=L.elem[j+1];
	}
	L.length--;
	return OK;
}
void print(Sqlist L){
	for(int i=0;i<L.length;i++){
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
}
int Getlist(Sqlist L){
	return(L.length);
}
int Isempty(Sqlist L){
	if(L.length==0) return 1;
	else return 0;
}
//根据位置i获取相应元素 
int Getelem(Sqlist L,int i,Elemtype &e){
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}
//按值查找,一样返回位置，没返回0 
int Locate(Sqlist L,Elemtype e){
	for(int i=0;i<L.length;i++){
		if(e==L.elem[i])
			return i+1;
	}
	return 0;
}
void Destroylist(Sqlist &L){
	if(L.elem) delete L.elem;
}
void Clearlist(Sqlist &L){
	L.length=0;
}
int main() {
	Sqlist L;
	Initlist(L);
	Pushback(L,12);
	Pushback(L,13);
	print(L);
	Insert(L,2,14);
	print(L);
	if(!Isempty(L)){
		cout<<"###"<<endl;
	}
	Deletelem(L,0);
	if(Deletelem(L,0)==ERROR) cout<<"error"<<endl;
	Deletelem(L,2);
	print(L);
	Clearlist(L);
	if(Isempty(L)){
		cout<<"nothing"<<endl;
	}	
	Destroylist(L);
	return 0;
}