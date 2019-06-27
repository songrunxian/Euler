/*************************************************************************
	> File Name: 53oj.c
	> Author: songrunxian 
	> Mail: 13359850710@163.com 
	> Created Time: Thu 27 Jun 2019 04:00:14 AM PDT
 ************************************************************************/

#include <stdio.h> 
#define MAX_N 1000000
int prime[MAX_N + 5] = {0};
long long dnum[MAX_N + 5];
long long mnum[MAX_N + 5];

int main() {
    dnum[1] = 1;
    for(int i = 2; i <= MAX_N; i++) {
        if(!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = i;
        }
        for(int j = 1; j <= prime[0]; j++) {
            if(prime[j]*i > MAX_N) {
                break;
            }
            prime[prime[j]*i] = 1;
            if(i %prime[j]) {
                dnum[i*prime[j]] = dnum[i]*dnum[prime[j]];
                mnum[i*prime[j]] = prime[j];
            }else {
                mnum[i*prime[j]] = mnum[i] * prime[j];
                int min_prime = mnum[i*prime[j]];
                int rest = i * prime[j] / min_prime;
                dnum[i*prime[j]] = dnum[min_prime]*dnum[rest];
                if(rest == 1) {
                    dnum[i*prime[j]] = (min_prime *prime[j] - 1) /(prime[j] - 1);
                }
                break;
            }
        }
    }
    long long ans = 0;
    for(int i = 2; i <= MAX_N; i++) {
        if(dnum[i] > ans) {
            ans = dnum[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
