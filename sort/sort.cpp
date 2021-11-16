//
//  sort.cpp
//  sort
//
//  Created by 朱康 on 2021/10/24.
//

#include "sort.hpp"
//快速排序
void Sort::quicksort(int number[],int start,int end,int key){
    int i=start;//保存头部位置防止丢失
    int j=end;//保存尾部位置防止丢失
//    定义返回条件
    if (i>j) {
        return ;
    }
//    快速排序
    while (i<j) {
        for (; number[j]>number[key]&&i<j; --j) {
        }
        for (; number[i]<=number[key]&&i<j; ++i) {
        }
//        交换元素
        if (i<j) {
            std::swap(number[i], number[j]);
        }
        else {
            std::swap(number[key], number[i]);
        }
    }
//    递归处理后续元素
    quicksort(number,start,i-1,start);
    quicksort(number,i+1,end,end);
}
//归并排序
void Sort::mergesort(int number[],int start,int end){
    int mid=(start+end)/2;
    if (start<end) {
        mergesort(number, start, mid);
        mergesort(number, mid+1, end);
        merge(number, start, mid, mid+1, end);
    }
}
//归并
void Sort::merge(int number[],int start,int end,int start_2,int end_2){
    int* stemp=new int[end_2+1];
    int i=start,j=start_2,step=0;
//    归并
    while (i<start_2&&j<end_2+1) {
        if (number[i]<=number[j]) {
            stemp[step++]=number[i++];
        }
        else
            stemp[step++]=number[j++];
    }
//    将剩下的合并
    while (i<=end) {
        stemp[step++]=number[i++];
    }
    while (j<=end_2) {
        stemp[step++]=number[j++];
    }
    for (int key=start,stemp_key=0; key<(start+step); ++key,++stemp_key) {
        number[key]=stemp[stemp_key];
    }
    delete [] stemp;
}
//堆排序
void Sort::heapsort(int number[]){
    for (int i=data_number-1,j=0; i>0; --i,++j) {
        judge(number, 0,j,false);
        std::swap(number[0], number[i]);
        printf("%d  ",number[i]);
    }
    printf("\n");
}
//堆排序判断
void Sort::judge(int number[], int size,int step,bool key){
    if (2*size+1<(data_number-step)) {
        if (step==0||key) {
            judge(number, size*2+1,step,key);
            judge(number, size*2+2,step,key);
            key=false;
        }
        if (2*size+2<(data_number-step)&&number[size]<number[2*size+2]) {
            std::swap(number[size], number[2*size+2]);
            key=true;
        }
        if (number[size]<number[2*size+1]){
            std::swap(number[size], number[2*size+1]);
            key=true;
        }
        if (key) {
            judge(number, size, step,key);
        }
    }
}
//读取文件
void Sort::read_file(FILE *file,int number[]){
    //    判断文件是否存在
        if (file==nullptr) {
            printf("can`t find file\n");
            exit(0);
        }
    //    读取字符串
        fgets(Data, 255, file);
    //    分割字符串
        data=strtok(Data, ",");
    //    数字转化
        while (data) {
            number[data_number]=atoi(data);
            ++data_number;
            data=strtok(nullptr, ",");
        }
    //    关闭文件
        fclose(file);
}
//写入文件
void Sort::write_file(FILE *write,int number[]){
    for (int i=0; i<data_number; ++i) {
        if (i==data_number-1) {
            fprintf(write, "%d",number[i]);
        }
        else
        fprintf(write, "%d,",number[i]);
    }
    fclose(write);
}
