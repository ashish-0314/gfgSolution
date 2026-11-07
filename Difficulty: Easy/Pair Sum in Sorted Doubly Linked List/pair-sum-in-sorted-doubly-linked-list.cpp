/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    Node* findTail(Node* head){
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        return temp;
    }
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        vector<vector<int>> ans ;
        Node* left = head;
        Node* right = findTail(head);
        while(left->data < right->data){
            int sum = left->data + right->data;
            if(sum==target) {
                ans.push_back({left->data,right->data});
                right = right->prev;
                left = left->next;
            }
            else if(sum>target) right = right->prev;
            else left = left->next;
        }
        return ans;
    }
};