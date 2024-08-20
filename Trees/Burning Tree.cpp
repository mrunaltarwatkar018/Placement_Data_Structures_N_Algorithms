/* GFG Problem: Burning Tree */

/*
    Company Tags                : Flipkart, Amazon, Microsoft, Adobe
    GFG Link                    : https://www.geeksforgeeks.org/problems/burning-tree/1
*/



// python code

/*
    Time and Space Complexity
        - Time Complexity: The algorithm runs a BFS, which has a time complexity of O(N), where N is the number of nodes in the binary tree.
        - Space Complexity: The space complexity is O(N) as we use a parent map and a queue to perform BFS.
*/

from collections import deque

class Solution:
    def __init__(self):
        self.parent_map = {}  # A dictionary to keep track of parent nodes
        self.target_node = None  # The target node we are searching for
        self.min_time = 0  # The minimum time to reach the target node

    def buildParentMap(self, node, target):
        """
        Build a parent map while searching for the target node.
        """
        if node.data == target:
            self.target_node = node
        if node.left:
            self.parent_map[node.left] = node
            self.buildParentMap(node.left, target)
        if node.right:
            self.parent_map[node.right] = node
            self.buildParentMap(node.right, target)

    def minTime(self, root, target):
        """
        Calculate the minimum time to reach the target node from the root.
        """
        self.buildParentMap(root, target)

        queue = deque()
        queue.append((self.target_node, 0))
        visited = set()

        while queue:
            current_node, time = queue.popleft()
            visited.add(current_node)

            if current_node in self.parent_map and self.parent_map[current_node] not in visited:
                queue.append((self.parent_map[current_node], time + 1))
            if current_node.left and current_node.left not in visited:
                queue.append((current_node.left, time + 1))
            if current_node.right and current_node.right not in visited:
                queue.append((current_node.right, time + 1))

            self.min_time = time  # Update the minimum time

        return self.min_time







// c++ code
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = nullptr;
        int minTime = 0;

        buildParentMap(root, target, parentMap, targetNode);

        queue<pair<Node*, int>> q;
        q.push({targetNode, 0});
        unordered_set<Node*> visited;

        while (!q.empty()) {
            Node* currentNode = q.front().first;
            int time = q.front().second;
            q.pop();

            visited.insert(currentNode);

            if (parentMap.find(currentNode) != parentMap.end() && visited.find(parentMap[currentNode]) == visited.end()) {
                q.push({parentMap[currentNode], time + 1});
            }
            if (currentNode->left && visited.find(currentNode->left) == visited.end()) {
                q.push({currentNode->left, time + 1});
            }
            if (currentNode->right && visited.find(currentNode->right) == visited.end()) {
                q.push({currentNode->right, time + 1});
            }

            minTime = time;  // Update the minimum time
        }

        return minTime;
    }

private:
    void buildParentMap(Node* node, int target, unordered_map<Node*, Node*>& parentMap, Node*& targetNode) {
        if (node->data == target) {
            targetNode = node;
        }
        if (node->left) {
            parentMap[node->left] = node;
            buildParentMap(node->left, target, parentMap, targetNode);
        }
        if (node->right) {
            parentMap[node->right] = node;
            buildParentMap(node->right, target, parentMap, targetNode);
        }
    }
};