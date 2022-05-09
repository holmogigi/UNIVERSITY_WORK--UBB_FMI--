from src.exceptions import NoUndoRedoError

class UndoAction:
    def __init__(self, undo_object, undo_function, redo_object, redo_function):
        self.__undo_object = undo_object
        self.__undo_function = undo_function
        self.__redo_object = redo_object
        self.__redo_function = redo_function

    def undo(self):
        self.__undo_function(self.__undo_object)

    def redo(self):
        self.__redo_function(self.__redo_object)


class ComplexUndoAction:
    def __init__(self, list_of_undos):
        self.__list_of_undos = list_of_undos

    def undo(self):
        for undo in self.__list_of_undos:
            undo.undo()

    def redo(self):
        for i in range(len(self.__list_of_undos) - 1, -1, -1):
            self.__list_of_undos[i].redo()


class UndoStack:
    def __init__(self):
        self.__undo_stack = []

    def pop_stack(self):
        if not len(self.__undo_stack):
            raise NoUndoRedoError
        return self.__undo_stack.pop()

    def push_stack(self, undo_action):
        self.__undo_stack.append(undo_action)

    def clear_stack(self):
        self.__undo_stack = []



