/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev ;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // code here
        int carry = 1;
        Node* newHead = reverse(head);
        Node* temp = newHead;
        Node* prev = NULL;
        while(temp != NULL && carry){
            int sum = temp->data + carry;
            temp->data = sum %10;
            carry = sum/10;
            prev = temp;
            temp=temp->next;
        }
        if(carry){
            Node * newNode = new Node(carry);
            prev->next = newNode;
        }
        return reverse(newHead);
    }
};