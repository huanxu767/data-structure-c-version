//
// Created by 许欢 on 2020/8/14.
//

#include <cstdlib>
#include <printf.h>
#include "T4.h"


typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;


void LinkList_t4();

//带头节点 单链表 删除最小值（最小值唯一） 要求高效
void Del_min(LinkList &L){
    LNode *pre = L;//指向前驱
    LNode *p = L->next; //工作指针
    LNode *minPre = L;//最小值前驱指针
    LNode *min = L->next;//最小值指针
    while (p != NULL){
        if(min->data > p->data){
            min = p;
            minPre = pre;
        }
        pre = pre->next;
        p = p->next;
    }
    printf("\nmin:%d\n",min->data);
    minPre->next = min->next;
    free(min);
}

void LinkList_t4(){
    LNode *L;
    //头指针
    LNode *headNode = (LNode*)malloc(sizeof(LNode));
    L = headNode;
    L->next = NULL;

    //
    LNode *p = L;

    int val[5]={4,2,3,1,7};//分别赋值

    for (int i = 1; i < 5; ++i) {
        LNode *tempNode = (LNode*)malloc(sizeof(LNode));
        tempNode->data = val[i];
        p->next = tempNode;
        p = p->next;
    }
    LNode *read = L->next;

    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
    printf("\n删除最小值\n");
    Del_min(L);
    read = L->next;

    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
    printf("\n删除最小的值\n");

}