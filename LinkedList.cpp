#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

 public:
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  }

 public:
  Node(int data) {
    data = data;
    next = nullptr;
  }
};

Node* convertArrToLL(vector<int>& arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
};

int lengthOfLL(Node* head) {
  int count = 0;
  Node* temp = head;
  while (temp) {
    temp = temp->next;
    count++;
  }
  return count;
}

Node* insertHead(Node* head, int val) {
  return new Node(val, head);
}

int main() {
  vector<int> arr = {22, 4, 6, 9, 8};
  // Node* y = new Node(arr[0], nullptr);
  // cout << y-> data << endl;
  Node* head = convertArrToLL(arr);
  head = insertHead(head, 100);
  cout << head << endl;
};
