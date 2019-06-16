/*************************************************************************
	> File Name: 38_1.c
	> Author: songrunxian 
	> Mail: 13359850710@163.com 
	> Created Time: Sat 15 Jun 2019 11:59:48 PM PDT
 ************************************************************************/

#include <stdio.h> 
#include <math.h>
int digits(long long num) {
    return floor(log10(num)) + 1;
}

long long calc (int x) {
    long long ans = 0;
    int n = 1;
    while (digits(ans) < 9) {
        ans *= pow(10, digits(n*x));
        ans += n*x;
        n+=1;
    }
    if(digits(ans) != 9) return -1;
    int num[10] = {0};
    long long temp = ans;
    num[0] = 1;
    while ( temp ) {
        if (num[temp % 10]) return -1;
        num[temp % 10] += 1;
        temp /= 10;
    }
    return ans;
}

int main () {
    long long temp, ans = 0;
    for (int i = 1; i < 10000; i ++) {
        temp = calc(i);
        if(temp > ans) ans = temp;

    }
    printf ("%lld\n",ans);

    return 0;
}
