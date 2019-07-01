#include<stdio.h>
#include<math.h>
#define PI (acos(-1))
#define eps (1e-14)
int main(int argc, char *argv[])
{
    double L,n,C,L1;
    
    double minCentralAngle,maxCentralAngle,CentralAngle;
    double radius,L2;
    double ans;
    
    scanf("%lf%lf%lf",&L,&n,&C);
    
    if(n*C*L<=eps)   //假如膨胀量太小就不用计算了，直接认为结果就是0. 
    {
        printf("0.000\n");
        return 0;
    }
    
    L1=(1+n*C)*L;
    
    //下面对圆心角进行二分枚举
    //（膨胀量不超过原来的1.5倍，
    //分析圆的半周长PI*R与直径2*R的关系可知圆心角范围0~2*PI而且不可能取2*PI） 
    minCentralAngle=0;//圆心角的极小值 
    maxCentralAngle=PI;//圆心角的极大值 
    while(minCentralAngle<maxCentralAngle-eps)
    {
        CentralAngle=(minCentralAngle+maxCentralAngle)/2;
        radius=L/2/sin(CentralAngle/2);
        L2=CentralAngle*radius;
        if(L2>=L1)//当弦长固定时，圆心角越大 ，弧长就越大 
            maxCentralAngle=CentralAngle;
        else if(L2<L1)
            minCentralAngle=CentralAngle;
    }
    radius=L/2/sin(minCentralAngle/2);
    ans=radius-L/2/tan(minCentralAngle/2);
    printf("%.3lf\n",ans);
    return 0;
}
