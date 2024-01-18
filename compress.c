#include <stdio.h>
#include <stdlib.h>

struct node {
    char val;
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
        printf(".\n");
        return;
    }

    printf("%c", list->val);
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

int subseq(LList list, char c) {
    if (list == NULL || list->val != c) return 0;

    return 1 + subseq(list->next, c);
}

LList compress(LList list) {
    int counter = 0;
    while (counter < length(list)) {
        LList letter = getAt(list, counter);
        int reps = subseq(letter, letter->val);
        if (reps > 1) {
            getAt(list, counter + 1)->val = reps + '0';
            getAt(list, counter + 1)->next = getAt(list, counter + reps);
            counter += 2;
        } else {
            counter++;
        }
    }

    return list;
}

int main() {
    LLItem letter0 = {'s', NULL};
    LLItem letter1 = {'a', NULL};
    LLItem letter2 = {'b', NULL};
    LLItem letter3 = {'b', NULL};
    LLItem letter4 = {'b', NULL};
    LLItem letter5 = {'a', NULL};
    LLItem letter6 = {'s', NULL};
    LLItem letter7 = {'s', NULL};
    LLItem letter8 = {'a', NULL};
    LLItem letter9 = {'s', NULL};
    LLItem letter10 = {'e', NULL};
    LLItem letter11 = {'m', NULL};
    LLItem letter12 = {'m', NULL};
    LLItem letter13 = {'m', NULL};
    LLItem letter14 = {'m', NULL};
    LLItem letter15 = {'p', NULL};
    LLItem letter16 = {'r', NULL};
    LLItem letter17 = {'e', NULL};

    letter0.next = &letter1;
    letter1.next = &letter2;
    letter2.next = &letter3;
    letter3.next = &letter4;
    letter4.next = &letter5;
    letter5.next = &letter6;
    letter6.next = &letter7;
    letter7.next = &letter8;
    letter8.next = &letter9;
    letter9.next = &letter10;
    letter10.next = &letter11;
    letter11.next = &letter12;
    letter12.next = &letter13;
    letter13.next = &letter14;
    letter14.next = &letter15;
    letter15.next = &letter16;
    letter16.next = &letter17;

    LList list = &letter0;

    print(compress(list));
}

