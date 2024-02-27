//concate(union) two lists and intersection of two singly linked lists
//Question 18 and 27
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *start1=NULL;
struct Node *start2=NULL;
struct Node *start3=NULL;
struct Node *start4=NULL;
void insertAtB(struct Node *temp,int x){
	struct Node *temp1=malloc(sizeof(struct Node));
	if(temp1==NULL){
		printf("No space\n");
		return;
	}
	temp1->data=x;
	if(temp==start1){
		temp1->next=start1;
		start1=temp1;
	}
	else if(temp==start2){
		temp1->next=start2;
		start2=temp1;
	}else if(temp==start3){
		temp1->next=start3;
		start3=temp1;
	}else if(temp==start4){
		temp1->next=start4;
		start4=temp1;
	}
}
void display(struct Node *temp){
	if(temp==NULL){
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void concate(struct Node *temp1,struct Node *temp2){
	while(temp1!=NULL){
		insertAtB(start3,temp1->data);
		temp1=temp1->next;
	}
	while(temp2!=NULL){
		insertAtB(start3,temp2->data);
		temp2=temp2->next;
	}
	display(start3);
}
void intersection(struct Node *temp1,struct Node *temp2){
	while(temp1!=NULL){
		temp2=start2;
		while(temp2!=NULL){
			if(temp1->data==temp2->data){
				int x=temp2->data;
				insertAtB(start4,x);
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	display(start4);
}
void main(){
	insertAtB(start1,10);
	insertAtB(start1,30);
	insertAtB(start1,50);
	insertAtB(start1,70);
	display(start1);
	insertAtB(start2,10);
	insertAtB(start2,50);
	insertAtB(start2,60);
	insertAtB(start2,80);
	display(start2);
	concate(start1,start2);
	intersection(start1,start2);
}
