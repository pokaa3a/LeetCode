/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    map<RandomListNode*, RandomListNode*> hash;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        if(hash.find(head)!=hash.end()){
            return hash[head];
        }
        RandomListNode *node = new RandomListNode(head->label);
        hash[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};

// class Solution {
// public:
//   Node* copyRandomList(Node* head) {
//     unordered_map<Node*, Node*> mp;
    
//     Node* cur = head;
//     while (cur) {
//       Node* new_node = new Node(cur->val);
//       mp[cur] = new_node;
//       cur = cur->next;
//     }
    
//     cur = head;
//     while (cur) {
//       mp[cur]->next = mp[cur->next];
//       mp[cur]->random = mp[cur->random];
//       cur = cur->next;
//     }
//     return mp[head];
//   }
// };