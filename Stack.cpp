#include <iostream>

using namespace std;

const int stackSize = 5;

class Stack{

private: 
int top;
char arr[stackSize];

public: 

Stack(){
 top = -1;
}

void push(int value){
 
 if (top+1 >= stackSize){
   cout<<"Stack Overflow"<<endl;     
 }else{   
    top = top + 1; 
    arr[top] = value;
 }    


} 

int pop( ){
  
 int stackPopVal;

 if (top <= -1){
   cout<<"Stack underflow"<<endl;     
 }else{ 
  stackPopVal = arr[top];
  top --;
 }
  return stackPopVal;

 
}    

void display() {
   if(top >= 0) {
      cout<<"Stack elements are :"<<" , ";
      for(int i = top; i>= 0; i--)
         cout<<arr[i]<<" ";
      cout<<endl;
   } else
      cout<<"Stack is empty";
}




};


int main()
{

int userVal;
/*push only in stack one*/
Stack objStack1; 
/*pop in stack one*/
Stack objStack2;

for(int i = 0; i<stackSize; i++ ){
 cout<<"Enter value to be pushed :"<<endl;
 cin>>userVal; 
 objStack1.push(userVal);
}

for(int i = 0; i<stackSize; i++ ){
 objStack2.push(objStack1.pop());
}

objStack2.display();


}