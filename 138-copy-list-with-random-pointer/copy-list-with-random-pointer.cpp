/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution { // using Hashmap. 
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> mp; // original node, copy node

        Node* curr = head;

        while(curr){ // create copy

            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr){ // create pointer

            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};