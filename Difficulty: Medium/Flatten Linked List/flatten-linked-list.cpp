/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

// class Solution {
//   public:
//     Node* mergeList(Node* list1 , Node* list2){
//         Node* dummyNode = new Node(-1);
//         Node* res = dummyNode;
//         while(list1 != NULL && list2 != NULL){
//             if(list1->data <= list2->data){
//                 res->bottom= list1;
//                 list1 = list1->bottom;
//             } else{
//                 res->bottom = list2;
//                 list2 = list2->bottom;
//             }
//             res = res->bottom;
//             res->next = nullptr;
//         }
//         if(list1) res->bottom = list1;
//         else res->bottom = list2;
//         while(res->bottom) {
//                 res = res->bottom;
//                 res->next = nullptr;
//             }
//         return dummyNode->bottom;
        
        
//     }
//     Node* flatten(Node* head) {
//         // code here
//         if(head==NULL || head->next == NULL) return head;
//         Node* mergeHead = flatten(head->next);
//         head->next = nullptr;
//         //head = mergeList(head,mergeHead);
//         return mergeList(head,mergeHead);
        
//     }
// };



class Solution {
public:
    Node* flatten(Node* head) {

        if(head == NULL) return NULL;

        priority_queue<Node*, vector<Node*>,
        function<bool(Node*, Node*)>> pq(
            [](Node* a, Node* b) {
                return a->data > b->data;
            }
        );

        Node* temp = head;

        while(temp != NULL) {
            pq.push(temp);
            temp = temp->next;
        }

        Node* dummy = new Node(-1);
        Node* tail = dummy;

        while(!pq.empty()) {

            Node* curr = pq.top();
            pq.pop();

            tail->bottom = curr;
            tail = tail->bottom;

            tail->next = NULL;

            if(curr->bottom != NULL) {
                pq.push(curr->bottom);
            }
        }

        tail->bottom = NULL;

        return dummy->bottom;
    }
};