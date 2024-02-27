//biotonic doubly linked list
//Ex- 1<->3<->5<->7<->9<->11<->10<->6<->4<->2<->0
//output->  0<->1<->2<->3<->4<->5<->6<->7<->9<->10<->11
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};
struct Node *start=NULL;
struct Node *end=NULL;
struct Node *sortedNodeHead=NULL;
struct Node *sortedNodeEnd=NULL;
void insertAtE(struct Node *temp1,int x){
	struct Node *temp=malloc(sizeof(struct Node));
	if(temp==NULL){
		printf("No space\n");
		return;
	}
	temp->data=x;
	temp->next=NULL;
	if(temp1==start){
		temp->prev=end;
		if(start==NULL){
			start=temp;
		}else{
			end->next=temp;
		}
		end=temp;
	}else if(temp1==sortedNodeHead){
		temp->prev=sortedNodeEnd;
		if(sortedNodeHead==NULL){
			sortedNodeHead=temp;
		}else{
			sortedNodeEnd->next=temp;
		}
		sortedNodeEnd=temp;
	}
}
void showAll(struct Node *temp){
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void showAll1(struct Node *temp){
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
struct Node* reverse(struct Node *currentNode){
	if(currentNode==NULL)return NULL;
	struct Node *previousNode=NULL;
	struct Node *temp=currentNode->prev;
	struct Node *nextNode;
	end=currentNode;
	while(currentNode!=NULL){
		nextNode=currentNode->next;
		currentNode->next=previousNode;
		currentNode->prev=nextNode;
		previousNode=currentNode;
		currentNode=nextNode;
	}
	if(temp!=NULL){
		temp->next=previousNode;
		previousNode->prev=temp;
	}else{
		start=previousNode;
	}
	return previousNode;//returning start point of reversed list
}
void merge(struct Node *temp1,struct Node *temp){
	struct Node *temp2=temp;
	while(temp1!=temp2 && temp!=NULL){
		if(temp1->data<temp->data){
			insertAtE(sortedNodeHead,temp1->data);
			temp1=temp1->next;
		}else{
			insertAtE(sortedNodeHead,temp->data);
			temp=temp->next;
		}
	}
	while(temp1!=temp2){
		insertAtE(sortedNodeHead,temp1->data);
		temp1=temp1->next;
	}
	while(temp!=NULL){
		insertAtE(sortedNodeHead,temp->data);
		temp=temp->next;
	}
}
void sort(){
	struct Node *temp=start;
	while(temp!=NULL){
		if(temp->prev!=NULL && temp->data<temp->prev->data)break;
		temp=temp->next;
	}
	struct Node *temp1=reverse(temp);
	merge(start,temp1);
}
void main(){
	insertAtE(start,1);
	insertAtE(start,3);
	insertAtE(start,5);
	insertAtE(start,7);
	insertAtE(start,9);
	insertAtE(start,11);
	insertAtE(start,10);
	insertAtE(start,6);
	insertAtE(start,4);
	insertAtE(start,2);
	insertAtE(start,0);
	showAll(start);
	/*
	insertAtE(sortedNodeHead,1);
	insertAtE(sortedNodeHead,1);
	insertAtE(sortedNodeHead,1);
	insertAtE(sortedNodeHead,1);
	showAll(sortedNodeHead);
	*/
	sort();
	showAll(sortedNodeHead);
}