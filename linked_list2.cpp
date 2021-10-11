#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
  int data;
  struct node * next;
};
struct node * insert_at_begining(struct node *head, int data){
  struct node * ptr=(struct node *)malloc(sizeof(struct node));
   ptr->data = data ;
   ptr->next= head;
   return ptr;
}

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
  head= insert_at_begining(head,5);
  insert_at_last(head,60);
  insert_at_index(head,25,3);
  print_list(head);
  return 0;

 }

