#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  struct node *lcptr;
  int data;
  struct node *rcptr;
}NODE;

NODE* newNode(int data){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = data;
    node->lcptr = NULL;
    node->rcptr = NULL;

    return(node);
}

void inorder(NODE *root){
  if(root!=NULL){
    inorder(root->lcptr);
    printf("%d ",root->data);
    inorder(root->rcptr);
  }
}
int max(int a,int b){
  int res = a>b?a:b;
  return res;
}

int findHeight(NODE *root){
  if(root == NULL){
    return -1;
  }else{
    return(1+max(findHeight(root->lcptr),findHeight(root->rcptr)));
  }
}
void printGivenLevel(NODE* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d\n",root->data);
    else if (level > 1)
    {
        printGivenLevel(root->lcptr, level-1);
        printGivenLevel(root->rcptr, level-1);
    }
}

void printLevelOrder(NODE* root)
{
    int h = findHeight(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}


int main(){
  NODE* root = newNode(1);
  root->lcptr = newNode(2);
  root->rcptr = newNode(3);
  root->lcptr->lcptr = newNode(4);
  root->lcptr->rcptr = newNode(5);
  root->lcptr->rcptr->lcptr = newNode(6);
  inorder(root);
  printf("\n and height is = %d\n",findHeight(root));
  printLevelOrder(root);
  return 0;
}
