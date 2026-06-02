#include<iostream>
using namespace std;

typedef int Elemtype;

typedef struct node
{
    Elemtype data;
    struct node *next;
    
}node,*linklist;
void Creat_pushback(linklist &L,int n){
    L=new node;
    L->next=NULL;
    node *l,*p;
    l=L;
    for(int i=0;i<n;i++){
        p=new node;
        cin>>p->data;
        p->next=NULL;
        l->next=p;//!
        l=p;//!
    }
}
void print(linklist &L){
    node *p,*q;
    p=L->next;
    q=L;
    while (p&&p!=q)//后面那个是为了保证不进入死循环
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
node* last(linklist &L){
    node *last,*p;
    p=L;
    while(p->next){
        p=p->next;
        last=p;
    }
    return last;
}

//单链表转化为循环链表
void circular(linklist &L,node* &last){
    last->next=L;
}
//合并表1和2
void connect(node* last1,node* last2){
    node *p;
    p=last1->next;
    last1->next=last2->next->next;
    delete last2->next;
    last2->next=p;
}

int main()
{
    linklist la,lb;
    Creat_pushback(la,3);
    Creat_pushback(lb,3);
    print(la);
    print(lb);
    
    node *lasta,*lastb;
    lasta=last(la);
    lastb=last(lb);
    cout<<lasta->data<<endl;
    circular(la,lasta);
    // print(la);
    circular(lb,lastb);
    connect(lasta,lastb);
    print(la);
    return 0;
} 
