//
// Created by admin on 2022/7/24.
// 单链表
//

#include <stdio.h>
#include <stdlib.h>

//结构体定义链表节点
typedef struct LNode{
    int data;           //数据域
    LNode *next;     //指针域
}LNode;

// 尾插法创建链表
void createListR(LNode *&C, int a[], int n) {
    LNode *s,*r;
    C = (LNode*) malloc(sizeof(LNode));
    C->next = NULL;
    r = C;
    for (int i = 0; i < n; ++i) {
        s = (LNode*) malloc(sizeof(LNode));
        s->data = a[i];
        // 尾插法的关键步骤
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

// 头插法创建链表
void createListF(LNode *&C, int a[], int n) {
    LNode *s;
    C = (LNode*) malloc(sizeof(LNode));
    C->next = NULL;
    for (int i = 0; i < n; ++i) {
        s = (LNode*) malloc(sizeof(LNode));
        s->data = a[i];
        // 头插法的关键步骤
        s->next = C->next;
        C->next = s;
    }
}

// 查找节点
LNode* findNode(LNode *C, int x) {
    LNode *p = C->next;
    while (p != NULL) {
        if(p->data == x)
            break;
        p = p->next;
    }
    return p;
}

// 删除节点
int deleteNode(LNode *C, int x) {
    LNode *p,*q;
    p = C;
    // 遍历单链表
    while (p->next != NULL) {
        if(p->next->data == x)
            break;
        p = p->next;
    }
    if (p->next != NULL) {
        // 删除操作
        q = p->next;
        p->next = p->next->next;
        free(q);
        return 1;
    }
    // 查找失败的情况，此时已经遍历完单链表了
    return 0;
}

// 归并两个有序链表
void merge(LNode *A, LNode *B, LNode *&C) {
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;
    // 将A的头节点给C，这里可以任意选用A、B的头节点
    C = A;
    C->next = NULL;
    free(B);    // 释放B的头节点
    r = C;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->next = p;
            r = r->next;
            p = p->next;
        } else {
            r->next = q;
            r= r->next;
            q = q->next;
        }
    }
    r->next = NULL;
    if (p != NULL)
        r->next = p;
    if (q != NULL)
        r->next = q;
}