import numpy as np
from numpy import *
from exceptions import *
import random
import copy

class Board:
    def __init__(self):
        # 6x7 board
        self.__data=np.array([[' ',' ',' ',' ',' ',' ',' '],
                              [' ',' ',' ',' ',' ',' ',' '],
                              [' ',' ',' ',' ',' ',' ',' '],
                              [' ',' ',' ',' ',' ',' ',' '],
                              [' ',' ',' ',' ',' ',' ',' '],
                              [' ',' ',' ',' ',' ',' ',' ']])

    # Getter
    def get_items(self):
        return self.__data

    # Adding the first player move on the board
    def add_yellow(self, p1):
        i = 5
        ok = 0
        while i >= 0 and ok==0:
            if self.__data[i, p1] == ' ':
                self.__data[i, p1] = '⚫'
                ok = 1
            i-=1
        if ok == 0:
            self.clear_board()
            raise FullCollumError

    # Adding the second player move on the board
    def add_red(self, p2):
        i = 5
        ok = 0
        while i >= 0 and ok==0:
            if self.__data[i, p2] == ' ':
                self.__data[i, p2] = '○'
                ok = 1
            i-=1
        if ok == 0:
            self.clear_board()
            raise FullCollumError

    # Easy "AI" that just chooses a valid random collum on the board
    def easy_ai(self):
        ok1=0
        while ok1==0:
            move = random.randint(0, 6)
            ok=0
            i=5
            while i>=0 and ok==0:
                if self.__data[i, move] == ' ':
                    self.__data[i, move] = '○'
                    ok = 1
                    ok1=1
                i -= 1

    # Clearing the board when needed
    def clear_board(self):
        self.__data = np.array([[' ', ' ', ' ', ' ', ' ', ' ', ' '],
                                [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                                [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                                [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                                [' ', ' ', ' ', ' ', ' ', ' ', ' '],
                                [' ', ' ', ' ', ' ', ' ', ' ', ' ']])

    # Checking if there is any connect on the board diagonally
    def check_diagonally(self):
        # First diagonal
        j=0
        while j<=3:
            i=2
            while i<=5:
                if (self.__data[i,j]=='⚫' and self.__data[i-1,j+1]=='⚫' and self.__data[i-2,j+2]=='⚫' and
                    self.__data[i-3,j+3]=='⚫') \
                        or (
                        self.__data[i,j]=='○' and self.__data[i-1,j+1]=='○' and self.__data[i-2,j+2]=='○' and
                        self.__data[i-3,j+3]=='○'):
                    return 1
                i+=1
            j+=1

        # Second diagonal
        j=0
        while j<=3:
            i=0
            while i<=2:
                if (self.__data[i,j]=='⚫' and self.__data[i+1,j+1]=='⚫' and self.__data[i+2,j+2]=='⚫' and
                    self.__data[i+3,j+3]=='⚫') \
                        or (
                        self.__data[i,j]=='○' and self.__data[i+1,j+1]=='○' and self.__data[i+2,j+2]=='○' and
                        self.__data[i+3,j+3]=='○'):
                    return 1
                i+=1
            j+=1
        return 0

    # Checking if there is any connect on the board vertically
    def check_vertically(self):
        j = 0
        while j <= 6:
            i = 0
            while i <= 2:
                if (self.__data[i, j] == '⚫' and self.__data[i+1, j] == '⚫' and self.__data[i+2, j] == '⚫' and
                    self.__data[i+3,j] == '⚫') \
                        or (
                        self.__data[i, j] == '○' and self.__data[i+1,j] == '○' and self.__data[i+2,j] == '○' and
                        self.__data[i+3,j ] == '○'):
                    return 1
                i += 1
            j += 1
        return 0

    # Checking if there is any connect on the board horizontally
    def check_horizontally(self):
        i=0
        while i<=5:
            j=0
            while j<=3:
                if (self.__data[i, j] == '⚫' and self.__data[i, j+1] == '⚫' and self.__data[i, j+2] == '⚫' and
                    self.__data[i, j+3] == '⚫') \
                        or (self.__data[i, j] == '○' and self.__data[i, j+1] == '○' and self.__data[i, j+2] == '○' and
                            self.__data[i, j+3] == '○'):
                    return 1
                j+=1
            i+=1
        return 0

    '''
    MINIMAX AI
    '''

    @staticmethod
    # The actual Minimax algo
    def minimax(board,depth,alpha,beta,maximizing_player):
        valid_move=get_valid_movee(board)
        terminal_node=check_terminal_nodee(board)
        if depth==0 or terminal_node:
            if terminal_node:
                if check_horizontallyy(board) or check_verticallyy(board) or check_diagonallyy(board):
                    return (None, 10000000)
                else:
                    return (None, 0)
            else:
                return (None, position_scoringg(board))
        if maximizing_player:
            value= -math.inf()
            column=random.choice(valid_move)
            for i in valid_move:
                row=get_next_free_roww(board,i)
                board_copy=board.copy()
                # Droping the piece
                ok = 0
                j = 5
                while j >= 0 and ok == 0:
                    if board[j,row] == ' ':
                        board[j,row] = '○'
                        ok = 1
                j -= 1
                new_score=minimax(board_copy,depth-1,alpha,beta,False)[1]
                if new_score>value:
                    value=new_score
                    column=i
                alpha=max(alpha,value)
                if alpha >=beta:
                    break
                return column,value
        else:
            value= math.inf
            column=random.choice(valid_move)
            for i in valid_move:
                row=get_next_free_roww(board,i)
                board_copy = board.copy()
                ok = 0
                j = 5
                while j >= 0 and ok == 0:
                    if board[j, row] == ' ':
                        board[j, row] = '⚫'
                        ok = 1
                j -= 1
                new_score=minmax(board_copy,depth-1,alpha,beta,True)[1]
                if new_score<value:
                    value=new_score
                    column=i
                alpha=min(alpha,value)
                if alpha >=beta:
                    break
                return column,value

    # Checking to see if the game is over before AI moves. Cases: 1.someone won, 2.board is full
    def check_terminal_node(self):
        if self.check_horizontally() or self.check_vertically() or self.check_diagonally() or len(self.get_valid_move())==0:
            return 1
        return 0

    # Scoring the list of four
    def score_four(self,four):
        score=0
        if four.count('○') == 4:
            score += 1000
        elif four.count('○') == 3 and four.count(' ') == 1:
            score += 400
        elif four.count('○') == 2 and four.count(' ') == 2:
            score += 100
        if four.count('⚫') == 3 and four.count(' ') == 1:
            score -= 800
        return score

    # Checking the positon scoring
    def position_scoring(self,temp_board):
        four = ['0', '1', '2', '3']
        row_board = []
        flat = []
        score=0

        # Horizontal scoring
        i=5
        while i>=0:
            row_board=[list(temp_board[i,:])]
            flat=[x for l in row_board for x in l]
            j=0
            while j<=3:
                four[0] = flat[j]
                four[1] = flat[j+1]
                four[2] = flat[j+2]
                four[3]=  flat[j+3]
                score+=self.score_four(four)
                j+=1
            i-=1

        # Vertical scoring
        j=6
        while j>=0:
            col_board=[list(temp_board[:,j])]
            flat=[x for l in col_board for x in l]
            i=0
            while i<=2:
                four[0] = flat[i]
                four[1] = flat[i + 1]
                four[2] = flat[i + 2]
                four[3] = flat[i + 3]
                score+=self.score_four(four)
                i+=1
            j-=1

        # First diagonal scoring
        i=5
        while i>=3:
            j=0
            while j<=3:
                diag_board=[list(temp_board[i-x,j+x] for x in range(4))]
                flat = [y for l in diag_board for y in l]
                four[0] = flat[0]
                four[1] = flat[1]
                four[2] = flat[2]
                four[3] = flat[3]
                score+=self.score_four(four)
                j+=1
            i-=1

        # Second diagonal scoring
        i=5
        while i>=2:
            j=0
            while j<=3:
                diag_board = [list(temp_board[i+x-3, j + x] for x in range(4))]
                flat = [y for l in diag_board for y in l]
                four[0] = flat[0]
                four[1] = flat[1]
                four[2] = flat[2]
                four[3] = flat[3]
                score += self.score_four(four)
                j+=1
            i-=1

        return score

    # Function that checks if a collum is full
    def valid_move(self, j):
        return self.__data[0,j]==' '

    # Function that returns all valid collums on the board
    def get_valid_move(self):
        valid_loc=[]
        j=6
        while j>=0:
            if self.valid_move(j):
                valid_loc.append(j)
            j-=1
        return valid_loc

    # Funcitons that returns the next free row on the board
    def get_next_free_row(self,i):
        j=5
        while j>=0:
            if self.__data[j,i]==' ':
                return j
            j-=1

    # Hard AI picking best move
    def best_move(self):
        best_score=0
        valid_location=self.get_valid_move()
        best_col = random.choice(valid_location)

        for i in valid_location:
            j=self.get_next_free_row(i)
            tempo_board=self.__data.copy()
            tempo_board[j, i] = '○'
            score=self.position_scoring(tempo_board)
            if score > best_score:
                best_score=score
                best_col=i
        return best_col

    # Hard AI drops piece
    def hard_ai(self):
        best_col=self.best_move()
        ok = 0
        i = 5
        while i >= 0 and ok == 0:
            if self.__data[i, best_col] == ' ':
                self.__data[i, best_col] = '○'
                ok = 1
            i -= 1