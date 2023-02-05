import heapq
import math

def astar(start, end, h_func):
    heap = [(h_func(start), 0, start)]
    visited = set()

    while heap:
        f, g, node = heapq.heappop(heap)
        if node == end:
            return g
        if node in visited:
            continue
        visited.add(node)
        for child in expand_node(node):
            heapq.heappush(heap, (g + 1 + h_func(child), g + 1, child))

def h_manhattan(puzzle):
    h = 0
    for i, tile in enumerate(puzzle):
        if tile == 0:
            continue
        row, col = divmod(i, 3)
        target_row, target_col = divmod(tile - 1, 3)
        h += abs(row - target_row) + abs(col - target_col)
    return h

def expand_node(puzzle):
    zero_index = puzzle.index(0)
    row, col = divmod(zero_index, 3)
    children = []
    if row > 0:
        new_puzzle = puzzle[:]
        new_puzzle[zero_index], new_puzzle[zero_index - 3] = new_puzzle[zero_index - 3], new_puzzle[zero_index]
        children.append(new_puzzle)
    if row < 2:
        new_puzzle = puzzle[:]
        new_puzzle[zero_index], new_puzzle[zero_index + 3] = new_puzzle[zero_index + 3], new_puzzle[zero_index]
        children.append(new_puzzle)
    if col > 0:
        new_puzzle = puzzle[:]
        new_puzzle[zero_index], new_puzzle[zero_index - 1] = new_puzzle[zero_index - 1], new_puzzle[zero_index]
        children.append(new_puzzle)
    if col < 2:
        new_puzzle = puzzle[:]
        new_puzzle[zero_index], new_puzzle[zero_index + 1] = new_puzzle[zero_index + 1], new_puzzle[zero_index]
        children.append(new_puzzle)
    return children

start = [1, 2, 3, 4, 5, 6, 7, 0, 8]
end = [1, 2, 3, 4, 5, 6, 8, 7, 0]
print(astar(start, end, h_manhattan))
