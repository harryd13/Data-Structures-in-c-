#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  struct node *lcptr;
  int data;
  int hd;
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
void printGivenLevel(NODE* root, int level){
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
void printLevelOrder(NODE* root){
    int h = findHeight(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}
void assginHD(NODE *root,int hd){
  if(root!=NULL){
    printf("%d -- %d\n",root->data,hd);
    assginHD(root->lcptr,hd-1);
    assginHD(root->rcptr,hd+1);
  }
}

void findMinMax(NODE *root,int *min, int *max, int hd){
  if(root == NULL){
    return;
  }
  if(hd < *min)
    *min = hd;

  else if(hd > *max)
    *max = hd;
  findMinMax(root->lcptr,min,max,hd-1);
  findMinMax(root->rcptr,min,max,hd+1);
}
void printVerticalLine(NODE *node, int line_no, int hd)
{
    if (node == NULL) return;
    if (hd == line_no)
        printf("%d ",node->data);
    printVerticalLine(node->lcptr, line_no, hd-1);
    printVerticalLine(node->rcptr, line_no, hd+1);
}
void verticalOrder(NODE *root)
{
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
    }
    printf("\n");
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
  printf("\n----horizontal dist-------\n");
  assginHD(root,0);
  printf("\n------verticalOrder-------\n");
  verticalOrder(root);
  return 0;
}
