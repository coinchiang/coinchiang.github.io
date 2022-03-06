#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXN 10
#define MAXK 1e7

clock_t start, stop;

double duration;

void printN01(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d\n", i);
    }
}

void printN02(int n) {
    if (n) {
        printN02(n - 1);
        printf("%d\n", n);
    }
}
//计算多项式的值
double f01(int n, double a[], double x) {
    double p = 0;
    for (int i = 0; i < n; i++) {
        p += (a[i] * pow(x, i));
    }
    return p;
}
//秦九韶公式a0 + x(a1 + x(...(an-1 + x(an))...))
double f02(int n, double a[], double x) {
    double p = a[n];
    for (int i = n; i > 0; i--) {
        p = a[i - 1] + x * p;
    }
    return p;
}
int main() {
    //printN01(9);
    //printN02(100000);
    double a[MAXN];
    for (int i = 0; i < MAXN; i++) 
        a[i] = i;

    start = clock();
    for (int i = 0; i < MAXK; i++)
        f01(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("ticks1:%f\n", (double)(stop - start) / MAXK);
    printf("duration1:%f\n", duration);

    start = clock();
    for (int i = 0; i < MAXK; i++)
        f02(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("ticks2:%f\n", (double)(stop - start) / MAXK);
    printf("duration2:%f\n", duration);

    return 0;
}