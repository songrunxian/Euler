/*************************************************************************
	> File Name: 32_1.c
	> Author: songrunxian 
	> Mail: 13359850710@163.com 
	> Created Time: Sat 15 Jun 2019 11:11:08 PM PDT
 ************************************************************************/

#include <stdio.h> 
#include <math.h>
#define bool char
#define true 1
#define false 0
#define MAX_N 10000
int can[MAX_N + 5];

bool add_to_num (int x,int *num) {
    while (x) {
        if (num [x %10]) return false;
        num[x % 10] += 1;
        x /= 10;
    }
    return true;
}

int digits(int x) {
    if( x == 0) return 1;
    return floor(log10(x)) + 1;
}

bool is_valid(int a,int b,int c) {
    if(digits(a) + digits(b) + digits(c) - 9) return false;
    int num[10] = {0};
    int flag = 1;
    num[0] = 1;
    flag = flag && add_to_num(a,num);
    flag = flag && add_to_num(b,num);
    flag = flag && add_to_num(c,num);
    return flag;
}

int main () {
    int sum = 0;
    for (int a = 1; a < 100;a++) {
        for (int b = a + 1; b < 10000;b++) {
            if (!is_valid(a,b,a*b))continue;
            if (can[a*b])continue;
            sum += a*b;
            can[a*b] = 1;
            printf("%d * %d = %d\n",a,b,a*b);
        }
    }
    printf("%d\n",sum);
    return 0;
}
