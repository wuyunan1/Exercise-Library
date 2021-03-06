/*************************************************************************
	> File Name: 12.haffman.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月22日 星期二 21时27分29秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key, int freq) { 
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}

Node *build_haffman(Node **arr, int n) {
    Node INIT_NODE = {0, INT32_MAX, NULL, NULL};
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 2; j++) {
            if (arr[j]->freq < arr[n - i - 1]->freq) {
                swap_node(arr + j, arr + n - i - 1);
            }
            if (arr[j]->freq < arr[n - i - 2]->freq) {
                swap_node(arr + j, arr + n - i - 2);
            }
        }
        Node *temp = getNewNode(0, arr[n - i - 1]->freq + arr[n - i - 2]->freq);
        temp->lchild = arr[n - i - 1];
        temp->rchild = arr[n - i - 2];
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0';
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff);
    return ;
}

int main() {
    #define CNT 26
    int str[CNT] = {0};
    char buffer[50][50];
    int n;
    scanf("%d", &n); //表示输入几个句子
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer[i]);}
    for (int i = 0; i < n; i++) {
        for (int j = 0; buffer[j]; j++) {
            str[buffer[i][j] - 'a']++;
        }
    }
    Node **arr = (Node **)malloc(sizeof(Node *) * CNT);
    Node *root;
    for (int i = 0; i < CNT; i++) {
        if (!str[i]) continue;
        arr[i] = getNewNode(i + 'a', str[i]);
    }
    root = build_haffman(arr, CNT);
    char code[256][20] = {0}, buff[20];
    extract_code(root, code, 0, buff);
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }
    return 0;
    #undef CNT 26
}

/*
int main() {
    int n;
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);
        if (freq == 0) continue; //若该字母个数为0，则没有该字母
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_haffman(arr, n);
    char code[256][20] = {0}, buff[20];
    extract_code(root, code, 0, buff);
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }
    return 0;
}*/

