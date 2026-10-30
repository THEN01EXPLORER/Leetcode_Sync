import heapq

class Solution:
    def shortestPath(self, n: int, edges: list[list[int]], labels: str, k: int) -> int:
        if n == 1:
            return 0

        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))

        dist = [[float('inf')] * (k + 1) for _ in range(n)]
        
        pq = [(0, 0, 1)]
        dist[0][1] = 0

        diff_relaxed = [False] * n

        while pq:
            d, u, count = heapq.heappop(pq)

            if d > dist[u][count]:
                continue

            if u == n - 1:
                return d

            can_relax_diff = not diff_relaxed[u]
            if can_relax_diff:
                diff_relaxed[u] = True

            for v, w in adj[u]:
                if labels[u] == labels[v]:
                    if count + 1 <= k and d + w < dist[v][count + 1]:
                        dist[v][count + 1] = d + w
                        heapq.heappush(pq, (d + w, v, count + 1))
                else:
                    if can_relax_diff and d + w < dist[v][1]:
                        dist[v][1] = d + w
                        heapq.heappush(pq, (d + w, v, 1))

        return -1