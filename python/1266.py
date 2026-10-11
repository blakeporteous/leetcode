class Solution:
    def minTimeToVisitAllPoints(self, points: list[list[int]]) -> int:

        time = 0
        
        for (x1, y1), (x2, y2) in zip(points, points[1:]):
            time += max(abs(x2 - x1), abs(y2 - y1))
        return time

        
