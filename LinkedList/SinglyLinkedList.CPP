#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
//Structure of Linked List
struct node
{
 int data;
 struct node* next;
};
struct node * head= NULL;
//Method for traversing Linked List
//Complexity O(n)
void traverse()
{
 if (head==NULL)
 cout<<"\n Linked List is Empty";
 else
 {
  struct node *ptr=head;
  while(ptr)
  {
   cout<<"\n ptr->data:"<<ptr->data;
   ptr=ptr->next;
  }
}
}
//Method for inserting element at beg
//Complexity is O(1)
void insertbeg(int data)
{
 struct node * newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data= data;
 if (head==NULL)
 {
   head=newnode;
   newnode->next=NULL;
 }
 else
 {
  newnode->next=head;
  head=newnode;
 }
 traverse();
}
//Method for inserting element at the value after the given value
//Complexity is O(n) where n is position
void insertmid(int data,int value)
{
struct node * newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data= data;
 if (head==NULL)
 { head=newnode;
   newnode->next=NULL;
 }
 else
 {
  struct node *ptr=head;
  while(ptr)
  {
   if(ptr->data==value){
   newnode->next=ptr->next;
   ptr->next=newnode;
   break; }
   ptr=ptr->next;
  }
 }
 traverse();
}
//MEthod for inserting data at the end
//Complexity is  O(n) where n is size
void insertend(int data)
{
 struct node * newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data= data;
 if (head==NULL)
 { head=newnode;
   newnode->next=NULL;
 }
 else
 {
  struct node *ptr=head;
  while(ptr->next)
  ptr=ptr->next;
  ptr->next=newnode;
  newnode->next=NULL;
 }
 traverse();
}
//Method for deleting element at beg
//complexity is O(1)
void deletebeg()
{
 struct node *ptr=head;
 if (head==NULL)
 {
  cout<<"\n Linked List if Empty";
 }
 else if (head->next==NULL)
 {
  free(ptr);
  head=NULL;
 }
 else
 {
  head=head->next;
  free(ptr);
 }
 traverse();
}
//Method for deleting element in b/w value comparision
//Complexity is O(n) where n is position at which value find
void deletemid(int value)
{
  struct node *ptr=head;
 if (head==NULL)
 {
  cout<<"\n Linked List if Empty";
 }
 else if (head->next==NULL)
 {
  free(ptr);
  head=NULL;
 }
 else
 {
  struct node *preptr;
  while(ptr)
  {
   if(ptr->data==value)
   {
    preptr->next=ptr->next;
    struct node* temp=ptr;
    free(temp);
    break;
   }
   preptr=ptr;
   ptr=ptr->next;
  }
 }
 traverse();
}
//Method for deleting Element
//Complexity is O(n) where n is size
void deleteend()
{
 struct node *ptr=head;
 if (head==NULL)
 {
  cout<<"\n Linked List if Empty";
 }
 else if (head->next==NULL)
 {
  free(ptr);
  head=NULL;
 }
 else
 {
  struct node *preptr=ptr;
  ptr=ptr->next;
  while(ptr->next)
  {
   preptr=ptr;
   ptr=ptr->next;
  }
  free(preptr->next);
  preptr->next=NULL;
 }
 traverse();
}
void main()
{
 clrscr();
 char x='y';
 int choice,pos,data,value;
 do{
 cout<<"\n Which operation do you want to perform:";
 cout<<"\n 1. Insertion \n 2. Deletion \n 3. Traverse \n:";
 cin>>choice;
 if(choice!=3){
 cout<<"\n Enter position \n 1.beg \n 2.mid \n 3.end \n:";
 cin>>pos;     }
 switch(choice)
 {
  case 1:cout<<"\n Enter data to be inserted : ";
  cin>>data;
  switch(pos)
  {
   case 1:insertbeg( data);
   break;
   case 2:   cout<<"\n Enter value after which data to be inserted : ";
   cin>>value;
   insertmid(data, value);
   break;
   case 3:insertend( data);
   break;
  }
  break;
  case 2:
    switch(pos)
  {
   case 1:deletebeg();
   break;
   case 2:cout<<"\n Enter value at which data to be deleted : ";
   cin>>value;
   deletemid(value);
   break;
   case 3:deleteend();
   break;
  }
  break;
  case 3:
  traverse();
  break;
 }
 cout<<"\n Do you want to continue:(y/n) ->  ";
 cin>>x;
 }while(x=='y');
}