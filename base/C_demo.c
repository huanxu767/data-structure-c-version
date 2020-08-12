//
// Created by 许欢 on 2020/8/11.
//

#include "C_demo.h"
#include <stdio.h>
#include <string.h>

/* 函数声明 */
void printBook( struct Books *book );
//结构体
struct Books
{
    char  title[50];
    char  author[50];
    int   book_id;
} book1,book2;

//void printBook( struct Books *book )
//{
//    printf( "Book title : %s\n", book->title);
//    printf( "Book author : %s\n", book->author);
//    printf( "Book book_id : %d\n", book->book_id);
//};




/**
 * 交换,值传递
 * @param a
 * @param b
 */
void valueExchange(int a,int b){
   int temp = b;
   b = a;
   a = temp;
   printf("值传递：内部交换a=%d,b=%d\n",a,b);
}
/**
 * 交换,引用传递
 * @param a
 * @param b
 */
void valueExchangeIndex(int* a,int* b){
    //此时 输出a是地址 *a是具体的值
    int temp = *b;
    *b = *a;
    *a = temp;
    printf("引用传递：内部交换a=%d,b=%d\n",*a,*b);
}

void valueAndIndexTransDemo(){
    int a = 1;
    int b = 2;
    printf("值传递：外部交换前： a=%d,b=%d\n",a,b);
    valueExchange(a,b);
    printf("值传递：外部交换后： a=%d,b=%d\n",a,b);

    printf("引用传递：外部交换前： a=%d,b=%d\n",a,b);
    valueExchangeIndex(&a,&b);
    printf("引用传递：外部交换后： a=%d,b=%d\n",a,b);
}
/**
 * 数组案例
 */
void arrayDemo(){
    printf("一维数组\n");
    int a[4] = {1,2,3,4};
    for (int i = 0; i < 4; ++i) {
        printf("a[%d]=%d\n",i,a[i]);
    }
    int b[2][3] ={
            {1,2,3},{4,5,6}
    };
    printf("二维数组\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("a[%d][%d]=%d",i,j,b[i][j]);
        }
    }
}

void pointer(){
    int  var = 20;   /* 实际变量的声明 */
    int  *ip;        /* 指针变量的声明 */
    ip = &var;  /* 在指针变量中存储 var 的地址 */

    printf("Address of var variable: %p\n", &var  );

    /* 在指针变量中存储的地址 */
    printf("Address stored in ip variable: %p\n", ip );

    /* 使用指针访问值 */
    printf("Value of *ip variable: %d\n", *ip );
    *ip = 30;
    printf("1111 Value of *ip variable: %d\n", *ip );
    printf("Address of var variable: %d\n", var  );

}

void structDemo(){
    strcpy(book1.title,"悲惨世界");
    strcpy(book1.author,"雨果");
    book1.book_id = 1;

    strcpy(book2.title,"多啦A梦");
    strcpy(book2.author,"大熊");
    book2.book_id = 2;

    struct Books book3;

    strcpy(book3.title,"黄河");
    strcpy(book3.author,"小溪");
    book3.book_id = 3;
//    printBook(&book1);
//    printBook(&book2);
//    printBook(&book3);
    printf("title : %s\tauthor: %s\tbook_id: %d\n", book1.title, book1.author, book1.book_id);
    printf("title : %s\tauthor: %s\tbook_id: %d\n", book2.title, book2.author, book2.book_id);
    printf("title : %s\tauthor: %s\tbook_id: %d\n", book3.title, book3.author, book3.book_id);
}






void strDemo(){
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("Greeting message: %s\n", greeting );
}

void cDemo(){
//    valueAndIndexTransDemo();
//    arrayDemo();
//    structDemo();
    pointer();

}
//void printBook(struct Books *book) {
//    printf("title : %s\tauthor: %s\tbook_id: %d\n", book->title, book->author, book->book_id);
//}

