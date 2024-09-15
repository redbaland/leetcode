class Solution {
private:
    std::unordered_map<int, std::vector<int>> prereqMap;
    std::unordered_set<int> visitSet;

    void fillMap(int numCourses, std::vector<std::vector<int>>& prereq) {
        for (const auto& pair : prereq) {
            prereqMap[pair[0]].push_back(pair[1]);
        }
    }

    bool dfs(int course) {
        if (visitSet.find(course) != visitSet.end()) {
            return false;
        }
        if (prereqMap[course].empty()) {
            return true;
        }
        visitSet.insert(course);
        for (auto& prereq : prereqMap[course]) {
            if (!dfs(prereq)) {
                return false;
            }
        }
        visitSet.erase(course);
        prereqMap[course].clear();
        return true;
    }

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        fillMap(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
