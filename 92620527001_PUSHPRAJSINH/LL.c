#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
void display(struct Node *h) {
    while (h) { printf("%d -> ", h->data); h = h->next; }
    printf("NULL\\n");
}
int main() {
    struct Node *head=NULL, *p, *prev;
    int n,i,x,key;
    printf("Number of nodes: "); scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&x); p=malloc(sizeof(struct Node));
        p->data=x; p->next=NULL;
        if(!head) head=p; else { for(prev=head;prev->next;prev=prev->next); prev->next=p; }
    }
    if(head) { p=head; head=head->next; free(p); }
    if(head) {
        if(!head->next) { free(head); head=NULL; }
        else { for(prev=head;prev->next->next;prev=prev->next); p=prev->next; prev->next=NULL; free(p); }
    }
    printf("Value to delete: "); scanf("%d",&key);
    if(head && head->data==key) { p=head; head=head->next; free(p); }
    else {
        prev=head;
        while(prev && prev->next && prev->next->data!=key) prev=prev->next;
        if(prev && prev->next) { p=prev->next; prev->next=p->next; free(p); }
        else printf("Value not found\\n");
    }
    display(head);
    return 0;
}
