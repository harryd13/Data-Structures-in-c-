#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

int compare_LL(struct node* root1,struct node* root2);
void push_LL(struct node** root,int val);
void print_LL(struct node* root);

int main(){
	struct node* ll1 = malloc(sizeof(struct node));
	struct node* ll2 = malloc(sizeof(struct node));
	push_LL(&ll1,1);
	push_LL(&ll1,2);
	push_LL(&ll1,3);
	push_LL(&ll1,4);
	push_LL(&ll1,5);
	//push_LL(&ll1,44);
	
	print_LL(ll1);
	
	//push_LL(&ll2,1);
	//push_LL(&ll2,2);
	//push_LL(&ll2,3);
	//push_LL(&ll2,4);
	//push_LL(&ll2,5);
	print_LL(ll2);
	
	int ans= compare_LL(ll1,ll2);
	printf("ANs = %d\n",ans);
	
	if(ans ==0){
		printf("\033[0;32m");
		printf("Both lls are equal\n");
		printf("\033[0m");
	}
	else{
		printf("\033[0;31m");
		printf("Both lls are not equal\n");
		printf("\033[0m");
	}
	
	
	
	
return 0;
}

void push_LL(struct node** root,int val){
	struct node* temp = malloc(sizeof(struct node));
	temp->data = val;
	temp->next = *root;
	*root = temp;
}
void print_LL(struct node* root)
{
    struct node* root_copy = root;
	while(root_copy->next!=NULL)
	{
		printf("|%d|->",root_copy->data);
		root_copy = root_copy->next;
	}
	printf("linked list print completed\n");

}

int compare_LL(struct node* root1,struct node* root2){
	int flag= 0;
	struct node* ll1 = root1;
	struct node* ll2 = root2;
	if(ll1==NULL && ll2==NULL)
		flag =0;
	else{
		
		while(ll1->next!=NULL && ll2->next!=NULL){
			if(ll1->data!=ll2->data){
				printf("datall1 = %d,datall2 = %d\n",ll1->data,ll2->data);
				flag ==1;
				break;
			}
			else{
				
				ll1 = ll1->next;
				ll2 = ll2->next;
			}
		}
		if(ll1->next!=NULL || ll2->next!=NULL){
			flag = 1;
		}

	}
	return flag;

}
