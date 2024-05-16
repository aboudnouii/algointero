#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    int val;
    struct LinkedList *next;
} node;

void display(node* p) {
    if (p == NULL)
        printf("\nThe list is empty.\n");
    else {
        printf("\nThe elements of the list:\n");
        while (p != NULL) {
            printf("%d\n", p->val);
            p = p->next;
        }
    }
}

node* ins_e(int a, node* head) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->val = a;
    new_node->next = NULL;
    if (head == NULL)
        head = new_node;
    else {
        node* p = head;
        while (p->next)
            p = p->next;
        p->next = new_node;
    }
    return head;
}

void del_b(node** head) {
    if (*head == NULL)
        return;
    node* p = *head;
    *head = (*head)->next;
    free(p);
}

node* fill(int n, node* head) {
    for (int i = 1; i <= n; i++) {
        head = ins_e(i, head);
    }
    display(head);
    return head;
}

void deleteMultiples(node** head) {
    node* p = *head;
    node* q;
    while (p != NULL) {
        node* q = p->next;
        while (q != NULL) {
            if ( (q->val) % (p->val) != 0) {
                q = q->next;
            } else {
                del_b(&q);
            }
        }
        p = p->next;
    }
}

int main() {
    node* head = NULL;
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    head = fill(n, head);
    deleteMultiples(&head);
    display(head);
    return 0;
}
