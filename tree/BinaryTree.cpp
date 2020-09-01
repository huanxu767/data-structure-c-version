//
// Created by 许欢 on 2020/8/20.
//

#include <cstdlib>
#include <cstdio>
#include "BinaryTree.h"
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

typedef int ElemType ;

typedef struct BiNode{
    struct BiNode *lChild;
    struct BiNode *rChild;
    ElemType data;
} BiNode,*BiTree;

void visit(BiNode *node);

void init(BiTree &T){
    /**
     *          1
     *      2       3
     *   4    5   6
     *      7
     */
    T = (BiNode *)malloc(sizeof(BiNode));
    T->data = 1;

    T->lChild = (BiNode *)malloc(sizeof(BiNode));
    T->lChild->data = 2;

    T->rChild = (BiNode *)malloc(sizeof(BiNode));
    T->rChild->data = 3;

    T->rChild->lChild = (BiNode *)malloc(sizeof(BiNode));
    T->rChild->lChild->data = 6;
    T->rChild->lChild->lChild = NULL;
    T->rChild->lChild->rChild = NULL;

    T->lChild->lChild = (BiNode *)malloc(sizeof(BiNode));
    T->lChild->lChild->data = 4;
    T->lChild->lChild->lChild = NULL;
    T->lChild->lChild->lChild = NULL;

    T->lChild->rChild = (BiNode *)malloc(sizeof(BiNode));
    T->lChild->rChild->data = 5;

    T->lChild->rChild->lChild = (BiNode *)malloc(sizeof(BiNode));
    T->lChild->rChild->lChild->data = 7;

    T->lChild->rChild->lChild->lChild = NULL;
    T->lChild->rChild->lChild->rChild = NULL;
}

//先序 Recursion
void preOrderTraverse(BiTree &T){
    if(T){
        visit(T);
        preOrderTraverse(T->lChild);
        preOrderTraverse(T->rChild);
    }
}

//中序 Recursion
void inOrderTraverse(BiTree &T){
    if(T){
        inOrderTraverse(T->lChild);
        visit(T);
        inOrderTraverse(T->rChild);
    }
}

//后序 Recursion
void postOrderTraverse(BiTree &T){
    if(T){
        postOrderTraverse(T->lChild);
        postOrderTraverse(T->rChild);
        visit(T);
    }
}

//先序遍历非递归版本
// 中 左 右 栈是先进后出，所以右边要先放 然后 左边 最后中间
// 从上到下 最先访问的是 根节点

void preOrderTraverseNonRecursion(BiTree &T){
    if(T == nullptr){
        return;
    }
    if(T){
        stack<BiNode*> st;
        st.push(T);//根节点入栈
        BiNode* p;
        while(!st.empty()){
            p = st.top();
            st.pop();

            visit(p);
            //!!!先右后左 因为后入栈的先出栈 而先序遍历 通常先访问左孩子
            if(p->rChild){
                st.push(p->rChild);
            }
            if(p->lChild){
                st.push(p->lChild);
            }
        }
    }
}

//中序 非递归
// 左右中 1，一次性 左边节点全压入 2 出一个节点 如果该节点有右孩子压入
// 从下到上 ，最先访问的是 左下角的节点
void inOrderTraverseNonRecursion(BiTree &T){
    if(T == nullptr){
        return;
    }
    BiNode *p = T;//辅助指针p 指向当前要操作的结点 初始为root
    stack<BiNode*> st;
    while (p != nullptr || !st.empty()){
        if(p){
            st.push(p);
            p = p->lChild;

        } else{
            p = st.top();
            st.pop();
            visit(p);
            p = p->rChild;
        }
    }
}
//后序非递归
//后序遍历的递归算法 左右中
void postOrderTraverseNonRecursion(BiTree Tree) {
    if(Tree == nullptr){
        return;
    }
    stack<BiNode*> st1;//栈一用来辅助遍历，栈二存放遍历的顺序。
    stack<BiNode*> st2;//后序遍历的非递归算法 通常需要双栈 ，但是也有单栈的算法.
    BiNode *p = Tree;
    st1.push(p);//先将根结点入栈1
    while (!st1.empty()) {
        p = st1.top();//出栈1
        st1.pop();
        st2.push(p);//进入栈2 ，栈二是为了保存每遍历顺序的逆序的栈

        //先左后右的目的是 右先弹出栈1 然后先进栈2 后出栈2 所以是左 右 根的顺序
        if (p->lChild) {//先入左
            st1.push(p->lChild);
        }
        if (p->rChild) {//后入右
            st1.push(p->rChild);
        }
    }
    //遍历栈二 即访问顺序
    while (!st2.empty()) {
        p = st2.top();
        st2.pop();
        visit(p);
    }
}

void visit(BiNode *node){
    printf("【访问】%d \n",node->data);
}


//先序
void preOrderS(BiNode *root)
{
    stack<BiNode*> s;
    BiNode *p=root;
    while(p!=NULL||!s.empty())
    {
        //沿着左支走到底
        //用栈记录走过的路径
        while(p!=NULL)
        {
            visit(p);
            s.push(p);
            p=p->lChild;
        }
        //当左支走到尽头时，若栈里边还有结点
        //则退栈，后退到跟结点，并且向右支前进
        //此时p!=NULL,会进入以上while循环
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->rChild;
        }
    }
}
//注：在 if(!s.empty())中，获取根结点只是为了得到往右支的中转，
//当获得右支指针后，将根结点从栈中弹出，以便返回的时候直接
//回到爷爷结点


