class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:

        num_nodes = len(graph)  # Number of nodes in the graph
        queue = deque()
        visited = set()  # Set to store visited (node, state) tuples
      
        # Initialize the queue and visited set with all individual nodes and their bitmasks
        for node in range(num_nodes):
            state = 1 << node
            queue.append((node, state))
            visited.add((node, state))
      
        # Initialize the number of steps taken to reach all nodes
        steps = 0
      
        # Perform a BFS until a path visiting all nodes is found
        while True:
            # Iterate over nodes in the current layer
            for _ in range(len(queue)):
                current_node, state = queue.popleft()
                
                # Check if the current state has all nodes visited
                if state == (1 << num_nodes) - 1:
                    # Return the number of steps taken so far
                    return steps
              
                # Explore neighbors of the current node
                for neighbor in graph[current_node]:
                    new_state = state | (1 << neighbor)
                    # If the new state has not been visited, add it to the queue and set
                    if (neighbor, new_state) not in visited:
                        visited.add((neighbor, new_state))
                        queue.append((neighbor, new_state))
          
            # After exploring all nodes at the current depth, increment steps
            steps += 1
