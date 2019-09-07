#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
using namespace std;
 
typedef struct QNode{
	int data;
	struct QNode* next;
}*Link;
 
void InitQLinkList(Link& Q,int N){
	Q = (Link)malloc(sizeof(QNode));
	Q->data = 1;
	Link T = Q;
	for(int i = 2;i < N;i++){
		T->next = (Link)malloc(sizeof(QNode));
		T->next->data = i;
		T = T->next;
	}
	if (N != 1){
	    T->next = (Link)malloc(sizeof(QNode));
        T->next->data = N;
        T->next->next = Q;
	}
	else
	{
	    Q->next = Q;
	}
}
 
Link del(Link Q){
	Link F = Q;
	Link p = Q->next;
	while(p != Q){
		F = F->next;
		p = p->next;
	}
	if (F != p){
		F->next = p->next;
		free(p);
		return (F->next);
	}
	free(p);
	return NULL;
}
void GetOut(Link Q,int c,int m){
	int t = 1;
	while(t != m){
		Q = Q->next;
		t++;
	}
	do{
		for(int i = 0;i < c - 1;i++){
			Q = Q->next;
		}
		cout<<Q->data<<" ";
	}while(Q = del(Q));
}
 
void output(Link Q){
    int init = Q->data;
    while(Q->next->data != init){
        cout<<Q->data<<endl;
        Q = Q->next;
    }
    cout<<Q->data<<endl;
}
 
int main(){
	int n,m,c;
	cout<<"请输入围坐在圆桌周围的人数n:";
	cin>>n;
	cout<<"请输入第一次开始报数的人的位置m:";
	cin>>m;
	cout<<"你希望报数到底几个人出列？";
	cin>>c;
	Link Q;
	InitQLinkList(Q,n);
	//output(Q);
	cout<<"出列的顺序如下:"<<endl;
	GetOut(Q,c,m);
	return 0;
}
