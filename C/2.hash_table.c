/*************************************************************************
	> File Name: 2.hash_table.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年11月06日 星期二 20时41分52秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node { 
    char *str;
    struct Node *next;
}Node;

typedef struct HashTable {
    Node **data;
    int size;

}HashTable;

Node *init_node (char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str); //拷贝
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    //为了效率，开大两倍
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

int BKDRHash(char *str) {
    int seed = 31;       //seed为何设为31
    int hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    return hash && 0x7fffffff;
}


int insert(HashTable *h, char *str) {
    
    int hash = BKDRHash(str); //拉链法头插法
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);

    /*开放定值法
    Node *node = init_node(str, NULL);
    int times = 0;
    while (h->data[ind]) {
        //ind++;
        times++;  //坐标重映射
        ind += times * times;  //二次试探法
        ind % h->size;
    }
    h->data[ind] = node;*/
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}



int main() {
    int op;
    char str[100];
    HashTable *h = init_hashtable(100);
    while (scanf("%d%s", &op, str) != EOF) {
        switch(op) {
            case 0: {
                printf("insert %s to hash table\n", str);
                insert(h, str);
            } break;
                       case 1: {
                           printf("search %s result = %d\n", str, search(h, str));
                       } break;
        }
    }

    return 0;
}
