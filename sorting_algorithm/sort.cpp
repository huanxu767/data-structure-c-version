//
// Created by 许欢 on 2020/8/10.
//

#include <iostream>
#include "sort.h"
using namespace std;

/**
 *
 * 自己一开始的想法写的，与正统的有些差异 【建议 看方法2】
 *
 * 稳定排序
 * 【交换排序】冒泡排序 升序 O(n^2)
 * n = 5 则比较4轮,z
 *比较相邻的元素，如果前一个比后一个大，交换之。
 *第一趟排序第1个和第2个一对，比较与交换，随后第2个和第3个一对比较交换，这样直到倒数第2个和最后1个，将最大的数移动到最后一位。
 *第二趟将第二大的数移动至倒数第二位
 *
 * 1 3 7 5 8
 * 1 3 5 7 8
 * @param a
 * @param len
 */
void bubbleSort(int a[],int len){
    cout<< "从小到大开始排序" <<endl;
    // 趟数
    for (int i = 0; i < len-1; i++) {
        //比较次数
        for (int j = i; j < len - 1; j++) {
            cout<< "比较" << a[j] << " : " << a[j+1]<<endl;
            if(a[j] > a[j+1] ){
                //交换
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
        cout<< "比较:第" << i+1 << "轮结束 取得最小值" << a[i] <<endl;
    }
}

/**
 * 冒泡写法2 书上方法 与方法一不同的是 每次取得最大值 放最后,方法一是每次取得最小值放放前面
 *
 * @param a
 * @param len
 */
void bubbleSort2(int a[], int len) {
    cout<< "从小到大开始排序" <<endl;
    //趟数
    for (int i = 0; i < len - 1; ++i) {
        //比较次数
        for (int j = 0; j < len - i - 1; ++j) {
            cout<< "比较" << a[j + 1] << " : " << a[j]<<endl;
            if (a[j + 1] < a[j]) {
                //交换
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        cout<< "比较:第" << i+1 << "轮结束 取得最大值" << a[len-i-1] <<endl;
        for (int i = 0; i < len; i++) {
            cout<< "\t" << a[i];
        }
        cout<< "\n";

    }
}


void printArray(int *pInt, int len);

/**
 * 插入排序
 * @param a
 * @param len
 * 基本思想是在一个有序的序列中找到待排序元素的位置，比如将3插入-1，2，4，6这个有序序列中，先与6和4比较，直到和2比较之后，找到适合插入的位置(2之后)。
    下面以按升序排序为例：

    step1 第一个元素默认有序。
    step2 取待排序的元素B，在有序序列上从后往前寻找。
    step3 如果已排序元素A大于待排序的元素B，则将A往后移动一位。
    step4 重复step3，直到找到元素A<=B(待排序)时或者有序序列全部被扫描。将待排序元素A插入。
    重复step2—step4

 */
void insetSort(int *a,int len){
    // 1 7 5 9 8
    for (int i = 1; i < len; i++) {
        //从第二个元素开始 第一个元素默认有序
        // 逐步与之前的元素比较 找到插入的位置
        for (int j = i; j > 0; j--) {
            if(a[j] < a[j-1]){
                //交换
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }

        }
        cout<< "\n比较:第" << i << "轮结束"<<endl ;
        for (int k = 0; k < len; k++) {
            cout<< "\t" << a[k];
        }
    }
}

/**
 * 打印数组
 * @param a
 * @param len
 */
void printArray(int a[],int len){
    for (int i = 0; i < len; i++) {
        cout<< "\t" << a[i];
    }
}

void bubbleSortDemo(){
    int a[14]{1,3,7,5,8,6,9,12,32,17,34,56,78};
//    int len = 5;
    int len = (int) sizeof(a) / sizeof(*a);
    cout<< "【冒泡排序 Bubble Sort 】" << endl;
    printArray(a,len);
//    bubbleSort(a,len);
    bubbleSort2(a,len);
    cout<< "\n排序后" << endl;
    printArray(a,len);
}

void insetSortDemo(){
    cout<< "【插入排序 Insert Sort 】" << endl;
    int a[7]{1,3,7,5,18,12,2};
    int len = (int) sizeof(a) / sizeof(*a);
    printArray(a,len);
    insetSort(a,len);
}


/**
 * 选择排序
 * https://www.runoob.com/w3cnote/selection-sort.html
 * @param a
 * @param len
 */
void selectSort(int *a,int len){

    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if(a[min] > a[j]){
                min = j;
            }
        }
        if(min != i){
            //交换 i 与 tempMinIndex的值
            int t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
        cout<< "\n比较:第" << i+1 << "轮结束"<<endl ;
        for (int k = 0; k < len; k++) {
            cout<< "\t" << a[k];
        }
    }
}

void selectSortDemo(){
    cout<< "【选择排序 Select Sort 】" << endl;
    int a[7]{1,3,7,5,18,12,2};
    int len = (int) sizeof(a) / sizeof(*a);
    printArray(a,len);
    selectSort(a,len);
}

/**
 * 希尔排序 非稳定
 * https://www.runoob.com/w3cnote/shell-sort.html
 * 希尔排序的基本思想是：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。
 *
 * 一般的初次取序列的一半为增量，以后每次减半，直到增量为1。
 *
 * 初始值  1 2 3 4 5 6 7 8 9 10
 * 10个元素 则 开始增量 10/2 = 5
 * 分组情况[1,6][2,7],[3,8],[4,9],[5,10]
 * @param a
 * @param len
 */
void shellSort(int *a,int len){

    // 步长的变化情况 假如：len = 10 ，每次步长缩减一半 最终步长为1
    for (int l = len/2; l >= 1 ; l = l / 2) {
        // l  5 2 1

        // l为步长
        for (int i = l+1; i < len; i += l) {
            //从dk+1处开始对步长为dk的所有元素进行排序，表示进行直接插入排序的次数
            // 如上图 从6开始
            // 使用插入排序


        }

    }
   


    int h = 1;
    while (h < len / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < len; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                std::swap(a[j], a[j - h]);
            }
        }
        h = h / 3;
        cout<< "\n比较:第" << h << "轮结束"<<endl ;
        for (int k = 0; k < len; k++) {
            cout<< "\t" << a[k];
        }
    }
}
void shellSortDemo(){
    cout<< "【希尔排序 Shell Sort 】" << endl;
    int a[7]{1,3,7,5,18,12,2};
    int len = (int) sizeof(a) / sizeof(*a);
    printArray(a,len);
    shellSort(a,len);

}
/**
 * test
 */
void sortDemo(){
//    bubbleSortDemo();
//    insetSortDemo();
//     selectSortDemo();

    shellSortDemo();

}