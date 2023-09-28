from collections import deque


class Searches:
    def dfs(self, graph, node):
        stack = []
        visited = []

        visited.append(node)
        stack.append(node)

        while stack:
            vertex = stack.pop()
            print(vertex, end=" ")
            for neighbor in reversed(graph[vertex]):
                if neighbor not in visited:
                    visited.append(neighbor)
                    stack.append(neighbor)

    def bfs(self, graph, node):
        visited = []
        queue = deque()

        visited.append(node)
        queue.append(node)

        while queue:
            vertex = queue.popleft()
            print(vertex, end=" ")
            for neighbor in graph[vertex]:
                if neighbor not in visited:
                    visited.append(neighbor)
                    queue.append(neighbor)


def main():
    graph = {
        'A': ['B', 'G'],
        'B': ['C', 'D', 'E'],
        'C': [],
        'D': [],
        'E': ['F'],
        'F': [],
        'G': ['H'],
        'H': ['I'],
        'I': [],
    }

    graph2 = {
        'A': ['B', 'C'],
        'B': ['D', 'E', 'F'],
        'C': ['G'],
        'D': [],
        'E': [],
        'F': ['H'],
        'G': ['I'],
        'H': [],
        'I': []
    }

    x = Searches()
    x.dfs(graph, 'A')
    print("\n")
    x.bfs(graph2, 'A')


main()
