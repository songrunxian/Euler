/*************************************************************************
	> File Name: 44_1.c
	> Author: songrunxian 
	> Mail: 13359850710@163.com 
	> Created Time: Sun 16 Jun 2019 12:30:45 AM PDT
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define INF 0x7ffffffffffffffffLL

long long Pentagonal(long long n) 
    return n*(3*n - 1) / 2;
}

long long  binary_search(long long (*fun)(long long),long long n) {
    long long head = 1,tail = n, mid;
    while(head < tail) {
        mid = (head + tail) >> 1;
        if(func(mid) == x) return mid;
        if(func(mid) < x) head = mid + 1;
        else tail = mid -1;
    }
    return 0;
}

int main () {
    long long D = INF;
    long long pk,pj,n = 2;
    while(Pentagonal(n) - Pentagonal(n-1) < D) {
        pk = Pentagonal(n);
        for(int j = n - 1; j >= 1; j--) {
            pj = Pentagonal(j);
            if(pk -pj >= D) break;
            int ind1 = binary_search(Pentagonal, 2*n, pk + pj);
            int ind2 = binary_search(Pentagonal,n,pk - pj);
            if(ind1 &&ind 2) {
                D = pk -pj;
            }
        }
        n++;
    }
    printf("%lld\n",D)

    return 0;
}
