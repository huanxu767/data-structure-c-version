//
// Created by 许欢 on 2020/8/20.
//

#include "stackDemo.h"
#include<stack>
#include <queue>
#include <iostream>
using namespace std;


/**
 *
    s.empty()//如果栈为空返回true，否则返回false
    s.size()//返回栈中元素的个数
    s.pop()//删除栈顶元素但不返回其值
    s.top()//返回栈顶的元素，但不删除该元素
    s.push(X)//在栈顶压入新元素 ，参数X为要压入的元素
 */
void stackDemo(){
    stack <int>stk;
    for (int i = 10; i < 20; ++i) {
        stk.push(i);
    }
    cout<<"栈的大小:"<<stk.size()<<endl;
    while (!stk.empty()){
        cout<<stk.top()<<endl;
        stk.pop();
    }
    cout<<"栈的大小:"<<stk.size()<<endl;
}

/**
 *
 * 队列：
q.empty()// 如果队列为空返回true，否则返回false
q.size() // 返回队列中元素的个数
q.pop()  //删除队列首元素但不返回其值
q.front()  // 返回队首元素的值，但不删除该元素
q.push(X) //在队尾压入新元素 ，X为要压入的元素
q.back() //返回队列尾元素的值，但不删除该元素
 */
void queueDemo(){
    queue<int> q;
    for (int i = 10; i < 20; ++i) {
        q.push(i);
    }
    cout<<"队列的大小:"<<q.size()<<endl;
    while (!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<"队列的大小:"<<q.size()<<endl;

}