#include<iostream>
using namespace std;
bool recy_p(int A[],int p,int n)
{
    //验证p的合理性
    if(p<0 || p>=n) return false;
    //保存temp元素
    int *temp_num=new int[10];
    int index_move=0;
    //遍历整个数组
    for(int i=0;i<n-1;i++)
    {
        if((i-p)<0) 
        {
            // index_move=n-p;
            temp_num[i]=A[i];
            continue;
        }
        else index_move=i-p;
        // temp_num=A[index_move];
        A[index_move]=A[i];
    }
    for(int i=0;i<p;i++)
    {
        A[n-i-1]=temp_num[i];
    }
    return true;
}
int main()
{
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    recy_p(A,2,10);
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}