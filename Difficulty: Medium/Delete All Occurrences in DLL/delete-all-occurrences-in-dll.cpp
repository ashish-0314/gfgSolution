/*Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        // code here
        Node * temp = head;
        while(temp != NULL){
            if(temp->data == x){
                if(temp==head) head = head->next;
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                if(nextNode) nextNode->prev = prevNode;
                if(prevNode) prevNode->next = nextNode;
                delete temp;
                temp = nextNode;
            } else temp = temp->next;
        }
        return head;
    }
};