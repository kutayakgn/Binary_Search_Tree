// ?EREF KUTAY AKGÜN
//150118065
#include <stdio.h>
#include <stdlib.h>
struct n{
int data;
struct n *left;
struct n *right;
};
typedef struct n node;
// Add node in tree Method
node * add (node * tree, int x){
if(tree==NULL){
node *root=(node *)malloc(sizeof(node));
root->left= NULL;
root->right=NULL;
root->data=x;
return root;
}
if(tree->data<x){
tree->right=add(tree->right,x);
return tree;
}
tree->left=add(tree->left,x);
return tree;
}
//Print tree inorder traversal type:
void printInorder(node *node)
{
 if (node == NULL)
 return;

 /* first recur on left child */
 printInorder(node->left);

 /* then print the data of node */
 printf("%d ", node->data);

 /* now recur on right child */
 printInorder(node->right);
}
// Count number of node in tree:
int countnode(node *tree)
{
 int c = 1;
 if (tree ==NULL)
 return 0;
 else
 {
 c += countnode(tree->left);
 c += countnode(tree->right);
 return c;
 }
}
//Count left nodes in tree
int countLeftNodes(node *tree) {
 int c = 0;
 if (tree->left != NULL)
 c += 1 + countLeftNodes(tree->left);
 if (tree->right != NULL)
 c += countLeftNodes(tree->right);
 return c;
}
// Check if the node is Leaf or not
int isLeaf(node *node){
 if (node == NULL)
 return 1;
 if (node->left == NULL && node->right == NULL)
 return 0;
 return 1;
}
//Count left side of Leaves
int countLeftLeaves(node *root){
 int res = 0;

 if (root != NULL)
 {
 if (isLeaf(root->left)==0)
 res +=1;
 else{

 res += countLeftLeaves(root->left);
 res += countLeftLeaves(root->right);
 }}
 return res;
}
//Count Right Side of Leaves
int countRightLeaves(node *root){
 int res = 0;
 if (root != NULL)
 {
 if (isLeaf(root->right)==0)
 res +=1;

 res += countRightLeaves(root->right);
 res += countRightLeaves(root->left);
 }
 return res;
}
// Calculate sequences of tree:
int sequences(int an,int ln,int ll, int rl){
an=an-1;
int i;
int j;
int k;
int b=1;
int c=1;
i= an-ln;
for (j=0;j<ln;j++){
b*=an-j;
}
for (k=0;k<ln ;k++){
c*=ln-k;
}
return ll*rl*(b/c);
}
int main(){
//Creating variables and nodes
node* root=NULL;
int num;
int numofn;
int numofleftleaf;
int numofrightleaf;
int numofleftnode;
int treeseq;
while(1<2){
printf("Enter an integer (0 to exit): ");
scanf(" %d",&num);
if(num==0)
break;
root=add(root,num);
}
// Calling Methods and print Results:
printf("\nTree In order :\n");
printInorder(root);
 numofn = countnode(root);
 printf("\nNumber of node: %d ",numofn);
 numofleftleaf = countLeftLeaves(root);
 printf("\nNumber of left leaf: %d ",numofleftleaf);

numofrightleaf = countRightLeaves(root);
 printf("\nNumber of right leaf: %d ",numofrightleaf);
numofleftnode = countLeftNodes(root);
 printf("\nNumber of left node: %d\n ",numofleftnode);

printf("\nNumber of sequences formul is::: number of left leaf x number of right leaf x Combination(Number of nodes-1 , Number of Left Nodes)\n");
treeseq =
sequences(numofn,numofleftnode,numofleftleaf,numofrightleaf);
printf("\n Number of sequences of tree: %d",treeseq);
return 0;
}
