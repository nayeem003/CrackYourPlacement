/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    void breakAndLink(Node* node) {
        Node* nextNode = node->next;
        node->next = node->child;
        node->child->prev = node;
        node->child = NULL;
        if(nextNode == nullptr) {
            return;
        }
        while(node->next) {
            node = node->next;
        }
        node->next = nextNode;
        nextNode->prev = node;
    }
    Node* flatten(Node* head) {
        if(head==nullptr) return head;
        Node* temp = head;
        level: while(temp && temp->child == nullptr) temp = temp->next;
        if(temp && temp->child) {
            breakAndLink(temp);
            goto level;
        }
        return head;
    }
};
