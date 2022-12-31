#include<iostream>
using namespace std;
int get_not_in_num(int A[],int n)
{
    int result=-10000;
    int max_num=-10000;
    for(int i=0;i<n;i++)
    {
        if(A[i]>=max_num) max_num=A[i];
        else
        {

        }
    }
    result=max_num;
    return max_num;
}
int main()
{
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int res=get_not_in_num(A,10);
    cout<<res;
    return 0;
}