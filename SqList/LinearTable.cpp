//
// Created by 许欢 on 2020/8/7.
//

#include <iostream>
#include "LinearTable.h"

#define ElemType int
#define MAX_SIZE 50

typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} SqList;

/**
 * T1,删除最小的值
 * @param list
 * @param value
 * @return
 */
bool deleteMinElem(SqList &list,int &value){
    if(list.length == 0){
        return false;
    }
    value = list.data[0];
    int index = 0;
    //取得了最小的元素 和 位置
    for(int i = 0 ;i < list.length;i++){
        if(list.data[i] < value){
            value = list.data[i];
            index = i;
        }
    }
   //将最后一个元素 放入指定位置 长度减1
   //带来的问题 顺序变了 但是实现起来简单
   list.data[index] = list.data[list.length - 1];
   list.length--;
   return true;
}

/**
 * T2,将顺序表所有的元素逆置
 * 算法1
 * @param list
 */
void reverseList(SqList &list){
    //空表 和长度为1的表 不需要转换
    if(list.length == 0 || list.length ==1){
        return;
    }
    // 收尾对调
    // 1 2 3 4 偶数 需要转换 2次 n/2
    // 1 2 3 4 5 奇数 需要转换2次 n/2 取整
    int times = list.length / 2;
    for (int i = 0; i < times; i++) {
        int temp = list.data[i];
        list.data[i] = list.data[list.length - 1 -i];
        list.data[list.length - 1 -i] = temp;
    }
}
/**
 * T2,将顺序表所有的元素逆置
 * 算法2
 * @param list
 */
void reverseListM2(SqList &list){
    //空表 和长度为1的表 不需要转换
    if(list.length == 0 || list.length ==1){
        return;
    }
    // 收尾对调
    // 1 2 3 4 偶数 需要转换 2次 n/2
    // 0 3 ，1 2 ，2 1结束

    // 1 2 3 4 5 奇数 需要转换2次 n/2 取整
    // 0 4,1 3,2 2 结束
    //结束的标志 i >= j 故 循环条件 i< j
    for (int i = 0,j = list.length -1 ; i < j; i++,j--) {
        int temp = list.data[i];
        list.data[i] = list.data[j];
        list.data[j] = temp;
    }
}

//T3：删除所有值为x的元素
//方法1：构造个新数组把不等于X的值放进去 多出了一个Sqllist
void deleteAllValueXM1(SqList &list,int x){
    if(list.length == 0 ){
        return;
    }
    //获取不等于X的长度
    int newArraySize = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] != x){
            newArraySize++;
        }
    }
    SqList sqList;
    sqList.length = newArraySize;
    int index = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] != x){
            sqList.data[index++] = list.data[i];
        }
    }
    list = sqList;
}

//T3：删除所有值为x的元素
//方法2：构造个新数组把不等于X的值放进去，利用本来的数组
void deleteAllValueXM2(SqList &list,int x){
    if(list.length == 0 ){
        return;
    }
    //不等于X的长度
    int newArraySize = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] != x){
            //外循环移动的比新的块
            list.data[newArraySize] = list.data[i];
            newArraySize++;
        }
    }
    list.length = newArraySize;
}

//T3：删除所有值为x的元素
//方法3：有几个等于X的元素 当前元素就向前移动几个
//分析 1 2 3 2 3 目标 删除2
// 0   1 不等 移动 0   不相等k = 0
// 1   2 相等 不动     不相等k = 1
// 2   3 不等 移动 1   不相等k = 2
// 3   2 相等 不动
// 4   3 不等 移动 2   不相等k = 3
//最终长度 3 ,序列 133
void deleteAllValueXM3(SqList &list,int x){
    if(list.length == 0 ){
        return;
    }
    //不等于X的长度
    int newArraySize = 0;
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] != x){
            list.data[i-newArraySize] = list.data[i];
            newArraySize++;
        }
    }
    list.length = newArraySize;
}

//T4：删除有序的顺序表的值[min,max]的元素
bool deleteMin_Max(SqList &list,int min,int max){
    if(min > max){
        return false;
    }
    //如果 min 比 最大值还大 或者 max比最小值还小 直接返回空
    //此逻辑暂时没加

    //记录虚拟数组的长度
    int k = 0;
    for (int i = 0; i < list.length; ++i) {
        //适用T3 M2 虚拟数组的方法
        if(list.data[i] < min || list.data[i] > max){
            list.data[k] = list.data[i];
            k++;
        }
    }
    list.length = k;
    return true;
}

// T4： wangdao git方法 这个判断感觉有问题【如果s和t都在数组值的范围内 时候删除元素】 回去看书上题目
bool deleteS_T(SqList &l, int s, int t) {
    if (s >= t) {
        return false;
    }
    if (l.length == 0) {
        return false;
    }
    if ((s >= l.data[0] && s <= l.data[l.length - 1]) && (t >= l.data[0] && t <= l.data[l.length - 1])) {
        //如果s和t都在数组值的范围内 时候删除元素
        //利用上面的方法 有种伪造数组的感觉
        int k = 0;
        for (int i = 0; i < l.length; ++i) {
            if (l.data[i] < s || l.data[i] > t) {
                l.data[k] = l.data[i];
                k++;
            }
        }
        l.length = k;
    }
    return true;
}
/**
 * T6:合并两个有序顺序表
 * t1: 1 3 4 5 8 12
 * t2: 1 3 6 9
 * t3: 1 1 3 3 4 5 6 8 9
 * 思路一：双重循环搞不定
 * 思路二：线截取长度一致（demo为 4）合并，再合多余的
 * @param list1
 * @param list2
 * @param list
 * @return
 */
