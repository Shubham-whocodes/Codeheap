#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
  int data;
  struct node *prev;
  struct node *next;
};

struct node *insert_beginning(struct node *head, int data)
{
  struct node *ptr = new (struct node);
  ptr->data = data;
  ptr->prev = NULL;
  ptr->next = head;
  head->prev = ptr;
  return ptr;
}

void insert_at_index(struct node *head, int index, int data)
{
  struct node *ptr = new (struct node);
  struct node *p = head;
  int i = 1;
  while (i < index)
  {
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p;
  p->prev->next = ptr;
  p->prev = ptr;
  ptr->prev = p->prev;
}

void insert_at_last(struct node *head, int data)
{
  struct node *ptr = new (struct node);
  struct node *p = head;
  while (p->next != NULL)
  {
    p = p->next;
  }
  ptr->data = data;
  p->next = ptr;
  ptr->prev = p;
  ptr->next = NULL;
}

void delete_from_beginning(struct node *head)
{
  struct node *p = head;
  head = head->next;
  free(p);
  head->prev = NULL;
}

void delete_from_index(struct node *head, int index)
{
  int i = 1;
  struct node *p = head;
  while (i < index)
  {
    p = p->next;
    i++;
  }
  p->prev->next = p->next;
  p->next->prev = p->prev;
  free(p);
}

void delete_from_end(struct node *head)
{
  struct node *ptr,*p =head;
  while (p->next != NULL)
  {
    p = p->next;
  }
   ptr=p->prev;
   ptr->next = NULL;
   free(p);

}

void print(struct node *head)
{
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
}

int main()
{
  struct node *head;
  head = new (struct node);

  head->data = 25;
  head->next = NULL;
  head->prev = NULL;
  struct node *temp = head;
//  cout << "enter the element in the linked list ";
  for (int i = 1; i < 9; i++)
  {
    // struct node* newnode= ( struct node*)malloc(sizeof(struct node));
    struct node *newnode = new (struct node);
    newnode->data = i;
    newnode->next = NULL;
    newnode->prev = NULL;
    temp->next = newnode;
    newnode->prev = temp;
    temp = newnode;
  }
  // print(head);
  // head= insert_beginning(head,18);
  //insert_at_index(head, 3, 66);
  //insert_at_last(head , 56);
 // delete_from_beginning(head);
  // delete_from_index(head, 5);
  delete_from_end(head);
  print(head);

  return 0;
}