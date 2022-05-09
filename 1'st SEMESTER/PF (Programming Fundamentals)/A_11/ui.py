from exceptions import *
from services import *
from validator import *
import unittest
import random

class UI():

    def __init__(self,services):
        self._operation=services

    def main_menu(self):
        print('\n')
        print('\n')
        print('\033[1m' +"                                                                                                                                                                    CONNECT FOUR GAME"+ '\033[0m')
        print()
        print("                                                                                                                                                             Press '1' for player VS player")
        print("                                                                                                                                                               Press '2' for player VS AI")
        print("                                                                                                                                                        Type 'exit' to close the game at any time")
        print()

    def player1_menu(self):
        print('\n')
        print('\033[1m' + "             Player 1"+ '\033[0m')
        print("Choose a collum to drop the piece in")
        print()
        print('   1   2   3   4   5   6   7')
        print('  ___________________________')

    def player2_menu(self):
        print('\n')
        print('\033[1m' +"              Player 2"+ '\033[0m')
        print("Choose a collum to drop the piece in")
        print()
        print('   1   2   3   4   5   6   7')
        print('  ___________________________')

    def ai_menu(self):
        print('\n')
        print("                                                                                                                                                                 Press '1' for easy AI")
        print("                                                                                                                                                                 Press '2' for hard AI")

    def run(self):
        while True:
            try:
                self.main_menu()
                gamemode=input(">>> ")

                # PvP mode
                if gamemode=='1':
                    win=0
                    move=0
                    while win==0:

                        # First player move
                        ok = 0
                        while ok == 0:
                            self.player1_menu()
                            self._operation.print()
                            print()
                            player1=input(">>> ")
                            if Validator.validate_collum(player1):
                                ok=1
                                player1=int(player1)
                                player1-=1
                                self._operation.add_p1(player1)
                                move+=1
                            elif player1=='exit':
                                exit()
                            else:
                                print(" !ERROR! INVALID COLLUM INPUT")

                        # First player win check
                        if self._operation.check_win():
                            self._operation.print()
                            print()
                            print('\033[1m' +"         !PLAYER 1 WINS!"+ '\033[0m' )
                            return

                        # Second player move
                        ok = 0
                        while ok == 0:
                            self.player2_menu()
                            self._operation.print()
                            print()
                            player2=input(">>> ")
                            if Validator.validate_collum(player2):
                                ok=1
                                player2=int(player2)
                                player2-=1
                                self._operation.add_p2(player2)
                                move+=1
                            elif player2=='exit':
                                exit()
                            else:
                                print(" !ERROR! INVALID COLLUM INPUT")

                        # Second player win check
                        if self._operation.check_win():
                            self._operation.print()
                            print()
                            print('\033[1m' + "         !PLAYER 2 WINS!" + '\033[0m')
                            return

                        # Full baord check
                        if move==42:
                            raise FullBoardError
                            self._operation.new_game()

                # PvAI mode
                elif gamemode=='2':
                    self.ai_menu()
                    difficulty=input(">>> ")

                    # PvAI EASY MODE
                    if difficulty=='1':

                        # Choosing randomly if the AI or the human player makes the first move
                        first=random.randint(1,2)
                        win = 0
                        move=0
                        if first==1:
                            while win == 0:

                                # First player move
                                ok = 0
                                while ok == 0:
                                    self.player1_menu()
                                    self._operation.print()
                                    print()
                                    player1 = input(">>> ")
                                    if Validator.validate_collum(player1):
                                        ok = 1
                                        player1 = int(player1)
                                        player1 -= 1
                                        self._operation.add_p1(player1)
                                        self._operation.print()
                                        move+=1
                                    elif player1 == 'exit':
                                        exit()
                                    else:
                                        print(" !ERROR! INVALID COLLUM INPUT")

                                # First player win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "         !PLAYER 1 WINS!" + '\033[0m')
                                    return

                                # Easy AI move
                                print("\n")
                                print('\033[1m' +"    The AI is making it's move!"+ '\033[0m')
                                self._operation.ai_easy_move()
                                move+=1

                                # AI win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "            !AI WINS!" + '\033[0m')
                                    self._operation.print()
                                    return

                                # Full baord check
                                if move==42:
                                    raise FullBoardError
                                    self._operation.new_game()
                        else:
                            while win == 0:

                                # Easy AI move
                                print("\n")
                                print('\033[1m' + "    The AI is making it's move!" + '\033[0m')
                                self._operation.ai_easy_move()
                                move += 1

                                # AI win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "            !AI WINS!" + '\033[0m')
                                    self._operation.print()
                                    return
                                # First player move
                                ok = 0
                                while ok == 0:
                                    self.player1_menu()
                                    self._operation.print()
                                    print()
                                    player1 = input(">>> ")
                                    if Validator.validate_collum(player1):
                                        ok = 1
                                        player1 = int(player1)
                                        player1 -= 1
                                        self._operation.add_p1(player1)
                                        self._operation.print()
                                        move += 1
                                    elif player1 == 'exit':
                                        exit()
                                    else:
                                        print(" !ERROR! INVALID COLLUM INPUT")

                                # First player win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "         !PLAYER 1 WINS!" + '\033[0m')
                                    return

                                # Full baord check
                                if move == 42:
                                    raise FullBoardError
                                    self._operation.new_game()

                    # PvAI HARD MODE
                    elif difficulty=='2':
                        first=random.randint(1,2)
                        win = 0
                        move = 0
                        if first==1:
                            while win == 0:

                                # First player move
                                ok = 0
                                while ok == 0:
                                    self.player1_menu()
                                    self._operation.print()
                                    print()
                                    player1 = input(">>> ")
                                    if Validator.validate_collum(player1):
                                        ok = 1
                                        player1 = int(player1)
                                        player1 -= 1
                                        self._operation.add_p1(player1)
                                        self._operation.print()
                                        move += 1
                                    elif player1 == 'exit':
                                        exit()
                                    else:
                                        print(" !ERROR! INVALID COLLUM INPUT")

                                # First player win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "         !PLAYER 1 WINS!" + '\033[0m')
                                    return

                                # HARD AI move
                                print("\n")
                                print('\033[1m' + "    The AI is making it's move!" + '\033[0m')
                                self._operation.ai_hard_move()
                                move += 1

                                # AI win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "            !AI WINS!" + '\033[0m')
                                    self._operation.print()
                                    return

                                # Full baord check
                                if move == 42:
                                    raise FullBoardError
                                    self._operation.new_game()
                        else:
                            while win == 0:

                                # HARD AI move
                                print("\n")
                                print('\033[1m' + "    The AI is making it's move!" + '\033[0m')
                                self._operation.ai_hard_move()
                                move += 1

                                # AI win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "            !AI WINS!" + '\033[0m')
                                    self._operation.print()
                                    return

                                # First player move
                                ok = 0
                                while ok == 0:
                                    self.player1_menu()
                                    self._operation.print()
                                    print()
                                    player1 = input(">>> ")
                                    if Validator.validate_collum(player1):
                                        ok = 1
                                        player1 = int(player1)
                                        player1 -= 1
                                        self._operation.add_p1(player1)
                                        self._operation.print()
                                        move += 1
                                    elif player1 == 'exit':
                                        exit()
                                    else:
                                        print(" !ERROR! INVALID COLLUM INPUT")

                                # First player win check
                                if self._operation.check_win():
                                    print()
                                    print('\033[1m' + "         !PLAYER 1 WINS!" + '\033[0m')
                                    return

                                # Full baord check
                                if move == 42:
                                    raise FullBoardError
                                    self._operation.new_game()
                    elif difficulty=='exit':
                        exit()
                    else:
                        raise InvalidInputError
                elif gamemode=="exit":
                    exit()
                elif gamemode=="test":
                    unittest.main(module="tests", exit=False)
                else:
                    raise InvalidInputError
            except InvalidInputError:
                print(" !ERROR! IVALID INPUT")
            except FullCollumError:
                print(" !ERROR! THE COLLUM IS FULL")
            except FullBoardError:
                print('\033[1m' +"         !DRAW! THE BOARD IS FULL"'\033[0m')