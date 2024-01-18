#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node * next;
};

typedef struct node * LList;
typedef struct node  LLItem;

int length(LList list) {
    if (list == NULL) return 0;

    return 1 + length(list->next);
}

LList getAt(LList list, int index) {
    if (list == NULL || index == 0) return list;

    return getAt(list->next, index - 1);
}

void print(LList list) {
    if (list == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", list->val);
    print(list->next);
}

LList circulate(LList list, int k) {
    if (k <= 0 || k % length(list) == 0) return list;

    LList last = getAt(list, length(list) - 1);
    LList last2 = getAt(list, length(list) - 2);
    
    last->next = list;
    last2->next = NULL;

    return circulate(last, k - 1);
}

int main() {
    LLItem e = {5, NULL};
    LLItem d = {4, &e};
    LLItem c = {3, &d};
    LLItem b = {2, &c};
    LLItem a = {1, &b};

    LList list = &a;

    print(circulate(list, 4));
}