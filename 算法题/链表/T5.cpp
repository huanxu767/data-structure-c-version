//
// Created by 许欢 on 2020/8/14.
//

#include <cstdio>
#include "T5.h"

typedef int ElemType ;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;



void LinkList_t5();

//要求空间复杂度O(1)
//带头节点的单链表 反转
//利用头插法
void reverse(LinkList &L){


    LNode *p,*r;//p工作节点，r为p的后继
    p = L->next;//从第一个元素节点开始
    L->next = NULL;//先把头节点断开
    while (p != NULL){//依次将元素结点摘下
        r = p->next;//暂存p的后继

        p->next = L->next;//将p节点插入到头节点之后
        L->next = p;

        p = r;
    }
}


void LinkList_t5(){
    LNode *L;
    //头节点
    LNode *head = new LNode();
    L = head;
    L->next = NULL;

    LNode *writePoint = L;
    //尾插法 初始化值
    for (int i = 1; i < 5; ++i) {
        LNode *p = new LNode();
        p->data = i;
        writePoint->next = p;
        writePoint = writePoint->next;
    }
    writePoint->next = NULL;

    LNode *read = L->next;
    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
    reverse(L);
    printf("\n");

    read = L->next;
    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
}