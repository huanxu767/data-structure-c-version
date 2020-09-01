#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstdio>

#include "./SqList/LinearTable.h"
#include "./base/vector_demo.h"
#include "./sorting_algorithm/sort.h"
#include "SqList/SingleLinkList.h"
#include "SqList/DoubleLinkedList.h"
#include "算法题/链表/T1.h"
#include "算法题/链表/T2.h"
#include "算法题/链表/T3.h"
#include "算法题/链表/T4.h"
#include "算法题/链表/T5.h"
#include "tree/BinaryTree.h"
#include "base/stackDemo.h"

extern "C" {
    #include "./base/C_demo.h";
}
using namespace std;
void studyLinearTable(){
    std::cout << "\n-------------【deleteMinValDemo】-----------" << std::endl;
    deleteMinValDemo();
    std::cout << "\n-------------【reverseListDemo】-----------" << std::endl;
    reverseListDemo();
    std::cout << "\n-------------【deleteAllValueXDemo】-----------" << std::endl;
    deleteAllValueXDemo();
    std::cout << "\n-------------【deleteMin_MaxDemo】-----------" << std::endl;
    deleteMin_MaxDemo();
    std::cout << "\n-------------【mergeTwoSortList】-----------" << std::endl;
    mergeTwoSortListDemo();
}


void pointerAddress(){
    int a = 3;
//    指针可以指向指针 也可以指向地址
    int *aa = &a;
    //指向指针的指针
    cout << "a:：" << a << endl;
    cout << "&a:：" << &a << endl;

    cout << "aa：" << aa << endl;
    cout << "*aa：" << *aa << endl;

    free(aa);

//
//    int *bb = aa;
//    cout << "&bb是*aa：" << bb << endl;
//
//    a = 4;
//    *bb = 7;
//
//    cout << "&a是a的地址：" << a << endl;
//
//    cout << "&aa是a的地址：" << *aa << endl;
//
//    cout << "&bb是*aa：" << *bb << endl;

//
//    int *b = &a;
//    cout << "a：" << a << endl;
//    cout << "b：" << b << endl;
//    *b = 10;
//    cout << "&a：" << &a << endl;
//    cout << "b：" << b << endl;
//    b是a的指针，指向a的地址。（也就是a与b相连，只要修改*b的值，a的值也跟着改动）

}


void shu(){
    //  c语言Demo
//    cDemo();

//    顺序表demo
//    studyLinearTable();
    //单链表
//    SingleLinkListDemo();
    //双链表
//    doubleLinkDemo();

//    vector案例
//     vectorDemo();

//    排序案例
//    sortDemo();
}
void ti(){
//    LinkList_t1();
//    LinkListT2Demo();
//    LinkListT3Demo();
//    LinkList_t4();
    LinkList_t5();
}

void tree(){
    BinaryTree();
}

int main() {
//    ti();
//    pointerAddress();
    tree();

//    stackDemo();
//    queueDemo();
    return 0;

}




