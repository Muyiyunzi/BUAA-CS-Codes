#include <cstdio>

struct ListNode {
  int start, length;
  ListNode *next, *prev;
  ListNode() : start(0), length(0), next(nullptr), prev(nullptr) {}
  ListNode(int start, int length)
      : start(start), length(length), next(nullptr), prev(nullptr) {}
};

ListNode *findBestFit(ListNode *now, int query) {
  ListNode *temp = now;
  int best = 0x7fffffff;
  ListNode *chosen = nullptr;
  do {
    if (now->length >= query && now->length < best) {
      chosen = now;
      best = now->length;
    }
    now = now->next;
  } while (now != temp);
  return chosen;
}

void print_list(ListNode *head, int size) {
  ListNode *temp = head;
  for (int i = 0; i < size; i++) {
    printf("%d %d\n", temp->start, temp->length);
    temp = temp->next;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int start, length;
  ListNode *dummyNode = new ListNode();
  ListNode *last = dummyNode;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &start, &length);
    ListNode *node = new ListNode(start, length);
    node->prev = last;
    last->next = node;
    last = node;
  }
  last->next = dummyNode->next;
  dummyNode->next->prev = last;
  int query;
  ListNode *now = dummyNode->next;
  int list_size = n;
  while (true) {
    scanf("%d", &query);
    if (query == -1) {
      break;
    }
    ListNode *bestFit = findBestFit(now, query);
    if (bestFit != nullptr) {
      bestFit->length -= query;
      if (bestFit->length == 0) {
        ListNode *prevNode = bestFit->prev;
        ListNode *nextNode = bestFit->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete bestFit;
        now = nextNode;
        list_size--;
      } else {
        now = bestFit;
      }
    }
  }
  print_list(now, list_size);
  return 0;
}
