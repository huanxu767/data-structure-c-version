//
// Created by 许欢 on 2020/8/10.
//

#include "vector_demo.h"
#include <vector>
#include <iostream>
#include <algorithm>


void initVector();

void sortVector();

void init2DVector();

using namespace std;


void vectorDemo(){
    initVector();

    sortVector();

    init2DVector();
}

//二维数组两种定义方法
void init2DVector(){
    int N = 5,M = 6;

    vector<vector<int>> obj(N);//5行

    for (int i = 0; i < obj.size(); i++) { //动态2维数组为5行6列，值全为0
        obj[i].resize(M);
    }
    cout<<"\n";
    for (int i = 0; i < obj.size(); i++) {
        for (int j = 0; j < obj[i].size(); j++) {
            cout<<obj[i][j]<<"\t";
        }
        cout<<"\n";
    }

}

void sortVector() {
    vector<int> obj;
    obj.push_back(2);
    obj.push_back(4);
    obj.push_back(3);
    sort(obj.begin(),obj.end());
    cout<<"从小到大:";
    for (int i = 0; i < obj.size(); i++) {
        cout<<obj[i]<<",";
    }
    reverse(obj.begin(),obj.end());
    cout<<"\n从大到小:";
    for (int i = 0; i < obj.size(); i++) {
        cout<<obj[i]<<",";
    }
}

void initVector(){
    vector<int>obj;//创建一个向量存储容器 int
    for(int i=0;i<10;i++) // push_back(elem)在数组最后添加数据
    {
        obj.push_back(i);
        cout<<obj[i]<<",";
    }

    for(int i=0;i<5;i++)//去掉数组最后一个数据
    {
        obj.pop_back();
    }

    cout<<"\n"<<endl;

    for(int i=0;i<obj.size();i++)//size()容器中实际数据个数
    {
        cout<<obj[i]<<",";
    }
    obj.clear();
    cout<<"\nafter clear,size:"<<obj.size()<<endl;;
}