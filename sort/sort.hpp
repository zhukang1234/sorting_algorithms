//
//  sort.hpp
//  sort
//
//  Created by 朱康 on 2021/10/24.
//

#ifndef sort_hpp
#define sort_hpp

#include <stdio.h>
#include <string>
#include <stdlib.h>


class Sort{
    char Data[20];//储存文件内容
    char* data;//储存处理后的单个字符串
public:
    int data_number=0;//记录元素个数
    void quicksort(int number[],int start,int end,int key);//快速排序
    void mergesort(int number[],int start,int end);//归并排序
    void merge(int number[],int start,int end,int start_2,int end_2);//归并
    void heapsort(int number[]);//堆排序
    void judge(int number[],int size,int step,bool key);//堆排序判断
    void read_file(FILE *file,int number[]);//读取文件
    void write_file(FILE *write,int number[]);//写入文件
};
#endif /* sort_hpp */
