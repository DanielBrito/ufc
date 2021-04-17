from models.puzzle import Puzzle
from models.bfs import BreadthFirstSearch
from models.star_search import StarSearch

puzzle = Puzzle([
    [1, 3, 4],
    [2, None, 6],
    [5, 8, 7]
])

print("Initial state")
print(puzzle)
print("==================\n")

# puzzleBFS = BreadthFirstSearch(puzzle)
# movements = puzzleBFS.search()
# print("Finish search")
# print("Steps: ", puzzleBFS.expansed_nodes_size)

# final_puzzle = puzzle
# for movement in movements:
#     final_puzzle = puzzle.clone()
#     final_puzzle.move(movement)

# final_puzzle.pprint()


def evaluate_func(p: Puzzle):
    # return 100 - p.distance_to_goal()
    return p.number_part_of_place()

star_search = StarSearch(evaluate_func, puzzle)
movements = star_search.search()
print("Steps:", star_search.expansed_nodes_size)
print(len(movements))
final_puzzle = puzzle
for movement in movements:
    final_puzzle = puzzle.clone()
    final_puzzle.move(movement)

final_puzzle.pprint()

n=417
b=1.0121
h=148
acc=float(0)
for i in range(h+1):
    acc += b**i
print(acc, n)