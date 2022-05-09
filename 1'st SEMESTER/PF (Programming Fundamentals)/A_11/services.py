from board import *
from numpy import *

class Services():
    def __init__(self,board):
        self._board=Board()

    # Prints the game board
    def print(self):
        print(self._board.get_items())

    # Adds the first player move
    def add_p1(self, p1):
        self._board.add_yellow(p1)

    # Adds the second player move
    def add_p2(self, p2):
        self._board.add_red(p2)

    # Clearing the board every new game
    def new_game(self):
        self._board.clear_board()

    # Checks if a player has won the game
    def check_win(self):
        if self._board.check_horizontally() or self._board.check_vertically() or self._board.check_diagonally():
            return 1

    # Adds the easy AI move on the board
    def ai_easy_move(self):
        self._board.easy_ai()

    # Adds the hard AI move on the board
    def ai_hard_move(self):
        self._board.hard_ai()