#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* merge_LL(struct node* head1, struct node* head2);
int compare_LL(struct node* root1,struct node* root2);
void push_LL(struct node** root,int val);
void print_LL(struct node* root);

int main(){
	struct node* ll1;// = malloc(sizeof(struct node));
	struct node* ll2;// = malloc(sizeof(struct node));
	push_LL(&ll1,1);
	push_LL(&ll1,2);
	push_LL(&ll1,3);
	push_LL(&ll1,4);
	push_LL(&ll1,5);
	push_LL(&ll1,6);

	print_LL(ll1);

	push_LL(&ll2,1);
	push_LL(&ll2,2);
	push_LL(&ll2,3);
	push_LL(&ll2,4);
	push_LL(&ll2,5);
	print_LL(ll2);

  // struct node * merged;
  // merged = merge_LL(ll1,ll2);
  // print_LL(merged);



return 0;
}

struct node* merge_LL(struct node* head1, struct node* head2){
  struct node* merge;
  //decoy node
  struct node* merge1 = malloc(sizeof(struct node));
  merge = merge1;
  while(head1!=NULL && head2!=NULL){
    if(head1->data <= head2->data){
      merge1->next = head1;
      head1 = head1->next;
      merge1= merge1->next;
    }
    else{
      merge1->next = head2;
      head2 = head2->next;
      merge1= merge1->next;
    }
  }
  if(head1 == NULL){
    merge1->next = head2;
  }
  if(head2 == NULL){
    merge1->next = head1;
  }
  merge = merge->next;
  return merge;
}

void push_LL(struct node** root,int val){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = val;
	temp->next = *root;
	*root = temp;
}
void print_LL(struct node* root){
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
