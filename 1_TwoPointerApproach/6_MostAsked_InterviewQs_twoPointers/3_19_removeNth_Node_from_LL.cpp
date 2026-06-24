// given an LinkedList, remove the nth node from the end of list and return its head.

// we have given an LL : 1,2,3,4,5 and asked to delete the nth node ? if list length is 5 we can remove 5. But because this is a single LL, we can only move forward --> (Left to right) and we dont know where the end is until we reach. 

// Approach : we use fast slow (two pointer)
// where first we handle edge cases when we asked to delete head, we create a dummy node which points to head. so we can use previous and current pointers logic 


#include<iostream>
using namespace std;


// first we create the structure of a LL : which contains a val and next ptr.
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
    public:
    ListNode* removeNthNode(ListNode* head, int n){
        // creating a dummy node with val 0 in it, to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // now create two pointers fast and slow
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // now move fast n steps 
        for(int i = 0;i < n; i++){
            fast = fast->next;
        }

        // check if both pointers not reached to end (end == null ptr) move ptrs
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        // now once we move til the end slow is 1 step before target (because we need to delete nth node at nth position we have fast)
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        // now we return the head
        ListNode* NewHead = dummy->next;
        delete dummy;

        return NewHead;
    }

};

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val;
        if (temp->next != nullptr) {
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Main function to execute and test the code
int main() {
    // 1. Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    // 2. Define which node from the end to remove (e.g., 2nd from the end, which is '4')
    int n = 2;
    std::cout << "Removing " << n << "nd node from the end..." << std::endl;

    // 3. Run the solution
    Solution obj;
    head = obj.removeNthNode(head, n);

    // 4. Print the modified list
    std::cout << "Modified List: ";
    printList(head);

    // Clean up remaining memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}