#include <iostream>
using namespace std;

class node
{
public:
    node(){}; //用于头结点这种空Node
    node(int n_data):data(n_data),next(NULL){}; //用于链表中的元素结点
    int data;
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
    int n;
    cin>>n;

    while(n--)
    {
        int data;
        cin>>data;
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
        cout<<p->data<<" ";
    }
    cout<<endl;
}
void link_delete(node *head, int data)
{
    node *p = head->next;
    node *prev = head;
    while(p!=NULL)
    {
        if(p->data == data)
        {
            //删除该结点
            // cout<<"prev->next:"<<prev->data<<" "<<p->next->data<<endl;
            prev->next = p->next;
            node *del = p;
            p = p->next;
            delete del;
        }else
        {
            prev = p;
            p = p->next;
        }
    }
}
int main()
{
    // 头指针，指向链表的首个结点
    node *head = new node();

    link_create(head);
    // link_print(head);

    int delData;
    cin>>delData;
    link_delete(head,delData);
    link_print(head);

    delete head;
}
