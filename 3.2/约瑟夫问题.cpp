#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node *link_create(int n)
{
    // 创建第一个节点
    node *head;
    node *p = new node();
    p->data = 1;
    head = p;

    for(int i=2;i<=n;i++)
    {
        node *q = new node();
        q->data = i;
        p->next = q;
        p = q;
    }
    p->next = head;
    return head;
}

void link_process(node *head, int k,int m)
{
    // 获取第k个节点
    node *p = head, *prev = head;

    // 找到头结点的前一个结点
    while(prev->next != head)
        prev = prev->next;

    // 找到开始计数位置
    while(p->data!=k)
        p = p->next;

    // 开始约瑟夫过程
    while(p->next != p)
    {
        // count++;
        for(int i=0;i<m-1;i++)
        {
            prev = p;
            p = p->next;
        }

        // 删除当前结点
        node* del = p;
        // cout<<"del:"<<del->data<<endl;
        prev->next = p->next; // the same with: prev->next = prev->next->next;
        p = prev->next; //下一只猴子从1接着继续数
        delete del;
    }
    cout<<p->data<<endl;
    delete p;
}
int main()
{
    int n,m;
    while(true)
    {
        cin>>n>>m;
        if(n==0&&m==0)
            break;
        node* head = link_create(n);
        link_process(head,1,m);
    }
    return 0;
}
