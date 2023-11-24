class FA:
    def __init__(self, filename) -> None:
        self.states = []
        self.alphabet = []
        self.finalStates = []
        self.transitions = []
        self.initialState = None
        self.filename = filename

    def ReadFile(self):
        with open(self.filename, 'r') as file:
            states = file.readline().strip().split(":")
            self.states = states[1].strip().split(",")
            alphabet = file.readline().strip().split(":")
            self.alphabet = alphabet[1].strip().split(",")
            initial_state = file.readline().strip().split(":")
            self.initialState = initial_state[1].strip()
            final_states = file.readline().strip().split(":")
            self.finalStates = final_states[1].strip().split(",")
            transitions = file.readline().strip().split(":")
            for transition in transitions[1].strip().split(","):
                self.transitions.append(tuple(transition.strip().split(" ")))

    def PrintStates(self):
        print('\n States: ')
        for state in self.states:
            print(state, end=' ')

    def PrintAlphabet(self):
        print('\n Alphabet: ')
        for letter in self.alphabet:
            print(letter, end=' ')

    def PrintFinalStates(self):
        print('\n Final states: ')
        for state in self.finalStates:
            print(state, end=' ')

    def PrintInitialState(self):
        print('\n Initial state: ')
        print(self.initialState)

    def PrintTransitions(self):
        print('\n Transitions: ')
        for transition in self.transitions:
            print(f"{transition[0]} -> {transition[1]} : {transition[2]}")

    def CheckAccepted(self, word) -> bool:
        current_state = self.initialState
        for letter in word:
            found = False
            for transition in self.transitions:
                if transition[0] == current_state and transition[2] == letter:
                    current_state = transition[1]
                    found = True
                    break
            if not found:
                return False
        if current_state in self.finalStates:
            return True


if __name__ == '__main__':
    print('1 = READ FA from file path')
    print('2 = PRINT states')
    print('3 = PRINT alphabet')
    print('4 = PRINT transitions')
    print('5 = PRINT final states')
    print('6 = PRINT initial state')
    print('7 = Check if sequence is accepted')
    print('0 = Exit')
    while True:
        option = input('\n >>')
        if option == '1':
            filename = input('filename: ')
            fa = FA(filename)
            fa.ReadFile()
        elif option == '2':
            fa.PrintStates()
            print()
        elif option == '3':
            fa.PrintAlphabet()
            print()
        elif option == '4':
            fa.PrintTransitions()
        elif option == '5':
            fa.PrintFinalStates()
            print()
        elif option == '6':
            fa.PrintInitialState()
            print()
        elif option == '7':
            word = input('Word: ')
            if fa.CheckAccepted(word):
                print('Word is accepted')
            else:
                print('Word is not accepted')
        elif option == 0:
            break
        else:
            print('!ERROR! Invalid option!')


            # C:\OTHER\UBB FMI\SEM 5\LFTC\LAB2
