#include <iostream>
#include <stdio.h>

#include "./SqList/LinearTable.h"
#include "./base/vector_demo.h"
#include "./sorting_algorithm/sort.h"
#include "SqList/SingleLinkList.h"

extern "C" {
    #include "./base/C_demo.h";
}

void studyLinearTable(){
    std::cout << "\n-------------【deleteMinValDemo】-----------" << std::endl;
    deleteMinValDemo();
    std::cout << "\n-------------【reverseListDemo】-----------" << std::endl;
    reverseListDemo();
    std::cout << "\n-------------【deleteAllValueXDemo】-----------" << std::endl;
    deleteAllValueXDemo();
    std::cout << "\n-------------【deleteMin_MaxDemo】-----------" << std::endl;
    deleteMin_MaxDemo();
    std::cout << "\n-------------【mergeTwoSortList】-----------" << std::endl;
    mergeTwoSortListDemo();
}

int main() {
//  c语言Demo
//    cDemo();

//    顺序表demo
//    studyLinearTable();
      //链表
    SingleLinkListDemo();

//    vector案例
//     vectorDemo();

//    排序案例
//    sortDemo();
    return 0;

}




