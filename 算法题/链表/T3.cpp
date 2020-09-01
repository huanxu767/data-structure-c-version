//
// Created by 许欢 on 2020/8/14.
//

#include <cstdlib>
#include <cstdio>
#include "T3.h"

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;

void LinkListT3Demo();

void R_Print(LinkList &L){
    if (L->next != NULL){
        printf("%d\n",L->next->data);
        R_Print(L->next);
    }//if
    // 自己写的
    if (L->next != NULL) {
        printf("%d,",L->next->data);
    }
    //答案写的 会把头节点的值输出了
//        if(L !=NULL) printf("%d.",L.->data);
}

//设L为带头节点的单链表，编写程序实现从尾到头输出
void LinkListT3Demo(){
    LNode *L;
    //头指针
    LNode *headNode = (LNode*)malloc(sizeof(LNode));
    L = headNode;
    L->next = NULL;

    //
    LNode *p = L;
    for (int i = 1; i < 5; ++i) {
        LNode *tempNode = (LNode*)malloc(sizeof(LNode));
        tempNode->data = i;
        p->next = tempNode;
        p = p->next;
    }
    LNode *read = L->next;

    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
    printf("\n反转\n");
    R_Print(L);
}