/*************************************************************************
	> File Name: 1.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月18日 星期五 18时25分28秒
 ************************************************************************/

#include<stdio.h>
 
int main() {
    int a = 1, b = 2, c = 3;
    (a = b) = c; 
    /*
     * (a = b)产生一个a的引用,a' = c, 然后a = a'
     */
    printf("%d\n", c);
    return 0;
}
