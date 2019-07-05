#include "iostream"
using namespace std;
int num[3000];
int dis[3000];
/**
 * 冒泡排序，扫描len次，每次用下标0扫描到len-1-i，比较相邻的两个元素并交换
 * @param num
 * @param len
 */
void bubbleSort(int num[],int len)
{
    for(int i=0;i<len;i++)//比较次数
    {
        for(int j=0;j<len-1-i;j++)//比较位置
        {
            if(num[j]>num[j+1])
            {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    //输入数据总数
    cin>>n;
    //输入数据
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    //求出相邻元素差的绝对值，并存储在一维数组中
    for(int i=0;i<n-1;i++)
    {
        dis[i]=abs(num[i+1]-num[i]);
    }
    //对一维数组进行排序
    bubbleSort(dis,n-1);
    //判断是否符合条件
    for(int i=1;i<=n-1;i++)
    {
        if(dis[i-1]!=i) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout<<"Jolly";
    return 0;
}
