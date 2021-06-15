#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 110;
const int MAX_SON = 3;

struct Gate {
  int index, strength;
  Gate() : index(0), strength(0) {}
  Gate(int index, int strength) : index(index), strength(strength) {}
};

struct TreeNode {
  int index;
  TreeNode *children[MAX_SON];
  TreeNode() {}
  TreeNode(int index) : index(index) {
    for (int i = 0; i < MAX_SON; i++) {
      children[i] = nullptr;
    }
  }
};

bool isGate(int index) { return 1 <= index && index <= 99; }

bool cmpGate(Gate a, Gate b) {
  if (a.strength != b.strength) {
    return a.strength > b.strength;
  }
  return a.index < b.index;
}

vector<int> BFS(TreeNode *root) {
  vector<int> res;
  queue<TreeNode *> que;
  que.push(root);
  while (!que.empty()) {
    TreeNode *node = que.front();
    que.pop();
    if (isGate(node->index)) {
      res.push_back(node->index);
    }
    for (int j = 0; j < MAX_SON; j++) {
      if (node->children[j] != nullptr) {
        que.push(node->children[j]);
      }
    }
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  map<int, TreeNode *> getFather;
  const int rootIndex = 100;
  TreeNode *root = new TreeNode(rootIndex);
  getFather[rootIndex] = root;
  int father, ch[MAX_SON], gateCnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &father, ch, ch + 1, ch + 2);
    for (int j = 0; j < MAX_SON; j++) {
      TreeNode *f = getFather[father];
      if (ch[j] == -1) {
        f->children[j] = nullptr;
      } else {
        TreeNode *node = new TreeNode(ch[j]);
        f->children[j] = node;
        if (isGate(ch[j])) { // gate
          gateCnt++;
        } else {             // cross point
          getFather[ch[j]] = node;
        }
      }
    }
  }
  vector<Gate> gateList(gateCnt);
  for (int i = 0; i < gateCnt; i++) {
    scanf("%d%d", &gateList[i].index, &gateList[i].strength);
  }
  sort(gateList.begin(), gateList.end(), cmpGate);
  vector<int> cost2gate = BFS(root);
  for (int i = 0; i < gateCnt; i++) {
    printf("%d %d\n", gateList[i].index, cost2gate[i]);
  }
  return 0;
}