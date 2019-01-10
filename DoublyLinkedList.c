// Name: Subah Mehrotra
// Implementation of a doubly linked list in C language

#include <stdio.h>
#include <stdlib.h>

// Node of a doubly linked list
struct node {
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
  new_node -> prev = NULL:
  // Making new_node the previous of the current head node
  if ((*head) != NULL){
    (*head) -> prev = new_node;
  }
  // Making head point to new_node
  (*head) = new_node;
}
