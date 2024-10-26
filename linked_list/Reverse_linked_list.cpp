#include<iostream>
using namespace std;



class Node{
  public:
    int data;
    Node *next;
    Node(int key) {
      data = key;
      next = NULL;
    }
};
class LL{
  private:
  Node *head,*last;
  public:

    LL(){
      head = NULL;
      last = NULL;
    }
    void insert(int key){
      if (head == NULL){
        head = new Node(key);
        last = head;
      }
      else{
        last->next = new Node(key);
        last = last->next;
      }

    }
    void display(){
      Node *temp = head;
      while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
    }
    void reverse(){
      Node *r,*q,*p;
      r = NULL;
      q = NULL;
      p = head;

      while (p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;

      }
      head = q;
    }


};

int main(){
  LL l;
  l.insert(1);
  l.insert(2);
  l.insert(3);
  l.insert(4);
  l.insert(5);
  l.display();
  l.reverse();
  l.display();
  return 0;
}
