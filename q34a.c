//biotonic singly linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *start=NULL;
struct Node *end=NULL;
struct Node *sortedHead=NULL;
struct Node *sortedEnd=NULL;
void insertAtE(struct Node *temp,int x){
	struct Node *newNode=malloc(sizeof(struct Node));
	if(newNode==NULL){
		printf("No space\n");
		return;
	}
	newNode->data=x;
	newNode->next=NULL;
	if(temp==start){
		if(start==NULL)start=newNode;
		else end->next=newNode;
		end=newNode;
	}else if(temp==sortedHead){
		if(sortedHead==NULL)sortedHead=newNode;
		else sortedEnd->next=newNode;
		sortedEnd=newNode;
	}
}
void merge(struct Node *temp,struct Node *temp1){
	struct Node *temp2=temp1;
	while(temp!=temp2 && temp1!=NULL){
		if(temp1->data<temp->data){
			insertAtE(sortedHead,temp1->data);
			temp1=temp1->next;
		}else{
			insertAtE(sortedHead,temp->data);
			temp=temp->next;
		}
	}
	while(temp!=temp2){
		insertAtE(sortedHead,temp->data);
		temp=temp->next;
	}
	while(temp1!=NULL){
		insertAtE(sortedHead,temp1->data);
		temp1=temp1->next;
	}
}
struct Node* reverse(struct Node *currentNode){
	if(currentNode==NULL)return NULL;
	struct Node *previousNode=NULL;
	struct Node *temp1=NULL,*temp=start;
	while(temp!=currentNode){
		temp1=temp;
		temp=temp->next;
	}
	struct Node *nextNode;
	while(currentNode!=NULL){
		nextNode=currentNode->next;
		currentNode->next=previousNode;
		previousNode=currentNode;
		currentNode=nextNode;
	}
	if(temp1!=NULL){
		temp1->next=previousNode;
	}else{
		start=previousNode;
	}
	return previousNode;
}
struct Node showAll(struct Node *temp){
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void sort(){
	struct Node *temp=start;
	while(temp!=NULL){
		if(temp->next!=NULL && temp->data>temp->next->data)break;
		temp=temp->next;
	}
	struct Node *temp1=reverse(temp->next);
	merge(start,temp1);
	showAll(sortedHead);
}
void main(){
	insertAtE(start,1);
	insertAtE(start,3);
	insertAtE(start,5);
	insertAtE(start,7);
	insertAtE(start,4);
	insertAtE(start,2);
	insertAtE(start,0);
	showAll(start);
	sort();
}