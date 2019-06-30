#include "iostream"
using namespace std;
int main()
{
    int width,height,full;
    char shape;
    cin>>height>>width>>shape>>full;
    if(full)
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                cout<<shape;
            }
            cout<<endl;
        }
    }else
    {
        for(int i=0;i<height;i++)
        {
            if(i==0 || i==height-1) {
                for (int j = 0; j < width; j++) {
                    cout << shape;
                }
                cout << endl;
            } else
            {
                for (int j = 0; j < width; j++) {
                    if(j==0 || j==width-1)
                        cout<<shape;
                    else
                        cout<<" ";
                }
                cout << endl;
            }
        }
 
    }
 
}
