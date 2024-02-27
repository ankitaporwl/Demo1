//char palindrome && vowel-consonant arrange
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
	char data;
	struct Node *next;
};
struct Node *start=NULL;
struct Node *consonantHead=NULL;
struct Node *vowelHead=NULL;
void insertAtB(struct Node *temp,char x){
	struct Node *temp1=malloc(sizeof(struct Node));
	if(temp1==NULL){
		printf("No space\n");
		return;
	}
	temp1->data=x;
	if(temp==start){
		temp1->next=start;
		start=temp1;
	}else if(temp==vowelHead){
		temp1->next=vowelHead;
		vowelHead=temp1;
	}else if(temp==consonantHead){
		temp1->next=consonantHead;
		consonantHead=temp1;
	}
}
void insertAtE(struct Node *temp1,char x){
	struct Node *temp=malloc(sizeof(struct Node));
	if(temp==NULL){
		printf("No space\n");
		return;
	}
	if(temp1==NULL){
		insertAtB(temp1,x);
	}else{
		temp->data=x;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp->next=NULL;
	}
}
void display(struct Node *temp){
	if(temp==NULL){
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL){
		printf("%c\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int countNode(struct Node *temp){
	int c=0;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}
void charPalindrome(){
	struct Node *temp=start;
	struct Node *temp1=start;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	struct Node *temp2;
	int i=0;
	while(i<countNode(start)/2){
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
bool isVowel(char x){
	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')return true;
	return false;
}
void charArrange(){
	struct Node *temp=start;
	while(temp!=NULL){
		char x=temp->data;
		if(isVowel(x)==true)insertAtE(vowelHead,x);
		else insertAtE(consonantHead,x);
		temp=temp->next;
	}
	start=NULL;
	temp=vowelHead;
	while(temp!=NULL){
		insertAtE(start,temp->data);
		temp=temp->next;
	}
	temp=consonantHead;
	while(temp!=NULL){
		insertAtE(start,temp->data);
		temp=temp->next;
	}
}
void main(){
	insertAtB(start,'a');
	insertAtB(start,'b');
	insertAtB(start,'c');
	insertAtB(start,'d');
	insertAtB(start,'e');
	insertAtB(start,'f');
	insertAtB(start,'g');
	insertAtB(start,'h');
	insertAtB(start,'i');
	display(start);
	charPalindrome();
	charArrange();
	display(start);
}