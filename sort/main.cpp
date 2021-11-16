//
//  main.cpp
//  sort
//
//  Created by 朱康 on 2021/10/20.
//

#include <iostream>
#include "sort.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Sort sort;
    char write_data[10];
    int way=0;
    FILE *file=fopen("input1-data.txt", "r");
    cout<<"请输入输出文件名称\n";
    gets(write_data);
    FILE *write=fopen(write_data, "w");
    int* number=new int[10];
    sort.read_file(file, number);
    cout<<"请选择排序方式\n1.快速排序\n2.归并排序\n3.堆排序\n";
    cin>>way;
    switch (way) {
        case 1:
//    快速排序
            sort.quicksort(number,0,sort.data_number-1,0);
            break;
        case 2:
//            归并排序
            sort.mergesort(number, 0, sort.data_number-1);
            break;
        case 3:
//            堆排序
            sort.heapsort(number);
            break;
        default:
            break;
    }

//    打印结果
    for (int j=0; j<sort.data_number; ++j) {
        cout<<number[j]<<endl;
    }
    sort.write_file(write, number);
    delete [] number;
    return 0;
}
