//
// Created by 许欢 on 2020/8/14.
//

#include "T1.h"
#include <cstdio>
#include <cstdlib>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode,*LinkList;

//删除 2种方法
// 1，找到前一个元素  O(n)
// 2 把后面的值 赋值给当前元素 删除后继元素 O(1)


//设计一个递归程序删除不带头节点的单链表L中所有值为X的节点
//*L写错误 下面的是对的
void deleteX(LNode *L,ElemType x){

    LNode *p;//指向带删除的点
    if(L == NULL){//递归出口
        return;
    }
    if(L->data == x){
        p = L;
        L = L->next;
        free(p);
        deleteX(L,x);
    }else{
        deleteX(L->next,x);
    }
}

void Del_X_3(LinkList &L,ElemType x)
{
    LNode *p;  //p指向待删除结点，

    if(L==NULL) //递归出口
        return ;
    if(L->data==x){
        p=L;
        L=L->next; //删除L，并让L指向下一结点
        /*核心部分的代码是这个地方，因为使用了cpp的引用机制，实际上等于上一层的L->next = L->next->next;
		比较难以理解！可以参考https://blog.csdn.net/raby_gyl/article/details/13383573
		*/

        free(p);
        Del_X_3(L,x);
    }else{
        Del_X_3(L->next,x);//递归调用
    }
}

void LinkList_t1(){
    LNode *lNode;

    LNode *n = new LNode();
    n->data = 1;
    lNode = n;

    LNode *p = lNode;

    for (int i = 2; i < 10; ++i) {
        LNode *n2 = new LNode();
        n2->data = i;
        p->next = n2;
        p = p->next;
    }

    LNode *read = lNode;
    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
//    deleteX(lNode,2);
    Del_X_3(lNode,2);
    printf("\n");

    LNode *read2 = lNode;
    while (read2 != NULL){
        printf("%d,",read2->data);
        read2 = read2->next;
    }
}