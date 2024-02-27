//intersection and concate in doubly linked list
//mergeSort in linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *start1=NULL;
struct Node *end1=NULL;
struct Node *start2=NULL;
struct Node *end2=NULL;
struct Node *start3=NULL;
struct Node *end3=NULL;
struct Node *start4=NULL;
struct Node *end4=NULL;
struct Node* createNode(int x){
	struct Node *temp=malloc(sizeof(struct Node));
	if(temp==NULL){
		return NULL;
	}
	temp->data=x;
	return temp;
}
void insertAtB(struct Node *temp,int x){
	struct Node *temp1=createNode(x);
	if(temp1==NULL){
		printf("No space\n");
		return;
	}
	if(temp==start1){
		if(start1==NULL)end1=temp1;
		else start1->prev=temp1;
		temp1->next=start1;
		temp1->prev=NULL;
		start1=temp1;
	}else if(temp==start2){
		if(start2==NULL)end2=temp1;
		else start2->prev=temp1;
		temp1->next=start2;
		temp1->prev=NULL;
		start2=temp1;
	}else if(temp==start3){
		if(start3==NULL)end3=temp1;
		else start3->prev=temp1;
		temp1->next=start3;
		temp1->prev=NULL;
		start3=temp1;
	}else if(temp==start4){
		if(start4==NULL)end4=temp1;
		else start4->prev=temp1;
		temp1->next=start4;
		temp1->prev=NULL;
		start4=temp1;
	}
}
void showAll(struct Node *temp){
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void concate(struct Node *temp,struct Node *temp1){
	while(temp!=NULL){
		insertAtB(start3,temp->data);
		temp=temp->next;
	}
	while(temp1!=NULL){
		insertAtB(start3,temp1->data);
		temp1=temp1->next;
	}
	showAll(start3);
}
void intersection(struct Node *temp,struct Node *temp1){
	struct Node *temp2;
	while(temp!=NULL){
		temp2=temp1;
		while(temp2!=NULL){
			if(temp->data==temp2->data){
				insertAtB(start4,temp->data);
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}
	showAll(start4);
}
void middle(struct Node *temp,struct Node **temp1,struct Node **temp2){
	struct Node *slow=temp;
	struct Node *fast=temp->next;
	while(fast!=NULL){
		fast=fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	*temp1=temp;
	*temp2=slow->next;
	slow->next=NULL;
}
struct Node* merge(struct Node *temp1,struct Node *temp2){
	if(temp1==NULL){
		return temp2;
	}
	else if(temp2==NULL){
		return temp1;
	}
	struct Node *result=NULL;
	if(temp1->data<temp2->data){
		result=temp1;
		result->next=merge(temp1->next,temp2);
	}else{
		result=temp2;
		result->next=merge(temp1,temp2->next);
	}
	return result;
}
void mergeSort(struct Node **tempRef){
	struct Node *temp=*tempRef;
	if(temp==NULL || temp->next==NULL)return;
	struct Node *temp1;
	struct Node *temp2;
	middle(temp,&temp1,&temp2);
	mergeSort(&temp1);
	mergeSort(&temp2);
	*tempRef=merge(temp1,temp2);
}
void main(){
	insertAtB(start1,10);
	insertAtB(start1,30);
	insertAtB(start2,100);
	insertAtB(start1,40);
	insertAtB(start2,70);
	insertAtB(start1,50);
	//showAll(start1);
	insertAtB(start2,10);
	insertAtB(start2,60);
	insertAtB(start2,30);
	insertAtB(start1,20);
	//showAll(start2);
	concate(start1,start2);
	//intersection(start1,start2);
	mergeSort(&start3);
	showAll(start3);
}