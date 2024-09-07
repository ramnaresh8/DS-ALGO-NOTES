#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

 public:
  Node(int val, Node* next, Node* prev) {
    data = val;
    next = next;
    prev = prev;
  }

 public:
  Node(int val) {
    data = val;
    next = nullptr;
    prev = nullptr;
  }
};

Node* convertArrToDLL(vector<int>& arr) {
  if (arr.empty())
    return nullptr;
  Node* head = new Node(arr[0]);
  Node* current = head;

  for (int i = 1; i < arr.size(); i++) {
    Node* newNode = new Node(arr[i]);
    current->next = newNode;
    newNode->prev = current;
    current = newNode;
  }
  return head;
}

void printListForward(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

void printListBackward(Node* tail) {
  Node* current = tail;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->prev;
  }
  cout << endl;
}

void deleteDLL(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
}

Node* deleteHead(Node* head) {
  if (head == NULL || head->next == NULL)
    return NULL;

  Node* current = head;
  head = head->next;

  head->prev = nullptr;
  current->next = nullptr;

  delete current;
  return head;
}

Node* deleteTail(Node* head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  Node* tail = head;
  while (tail->next != NULL) {
    tail = tail->next;
  }

  Node* newTail = tail->prev;
  newTail->next = nullptr;
  tail->prev = nullptr;
  delete tail;
  return head;
}

Node* deleteKthElement(Node* head, int k) {
  if (head == NULL)
    return NULL;

  int count = 0;
  Node* KthNode = head;
  while (KthNode != NULL) {
    count++;
    if (count == k) {
      break;
    }
    KthNode = KthNode->next;
  }
  Node* prev = KthNode->prev;
  Node* front = KthNode->next;

  if (prev == NULL && front == NULL) {
    return NULL;
  } else if (prev == NULL) {
    return deleteHead(head);
  } else if (front == NULL) {
    return deleteTail(head);
  }
  prev->next = front;
  front->prev = prev;

  KthNode->next = nullptr;
  KthNode->prev = nullptr;

  delete KthNode;
  return head;
}

void deleteNode(Node* temp) {
  Node* prev = temp->prev;
  Node* front = temp->next;

  if(front == NULL) {
    prev->next = nullptr;
    temp->prev = nullptr;
    free(temp);
    return;
  }

  prev->next = front;
  front->prev = prev;

  temp->next = temp->prev = nullptr;
  free(temp);

}

int main() {
  vector<int> arr = {18, 17, 34, 90, 11, 56};
  Node* head = convertArrToDLL(arr);

  printListForward(head);

  Node* tail = head;
  while (tail->next != nullptr) {
    tail = tail->next;
  }

  // printListBackward(tail);
  // head = deleteTail(head);
  // printListForward(head);
  // head = deleteKthElement(head, 6);
  deleteNode(head->next->next);
  printListForward(head);

  return 0;
};