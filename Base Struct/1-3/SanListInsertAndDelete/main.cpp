#include <iostream>
using namespace std;
/***************************散列表定义**************************/
template <typename DataType>
class HashTable
{
public:
    HashTable(int size)
    {
        maxsize = size;
        count = 0;
        elements = new DataType[size];
        if(elements == NULL)
            exit(1);
        for(int i = 0; i < size; i++)
        {
            elements[i] = NULL;
        }
    }
    ~HashTable()
    {
        delete [] elements;
    }
    //散列函数
    int hash(DataType value);
    //查找函数，返回所查找元素的地址
    int searchHash(DataType value);
    //获取散列表第i 个元素的值
    DataType getData(int i)
    {
        if(i <= 0)
        {
            std::cout<<"索引值错误！必须为正整数"<<endl;
        }
        return elements[i - 1];
    }
    //插入操作
    bool insertHash(DataType value);

private:
    int maxsize;
    int count;
    DataType *elements; //数据域
};
/***********************hash函数**************************/
template <typename DataType>
int HashTable<DataType>::hash(DataType value)
{
    return value %13;
}
/**********************查找算法***************************/
template <typename DataType>
int HashTable<DataType>::searchHash(DataType value)
{
    int p = hash(value);
    if(elements[p] == value)
    {
        return p;
    }
    int rp = (p + 1) % maxsize;
    while(rp != p)
    {
        if(elements[rp] == value)
            return rp;
        if(elements[rp] == NULL)
            break;
        rp = (rp + 1)% maxsize;
    }
    if(rp == p)
        return -2;
    else
    {
        //elements[rp] = value;
        return rp;
    }
}
/****************************插入操作******************************/
template <typename DataType>
bool HashTable<DataType>::insertHash(DataType value)
{
    int pos = searchHash(value);
    if(pos < 0)
    {
        return false;
    }
    else if(elements[pos] == value)
    {
        cout<<"重复的元素"<<endl;
        return false;
    }
    else
    {
        elements[pos] = value;
        return true;
    }
}
int main(int argc, char *argv[])
{
    HashTable<int> hashtable = HashTable<int>(13);
    //依次插入元素
    hashtable.insertHash(66);
    hashtable.insertHash(32);
    hashtable.insertHash(98);
    hashtable.insertHash(478);
    hashtable.insertHash(11);
    hashtable.insertHash(23);
    hashtable.insertHash(43);
    hashtable.insertHash(55);
    hashtable.insertHash(67);
    hashtable.insertHash(108);
    hashtable.insertHash(230);
    hashtable.insertHash(223);
    hashtable.insertHash(10);
    //输出元素
    for(int i= 1; i <= 13; i++)
    {
        cout<<hashtable.getData(i)<<" ";
    }
    cout<<endl;
    //查找元素55
    cout<<"元素55的位置 ："<<hashtable.searchHash(55)<<endl;
    return 0;
}