bool mergeTwoSortList(SqList &list1, SqList &list2, SqList &list) {
    //
    if(list1.length == 0 || list2.length == 0){
        return false;
    }
    if((list1.length + list2.length) > MAX_SIZE){
        return false;
    }
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    //合并等长部分（描述不准确 ） 并不一定是短的先结束
    //其中一个已经合并完
    while (index1 < list1.length && index2 < list2.length){
        if(list1.data[index1] <= list2.data[index2]){
            list.data[index++] = list1.data[index1++];
        }else{
            list.data[index++] = list2.data[index2++];
        }
    }
    //将剩余部分合并
    while (index1 < list1.length) {
        list.data[index++] = list1.data[index1++];
    }
    while (index2 < list2.length) {
        list.data[index++] = list2.data[index2++];
    }
    list.length = index;
    return true;
}

/**
 * 打印SqList
 */
void printLinearTable(SqList &list){
    printf("\n");
    for (int i = 0; i < list.length; ++i) {
        printf("%d\t",list.data[i]);
    }

}

/**
 * 删除最小值Demo
 */
void deleteMinValDemo(){
    SqList l;
    l.length = 4;
    l.data[0] = 10;
    l.data[1] = 4;
    l.data[2] = 8;
    l.data[3] = 7;
    printLinearTable(l);
    int minValue;
    deleteMinElem(l,minValue);
    printf("\n被删除的最小值为：%d\n",minValue);

}

/**
 * 反转DEMO
 */
void reverseListDemo(){
    printf("偶数\n");
    SqList l;
    l.length = 4;
    l.data[0] = 1;
    l.data[1] = 2;
    l.data[2] = 3;
    l.data[3] = 4;
    printf("原来\t");
    printLinearTable(l);
    printf("方法1转换后\t");
    reverseList(l);
    printLinearTable(l);
    printf("方法2继续转换后\t");
    reverseListM2(l);
    printLinearTable(l);


    printf("\n奇数\n");
    SqList le;
    le.length = 5;
    le.data[0] = 1;
    le.data[1] = 2;
    le.data[2] = 3;
    le.data[3] = 4;
    le.data[4] = 5;

    printf("原来\t");
    printLinearTable(le);
    reverseList(le);
    printf("方法1转换后\t");
    printLinearTable(le);

    printf("方法2继续转换后\t");
    reverseListM2(le);
    printLinearTable(le);
    printf("方法2继续转换后\n");

}

/**
 *
 */
void deleteAllValueXDemo(){
    printf("\n[删除线性表中指定的值 M1]\n");
    SqList list;
    list.length = 5;
    list.data[0] = 1;
    list.data[1] = 2;
    list.data[2] = 3;
    list.data[3] = 2;
    list.data[4] = 3;
    deleteAllValueXM1(list,2);
    printLinearTable(list);

    printf("\n[删除线性表中指定的值 M2]\n");
    SqList list2;
    list2.length = 5;
    list2.data[0] = 1;
    list2.data[1] = 2;
    list2.data[2] = 3;
    list2.data[3] = 2;
    list2.data[4] = 3;
    deleteAllValueXM1(list2,2);
    printLinearTable(list2);

    printf("\n[删除线性表中指定的值 M3]\n");
    SqList list3;
    list3.length = 5;
    list3.data[0] = 1;
    list3.data[1] = 2;
    list3.data[2] = 3;
    list3.data[3] = 2;
    list3.data[4] = 3;
    deleteAllValueXM1(list3,2);
    printLinearTable(list3);
}

/**
 * 删除有序顺序表中指定范围的值
 */
void deleteMin_MaxDemo() {
    printf("\n[删除有序顺序表中指定范围的值 M3]\n");
    SqList list3;
    list3.length = 5;
    list3.data[0] = 1;
    list3.data[1] = 2;
    list3.data[2] = 3;
    list3.data[3] = 4;
    list3.data[4] = 5;
//    deleteS_T(list3,2,8);
    deleteMin_Max(list3,2,4);
    printLinearTable(list3);
}
/**
 * 合并两个有序顺序表
 */
void mergeTwoSortListDemo(){
    SqList list1;
    list1.length = 4;
    list1.data[0] = 1;
    list1.data[1] = 2;
    list1.data[2] = 2;
    list1.data[3] = 12;

    SqList list2;
    list2.length = 7;
    list2.data[0] = 1;
    list2.data[1] = 2;
    list2.data[2] = 3;
    list2.data[3] = 4;
    list2.data[4] = 5;
    list2.data[5] = 6;
    list2.data[6] = 7;

    SqList list;
    mergeTwoSortList(list1,list2,list);
    printLinearTable(list1);
    printLinearTable(list2);
    printLinearTable(list);

}