// Name: Subah Mehrotra
// Implementation of a doubly linked list in C language

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node of a doubly linked list
struct Node {
  int data;
  struct Node* next; // Pointer to next node
  struct Node* prev; // Pointer to previous node
};

struct Node* head = NULL;

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

// Insert a new node before a given node. Positive value if ref1 is before ref2, negative otherwise.
int distance(struct Node* ref1, struct Node* ref2){
  int dist = 0;
  bool PositiveDist = false;
  while(ref1 != NULL){
    if(ref1 == ref2){
      PositiveDist = true;
      break;
    }
    ref1 = ref1 -> next;
    dist = dist + 1;
  }
  if(PositiveDist == false){
    while(ref2 != NULL){
      if(ref2 == ref1){
        break;
      }
      ref2 = ref2 -> next;
      dist = dist - 1;
    }
  }
  return dist;
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

void swap(struct Node* ref1, struct Node* ref2){
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  if(ref1 == head){
    head = ref2;
  }
  else if(ref2 == head){
    ref1 = head;
  }
  new_node -> next = ref1 -> next;
  new_node -> prev = ref1 -> prev;
  ref1 -> next = ref2->next;
  ref2 -> next = new_node -> next;
  if (ref1 -> next != NULL)
    ref1 -> next -> prev = ref1;
  if (ref2 -> next != NULL)
    ref2 -> next -> prev = ref2;
  ref1 -> prev = ref2 -> prev;
  ref2 -> prev = new_node->prev;
  if (ref1 ->prev != NULL)
    ref1 -> prev -> next = ref1;
  if (ref2 -> prev != NULL)
    ref2 -> prev -> next = ref2;
  free(new_node);
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
  printf("\n");
}

int main(){
  //struct Node* head = NULL;
  add(&head, 2);
  add(&head, 4);
  add(&head, 8);
  add(&head, 10);

  insertFront(&head, head -> next, 7);

  printf("The list is: ");
  printList(head);

  deleteNode(&head, head);
  deleteNode(&head, head->next);
  deleteNode(&head, head->next);

  printf("The list is: ");
  printList(head);

  add(&head, 87);
  add(&head, 4);
  add(&head, 8);
  add(&head, 10);
  printList(head);

  struct Node* last;
  struct Node* node = head;
  while(node != NULL) {
    last = node;
    node = node -> next;
  }
  printf("\nThe distance between %d and %d is: %d \n", last-> data, head->next->next->data, distance(last, head->next->next));
  printf("\nThe distance between %d and %d is: %d \n", head->data, last-> data, distance(head, last));

  printList(head);
  printf("\nSwapping %d with %d: \n", head->data, last->data);
  swap(head, last);
  printList(head);
}
