#include <iostream>

using namespace std;

struct TreeNode {
  int value;
  TreeNode * LeftNode;
  TreeNode * RightNode;

};

TreeNode *root = NULL;  

class BST{
public:
    void insertBST(int data){
        
    TreeNode *newNode = new TreeNode(); 
    newNode->value = data;
    newNode->LeftNode = NULL;
    newNode->RightNode = NULL;
    
    
    if (root == NULL)
	{
        root = newNode;
        cout <<  data <<" Value was inserted to Root "  <<endl;
        return;
     }
	 else
	 { 
      TreeNode *tempNode = root; 

      while( tempNode != NULL ){
         if(data < tempNode->value)
		 {
            if(tempNode->LeftNode == NULL){
               tempNode->LeftNode = newNode;
               cout <<  data <<" Value was inserted to LEFT"  <<endl;
               break;
             }
			 else
			 {    
               tempNode = tempNode->LeftNode;
             }

          }
		  else
		  {
             
             if(tempNode->RightNode == NULL)
			 {	
               tempNode->RightNode = newNode;
               cout <<  data <<" Value was inserted to RIGHT"  <<endl;
               break;

             }
			 else
			 {    
               tempNode = tempNode->RightNode;
             }

            }
          }     
        }   
     }
 void preOrderTraversal(TreeNode* node){
    
     if(node == NULL){
         return;
     }    
     cout <<  node->value << endl;
     preOrderTraversal(node->LeftNode);
     preOrderTraversal(node->RightNode);
  }   
  
void InOrderTraversal(TreeNode* node){
    
     if(node == NULL){
         return;
     }    
     InOrderTraversal(node->LeftNode);
     cout <<  node->value << endl;
     InOrderTraversal(node->RightNode);
  }   
void postOrderTraversal(TreeNode* node){
    
     if(node == NULL){
         return;
     }    
     postOrderTraversal(node->LeftNode);
     postOrderTraversal(node->RightNode);
     cout <<  node->value << endl;
  }   
     
};

int main() {

BST objBst;

objBst.insertBST(50);
objBst.insertBST(40);
objBst.insertBST(30);
objBst.insertBST(60);
objBst.insertBST(70);

cout<<endl;
cout<<"Pre Order Traversal "<<endl;
objBst.preOrderTraversal(root);

cout<<endl;
cout<<"In Order Traversal "<<endl;
objBst.InOrderTraversal(root);

cout<<endl;
cout<<"Post Order Traversal "<<endl;
objBst.postOrderTraversal(root);

return 0;
 

}