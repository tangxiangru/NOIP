#include "iostream"
#include "string"
using namespace std;
int main() {
    int N;
    cin >> N;
    string name;
    int score1, score2;
    char state1, state2;
    int paper;
    //这里如果没有赋初值会出错。系统编译器没有给默认0
    int maxM=0;
    int sumM=0;
    string maxMName;
    for (int i = 0; i < N; i++)
    {
        cin>>name>>score1>>score2>>state1>>state2>>paper;
        int temp=0;
        if(score1>80&&paper>0)
        {
            temp+=8000;
        }
        if(score1>85&&score2>80)
        {
            temp+=4000;
        }
        if(score1>90)
        {
            temp+=2000;
        }
        if(score1>85&&state2=='Y')
        {
            temp+=1000;
        }
        if(score2>80&&state1=='Y')
        {
            temp+=850;
        }
        if(temp>maxM)
        {
            maxM = temp;
            maxMName = name;
        }
        sumM+=temp;
    }
    cout<<maxMName<<endl;
    cout<<maxM<<endl;
    cout<<sumM;
    return 0;
}

