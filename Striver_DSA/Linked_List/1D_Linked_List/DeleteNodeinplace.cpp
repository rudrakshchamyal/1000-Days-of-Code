
/**
 * ============================================================================
 * LEETCODE 237: Delete Node in a Linked List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 * ============================================================================
 * 
 * PROBLEM STATEMENT:
 * There is a singly-linked list 'head' and we want to delete a given 'node' in it.
 * You are given ONLY the pointer/reference to the node to be deleted.
 * You WILL NOT be given access to the head of the linked list.
 * 
 * NOTE ON "DELETION":
 * Deleting the node means:
 * 1. The value of the given node should no longer exist in the linked list.
 * 2. The number of nodes in the linked list should decrease by one.
 * 3. All values before 'node' must maintain their original order.
 * 4. All values after 'node' must maintain their original order.
 * 
 * CONSTRAINTS & GUARANTEES:
 * - The number of nodes in the list is in the range [2, 1000].
 * - -1000 <= Node.val <= 1000
 * - The value of each node in the list is UNIQUE.
 * - The node to be deleted is in the list and is GUARANTEED NOT TO BE the last node.
 * 
 * EXAMPLE:
 * Input: head = [4,5,1,9], node = 5
 * Output: [4,1,9]
 * Explanation: You are given the second node with value 5. The list should 
 *              become 4 -> 1 -> 9 after calling your function.
 * 
 * APPROACH OVERVIEW (O(1) Time, O(1) Space):
 * Since we don't have access to the previous node (head is unknown), we cannot 
 * re-link 'prev->next' to 'node->next'. Instead, we copy the value of 
 * 'node->next' into 'node', and then bypass/delete 'node->next'.
 * ============================================================================
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value from the adjacent next node into current node
        ListNode* temp = node->next;
        node->val = temp->val;
        
        // Step 2: Unlink the next node from the list
        node->next = temp->next;
        
        // Step 3: Deallocate memory of the unlinked node
        delete temp;
    }
};


#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value from the next node
        ListNode* temp = node->next;
        node->val = temp->val;
        
        // Bypass the next node
        node->next = temp->next;
        
        // Free memory of the bypassed node
        delete temp;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << (curr->next ? " -> " : "");
        curr = curr->next;
    }
    std::cout << std::endl;
}

// Helper function to free list memory
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Construct linked list: [4] -> [5] -> [1] -> [9]
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    std::cout << "Original List: ";
    printList(head);

    // Node to delete: node with value 5 (head->next)
    ListNode* nodeToDelete = head->next;

    Solution sol;
    sol.deleteNode(nodeToDelete);

    std::cout << "After Deletion [O(1)]: ";
    printList(head);

    freeList(head);
    return 0;
}