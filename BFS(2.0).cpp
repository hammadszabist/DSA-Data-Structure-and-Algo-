#include<iostream>
#define MAX 5
using namespace std;


int adjMatrix[MAX][MAX];
class Queue{

public:
int queue[MAX], n = MAX, front = - 1, rear = - 1;
int queueItemCount = 0;

void enqueue() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cin>>val;
      queue[++rear] = val;
      queueItemCount = queueItemCount + 1;
   }
}
int dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow ";
   } else {
      queueItemCount = queueItemCount - 1;
     return queue[front++];
   }
}

bool isQueueEmpty() {
   if (queueItemCount == 0 ) {
      return true;
   } else {
     return false;
   }
}

void Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
         cout<<endl;
   }
}
};


struct Vertex { 
char label; 
bool visited; 
};

class BreathFirstSearch{

public:
struct Vertex* lstVertices[MAX];
int vertexCount = 0;

BreathFirstSearch() { 
 int i,j;
 for(i = 0; i< MAX; i++) { 
  for(j = 0; j< MAX; j++) { 
     adjMatrix[i][j] = 0; 
    } 
  }
}

void addVertex(char label) { 
 Vertex *vertex  = new Vertex; 
 vertex->label   = label; 
 vertex->visited = false; 
 lstVertices[vertexCount++] = vertex; 
 
}

void addEdge(int edgeStart,int edgeEnd) { 
 adjMatrix[edgeStart][edgeEnd] = 1; 
 adjMatrix[edgeEnd][edgeStart] = 1; 
}    

//display the vertex 
void displayVertex(int vertexIndex) { 
 cout<<lstVertices[vertexIndex]->label<<" "; 
}

int getAdjUnvisitedVertex(int vertexIndex) { 
    int i; 
    for(i = 0; i<vertexCount; i++) { 
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) 
        return i; 
    } 
    return -1; 
} 

void BFS(){ 

int i;

lstVertices[0]->visited = true;
displayVertex(0);
Queue objQueue;

int unvisitedIndex;
objQueue.enqueue(); //insert in queue

while(!objQueue.isQueueEmpty()){ 
  int removeData = objQueue.dequeue();

  while(unvisitedIndex = getAdjUnvisitedVertex(removeData)!= -1){ 
   lstVertices[unvisitedIndex]->visited = true;
   displayVertex(unvisitedIndex);
   objQueue.enqueue(unvisitedIndex); //insert in queue

  }   
}

}
   
};

int main() {

BreathFirstSearch obj;


obj.addVertex('S'); // 0
obj.addVertex('A'); // 1 
obj.addVertex('B'); // 2 
obj.addVertex('C'); // 3 
obj.addVertex('D'); // 4

obj.addEdge(0, 1); //S - A 
obj.addEdge(0, 2); // S - B 
obj.addEdge(0, 3); // S - C 
obj.addEdge(1, 4); // A - D 
obj.addEdge(2, 4); // B - D 
obj.addEdge(3, 4); // C - D

obj.BFS();

return 0;

}