class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> m;
        for (int i = 0; i < employees.size(); ++i) {
            m[employees[i]->id] = employees[i];
        }
        if (m[id] == NULL) return 0;
        return getImportance(m[id], m);
    }
    
    int getImportance (Employee* curr, unordered_map<int,Employee*>& m) {
        if (curr && curr->subordinates.size() == 0) return curr->importance;
        int totalSubImp = 0;
        for (int i = 0; i < curr->subordinates.size(); ++i) {
            totalSubImp += getImportance(m[curr->subordinates[i]], m);
        }
        return curr->importance + totalSubImp;
    }
};
