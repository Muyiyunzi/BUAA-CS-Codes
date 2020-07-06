#include <cstdio>

const int maxn = 100010;

bool hashTable[maxn] = {false};
int prime[maxn], pNum = 0;

//使用埃式筛法打印质数表
void FindPrime() {
    hashTable[1] = true; //特判认为1不是质数
    for(int i = 2; i < maxn; i++) {
        if(hashTable[i] == false) {
            prime[pNum++] = i;
            for(int j = 2 * i; j < maxn; j += i) {
                hashTable[j] = true;
            }
        }
    }
}

int main() {
    FindPrime(); //初始化素数表
    int a, b;
    scanf("%d %d", &a, &b);
    //找到从a开始的第一个质数
    int first;
    for(int i = 0; ; i++) {
        if(prime[i] >= a) {
            first = i;
            break;
        }
    }
    //从first开始讨论，其开始的相邻三个是否为等差数列，当prime[i + 2] > b时或i+2大于了最大质数个数时退出循环
    for(int i = first; i + 2 <= pNum && prime[i + 2] <= b; i++) {
        if(prime[i] + prime[i + 2] == 2 * prime[i + 1]) {
            printf("%d %d %d ", prime[i], prime[i + 1], prime[i + 2]);
            //接下来判断是否多于三个，若多于三个，提前对i做++，以循环判断并避免重复输出
            while(prime[i + 1] + prime[i + 3] == 2 * prime[i + 2] && i + 3 <= pNum && prime[i + 3] <= b) {
                printf("%d ", prime[i + 3]);
                i++;
            }
            printf("\n");
        }
    }
    return 0;
}
