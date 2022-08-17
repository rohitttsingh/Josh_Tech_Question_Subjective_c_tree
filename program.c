#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct TNode{
  char data;
  struct TNode * left;
  struct TNode * right;
  
};
struct TNode * newNode(char data);
struct TNode * arrayToTree(char arr[], int start, int end)
{
  if (start>end)
  return NULL;
  int mid=(start+end)/2; cout<<"mid "<<mid<<endl;
  struct TNode * root=newNode(arr[mid]);
  root->left=arrayToTree(arr,start, mid-1); 
  root->right=arrayToTree(arr,mid+1, end);
  return root;
  
}

struct TNode * newNode(char data)
{
  struct TNode * node= (struct TNode *) malloc(sizeof(struct TNode));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
  return node;
}

void preorder(struct TNode * node)
{
  if (node==NULL) return;
  printf("%c", node->data);
  preorder(node->left);
  preorder(node->right);
  
}

void reverseArray(char * arr, int start, int end)
{
  while(start<end)
  {
    char x=arr[start];
    
    arr[start++]=arr[end];
    arr[end--]=x;
  }
}

void updateArray(char * arr, int n)
{
  int size;
  for(size=0;arr[size]!='\0';++size);
  reverseArray(arr,0,size-1);
  reverseArray(arr,0,n-1);
  reverseArray(arr,0,size-1);
}

int main()
{
  char arr[]="jaaen*zrdpm";

  int n;
  for(n=0;arr[n]!='\0';++n);
  
  struct TNode * root=arrayToTree(arr,0,n-1);
  preorder(root);
  printf("\n");
//   updateArray(arr,4);
//   root=arrayToTree(arr,0,n-1);
//   preorder(root);
//   printf("\n");
//   updateArray(arr,2);
//   root=arrayToTree(arr,0,n-1);
//   preorder(root);
//   printf("\n");
//   updateArray(arr,1);
//   root=arrayToTree(arr,0,n-1);
//   preorder(root);
  printf("\n");

  return 0;
}





