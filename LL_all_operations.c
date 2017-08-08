#include <stdio.h>
#include <stdlib.h>

struct node* head = NULL;
void display(struct node*);
void swap(struct node *a, struct node *b);
struct node* create_ll(struct node*);
struct node* insert_beg(struct node*);
struct node* insert_end(struct node*);
struct node* insert_before(struct node*);
struct node* insert_after(struct node*);
struct node* delete_beg(struct node*);
struct node* delete_end(struct node*);
struct node* delete_node(struct node*);
struct node* delete_after(struct node*);
struct node* delete_ll(struct node*);
struct node* sort_ll(struct node*);

struct node {
    int data;
    struct node* next;
};

struct node* create_ll(struct node* head){
    struct node* new_node, *current;
    int data;
    printf("Enter -1 to end\n");
    printf("Enter data: ");
    scanf("%d", &data);
    while (data != -1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        if (head == NULL) {
            new_node->next = NULL;
            head = new_node;
        }else{
            current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = NULL;
        }
        printf("Enter next data: ");
        scanf("%d", &data);
    }
    display(head);
    return head;
}

void display(struct node* head){
    while (head != NULL) {
        if (head->next == NULL) {
            printf("%d->NULL\n", head->data);
        }else{
            printf("%d->", head->data);
        }
        head = head->next;
    }
}

struct node* insert_beg(struct node* head){
    struct node* new_node;
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    display(head);
    return head;
}

struct node* insert_end(struct node* head){
    struct node* new_node, *current;
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    new_node = (struct node*)malloc(sizeof(struct node));
    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    new_node->data = data;
    current->next = new_node;
    new_node->next = NULL;
    display(head);
    return head;
}

struct node* insert_before(struct node* head){
    struct node* new_node, *ptr, *preptr = NULL;
    int data, pos;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter position of the node before which you want to insert(head = 1): ");
    scanf("%d", &pos);
    if (pos == 1) {
        insert_beg(head);
    }
    printf("Enter data: ");
    scanf("%d", &data);
    ptr = head;
    while (pos != 1) {
        preptr = ptr;
        ptr = ptr->next;
        pos--;
    }
    new_node->data = data;
    preptr->next = new_node;
    new_node->next = ptr;
    display(head);
    return head;
}

struct node* insert_after(struct node* head){
    struct node* new_node, *ptr, *preptr = NULL;
    int data, pos;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter position of the node after which you want to insert(head = 1): ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &data);
    ptr = head;
    while (pos != 0) {
        preptr = ptr;
        ptr = ptr->next;
        pos--;
    }
    new_node->data = data;
    preptr->next = new_node;
    new_node->next = ptr;
    display(head);
    return head;
}

struct node* delete_beg(struct node* head){
    struct node* current;
    current = head;
    head = head->next;
    free(current);
    display(head);
    return head;
}

struct node* delete_end(struct node* head){
    struct node* ptr, *preptr = NULL;
    ptr = head;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    display(head);
    return head;
}

struct node* delete_node(struct node* head){
    struct node* ptr, *preptr = NULL;
    int pos;
    printf("Enter position of the node which you want to delete(head = 1): ");
    scanf("%d", &pos);
    if (pos == 1) {
        delete_beg(head);
    }
    ptr = head;
    while (pos != 1) {
        preptr = ptr;
        ptr = ptr->next;
        pos--;
    }
    preptr->next = ptr->next;
    free(ptr);
    display(head);
    return head;
}

struct node* delete_after(struct node* head){
    struct node* ptr, *preptr = NULL;
    int pos;
    printf("Enter position of the node after which you want to delete(head = 1): ");
    scanf("%d", &pos);
    ptr = head;
    while (pos > 0) {
        preptr = ptr;
        ptr = ptr->next;
        pos--;
    }
    preptr->next = ptr->next;
    free(ptr);
    display(head);
    return head;
}

struct node* delete_ll(struct node* head){
    struct node* ptr;
    ptr = head;
    while (ptr != NULL) {
        printf("%d was deleted\n", ptr->data);
        ptr = ptr->next;
        free(ptr);
    }
    head = ptr;
    display(head);
    return head;
}

struct node* sort_ll(struct node* head)
{
    int swapped;
    struct node* ptr1 = head;
    struct node* lptr = NULL;
    
    /* Checking for empty list */
    if (ptr1 == NULL)
        return head;
    
    do
    {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    head = ptr1;
    display(ptr1);
    return head;
}

void swap(struct node *a, struct node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int main(void){
    int options;
    printf("************* Main Menu ***********\n");
    printf("Choose the number of the operation you want to perform: \n");
    printf("1) Create linked list\n");
    printf("2) Display LL\n");
    printf("3) Insert_beg\n");
    printf("4) Insert_end\n");
    printf("5) Insert before a given node\n");
    printf("6) Insert after a given node\n");
    printf("7) Delete_beg\n");
    printf("8) Delete_end\n");
    printf("9) Delete a given node\n");
    printf("10) Delete a node after given node\n");
    printf("11) Delete entire LL\n");
    printf("12) Sort the list\n");
    printf("13) Exit\n");
    printf("Enter your choice: \n");
    scanf("%d", &options);
Again:
    switch (options) {
        case 1:
            head = create_ll(head);
            printf("LL created!!\n");
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insert_beg(head);
            break;
        case 4:
            head = insert_end(head);
            break;
        case 5:
            head = insert_before(head);
            break;
        case 6:
            head = insert_after(head);
            break;
        case 7:
            head = delete_beg(head);
            break;
        case 8:
            head = delete_end(head);
            break;
        case 9:
            head = delete_node(head);
            break;
        case 10:
            head = delete_after(head);
            break;
        case 11:
            head = delete_ll(head);
            break;
        case 12:
            head = sort_ll(head);
            break;
        case 13:
            printf("Bye bye!!\n\n\n");
            break;
        default:
            printf("Enter valid number between 1-12\n");
            break;
    }
    while (options != 13) {
        printf("What do you want to do next?(1-12): ");
        scanf("%d", &options);
        goto Again;
    }
}
