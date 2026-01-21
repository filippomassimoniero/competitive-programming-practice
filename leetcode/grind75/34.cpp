#include <bits/stdc++.h>

using namespace std;

//Kahn's algorithm
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    
    vector<int> status(numCourses, 0);
    
    for(auto &x : prerequisites) {
        adj[x[0]].push_back(x[1]);
        status[x[1]] -=1;
    }

    queue<int> reachable;

    for (int i = 0; i < numCourses; i++) {
        if(status[i] == 0) reachable.push(i);
    }

    vector<int> completedCourses;
    while (!reachable.empty()) {
        int current = reachable.front();
        reachable.pop();

        completedCourses.push_back(current);

        int edgesToDelete = adj[current].size();
        for (int i = edgesToDelete - 1; i>= 0; i--) {
            status[adj[current][i]]++;
            if(status[adj[current][i]] == 0) reachable.push(adj[current][i]);
            // adj[current].erase(adj[current].begin() + i); // Not needed! 
        }
    }

    return completedCourses.size() == numCourses;


}

void testCase(int testNum, int numCourses, vector<vector<int>> prerequisites, bool expected) {
    bool result = canFinish(numCourses, prerequisites);
    string status = (result == expected) ? "✓ PASS" : "✗ FAIL";
    
    cout << "Test " << testNum << ": " << status << "\n";
    cout << "  Courses: " << numCourses << "\n";
    cout << "  Prerequisites: [";
    for (int i = 0; i < prerequisites.size(); i++) {
        cout << "[" << prerequisites[i][0] << "," << prerequisites[i][1] << "]";
        if (i < prerequisites.size() - 1) cout << ", ";
    }
    cout << "]\n";
    cout << "  Expected: " << (expected ? "true" : "false") 
         << ", Got: " << (result ? "true" : "false") << "\n\n";
}

int main() {
    cout << "Testing Kahn's Algorithm - Course Schedule\n";
    cout << "==========================================\n\n";
    
    // Test 1: Simple valid case
    testCase(1, 2, {{1, 0}}, true);
    // Can take course 0 first, then course 1
    
    // Test 2: Simple cycle
    testCase(2, 2, {{1, 0}, {0, 1}}, false);
    // Circular dependency - impossible
    
    // Test 3: No prerequisites
    testCase(3, 3, {}, true);
    // All courses independent
    
    // Test 4: Linear dependency chain
    testCase(4, 4, {{1, 0}, {2, 1}, {3, 2}}, true);
    // 0 -> 1 -> 2 -> 3 (valid order)
    
    // Test 5: Diamond dependency (valid)
    testCase(5, 4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, true);
    //     0
    //    / \
    //   1   2
    //    \ /
    //     3
    
    // Test 6: Larger cycle
    testCase(6, 3, {{0, 1}, {1, 2}, {2, 0}}, false);
    // 0 -> 1 -> 2 -> 0 (cycle)
    
    // Test 7: Single course
    testCase(7, 1, {}, true);
    // Just one course, no prereqs
    
    // Test 8: Self-loop
    testCase(8, 1, {{0, 0}}, false);
    // Course depends on itself
    
    // Test 9: Multiple independent chains
    testCase(9, 6, {{1, 0}, {2, 1}, {4, 3}, {5, 4}}, true);
    // Two separate chains: 0->1->2 and 3->4->5
    
    // Test 10: Complex valid graph
    testCase(10, 5, {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}}, true);
    //     0
    //    / \
    //   1   2
    //    \ /
    //     3
    //     |
    //     4
    
    // Test 11: Disconnected cycle
    testCase(11, 5, {{1, 0}, {2, 1}, {1, 2}, {4, 3}}, false);
    // Has a cycle between 1 and 2: 1->2->1
    
    // Test 12: Large valid course set
    testCase(12, 10, {{1,0}, {2,1}, {3,2}, {4,3}, {5,4}, {6,5}, {7,6}, {8,7}, {9,8}}, true);
    // Long chain: 0->1->2->3->4->5->6->7->8->9
    
    // Test 13: Multiple prerequisites for one course
    testCase(13, 5, {{4, 0}, {4, 1}, {4, 2}, {4, 3}}, true);
    // Course 4 requires courses 0, 1, 2, and 3 first
    
    // Test 14: Indirect cycle
    testCase(14, 4, {{1, 0}, {2, 1}, {3, 2}, {0, 3}}, false);
    // 0->1->2->3->0 (cycle)
    
    cout << "==========================================\n";
    cout << "Testing complete!\n";
    
    return 0;
}