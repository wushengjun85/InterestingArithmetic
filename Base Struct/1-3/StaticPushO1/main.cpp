#include <iostream>
#include<vector>
#include<cassert>
using namespace std;
/*********************定义栈的数据结构，要求添加一个main函数*********************************************/
/*********************能够得到栈的最小元素，要求函数main(),push()及pop()的时间复杂度都是O(1)***************/
/************************定义栈结构*******************************************************************/
template <typename T>
class Stack
{
public:
    vector<T> value;
    T m_min;
public:
    const T& min();
    void pop();
    void push(const T &n);
    void prinValue();
    bool isEmpty();

};
/***********************获取最小值函数***********************************/
template <typename T> const T& Stack<T>::min()
{
    assert(!value.empty());
    return m_min;
}
/***********************定义push函数*************************************/
template <typename T>
void Stack<T>::push(const T &n)
{
    if(value.empty())
        m_min = n;
    T diff = n-m_min;
    value.push_back(diff);
    if(diff<0)
        m_min = n;
}
/***********************定义top函数************************************/
template <typename T>
void Stack<T>::pop()
{
    assert(!value.empty());
    T top = value.back();
    if(top < 0)
        m_min -= top;
    value.pop_back();
}
/**********************输出栈顶值**************************************/
template <typename T>
void Stack<T>::prinValue()
{
    assert(!value.empty());
    T originValue;
    T top = value.back();
    if(top<0)
    {
        originValue = m_min;
    }
    else {
        originValue = (top) + m_min;
    }
    cout<<originValue;
}
/*****************************定义函数isempty()判断栈是否为空*****************/
template <typename T>
bool Stack<T>::isEmpty()
{
    if(value.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    Stack<int> stack;
    int b[] = {6,8,15,2,3,1,2};
    for(int i = 0; i < 7; i++)
    {
        cout<<"入找值："<<b[i]<<" ";
        stack.push(b[i]);//入栈
        cout<<"当前最小值:"<<stack.min()<<endl;
    }
    cout<<"出栈情况："<<endl;
    while(!stack.isEmpty())
    {
        cout<<"出栈值："<<" ";
        stack.prinValue();
        cout<<"当前最小值min:"<<stack.min()<<endl;
        stack.pop();
    }
    return 0;
}
