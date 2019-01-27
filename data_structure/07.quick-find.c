/*************************************************************************
	> File Name: quick_find.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月20日 星期日 16时48分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct UnionSet {
    int *color; //第i个节点的颜色 
    int size;
}UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)calloc(sizeof(UnionSet), 1);
    u->color = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        u->color[i] = i;
    }
    u->size = n;
    return u;
}

int find(UnionSet *u, int x) { //返回x节点的颜色
    return u->color[x];
}

int merge(UnionSet *u, int a, int b){ //合并两个点
    int color_a = find(u, a), color_b = find(u, b);
    if (color_a == color_b) return 0;
    for (int i = 0; i < u->size; i++) {
        if (u->color[i] == color_a) u->color[i] = color_b;
    }
    return 1;
}


void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->color);
    free(u);
    return ;
}

void output(UnionSet *u) {
    for (int i = 0; i < u->size; i++) {
        printf("(%d, %d)\t", i, u->color[i]);
        if (i + 1 < u->size && i + 1 % 5 == 0) printf("\n");
    }
}

int main() {
    #define MAX_N 
    int matrix[]
    
    return 0;
}








/*
int main() {
    srand(time(0));
    int op, a, b;
    #define MAX_OP 10
    #define MAX_N 10
    UnionSet *u = init(MAX_N);
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;
        a = rand() % MAX_N;
        b = rand() % MAX_N;
        switch (op) {
            case 0: {
                printf("find %d <-> %d = %d\n", a, b, find(u, a) == find(u, b));
                break;
            }
            default: {
                printf("union %d <-> %d = %d\n", a, b, merge(u, a, b));
            }
        }
    }
    
    return 0;
    #undef MAX_OP 
    #undef MAX_N
}*/
