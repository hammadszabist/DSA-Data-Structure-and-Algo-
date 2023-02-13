#include <iostream>

using namespace std;

const int stackSize = 10;

class Stack {

  private:
    int top;
  int arr[stackSize];

  public:

    Stack() {
      top = -1;
    }

  void push(int value) {

    if (top + 1 >= stackSize) {
      cout << "Stack Overflow" << endl;
    } else {
      top = top + 1;
      arr[top] = value;
    }

  }

  int pop() {

    int stackPopVal;

    if (top <= -1) {
      cout << "Stack underflow" << endl;
    } else {
      stackPopVal = arr[top];
      top--;
    }
    return stackPopVal;

  }

  int getStackTop(){
   return top;
  }

  void display() {
    if (top >= 0) {
      cout << "Stack elements are:";
      for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";
      cout << endl;
    } else
      cout << "Stack is empty";
  }

};

struct Node {
  public: int value;
  Node * next;

};

Node * head;
Node * tail;

class SingleLinkList {

  public:
  
   SingleLinkList( ){
      head = NULL;
      tail = NULL;
    }
    
    void addCustomer(int d) {

      Node * newNode = new Node();
      newNode -> value = d;

      /*check head & tail are already set or not */
      if (head == NULL and tail == NULL) {
        newNode -> next = NULL;
        head = newNode;
        tail = newNode;
        return;
      }

      if (head == tail) {
        newNode -> next = NULL;
        head -> next = newNode;
        tail = newNode;
        return;
      }

      if (head != tail) {
        newNode -> next = NULL;
        tail -> next = newNode;
        tail = newNode;
      }

    }

  void showCustomer() {

    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }

  cout << "List of customers who used ATM Machine is: " << endl;
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
  }

};

class ATMMachine {

  int customerPin[8][2];
  int customerBalance[8][2];
  Stack transctionInStack;
  SingleLinkList customerUsesMachine;

  public:
  int highestTransactionAmount = 0;
    ATMMachine() {
      /* initialize all details about the customers on instance creation*/
      initCustomerPin();
      initCustomerBalance();
  }
  bool isCardValid(int cardNumber) {
    /*Validate customr card via linear search on Array*/
    for (int i = 0; i < sizeof(customerBalance); i++) {
      if (cardNumber == customerBalance[i][0]) {
        return true;
      }
    }
    return false;
  }
  bool isPinValid(int cardNumber, int pin) {
    /*search customer PIN via linear search on Array*/
    for (int i = 0; i < sizeof(customerPin); i++) {
      if (customerPin[i][0] == cardNumber && customerPin[i][1] == pin) {
        return true;
      }
    }
    return false;

  }
  
  bool withdrawAmount(int cardNumber, int amount) {

    bool is_success = false;

    for (int i = 0; i < sizeof(customerBalance); i++) {
      if (cardNumber == customerBalance[i][0]) { /* first check customer with card no*/
        if (amount <= customerBalance[i][1]) {
          /* withdraw customer amount and update balance*/
          customerBalance[i][1] = customerBalance[i][1] - amount;
          is_success = true;
        } else {
          cout << "Insufficient Balance" << endl;
        }
      }
    }
    return is_success;

  }
  void initCustomerBalance() {

    /* initialize card balance....card no zero column card balance firt column*/
    customerBalance[0][0] = 1001;
    customerBalance[0][1] = 40000;

    customerBalance[1][0] = 1002;
    customerBalance[1][1] = 50000;

    customerBalance[2][0] = 1003;
    customerBalance[2][1] = 60000;

    customerBalance[3][0] = 1004;
    customerBalance[3][1] = 15000;

    customerBalance[4][0] = 1005;
    customerBalance[4][1] = 100;

    customerBalance[5][0] = 1006;
    customerBalance[5][1] = 20000;

    customerBalance[6][0] = 1007;
    customerBalance[6][1] = 800;

    customerBalance[7][0] = 1008;
    customerBalance[7][1] = 3000000;

  }
  void initCustomerPin() {

    /* initialize card one pin....card no zero column card pin firt column*/
    customerPin[0][0] = 1001;
    customerPin[0][1] = 1001;

    /* initialize card one pin*/
    customerPin[1][0] = 1002;
    customerPin[1][1] = 1002;

    /* initialize card three pin*/
    customerPin[2][0] = 1003;
    customerPin[2][1] = 1003;

    /* initialize card 4 pin*/
    customerPin[3][0] = 1004;
    customerPin[3][1] = 1004;

    /* initialize card 5 pin*/
    customerPin[4][0] = 1005;
    customerPin[4][1] = 1005;

    /* initialize card 6 pin*/
    customerPin[5][0] = 1006;
    customerPin[5][1] = 1006;

    /* initialize card 7 pin*/
    customerPin[6][0] = 1007;
    customerPin[6][1] = 1007;

    /* initialize card 8 pin*/
    customerPin[7][0] = 1008;
    customerPin[7][1] = 1008;

  }
  int geStackTop(){
    int top = transctionInStack.getStackTop();
    return top;
  }

  void startTransaction(){
    int cardNumber, pin, amount;
    /*operations*/
    /*first check Card is Valid*/
    cout << "Please Enter Card Number:" << endl;
    cin >> cardNumber;

    bool is_card_valid = isCardValid(cardNumber);
    if (is_card_valid == false) {
      cout << "Invalid Card" << endl;
      return;
    }

    cout << "Please Enter Card Pin:" << endl;
    cin >> pin;
    bool is_pin_valid = isPinValid(cardNumber, pin);
    if (is_pin_valid == false) {
      cout << "Invalid Pin" << endl;
      return;
    }

    cout << "Please Enter Amount to Withdraw :" << endl;
    cin >> amount;
    if (amount <= 0) {
      cout << "Invalid Amount" << endl;
      return;
    }

    /*withdrawAmount Amount & update Customer Balance*/
    bool is_withdraw = withdrawAmount(cardNumber, amount);
    if (is_withdraw == true) {
      transctionInStack.push(amount);     /*transactions are pushed into Stack*/

    }
     /*customers are added into linked list*/
    customerUsesMachine.addCustomer(cardNumber);
  }



 /*Recursive method to find highhest tranacation from Stack*/
  void highestTrasacation(int stackTop) {
    if (stackTop == -1) {
      return;
    }

    int amount = transctionInStack.pop();
    if (amount > highestTransactionAmount) {
      highestTransactionAmount = amount;
    }
    stackTop = stackTop - 1;
    highestTrasacation(stackTop);

  }

  void customerUsedATM() {
    customerUsesMachine.showCustomer();
  }

};

int main() {
  int ch;
  ATMMachine obj;
  cout << "1) to Start using ATM Machine" << endl;
  cout << "2) Display highest Transaction (if customer use at least once ATM Machine)" << endl;
  cout << "3) Customer list who used ATM Machine" << endl;
  cout << "4) Exit" << endl;

  do {
    cout << "Enter Operation....: " << endl;
    cin >> ch;
    switch (ch) {
    case 1: {
      obj.startTransaction();
      break;
    }
    case 2: {
      obj.highestTrasacation( obj.geStackTop() );
      cout << "Highest Transactional Amount is: " << obj.highestTransactionAmount << endl;
      break;
    }
    case 3: {
      obj.customerUsedATM();
      break;
    }
    case 4: {
      cout << "Exit" << endl;
      break;
    }
    default: {
      cout << "Invalid Choice" << endl;
    }
    }
  } while (ch != 4);
  return 0;
}