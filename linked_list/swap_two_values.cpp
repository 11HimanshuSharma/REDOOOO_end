class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* fast = head;

        // Move fast pointer to the k-th node from the start
        for (int i = 1; i < k; i++) {
            fast = fast->next;
        }
        first = fast; // first node to swap

        // Move fast to the end, and move second to the k-th node from the end
        while (fast->next != nullptr) {
            fast = fast->next;
            second = second->next;
        }

        // Swap the values of the two nodes
        std::swap(first->val, second->val);

        return head;
    }
};
int main() {
  // Helper function to create a new ListNode
  auto createNode = [](int val) -> ListNode* {
    return new ListNode(val);
  };

  // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
  ListNode* head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = createNode(4);
  head->next->next->next->next = createNode(5);

  Solution solution;
  int k = 2;
  head = solution.swapNodes(head, k);

  // Print the modified linked list
  ListNode* current = head;
  while (current != nullptr) {
    std::cout << current->val << " ";
    current = current->next;
  }

  // Free the allocated memory
  current = head;
  while (current != nullptr) {
    ListNode* next = current->next;
    delete current;
    current = next;
  }

  return 0;
}