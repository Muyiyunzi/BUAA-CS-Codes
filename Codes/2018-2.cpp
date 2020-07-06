
//20:22开始
//20:54写完，一遍AC
#include <cstdio>
#include <map>
using namespace std;

const int maxn = 10010;
int n, num, time, numtime, dmax = -1, cntmax = -1;
//n为输入行数，num为满足题意结点，time为遍历次数，numtime为满足题意的遍历次数
//dmax记录遍历过程中满足题意的最大深度，cntmax为最大子结点数

struct node {
    int data, depth;
    node *lchild, *mchild, *rchild;
};

map<int, node*> m; //使用map建立结点数字与结点指针的映射

node* newnode(int x) {
    if(x == -1) { //如果输入值为-1，则返回空指针
        return NULL;
    }
    node* root = new node;
    root->data = x;
    root->lchild = NULL;
    root->mchild = NULL;
    root->rchild = NULL;
    return root;
}

void preOrder(node* root, int d) { //前序遍历输入根节点和深度
    if(root == NULL) {
        return;
    }
    root->depth = d;
    time++;
    int cnt = 0;
    if(root->lchild != NULL) cnt++;
    if(root->mchild != NULL) cnt++;
    if(root->rchild != NULL) cnt++;
    if(cnt >= cntmax && d > dmax) {
        dmax = d;
        cntmax = cnt;
        num = root->data;
        numtime = time;
    }
    preOrder(root->lchild, d + 1);
    preOrder(root->mchild, d + 1);
    preOrder(root->rchild, d + 1);
}

int main() {
    scanf("%d", &n);
    int n1, n2, n3, n4;
    node* root;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
        if(i == 0) {
            root = newnode(n1);
            m[n1] = root;
        }
        node* rtemp = m[n1];
        rtemp->lchild = newnode(n2);
        rtemp->mchild = newnode(n3);
        rtemp->rchild = newnode(n4);
        m[n2] = rtemp->lchild;
        m[n3] = rtemp->mchild;
        m[n4] = rtemp->rchild;
    }
    preOrder(root, 1);
    printf("%d %d\n", num, numtime);
    return 0;
}
