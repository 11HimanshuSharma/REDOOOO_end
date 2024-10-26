class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* new_head = head->next;  // The new head after the first swap
        ListNode* prev = nullptr;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // Swapping the nodes
            first->next = second->next;
            second->next = first;

            // Connect the previous swapped pair with the current swapped pair
            if (prev) {
                prev->next = second;
            }
            prev = first;  // Move prev to the end of the current swapped pair
            head = first->next;  // Move to the next pair
        }

        return new_head;
    }
};
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* node) {
  while (node != nullptr) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

int main() {
  // Creating a linked list: 1->2->3->4
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  std::cout << "Original list: ";
  printList(head);

  Solution solution;
  ListNode* swapped = solution.swapPairs(head);

  std::cout << "Swapped list: ";
  printList(swapped);

  // Free the allocated memory
  while (swapped != nullptr) {
    ListNode* temp = swapped;
    swapped = swapped->next;
    delete temp;
  }

  return 0;
}