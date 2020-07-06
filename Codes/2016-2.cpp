
//15:30-16:08
#include <cstdio>

char str[1000010]; //输入记录在str中

struct ENUM { //enum类似于结构体，将变量名和值捆绑在一起
    char name[1010];
    int num;
}e[1010];

int main() {
    scanf("%s", str);
    int i = 3, j = 0, k = 0;
    while(str[++i] != '{'); //先找到定义所用的‘{’作为起始
    while(str[i++] != '}') { //若此时不为‘}’则一直循环记录定义项
        while(str[i] != '=' && str[i] != ',' && str[i] != '}') { //循环赋值项目名
            e[j].name[k++] = str[i++];
        }
        if(str[i] == '=') { //若因等号退出，则特殊记录该项的值
            int sum = 0;
            while(str[++i] >= '0' && str[i] <= '9') {
                sum = sum * 10 + str[i] - '0';
            }
            e[j].num = sum;
        }
        else { //否则为前一项值+1，第一项默认为0
            if(j == 0) e[j].num = 0;
            else e[j].num = e[j - 1].num + 1;
        }
        j++; //无论何种情况，记录下一变量前统一进行j++
        k = 0; //对计数器k归零
    }
    for(i = 0; i < j; i++) { //打印所有的enum项目和其值
        printf("%s %d\n", e[i].name, e[i].num);
    }
    return 0;
}
