//
// Created by Nanf_bunan on 2022/7/14.
// 顺序表
//

#include <stdio.h>
#define maxSize 100

// 顺序表结构体定义
typedef struct {
    int data[maxSize];	//存放顺序表元素的数组
    int length;			//顺序表的长度
}Sqlist;

// 初始化顺序表
void initList(Sqlist &L) {
    L.length = 0;
}

// 查找指定位置
int getElem(Sqlist L, int p, int &e) {
    // 下标不合法，查找失败
    if (p < 0 || p > L.length-1)
        return 0;
    // 查找成功
    e = L.data[p];
    return 1;
}

//查找指定元素
int findElem (Sqlist L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (e == L.data[i]) {
            return i;
        }
    }
    return -1;
}

// 插入元素
int insertElem(Sqlist &L, int p, int e) {
    // 判断插入位置的合法性
    if(p < 0 || p > L.length || L.length==maxSize)
        return 0;
    for (int i = L.length-1; i >= p ; --i) {
        L.data[i+1] = L.data[i];
    }
    L.data[p] = e;
    ++L.length;
    return 1;
}

// 删除元素
int deleteElem(Sqlist &L, int p, int &e) {
    // 下标不合法
    if (p < 0 || p > L.length-1)
        return 0;
    e = L.data[p];
    for (int i = p; i < L.length-1; ++i) {
        L.data[i] = L.data[i+1];
    }
    --L.length;
    return 1;
}