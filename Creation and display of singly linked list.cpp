/*
Linked list is a  data structure often used to store
similar data in memory. 
Unlike the elements of an array, linked list
are not constrained to be stored in adjacent location. 
Individual nodes of a L.L are dispersed in memory but bonded together.  
Thus, a linked list is a collection of elements called
nodes, each of which stores two item of information—an
element of the list, and a link.
*/

//Creation and display of singly linked list 

#include <iostream>  
using namespace std;

struct node {
   int data;            //data part of node 
   struct node *next;   //link part to next node 
};  

struct node* head = NULL;   //initialize head to NULL

//function to insert a new node at the beginning
void insert(int data) {
   struct node* new_node = (struct node*) malloc(sizeof(struct node));  //allocates memory
   new_node->data = data;   //stores data
   new_node->next = head;   //makes link between new_node and head
   head = new_node; //new_node is made head 
}

//function to display
void display() {
   struct node* ptr;
   ptr = head;
   
   //enter loop only when LL is not empty
   while (ptr != NULL) {
      cout<< ptr->data <<" ";   //prints data part of node
      ptr = ptr->next;          //gets next address of node
   }
}
int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The linked list is: ";
   display();   //calls display()
   return 0;
}
