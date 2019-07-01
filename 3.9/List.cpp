#include<iostream>
#include<list>
#include<cstring>
#include<iterator>
using namespace std;
int n,id1,id2;
string s;
list<int>lit[10001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(s=="new") cin>>id1;
        else if(s=="add")
        {
            cin>>id1>>id2;
            lit[id1].push_back(id2);//list[id1]后面插入元素id2
        }
        else if(s=="merge")
        {
            cin>>id1>>id2;
            lit[id1].merge(lit[id2]);//讲list[id2]接到list[id1]后面，同时清空list[id2]
        }
        else if(s=="unique")
        {
            cin>>id1;
            lit[id1].sort();//排序
            lit[id1].unique();//去重，unique只能去重相邻元素，所以用前先排序
        }
        else//输出
        {
            cin>>id1;
            if(!lit[id1].empty())//首先判断非空
            {
                lit[id1].sort();//排序
                ostream_iterator<int> output(cout," ");
                copy(lit[id1].begin(),lit[id1].end(),output);//输出，并以空格分隔
                cout<<endl;
            }
            else cout<<endl;
        }
    }
}
