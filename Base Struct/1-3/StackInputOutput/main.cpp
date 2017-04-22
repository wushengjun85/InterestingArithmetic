#include <iostream>
#include"stack.h"
using namespace std;
/***************入栈操作******************/
template<typename Datatype>
bool Stack<Datatype>::push(Datatype data)
{
    if(top == maxSize)
    {
        return false;
    }
    elements[++top] = data;
    return  true;
}
/***************出栈操作*****************/
template <typename Datatype>
Datatype Stack<Datatype>::pop()
{
    if(top == -1)
    {
        exit(1);
    }
    return elements[top--];
}
int main(int argc, char *argv[])
{
    /*****************首先顺序入栈*******************/
    Stack<int> s = Stack<int>(6);
    int temp = 0;
    //一次入栈
    s.push(23);
    s.push(56);
    s.push(11);
    //要求11出栈 所以此时弹出11
    temp = s.pop();
    cout<<temp<<" ";
    //将4入栈
    s.push(4);
    temp = s.pop();
    cout<<temp<<" ";
    temp = s.pop();
    cout<<temp<<" ";
    //入栈
    s.push(87);
    s.push(98);
    //按要求出栈
    temp = s.pop();
    cout<<temp<<" ";
    temp = s.pop();
    cout<<temp<<" ";
    temp = s.pop();
    cout<<temp<<" ";

    return 0;
}
