#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node* next;
};



class Stack{

    Node * top;
    int size;


    public:
    
    Stack():top(NULL),size(0){}

    void push(int value){
        Node * newNode = new Node;
        newNode->Data = value;
        newNode->next = top;
        top = newNode;
        size++;

    }

    void pop(){
        if(size == 0)
        { 
            cout<<"Nothing to pop.";
            return;
        }
        
        Node * currentTop = top;
        top = top->next;
        delete currentTop;
        size--;

    }

    void display(){
        Node * current = top;
        while(current != NULL){
            cout << current->Data <<endl;
            current = current->next;
        }
    }

  
};


class Queue{

    
    
    public:
    Node * front;
    Node * rear;
    int size;
    Queue():front(NULL),rear(NULL),size(0){}

    void enqueue(int value){
        Node * newNode = new Node;
        newNode->Data = value;
        if(rear==NULL && front ==NULL){
            rear=front=newNode;
        }
        else{
            rear->next = newNode;
            rear= newNode;
        }
        
        size++;      

    }

    void dequeue(){

        if(size == 0){
            cout << "Empty queue." <<endl;
            return;
        }
        
        Node * current = front;
        //int data=current->Data;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        size--;
        delete current;

    }
        void display(){
        Node * current = front;
        while(current != NULL){
            cout << current->Data <<endl;
            current = current->next;
        }
    }


};
class CircularQueue{

    int front;
    int rear;
    int size;
    int *arr;
    public:
    CircularQueue():front(-1),rear(-1),size(5){
        arr = new int[size];
    }
    ~CircularQueue(){
        delete [] arr;
    }

    int isFull() {
    return (rear + 1) % size == front;
    }
   int isEmpty() {
    return (rear == -1 && front == -1);
}


    void enqueue(int value){

        if(isFull()){
            return ;
        }
    if(isEmpty()){

        rear=front=0;
        arr[rear] = value;
    }else {


        rear = (rear + 1) % size;
        arr[rear] = value;
    }
    }
    



void dequeue() {

    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    if (rear == front) {
        rear = front = -1;
    }
    else {
        front = (front + 1) % size;
    }

}



};



int main() {
    cout << "Hello ITIANS!" << endl;
   Stack s1 ;
   s1.push(10);
   s1.push(110);
   s1.push(1110);
   s1.push(1110);
   s1.display();
   //s1.pop();
   //s1.pop();
   cout << "===================";

   Queue q1 ;
   q1.enqueue(10);
   q1.enqueue(10);
   q1.enqueue(11);
   q1.enqueue(12);
   q1.enqueue(13);
    q1.display();
   q1.dequeue();
   q1.dequeue();




   cout << "==========Test Circular Queue==========";
      CircularQueue q;

    cout << "--- Enqueue Test ---\n";

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Is Full: " << q.isFull() << endl;

    q.enqueue(60);

    cout << "\n--- Dequeue Test ---\n";

    q.dequeue();
    q.dequeue();

    cout << "Is Empty: " << q.isEmpty() << endl;

    cout << "\n--- Circular Test ---\n";

    q.enqueue(60);
    q.enqueue(70);

    cout << "Is Full: " << q.isFull() << endl;

    cout << "\n--- Remove All Elements ---\n";

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "Is Empty: " << q.isEmpty() << endl;

    q.dequeue();
;    return 0;
}
