#include <iostream>
using namespace std;

void insertSort(int a[],int n)
{
    int key = 0;
    int i = 0;
    int j = 0;
    while(i<n)
    {
        key = a[i];
        j = i - 1;
        while(j>= 0 && key < a[j])
        {
            a[j+1] = a[j];
            j = j -1;
        }
        a[j + 1] = key;
        i++;
    }
}
int main(int argc, char *argv[])
{
    int data[10];
    int i;
    cout<<"请输入10个整数："<<endl;
    for(i = 0; i < 10; i++)
        cin>>data[i];
    cout<<"您输入的值为："<<endl;
    for(i = 0; i < 10; i++)
        cout<<data[i]<<" ";
    cout<<endl;
    insertSort(data,10);
    cout<<"排序后的元素顺序为："<<endl;
    for(i= 0; i < 10; i++)
        cout<<data[i]<<" ";

    return 0;
}
