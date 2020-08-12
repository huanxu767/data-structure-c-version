//
// Created by 许欢 on 2020/8/12.
//

#include <cstdlib>
#include <printf.h>
#include "LinkList.h"

typedef int ElemType ;

typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;

void printList(LinkList &L);
LNode* getElem(LinkList &L,int i);

/**创建头节点*/
void initLinkList(LinkList &L){
    //创建头节点
//    L = (LinkList)malloc(sizeof(LNode));
    L = new LNode();
    L->next = NULL;
    printf("\n%d 头指针数据域，int就算赋值为NULL 打印出来也是0\n",L->data);

}

/**头插法 缺点 顺序反的 */
void headInsert(LinkList &L){
    printf("初始化头指针\n");
    //获取头节点
    LinkList head = L;
    for (int i = 1; i < 10; ++i) {
        LinkList s = (LinkList)malloc(sizeof(LNode));
        s->data = i;
        s->next = head->next;
        head->next = s;
    }
    printList(L);

}
/** 尾插法 借助尾指针*/
void tailInsert(LinkList &L) {
    printf("尾插法\n");
    //尾巴指针指向尾巴指针，初始指向头节点
    LNode *tail = L;
    for (int i = 1; i < 10; ++i) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = i;
        tail->next = s;
        //尾巴指针 指向新插入的元素
        tail = s;
        tail->next = NULL;
    }
    printList(L);
}

/** 按序号查找*/
LNode* getElem(LinkList &L,int i){
    if(i == 0){
        return L;
    }
    if(i < 1){
        //i无效
        return NULL;
    }
    //指向第一个节点（非头节点）
    LNode *p = L->next;
    for (int j = 1; j < i; ++j) {
        //如果是第一个位置 循环0次
        p = p->next;
    }
    return p;
}


/** 按值查找*/
LNode* locateElem(LinkList &L,ElemType e){
    //指向真实的第一个节点（非头节点）
    LNode *p = L->next;
    while (p != NULL && p->data !=e){
        p = p->next;
    }
    return p;
}

/** 循环打印*/
void printList(LinkList &L){
    LNode *p = L->next;
    while (p != NULL){
        printf("%d,",p->data);
        p = p->next;
    }
    printf("\n");
}

/** 插入*/
void insetNode(LNode *L,ElemType data,int position){
    //创建新节点
    LNode *newNode = (LNode*)malloc(sizeof(LNode));
    newNode->data = data;
    //找到前一个节点 q
    LNode *preNode = getElem(L,position-1);
    //新节点的后继指向 前一个节点的后继
    newNode->next = preNode->next;
    //前节点next指向new
    preNode->next = newNode;
    printList(L);
}

void LinkListDemo(){
    //头插
//    LinkList L;
//    initLinkList(L);
//    headInsert(L);

    //尾插
    LinkList L1;
    initLinkList(L1);
    tailInsert(L1);
    //按值查找
    LNode *node = locateElem(L1,3);
    printf("查找到到值为%d\n",node->data);
    //按序号查找
    LNode *node2 = getElem(L1,3);
    printf("查找到到值为%d\n",node2->data);

    insetNode(L1,22,3);

}