#include <iostream>

using namespace std;


struct Node{
public: 
 int value;
 Node* next;

};

Node* head;
Node* tail;

void insertElement(int d){

Node* newNode = new Node();
newNode->value = d;

/*check head & tail are already set or not */
if (head == NULL and tail == NULL) {
  newNode->next = NULL;
  head = newNode;
  tail = newNode;
}

if (head == tail ) {
 newNode->next = NULL;
 head->next = newNode;
 tail = newNode;

}

if (head != tail ) {
 newNode->next = NULL;
 tail->next = newNode;   
 tail = newNode;
}

}

void dispalyElement()
{
    Node* position = head;

    while (position != NULL ){
     cout << position->value << " ,";
     position = position->next;  
    }
    cout <<endl;

    
}

void searchElement(int userValue)
{
    Node* position = head;
    
    while (position != NULL ){
    if (position->value  == userValue) {
       cout << userValue << " found";
       break;
     }
    else{    
      position = position->next;
    }

   }
    if (position  == NULL) {
       cout << userValue << " Not found";
    }
    
}

void deleteElement(int delval)
{
    Node* currPos = head;
    Node* prevPos;

    while (currPos != NULL ){
    
    /*delete from head*/
    if (currPos->value  == delval && currPos == head ) {
      head = currPos->next;
      break;
    }

    /*delete from tail*/
    if (currPos->value  == delval && currPos == tail ) {
      tail = prevPos;
      break;
    }
    
    if (currPos != tail && currPos != head ) {
      prevPos->next = currPos->next;
      break;
    }


    prevPos = currPos;
    currPos = currPos->next;

   }
    
}



int main()
{

    insertElement(10);
    insertElement(20);
    insertElement(60);
    insertElement(80);
    insertElement(50);
    insertElement(1222);
    insertElement(50);
    insertElement(2);

    cout << endl;
    cout << "Head " << head->value << endl << endl;
    cout << "Tail " << tail->value << endl << endl;;
    cout << endl;
    
    dispalyElement();
    cout << endl;
    
    searchElement(80);
    cout << endl;
    
    deleteElement(10);
    cout << endl;
    cout << "Head " << head->value << endl << endl;
    cout << "Tail " << tail->value << endl << endl;;
    cout << endl;
    dispalyElement();



}