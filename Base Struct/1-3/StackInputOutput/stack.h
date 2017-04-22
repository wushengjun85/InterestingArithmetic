#ifndef STACK_H
#define STACK_H
template <typename DataType> class Stack
{
public:
    Stack(int size)
    {
        maxSize = size;
        top = -1;
        elements = new DataType[size];
    }
    ~Stack()
    {
        delete [] elements;
    }
    //入栈操作
    bool push(DataType data);
    DataType pop();

private:
    DataType *elements;
    int top;
    int maxSize;
};
#endif // STACK_H
