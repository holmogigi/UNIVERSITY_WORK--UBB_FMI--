from src.domain import Student
from src.services import Services
from src.services import *

class Ui:

    def __init__(self,services):
        self._services= services
        self._services._undol= []

    def menu(self):

        # Menu print function
        print("\n")
        print("Press '1' to add a student")
        print("Press '2' to display the list of students")
        print("Press '3' to filter a group from the list")
        print("Press '4' to undo the last operation")
        print("Press '5' to exit")
        print("\n")

    def start(self):

        # The start function that loops until the user exits
        while True:
            self.menu()
            op=input("Type your option: ")
            print("\n")
            if op=='1':
                id = input("Enter the student id: ")
                name = input("Enter the name of the student: ")
                group = input("Enter the group of the student: ")
                if name_check(name)==1 and group_check(id)==1 and group_check(group)==1:
                    i=0
                    ok=1
                    while i<len(self._services._list):      # Loop that checks to see if the student id is already used
                        if self._services._list[i].id==int(id):
                            ok=0
                        i+=1
                    if ok==0:
                        print("!ERROR! There is another student with inputted id in the list!\n")
                    else:
                        self._services.add_stud(Student(int(id),name,int(group)))
                else:
                    print("!ERROR! Invalid input!\n")
            elif op=='2':
                for i in self._services._list:
                    print(i)
            elif op=='3':
                val=input("Enter a group number: ")
                if group_check(val)==1:
                    self._services.filter_stud(val)
                else:
                    print("!ERROR! Invalid input!\n")
            elif op=='4':
                    self._services.undo()
            elif op=='5':
                exit()
            else:
                print("!ERROR! The inputted option is invalid!\n")
