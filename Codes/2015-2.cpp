
//10:50
#include <cstdio>

struct window {
    int rx, ry, lx, ly;
    int num, next; //表示窗口编号和下一层窗口
}w[10010];

int main() {
    int n, m, click_x, click_y, top = 0; //top表示此时的第一层窗口
    int j = top, jbefore; //j表示此时检查的窗口层，jbefore用于记录其上一层，便于之后修改层序
    scanf("%d", &n);
    for(int i = 0; i < n; i++) { //按序输入，并设置好下一层窗口，初始时下标越小越靠上
        scanf("%d%d%d%d%d", &w[i].num, &w[i].rx, &w[i].ry, &w[i].lx, &w[i].ly);
        if(i != n - 1) {
            w[i].next = i + 1;
        }
        else w[i].next = -1; //最后一个窗口，设置其下一窗口为-1，表示为空
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &click_x, &click_y);
        bool flag = true;
        while(click_x < w[j].lx || click_x > w[j].rx || click_y < w[j].ry || click_y > w[j].ly) { //若不在当前窗口范围内
            if(w[j].next > 0) { //若j的下一个窗口不为空，则向后移动j和jbefore
                jbefore = j;
                j = w[j].next;
            }
            else flag = false; //下一个窗口为空，也就是到了最后一个窗口，那么设置flag表示什么也没点到
        }
        if(j != top && flag) { //此时j不为第一个窗口且确实点到了某窗口
            w[jbefore].next = w[j].next;
            w[j].next = top;
            top = j;
        }
        //除此之外，点到第一个窗口或者所有窗口都没点到，都可以认为什么都没做，不用else
        j = top; //重新将j赋值为top（如果点到桌面j是不等于top的）
    }
    while(j != -1) { //循环打印，直至到最后一个窗口
        printf("%d ", w[j].num);
        j = w[j].next;
    }
    printf("\n");
    return 0;
}
