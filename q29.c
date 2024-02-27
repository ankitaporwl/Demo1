//doubly linked list
//Question-29,30,31,32,33,36,37
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *start=NULL;
struct Node *end=NULL;
struct Node *createNode(int x){
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
	if(start==NULL){
		end=temp;
	}else{
		start->prev=temp;
	}
	temp->next=start;
	temp->prev=NULL;
	start=temp;
}
void showAll(){
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
void insertAtE(int x){
	if(start==NULL){
		insertAtB(x);
		return;
	}
	struct Node *temp=createNode(x);
	if(temp==NULL){
		printf("No space\n");
		return;
	}
	temp->next=NULL;
	temp->prev=end;
	end->next=temp;
	end=temp;
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
void insertAtSP(int p,int x){
	if(p<=1){
		insertAtB(x);
	}
	if(p>countNode()){
		insertAtE(x);
	}
	struct Node *temp=createNode(x);
	int i;
	struct Node *temp1=start;
	for(i=1;i<p-1;i++){
		temp1=temp1->next;
	}
	temp1->next->prev=temp;
	temp->next=temp1->next;
	temp1->next=temp;
	temp->prev=temp1;
}
void insertAfterSD(int d,int x){
	struct Node *temp=createNode(x);
	if(temp==NULL){
		printf("No space\n");
		return;
	}
	struct Node *temp1=start;
	while(temp1->data!=d && temp!=NULL){
		if(temp->data==d){
			break;
		}
		temp1=temp1->next;
	}
	if(temp1->next!=NULL){
		temp1->next->prev=temp;
	}else{
		end=temp;
	}
	temp->next=temp1->next;
	temp1->next=temp;
	temp->prev=temp1;
}
void search(int d){
	struct Node *temp=start;
	while(temp!=NULL){
		if(temp->data==d)break;
		temp=temp->next;
	}
	if(temp!=NULL){
		printf("Data found\n");
	}
	else{
		printf("Data Not found\n");
	}
}
void deleteAtB(){
	if(start==NULL){
		printf("List is empty\n");
		return;
	}
	struct Node *temp=start;
	start->next->prev=NULL;
	start=start->next;
	temp->next=NULL;
	free(temp);
}
void deleteAtE(){
	if(start==end){
		deleteAtB();
		return;
	}
	struct Node *temp=end;
	temp->prev->next=NULL;
	end=end->prev;
	temp->prev=NULL;
	free(temp);
}
void deleteAtSP(int p){
	if(p<=1){
		deleteAtB();
		return;
	}
	if(p>=countNode()){
		deleteAtE();
		return;
	}
	int i;
	struct Node *temp=start;
	for(i=1;i<p-1;i++){
		temp=temp->next;
	}
	struct Node *temp1=temp->next;
	temp1->next->prev=temp1->prev;
	temp->next=temp1->next;
	temp1->next=temp1->prev=NULL;
	free(temp1);
}
void deleteAtSD(struct Node *temp,int d){
	struct Node *temp1=temp->prev,*temp2=temp->next;
	while(temp->data!=d && temp!=NULL){
		temp1=temp;
		temp=temp->next;
		temp2=temp->next;
	}
	if(temp!=NULL){
		if(temp1!=NULL){
			temp1->next=temp2;
			if(temp2!=NULL){
				temp2->prev=temp1;
			}else{
				end=temp1;
			}
		}else{
			if(temp2!=NULL){
				temp2->prev=NULL;
				start=temp2;
			}else{
				start=end=NULL;
			}
		}
		temp->next=temp->prev=NULL;
		free(temp);
	}
}
void showAll1(){
	struct Node *temp=end;
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
void update(int d,int x){
	struct Node *temp=start;
	int c=0;
	while(temp!=NULL){
		if(temp->data==d){
			c=1;
			temp->data=x;
		}
		temp=temp->next;
	}
	if(c==0)printf("Data Not Found\n");
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
void Show(struct Node *temp){
	if(temp==NULL)return;
	printf("%d\t",temp->data);
	Show(temp->prev);
}
void intPalindrome(){
	struct Node *temp=start;
	struct Node *temp1=end;
	int i=0;
	while(i<countNode()/2){
		i++;
		if(temp->data!=temp1->data){
			printf("Not a palindrome\n");
			return;
		}
		temp=temp->next;
		temp1=temp1->prev;
	}
	printf("it is a Palindrome\n");
}
void bubbleSort(){
	int i,j,k;
	struct Node *temp;
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
	struct Node *temp=start;
	int c=0;
	while(temp!=NULL){
		if(temp->data==x)c++;
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
	struct Node *temp1=end;
	int i=0;
	while(i<countNode()/2){
		temp=temp->next;
		temp1=temp1->prev;
		i++;
	}
	if(countNode()%2==0){
		printf("%d\t",temp1->data);
	}
	printf("%d\n",temp->data);
}
void deleteDuplicateInUnsortedList(){
	struct Node *temp=start;
	while(temp!=NULL){
		int x=temp->data;
		int m=countGivenData(x);
		if(m==1){
			temp=temp->next;
		}
		else{
			while(m!=1){
				m--;
				deleteAtSD(temp->next,x);
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
				m--;
				deleteAtSD(temp->next,x);
			}
			temp=temp->next;
		}
	}
}
void reverse(){
	struct Node *currentNode=start;
	struct Node *previousNode=NULL;
	struct Node *nextNode;
	end=currentNode;
	while(currentNode!=NULL){
		nextNode=currentNode->next;
		currentNode->next=previousNode;
		currentNode->prev=nextNode;
		previousNode=currentNode;
		currentNode=nextNode;
	}
	start=previousNode;
}

void firstAtLast(){
	struct Node *temp=start;
	start=start->next;
	start->prev=NULL;
	temp->next=NULL;
	temp->prev=end;
	end->next=temp;
	end=temp;
}
void moveLastElementToFirst(){
	struct Node *temp=end;
	end=end->prev;
	end->next=NULL;
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
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
	if(starting==NULL || ending==NULL || starting==ending|| ending->next==starting){
		return;
	}
	struct Node *p=sort(starting,ending);
	quickSort(starting,p->prev);
	quickSort(p->next,ending);
}
void insertionSort(){
	struct Node *temp=start->next;
	while(temp!=NULL){
		int x=temp->data;
		struct Node *temp1=temp;
		while(temp1!=start){
			if(temp1->prev->data>x){
				temp1->data=temp1->prev->data;
			}else break;
			temp1=temp1->prev;
		}
		temp1->data=x;
		temp=temp->next;
	}
}
void insertInSortedOrder(int x){
	struct Node *temp1=start;
	while(temp1!=NULL && temp1->data<=x){
		temp1=temp1->next;
	}
	if(temp1==start){
		insertAtB(x);
	}else if(temp1==NULL){
		insertAtE(x);
	}else{
		//insertAfterSD(temp1->prev->data,x);
		struct Node *temp=createNode(x);
		if(temp==NULL){
			printf("No space\n");
			return;
		}
		temp->next=temp1;
		temp1->prev->next=temp;
		temp->prev=temp1->prev;
		temp1->prev=temp;
	}
}
int findModularNode(int k){
	int n=countNode();
	struct Node *temp=start;
	struct Node *temp1=NULL;
	int i=0;
	while(temp!=NULL){
		i++;
		if(i%k==0){
			temp1=temp;
		}
		temp=temp->next;
	}
	if(temp1==NULL)return -1;
	else return temp1->data;
}
void swapNodes(int a,int b){
	if(a==b){
		printf("No swapping\n");
		return;
	}
	struct Node *currentNode1=start;
	struct Node *previousNode1=NULL;
	struct Node *nextNode1=currentNode1->next;
	struct Node *currentNode2=start;
	struct Node *previousNode2=NULL;
	struct Node *nextNode2=currentNode2->next;
	while(currentNode1!=NULL && currentNode1->data!=a){
		previousNode1=currentNode1;
		currentNode1=currentNode1->next;
		nextNode1=currentNode1->next;
	}
	while(currentNode2!=NULL && currentNode2->data!=a){
		previousNode2=currentNode2;
		currentNode2=currentNode2->next;
		nextNode2=currentNode2->next;
	}
	if(currentNode1!=NULL && currentNode2!=NULL){
		/*
		if(previousNode1!=NULL){
			if(previousNode2!=NULL){
				previousNode1->next=currentNode2;
				previousNode2->next=currentNode1;
				if(nextNode2!=NULL){
					
				}
				else{}
			}
			else{
				start=
				if(nextNode2!=NULL){}
				else{}
			}
		}else{
			if(previousNode2!=NULL){
				if(nextNode2!=NULL){}
				else{}
			}
			else{
				if(nextNode2!=NULL){}
				else{}
			}
		}
		if(nextNode1!=NULL){
			if(previousNode2!=NULL){
				if(nextNode2!=NULL){}
				else{}
			}
			else{
				if(nextNode2!=NULL){}
				else{}
			}
		}else{
			if(previousNode2!=NULL){
				if(nextNode2!=NULL){}
				else{}
			}
			else{
				if(nextNode2!=NULL){}
				else{}
			}
		}
		*/
		if(nextNode1!=NULL && previousNode1!=NULL){
			if(previousNode2!=NULL && nextNode2!=NULL){
				previousNode1->next=currentNode2;
				previousNode2->next=currentNode1;
				currentNode1->prev=previousNode2;
				currentNode2->prev=previousNode1;
				nextNode1->prev=currentNode2;
				nextNode2->prev=currentNode1;
				currentNode1->next=nextNode2;
				currentNode2->next=nextNode1;
			}
			else if(previousNode2!=NULL && nextNode2==NULL){}
			else if(previousNode2==NULL && nextNode2!=NULL){}
			else if(previousNode2==NULL && nextNode2==NULL){}
		}
		else if(nextNode1!=NULL && previousNode1==NULL){
			if(previousNode2!=NULL && nextNode2!=NULL){}
			else if(previousNode2!=NULL && nextNode2==NULL){}
			else if(previousNode2==NULL && nextNode2!=NULL){}
			else if(previousNode2==NULL && nextNode2==NULL){}
		}
		else if(nextNode1==NULL && previousNode1==NULL){
			if(previousNode2!=NULL && nextNode2!=NULL){}
			else if(previousNode2!=NULL && nextNode2==NULL){}
			else if(previousNode2==NULL && nextNode2!=NULL){}
			else if(previousNode2==NULL && nextNode2==NULL){}
		}
		else if(nextNode1==NULL && previousNode1!=NULL){
			if(previousNode2!=NULL && nextNode2!=NULL){}
			else if(previousNode2!=NULL && nextNode2==NULL){}
			else if(previousNode2==NULL && nextNode2!=NULL){}
			else if(previousNode2==NULL && nextNode2==NULL){}
		}
	}
}

void main(){
	insertAtB(10);
	insertAtB(20);
	insertAtE(25);
	insertAtE(35);
	insertAtB(30);

	insertAtB(40);
	insertAtSP(3,24);
	insertAtSP(3,26);
	insertAfterSD(24,-27);
	insertAfterSD(35,-37);
	insertAtB(37);
	insertAtB(27);
	insertAtB(37);
	insertAtB(-10);
	insertAtB(20);
	insertAtB(30);
	showAll();
	/*
	search(27);
	search(-27);
	deleteAtB();
	showAll();
	deleteAtE();
	deleteAtE();
	showAll();
	deleteAtSP(3);
	deleteAtSP(1);
	showAll();
	showAll1();
	showAll();
	update(27,47);
	showAll();
	printf("Maximum=%d\n",maximum());
	printf("Minimum=%d\n",minimum());
	insertAtB(1);
	insertAtB(2);
	insertAtB(3);
	insertAtB(4);
	insertAtB(3);
	insertAtB(2);
	insertAtB(1);
	intPalindrome();
	bubbleSort();
	showAll();
	printf("%d\n",countGivenData(37));
	printf("%d\n",countGivenData(-37));
	struct Node *temp=getNode(20);
	printf("%d\n",temp->next->data);
	middle();
	deleteAtSD(start,35);
	deleteAtSD(start,10);
	deleteAtSD(start,27);
	deleteAtSD(start,37);
	deleteAtSD(start,40);
	deleteAtSD(start,27);
	deleteAtSD(start,27);
	deleteAtSD(start,40);
	deleteAtE();
	deleteAtSD(start,35);
	Show(end);
	struct Node *temp=getNode(start,20);
	deleteAtSD(temp->next,37);
	printf("-----\n");
	showAll();
	deleteAtSD(start->next,37);
	printf("+++++++\n");
	showAll();
	deleteAtSD(start->next->next,37);
	printf("qqqqq\n");
	showAll();
	deleteDuplicateInUnsortedList();
	bubbleSort();
	deleteDuplicateInSortedList();
	showAll();
	reverse();
	showAll();
	firstAtLast();
	showAll();
	moveLastElementToFirst();
	showAll();
	quickSort(start,end);
	showAll();
	deleteAtE();
	swapNodes(20,25);
	showAll();
	showAll();
	insertInSortedOrder(15);
	insertInSortedOrder(-40);
	insertInSortedOrder(45);
	insertInSortedOrder(28);
	insertionSort();
	insertInSortedOrder(38);
	showAll();
	printf("%d\n",findModularNode(10));
	*/
}