//中序
void inOrderS(BiTree &root){
    stack<BiNode*> s;
    BiNode *p=root;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            s.push(p);
            p=p->lChild;
        }
        if(!s.empty()){
            p=s.top();
            s.pop();
            visit(p);
            p=p->rChild;
        }
    }
}
//中序遍历和先序遍历的代码几乎一致，除了访问点的位置不一样
//中序遍历是在退栈的时候访问根结点

//后序
void postOrder(BiTree &T) {
    BiNode *p = T, *r = NULL;
    stack<BiNode*> st;
    while (p!=NULL || !st.empty()) {
        if (p!=NULL) {//走到最左边
            st.push(p);
            cout<<p->data<<"-->>>>入栈"<<endl;
            p = p->lChild;
        }
        else {
            p = st.top();
            cout<<p->data<<"取栈顶元素"<<endl;
            if (p->rChild!=NULL && p->rChild != r){//右子树存在，未被访问
                cout<<p->data<<"右子树存在，未被访问"<<endl;
                p = p->rChild;
            }
            else {
                st.pop();
                cout<<p->data<<"<<<<--出栈"<<endl;
                visit(p);
                r = p;//记录最近访问过的节点
                p = NULL;//节点访问完后，重置p指针
            }
        }//else
    }//while
}

    /**
    *          1
    *      2       3
    *   4    5   6
    *      7
    */

void preOrderMy(BiTree &T){

    stack<BiNode*> st;
    BiNode *p = T;
    while (p != NULL || !st.empty()){
        while (p != NULL){
            visit(p);
            st.push(p);
            cout<<p->data<<"-->>>>入栈"<<endl;
            p = p->lChild;
        }
        if(!st.empty()){
            p = st.top();
            st.pop();
            cout<<p->data<<"<<<<--出栈"<<endl;
            p = p->rChild;
        }
    }
}

void inOrderMy(BiTree &T){

    stack<BiNode*> st;
    BiNode *p = T;
    while (p != NULL || !st.empty()){
        while (p != NULL){
            st.push(p);
            cout<<p->data<<"-->>>>入栈"<<endl;
            p = p->lChild;
        }
        if(!st.empty()){
            p = st.top();
            cout<<p->data<<"<<<<--出栈"<<endl;
            visit(p);
            st.pop();
            p = p->rChild;
        }
    }
}

//层次遍历 从上到下 从左到右
void levelOrder(BiTree &T){
    queue<BiNode*> qu;
    qu.push(T);
    BiNode *p;
    while (!qu.empty()){
        p = qu.front();
        qu.pop();
        visit(p);
        if(p->lChild != NULL){
            qu.push(p->lChild);
        }
        if(p->rChild != NULL){
            qu.push(p->rChild);
        }
    }
}

/**
           1
          / \
        2     3
      /   \		\
    4      5     6
    	  /
        7

 */
//求二叉树的高度，该二叉树使用链表存储
//先序
int getLengthByPreOrder(BiTree T){
    if(!T){
        return 0;
    }
    //采用先序的方式 试一试
    BiNode *p = T;
    stack<BiNode*> st;
    int max = 1;
    int current = 1;
    while (p!=NULL || !st.empty()){
        while (p!=NULL){
            visit(p);
            st.push(p);
            p = p->lChild;
            current++;
            max = current <= max?max:current;
        }
        if(!st.empty()){
            p = st.top();
            st.pop();
            current--;
            p = p->rChild;
        }
    }
    return max;
}

/**
           1
          / \
        2     3
      /   \		\
    4      5     6
    	  /
        7
 */

int getLengthByLevelOrder(BiTree T){
    if(!T){
        return 0;
    }
    BiNode *p = T;
    queue<BiNode*> qu;
    qu.push(T);
    int max = 0;
    while (!qu.empty()){
        max++;
        int currentLevelNodes = qu.size();//记录当前队列大小、即当前层元素个数
        cout<< "当前层:" << max << "，该层节点数:" << currentLevelNodes <<endl;

        //一次性把当前队列 都处理完
        for (int i = 0; i < currentLevelNodes; ++i) {
            p = qu.front();
            cout<< "访问：" << p->data <<endl;
            qu.pop();
            if(p->lChild != NULL){
                qu.push(p->lChild);
            }
            if(p->rChild != NULL){
                qu.push(p->rChild);
            }
        }
    }
    return max;
}

void BinaryTree() {
    /**
     *          1
     *      2       3
     *   4    5   6
     *      7
     */
    BiTree tree;
    init(tree);
//    printf("\n先序--递归------\n");
//    preOrderTraverse(tree);
//    printf("\n先序--非递归2------\n");
//    preOrderMy(tree);
////    printf("\n先序--非递归1------\n");
////    preOrderTraverseNonRecursion(tree);
//    printf("\n中序--------\n");
//    inOrderTraverse(tree);
//    printf("\n中序--非递归------\n");
//    inOrderMy(tree);
////    inOrderTraverseNonRecursion(tree);
//    printf("\n后序--------\n");
//    postOrderTraverse(tree
//    printf("\n后序--非递归------\n");
////    postOrder(tree);
//    postOrderTraverseNonRecursion(tree);

    printf("\n层次--非递归----\n");
    levelOrder(tree);
//    int h = getLength(tree);
    int h = getLengthByLevelOrder(tree);
    printf("\n高度--%d--\n",h);
}
