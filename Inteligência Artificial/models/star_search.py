from typing import Callable, Tuple, List
from .puzzle import Puzzle
import random

class StarSearch:
    pass

class StarSearch:
    evaluate_func: Callable
    start_state: Puzzle
    expansed_nodes_size: int

    def __init__(self, evaluate_func: Callable, start_state: Puzzle):
        self.evaluate_func = evaluate_func
        self.start_state = start_state

    def search(self, max_interaction = 1000000000):
        visited_nodes = set()
        current_value = ([], self.start_state)
        self.expansed_nodes_size = 1
        while max_interaction > 0:
            max_interaction = max_interaction - 1
            (path, current_node) = current_value
            visited_nodes.add(current_node.key_set())
            if current_node.is_goal:
                return path
            expansed_nodes = []
            valid_expansed_nodes = []
            for movement in current_node.get_available_movements():
                self.expansed_nodes_size += 1
                new_node = current_node.clone()
                new_node.move(movement)
                new_path = path.copy()
                new_path.append(movement)
                expansed_nodes.append((new_path, new_node))
                if new_node.key_set() not in visited_nodes:
                    valid_expansed_nodes.append((new_path, new_node))
            if len(valid_expansed_nodes) == 0:
                current_value = random.choice(expansed_nodes)
                continue
            current_value = self._take_best_state(valid_expansed_nodes)
    
    def _take_best_state(self, state_values: List[Tuple[List, Puzzle]]):
        best_state = state_values[0]
        best_value = self.evaluate_func(best_state[1])
        for i in range(1, len(state_values)):
            canditate = state_values[i]
            canditate_value = self.evaluate_func(canditate[1])
            if best_value < canditate_value:
                best_state = canditate
                best_value = canditate_value
        return best_state
