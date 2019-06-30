#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;
struct info
{
    string id;
    string name;
    char gender;
    int age;
    float score;
    string address; 
};
class node
{
public:
    node():next(NULL){}; //用于头结点这种空Node
    node(info n_data):data(n_data),next(NULL){}; //用于链表中的元素结点
    info data;
    node* next;
};

// 本题每次插入末尾，不会插入之前的序列中，因此不要每次插入时遍历链表，否则会超时
// void link_insert(node* head, int pos, node* p)
// {
//  node* tmp = head;
//  for(int i=1;i<=pos-1;i++)
//  {
//      tmp = tmp->next;
//  }   
//  tmp->next = p;
// }

void link_create(node* head)
{
    node *p = head;
    while(true)
    {
        // 借助stringstream用空格分隔字符串
        string command;
        getline(cin,command);
        stringstream ss(command);
        info data;
        ss>>data.id>>data.name>>data.gender>>data.age>>data.score>>data.address;
        // cout<<data.id<<" "<<data.name<<" "<<data.gender<<" "<<data.age<<" "<<data.score<<" "<<data.address<<endl;
        if(data.id=="end") 
        {
            break;
        }
        node *p_new = new node(data);
        p->next = p_new;
        p = p_new;
    }
}
void link_print(node* head)
{
    node *p = head;
    while(p->next!=NULL)
    {
        p = p->next;
        cout<<p->data.id<<" "<<p->data.name<<" "<<p->data.gender<<" "
            <<p->data.age<<" "<<p->data.score<<" "<<p->data.address<<endl;
    }
    cout<<endl;
}

// 普通循环方法逆置带头头结点的单链表
node* link_reverse(node *head)
{
    node *p1 = head->next;
    node *p2 = head->next->next;
    p1->next = NULL; //这里特殊处理一下头结点，否则头结点和第一个结点会生成环
    node *pnext;
    while(p2!=NULL)
    {
        pnext = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = pnext;
    }
    node* newHead = new node();
    newHead->next = p1;
    return newHead;
}
int main()
{
    // 头指针，指向链表的首个结点
    node *head = new node();

    link_create(head);
    // link_print(head);

    node *rLinkHead = link_reverse(head);
    link_print(rLinkHead);
}
