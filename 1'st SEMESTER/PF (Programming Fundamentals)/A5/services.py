from copy import deepcopy
from domain import Student

def name_check(name):

    # Checks if an input doesen't have any digits and return 1, otherwise returns 0
    if name.isdigit() == 0:
        return 1
    return 0

def group_check(group):

    # Checks if an input is a number and return 1 if it is positive, 0 otherwise
    if group.isdigit() == 1:
        if int(group) >= 1:
            return 1
        return 0
    return 0

class Services:
    def __init__(self):

        # list=the list of the students , unol=the backup list for the undo operation
        self._list = []
        self._undol = []

    def add_stud(self,stu):

        # Adds the student info to the list and creates a backup
        self._undol.append(deepcopy(self._list[:]))
        self._list.append(stu)

    def filter_stud(self, group):

        # Filters out all the student that are in the inputted group and creates a backup
        self._undol.append(deepcopy(self._list[:]))
        group = int(group)
        i=0
        while i<len(self._list):
            if self._list[i].group == group:
                self._list.pop(i)
            else:
                i+=1

    def undo(self):

        # Undoes the last operation, can be repeated
        self._list.clear()
        self._list.extend(self._undol.pop())
