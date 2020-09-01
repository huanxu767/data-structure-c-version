//
// Created by 许欢 on 2020/8/14.
//

#include <cstdlib>
#include <cstdio>
#include "T2.h"

//在带头节点带单链表L中，删除所有值为x的节点，并释放空间，假设x的节点不唯一

typedef int ElemType ;

typedef struct LNode{
    ElemType data;
    LNode* next;
}LNode,*LinkList;


void LinkListT2Demo();

//在带头节点带单链表L中，删除所有值为x的节点，并释放空间，假设x的节点不唯一
//算法1
void DeleteSameValue(LinkList &L,ElemType x){
    LNode *pre = L;//指向头节点
    LNode *current = L->next;//指向第一个元素
    LNode *p;
    while (current != NULL){
        if(current->data == x){
            p = current;//记录 待删除节点
            current = current->next;// 赶紧把带头探索的节点移到下一个，假如先释放了当前节点，走不下去了。
            pre->next = current;//把前面的节点 跳过 待删除节点 指向下一个 保证不断链
            free(p); //此时 可以放心释放了
        } else{
            pre = current;//往后移   [貌似这么移动也可以pre = pre->next];
            current = current->next;//往后移一个
        }
    }
}
//算法2
//尾指针
//思路：如果相同的值，直接删除，不相同的值移动到后面
void DeleteSameValue_tail(LinkList &L,ElemType x){

    LNode *current = L->next;//指向第一个元素
    LNode *deleteNode; //辅助删除
    LNode *tail = L; //指向尾节点 初始指向头

    while (current != NULL){
        if(current->data == x){
            //删除
            deleteNode = current;
            current = current->next;
            free(deleteNode);
        }else{
            tail->next = current; //尾巴指针 next 指向当前元素 保证不断裂
            tail = current; // 尾巴指针 移到当前位置
            current = current->next; //当前位置 往后移动
        }

    }


}
void LinkListT2Demo(){
    //
    LNode *L;
    //头节点
    LNode *node = (LNode*)malloc(sizeof(LNode));
    L = node;
    L->next = NULL;

    //塞入一些值
    LNode *p = L;
    for (int i = 1; i < 20; ++i) {
        LNode *d = (LNode*)malloc(sizeof(LNode));
        d->data = i % 5;
        p->next = d;
        p = p->next;
    }

    //输出
    LNode *read = L->next;
    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
//    DeleteSameValue(L,3);

    DeleteSameValue_tail(L,3);
    printf("\n删除3后\n");
    //输出
    read = L->next;
    while (read != NULL){
        printf("%d,",read->data);
        read = read->next;
    }
}