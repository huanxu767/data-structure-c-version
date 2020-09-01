//
// Created by 许欢 on 2020/8/13.
//

#include <cstdlib>
#include <cstdio>
#include "DoubleLinkedList.h"

typedef int ElemType;
typedef struct DNode{
    ElemType data;
    DNode *prior,*next;
}DNode,*DLinklist;

void printDNode(DNode *D);
DNode* getNode(DNode *D,int position);
/**
 * 初始化一个带头节点的双链表
 * @param D
 */
DNode* init(){
    //头节点
    DNode *D;
    D = (DNode*)malloc(sizeof(DNode));
    D->next = NULL;
    printf("\n%d 头指针数据域，int就算赋值为NULL 打印出来也是0\n",D->data);
    return D;
}

/**
 * 尾插法 插入
 * @param D
 */
void tailInsert(DNode *D){
    //尾指针 空的先指向头节点
    DNode *tailPointer = D;
    for (int i = 1; i < 5; ++i) {
        DNode *newNode = (DNode*)malloc(sizeof(DNode));
        newNode->data = i;

        newNode->prior = tailPointer;
        tailPointer->next = newNode;
        //指向最后一个元素
        tailPointer = newNode;
    }
    printDNode(D);
}

/**
 * 插入 应该要判断下是否是结尾
 * @param D
 */
void insertNode(DNode *D,int position,ElemType data){
    printf("\ninsertNode position:%d\n",position);

    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    //
    DNode* currentNode = getNode(D,position);

    newNode->prior = currentNode->prior;
    newNode->next = currentNode;

    currentNode->prior->next = newNode;
    currentNode->prior = newNode;

    printDNode(D);
}

/**
 * 获取指定位置元素
 * @param D
 * @param position
 * @return
 */
DNode* getNode(DNode *D,int position){
    //指向头节点
    DNode* p = D;
    for (int i = 0; i < position; ++i) {
        p = p->next;
    }
    printf("\n获取指定位置元素 %d\n",p->data);
    return p;
}

//删除指定位置
void deleteNode(DNode *D,int position){
    printf("\n 删除元素 \n");
    //找到当前元素
    DNode* currentNode = getNode(D,position);

    if(currentNode->next == NULL){
        //新增一个 接在尾部 逻辑暂未实现


    }
    currentNode->prior->next = currentNode->next;
    currentNode->next->prior = currentNode->prior;
    free(currentNode);
    printDNode(D);
}

void printDNode(DNode *D){
    DNode* p = D->next;
    while (p != NULL){
        printf("%d ,",p->data);
        p = p->next;
    }
}

void doubleLinkDemo(){
    DNode* dNode = init();
    tailInsert(dNode);
    getNode(dNode,2);
    insertNode(dNode,5,22);
    deleteNode(dNode,4);

}