//Question- 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,19,20,21,22,23,24,25,26,28,36
//singly linked list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *start=NULL;
void display(){
	if(start==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node *temp=start;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int countNode(){
	int c=0;
	struct Node *temp=start;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}
struct Node* createNode(int x){
	struct Node *temp=malloc(sizeof(struct Node));
	if(temp==NULL){
		return NULL;
	}
	temp->data=x;
	return temp;
}
void insertAtB(int x){
	struct Node *temp=createNode(x);
	if(temp==NULL){
		printf("No space\n");
		return;
	}
	temp->next=start;
	start=temp;
}
void insertAtE(int x){
	struct Node *temp=createNode(x);
	if(temp==NULL){
		printf("NO space\n");
		return;
	}
	if(start==NULL){
		insertAtB(x);
		return;
	}
	temp->next=NULL;
	struct Node *temp1=start;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=temp;
}
void insertAtSP(int p,int x){
	if(p<=1){
		insertAtB(x);
		return;
	}
	else if(p>countNode()){
		insertAtE(x);
		return;
	}
	struct Node *temp=createNode(x);
	if(temp==NULL){
		printf("No space\n");
		return;
	}
	int i=0;
	struct Node *temp1=start;
	for(i=1;i<p-1;i++){
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}
void insertAfterSD(int d,int x){
	struct Node *temp=createNode(x);
	if(temp==NULL){
		printf("No space\n");
		return;
	}
	struct Node *temp1=start;
	while(temp1->data!=d){
		temp1=temp1->next;
		if(temp1->next==NULL){
			printf("No such(%d) Data Found in linked list:so can't insert %d in list\n",d,x);
			return;
		}
	}
	
	temp->next=temp1->next;
	temp1->next=temp;
}
void search(int x){
	struct Node *temp=start;
	while(temp!=NULL){
		if(temp->data==x){
			printf("Data found\n");
			return;
		}
		temp=temp->next;
	}
	printf("Data not found\n");
}
void deleteAtB(){
	if(start==NULL){
		printf("list is empty\n");
		return;
	}
	struct Node *temp=start;
	start=start->next;
	temp->next=NULL;
	free(temp);
}
void deleteAtE(){
	if(start==NULL || start->next==NULL){
		deleteAtB();
		return;
	}
	struct Node *temp=start;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	struct Node *temp1=temp->next;
	temp->next=NULL;
	free(temp1);
}
void deleteAtSP(int p){
	if(p<=1){
		deleteAtB();
		return;
	}
	else if(p>=countNode()){
		deleteAtE();
		return;
	}
	struct Node *temp=start;
	int i;
	for(i=1;i<p-1;i++){
		temp=temp->next;
	}
	struct Node *temp1=temp->next;
	temp->next=temp1->next;
	temp1->next=NULL;
	free(temp1);
}
void deleteAtSD(struct Node *temp,struct Node *p,int d){
	while(temp!=NULL && temp->data!=d){
		p=temp;
		temp=temp->next;
	}
	if(temp!=NULL){
		if(p!=NULL){
			p->next=temp->next;
		}else{
			start=start->next;
		}
		temp->next=NULL;
		free(temp);
	}
}
void update(int d,int x){
	struct Node *temp=start;
	while(temp!=NULL){
		if(temp->data==d){
			temp->data=x;
			return;
		}
		temp=temp->next;
	}
}
int maximum(){
	struct Node *temp=start;
	int x=temp->data;
	while(temp!=NULL){
		if(x<temp->data){
			x=temp->data;
		}
		temp=temp->next;
	}
	return x;
}
int minimum(){
	struct Node *temp=start;
	int x=temp->data;
	while(temp!=NULL){ 
		if(x>temp->data){
			x=temp->data;
		}
		temp=temp->next;
	}
	return x;
}
void reverseShow(struct Node *temp){
	if(temp==NULL)return;
	reverseShow(temp->next);
	printf("%d\t",temp->data);
}
void intPalindrome(){
	struct Node *temp=start;
	struct Node *temp1=start;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	struct Node *temp2;
	int i=0;
	while(i<countNode()/2){
		if(temp->data!=temp1->data){
			printf("Not a palindrome\n");
			return;
		}
		temp=temp->next;
		temp2=temp1;
		temp1=start;
		while(temp1->next!=temp2){
			temp1=temp1->next;
		}
		i++;
	}
	printf("Yess, A palindrome\n");
}
void bubbleSort(){
	struct Node *temp;
	int i,j,k;
	for(i=countNode()-2;i>=0;i--){
		temp=start;
		for(j=0;j<=i;j++){
			if(temp->data>temp->next->data){
				k=temp->data;
				temp->data=temp->next->data;
				temp->next->data=k;
			}
			temp=temp->next;
		}
	}
}
int countGivenData(int x){
	int c=0;
	struct Node *temp=start;
	while(temp!=NULL){
		if(temp->data==x){
			c++;
		}
		temp=temp->next;
	}
	return c;
}
struct Node *getNode(struct Node *temp,int d){
	while(temp!=NULL && temp->data!=d){
		temp=temp->next;
	}
	return temp;
}
void middle(){
	struct Node *temp=start;
	int i=1;
	while(i<=countNode()/2)
	{
		if(i==countNode()/2 && countNode()%2==0){
			printf("%d\t",temp->data);
		}
		i++;
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
void reverse(){
	struct Node *current=start;
	struct Node *prev=NULL;
	struct Node *nexxt;
	while(current!=NULL){
		nexxt=current->next;
		current->next=prev;
		prev=current;
		current=nexxt;
	}
	start=prev;
}
void swapNodes(int a,int b){
	if(a==b){
		printf("Swapping not possible\n");
		return;
	}
	struct Node *temp=start;
	struct Node *temp1=start;
	struct Node *temp2;
	struct Node *p=NULL;
	struct Node *p1=NULL;
	while(temp!=NULL && temp->data!=a){
		p=temp;
		temp=temp->next;
	}
	while(temp1!=NULL && temp1->data!=b){
		p1=temp1;
		temp1=temp1->next;
	}
	if(temp!=NULL && temp1!=NULL){
		if(p!=NULL){
			p->next=temp1;
		}else{
			start=temp1;
		}
		if(p1!=NULL){
			p1->next=temp;
		}else{
			start=temp;
		}
		temp2=temp->next;
		temp->next=temp1->next;
		temp1->next=temp2;
	}
}
void firstAtLast(){
	struct Node *temp=start;
	start=start->next;
	struct Node *temp1=start;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=temp;
	temp->next=NULL;
}
void moveLastElementToFirst(){
	struct Node *temp=start;
	struct Node *temp1=NULL;
	
	while(temp->next!=NULL){
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	temp->next=start;
	start=temp;
}
void deleteDuplicateInUnsortedList(){
	struct Node *temp=start;
	while(temp!=NULL){
		int x=temp->data;
		int m=countGivenData(x);
		if(m==1){
			temp=temp->next;
		}else{
			while(m!=1){
				deleteAtSD(temp->next,temp,x);
				m--;
			}
			temp=temp->next;
		}
	}
}
void deleteDuplicateInSortedList(){
	struct Node *temp=start;
	while(temp!=NULL){
		int x=temp->data;
		int m=countGivenData(x);
		if(m==1){
			temp=temp->next;
		}else{
			while(m!=1){
				deleteAtSD(temp->next,temp,x);
				m--;
			}
			temp=temp->next;
		}
	}
}
int countBetweenNodes(struct Node *temp,struct Node *temp1){
	int c=0;
	while(temp!=temp1->next){
		c++;
		temp=temp->next;
	}
	return c;
}
struct Node* sort(struct Node *starting,struct Node *ending){
	struct Node *temp=starting;
	int k;
	while(starting!=ending){
		if(starting->data<ending->data){
			k=temp->data;
			temp->data=starting->data;
			starting->data=k;
			temp=temp->next;
		}
		starting=starting->next;
	}
	k=temp->data;
	temp->data=ending->data;
	ending->data=k;	
	return temp;
}
void quickSort(struct Node *starting,struct Node *ending){
	if(starting==ending || starting==NULL || ending==NULL || ending->next==starting){
		return;
	}
	struct Node *p=sort(starting,ending);
	struct Node *temp=starting;
	while(temp!=NULL && temp->next!=p){
		temp=temp->next;
	}
	quickSort(starting,temp);
	quickSort(p->next,ending);
}
void insertInSortedOrder(int x){
	struct Node *temp=start;
	while(temp!=NULL && temp->data<=x){
		temp=temp->next;
	}
	if(temp==start){
		insertAtB(x);
	}else if(temp==NULL){
		insertAtE(x);
	}else{
		struct Node *temp1=start;
		while(temp1->next!=temp){
			temp1=temp1->next;
		}
		struct Node *temp2=createNode(x);
		if(temp2==NULL){
			printf("No space\n");
			return;
		}
		temp2->next=temp1->next;
		temp1->next=temp2;
	}
}
int findModularNode(int k){
	struct Node *temp=start;
	int i=0;
	struct Node *temp1=NULL;
	while(temp!=NULL){
		i++;
		if(i%k==0){
			temp1=temp;
		}
		temp=temp->next;
	}
	if(temp1==NULL)return -1;
	return temp1->data;
}
struct Node* merge(struct Node *temp1,struct Node *temp2){
	if(temp1==NULL)return temp2;
	else if(temp2==NULL)return temp1;
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
void middleNode(struct Node *temp,struct Node **temp1,struct Node **temp2){
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
void mergeSort(struct Node **tempRef){
	struct Node *temp=*tempRef;
	if(temp==NULL ||temp->next==NULL)return;
	struct Node *temp1;
	struct Node *temp2;
	middleNode(temp,&temp1,&temp2);
	mergeSort(&temp1);
	mergeSort(&temp2);
	*tempRef=merge(temp1,temp2);
}
void main(){
	insertAtB(10);
	insertAtB(20);
	insertAtB(30);
	insertAtB(40);
	insertAtB(0);
	insertAtE(-10);
	insertAtSP(3,25);
	insertAtB(25);
	insertAtB(20);
	insertAtB(10);
	insertAtSP(2,35);
	insertAfterSD(25,45);
	insertAtB(40);
	insertAtB(40);
	insertAtB(40);
	insertAtB(40);
	display();
	/*
	insertAfterSD(-20,-30);
	display();
	search(-10);
	search(-30);
	deleteAtB();
	display();
	deleteAtE();
	display();
	deleteAtSP(3);
	display();
	display();
	update(45,-45);
	display();
	printf("Maximum=%d\t\n",maximum());
	printf("Minimum=%d\n",minimum());
	reverseShow(start);
	intPalindrome();
	display();
	printf("%d\n",countGivenData(-20));
	printf("%d\n",countGivenData(40));
	struct Node *temp=getNode(3);
	printf("%d\n",temp->data);
	middle();
	display();
	display();
	deleteDuplicateInUnsortedList();
	display();
	reverse();
	display();
	firstAtLast();
	display();
	moveLastElementToFirst();
	display();
	bubbleSort();
	swapNodes(0,-10);
	deleteAtSD(start,NULL,20);
	deleteAtSD(temp->next,temp,40);
	display();							
	display();
	deleteDuplicateInUnsortedList();
	display();
	bubbleSort();
	deleteDuplicateInSortedList();
	display();
	struct Node *temp1=getNode(start,35);
	printf("%d\n",countBetweenNodes(start,temp1));
	struct Node *temp2=start;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	quickSort(start,temp2);
	display();
	insertInSortedOrder(-40);
	insertInSortedOrder(50);
	insertInSortedOrder(23);
	display();
	printf("%d\n",findModularNode(3));	
	mergeSort(&start);
	display();
	*/
}
