//
// Created by admin on 2022/7/24.
// 双链表
//
#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode {
    int data;		//数据域
    struct DLNode *prior;	//指向前驱节点的指针域
    struct DLNode *next;		//指向后继节点的指针域
}DLNode;

// 尾插法创建链表
void createListR(DLNode *&L, int a[], int n) {
    DLNode *s,*r;
    L = (DLNode*) malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r = L;
    for (int i = 0; i < n; ++i) {
        s = (DLNode*) malloc(sizeof(DLNode));
        s->data = a[i];
        // 尾插法的关键步骤
        r->next = s;
        s->prior = r;
        r = r->next;
    }
    r->next = NULL;
}

// 头插法创建链表
void createListF(DLNode *&L, int a[], int n) {
    DLNode *s;
    L = (DLNode*) malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        s = (DLNode*) malloc(sizeof(DLNode));
        s->data = a[i];
        // 头插法的关键步骤
        s->next = L->next;
        if (L->next)
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}

// 查找节点
DLNode* findNode(DLNode *L, int x) {
    DLNode *p = L->next;
    while (p!=NULL) {
        if (p->data == x) {
            break;
        }
        p = p->next;
    }
    return p;
}

// 删除节点
int deleteNode(DLNode *C, int x) {
    DLNode *p,*q;
    p = C;
    // 遍历链表
    while (p->next != NULL) {
        if(p->next->data == x)
            break;
        p = p->next;
    }
    if (p->next != NULL) {
        // 删除操作
        q = p->next;
        p->next = p->next->next;
        q->next->prior = p;
        free(q);
        return 1;
    }
    // 查找失败的情况，此时已经遍历完链表了
    return 0;
}