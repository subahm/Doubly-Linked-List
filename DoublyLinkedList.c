// Name: Subah Mehrotra
// Implementation of a doubly linked list in C language

#include <stdio.h>
#include <stdlib.h>

// Node of a doubly linked list
struct Node {
  int data;
  struct Node* next; // Pointer to next node
  struct Node* prev; // Pointer to previous node
};

// Insert a new node at the front of the list using the head and an int
void add(struct Node** head, int enter_data){
  // Allocate memory to new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  // Adding data to new node created
  new_node -> data = enter_data;
  // Making next of new_node as head and previous as null
  new_node -> next = (*head);
  new_node -> prev = NULL;
  // Making new_node the previous of the current head node
  if ((*head) != NULL){
    (*head) -> prev = new_node;
  }
  // Making head point to new_node
  (*head) = new_node;
}

// Insert a new node before a given node
void insertFront(struct Node** head, struct Node* given_node, int enter_data){
  // Check if the given nod eis empty
  if(given_node == NULL){
    printf("The given node is empty");
  }
  // Allocate memory to new Node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  // Enter data in the node
  new_node -> data = enter_data;
  // Make prev of new node as prev of given Node
  new_node -> prev = given_node -> prev;
  // Make prev of given node as new Node
  given_node -> prev = new_node;
  // Make given node as next of new node
  new_node -> next = given_node;
  // Update the next of new node's previous Node
  if (new_node -> prev != NULL){
    new_node -> prev -> next = new_node;
  }
  else
    (*head) = new_node;
}

// Delete a node by using a pointer to node to be deleted
void deleteNode(struct Node** head, struct Node* delete){
  if(*head == NULL || delete == NULL){
    return;
  }
  // If the node being deleted is the head Node
  if (*head == delete){
    (*head) = delete -> next;
  }
  // If node being deleted is not the last node, then update next
  if(delete -> next != NULL){
    delete -> next -> prev = delete -> prev;
  }
  // If node being deleted is not the first node, then update previou
  if(delete -> prev != NULL){
    delete -> prev -> next = delete -> next;
  }
  // Free the memory after deleting the Node
  free(delete);
  return;
}

// Print the contents of the doubly linked list
void printList(struct Node* node){
  struct Node* last;
  printf("\n Forward Traversal: ");
  while(node != NULL) {
    printf(" %d ", node -> data);
    last = node;
    node = node -> next;
  }
  printf("\n Reverse Traversal: ");
  while (last != NULL){
    printf(" %d ", last -> data);
    last = last -> prev;
  }
  printf("\n");
}

int main(){
  struct Node* head = NULL;
  add(&head, 2);
  add(&head, 4);
  add(&head, 8);
  add(&head, 10);

  printf("The list is: ");
  printList(head);

  insertFront(&head, head -> next, 7);

  printf("The list is: ");
  printList(head);

  deleteNode(&head, head);
  deleteNode(&head, head->next);
  deleteNode(&head, head->next);

  printf("The list is: ");
  printList(head);

  deleteNode(&head, head->next);

  printf("The list is: ");
  printList(head);
}
