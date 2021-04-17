from collections import deque
from .puzzle import Puzzle
    
class BreadthFirstSearch:
    start_state: Puzzle
    expansed_nodes_size: int

    def __init__(self, puzzle):        
        self.start_state = puzzle
        
    def search(self): 
        visitedNodes = set()
        self.expansed_nodes_size = 1
        queue = deque([([], self.start_state)])
        
        while queue:
            (movement_list, currentNode) = queue.popleft()
            visitedNodes.add(currentNode.key_set())

            if currentNode.is_goal:
                return movement_list

            # Gerando os nós filhos com as possibilidades de movimento:
            for moviment in currentNode.get_available_movements():
                newNode = currentNode.clone()
                self.expansed_nodes_size += 1
                newNode.move(moviment)
                if newNode.key_set() not in visitedNodes:
                    new_movement_list = movement_list.copy()
                    new_movement_list.append(moviment)
                    queue.append((new_movement_list, newNode))
                    visitedNodes.add(newNode.key_set())
        return None