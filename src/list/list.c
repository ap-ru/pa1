#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data){
    struct Node* ptr = head;

    while(ptr->next != NULL && ptr->next->data < data){
        ptr = ptr->next;
    }

    if(ptr->next==NULL || ptr->next->data!=data){
        struct Node* insNode = malloc(sizeof(struct Node));
        insNode->next = NULL;
        insNode->data = data;
        if(ptr->next == NULL){
            ptr->next = insNode;
        }
        else{
            insNode->next = ptr->next;
            ptr->next = insNode;
        }
    }
}

void delete(int data){
    struct Node* ptr = head;
    while(ptr->next != NULL){
        if(ptr->next->data == data){
            struct Node* temp = ptr->next->next;
            free(ptr->next);
            ptr->next = temp;
            return;
        }
        ptr = ptr->next;
    }
}
int main(int argc, char* argv[]){
    
    head = malloc(sizeof(struct Node));
    head->next = NULL;
    char list[10];
    int data;
    while(fscanf(stdin,"%s%d", list, &data) > 0){
        if(list[0] == 'i'){
            insert(data); 
        }
        if(list[0] == 'd'){
            delete(data);
        }
        struct Node* ptr = head->next;
        int count = 0;
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
        }
        printf("%d :", count);
        ptr = head->next;
        while(ptr != NULL){
            printf(" %d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
        }
    while(head!=NULL){
        struct Node* temp = head->next;
        free(head);
        head = temp;
    }
}