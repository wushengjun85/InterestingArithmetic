#include <iostream>
using namespace std;
void insertSort(int [],int);
/************************插入排序***************************/
void insertSort(int d[],int n)
{
    int i,j;
    for(int j = 2; j < n; j++)
    {
        d[0] = d[j];
        i = j - 1;
        while(i > 0 & d[i]>d[0])
        {
            d[i+1] = d[i];
            i--;
        }
        d[i+1] = d[0];
    }
}
int main(int argc, char *argv[])
{
    int data[9] = {0,43,35,1,87,99,67,78,100};
    //遍历输入数据数组，数组大小比实际数据个数大1，data[0]为哨兵元素，用0填充9
    int length = 9;
    cout<<"The oranginal array is :"<<endl;
    for(int i = 1; i < length; i++)
        cout<<data[i]<<" ";
    cout<<endl;
    insertSort(data,length);
    cout<<"There result of insertion sorting is :"<<endl;
    for(int i = 1; i < length; i++)
        cout<<data[i]<<" ";
    cout<<endl;
    return 0;
}
