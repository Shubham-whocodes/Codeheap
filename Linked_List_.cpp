#include<iostream>
#include<cstdlib>
using namespace std;

// Creating  Node

struct node{
  int data;
  struct node * next;
};

// Inserting the element in beginning

struct node * insert_at_beginning(struct node *head, int data){
  struct node * ptr=(struct node *)malloc(sizeof(struct node));
   ptr->data = data ;
   ptr->next= head;
   return ptr;
}

// Inserting the element at last

struct node * insert_at_last(struct node * head,int data){
  struct node * ptr=(struct node *)malloc(sizeof(struct node));
  struct node * p=head;
  while (p->next!=NULL){
    p=p->next;
  }
  p->next= ptr;
  ptr->data= data;
  ptr->next =NULL;
  return head;
}
// Inserting the element at the given index

struct node * insert_at_index(struct node * head,int data, int index){
  struct node * ptr=(struct node *)malloc(sizeof(struct node));
  struct node * p=head;
  int i=1;
  while (i<index){
    p=p->next;
    i++;
  }
  ptr->data= data;
  ptr->next=p->next;
  p->next=ptr;
  return head;
}

// Delete an element from the beginning

struct node* delete_beginning ( struct node * head){
  struct node* p = head;
  head=head->next;
  delete(p);
  return head;
}

// Delete an element from the end

struct node * delete_at_last(struct node * head){
  struct node *ptr1,*ptr2,* p=head;
  while (p->next!=NULL){
    ptr1=p;
    p=p->next;
    ptr2=p;
  }
  ptr1->next =NULL;
  free(ptr2);
  return head;
}

//delete from a given index

struct node * delete_at_index(struct node * head,int index){
  struct node* p=head;
  struct node * ptr1=(struct node *)malloc(sizeof(struct node));
  struct node * ptr2=(struct node *)malloc(sizeof(struct node));
  int i=1;
  while (i<index){
    ptr1=p;
    p=p->next;
    ptr2=p;
    i++;
  }
  ptr1->next= p->next;
  free(ptr2);
  return head;
}

// Print the linked list

 void print_list( struct node *head){
  while (head !=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
}
 int main(){
  struct node * head,*p1,*p2,*p3,*p4,*p5;
  p1=(struct node *)malloc(sizeof(struct node));
  p2=(struct node *)malloc(sizeof(struct node));
  p3=(struct node *)malloc(sizeof(struct node));
  p4=(struct node *)malloc(sizeof(struct node));
  p5=(struct node *)malloc(sizeof(struct node));
  p1->data = 10;
  p1->next = p2;
  head = p1;
  p2->data = 20;
  p2->next = p3;
  p3->data = 30;
  p3->next = p4;
  p4->data = 40;
  p4->next = p5;
  p5->data = 50;
  p5->next = NULL;
  // head= insert_at_beginning(head,5);
  // insert_at_last(head,60);
  // insert_at_index(head,25,3);
 // head = delete_beginning(head);
   //delete_at_last(head);
  // delete_at_index(head,3);
  print_list(head);
  return 0;
 }

