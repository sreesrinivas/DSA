class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int room) {
        // Mark as visited
        visited[room] = true;

        for(int key : rooms[room]) {
            if(!visited[key]) dfs(rooms, visited, key);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        
        // Start from room 0
        dfs(rooms, visited, 0);

        // Check if every room was reachable
        for(bool i : visited)
            if(!i) return false;

        return true;
    }
};
