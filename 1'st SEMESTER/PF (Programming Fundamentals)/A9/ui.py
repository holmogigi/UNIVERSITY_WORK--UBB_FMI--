from src.domain import Person
from src.domain import Activity
from src.repository import *
from src.services import *
from src.exceptions import *
from src.undo_redo import *
from src.tests import *
import unittest

class UI():

    def __init__(self, service):
        self._operation = service

    def menu(self):
        print('\n')
        print("Press '1' to add a person to the list")
        print("Press '2' to remove a person from the list")
        print("Press '3' to update the information of a person")
        print("Press '4' to list the persons")
        print()
        print("Press '5' to add an activity to the list")
        print("Press '6' to remove an activity from the list")
        print("Press '7' to update an activity in the list")
        print("Press '8' to list the activities")
        print()
        print("Press '9' to add a person to an activity")
        print("Press '10' to remove a person from an actiivty")
        print("Press '11' to list all activities with the given id")
        print("Press '12' to list all activities that a person does")
        print()
        print("Press '13' to list all activities from a given day in cronological order")
        print("Press '14' to list all days sorted by free time")
        print("Press '15' to search for a person")
        print("Press '16' to search for an activity")
        print()
        print("Type 'undo' to undo the last operation")
        print("Type 'redo' to redo the last operation")
        print()
        print("Type 'test' to test all serivce functions")
        print()
        print("Type 'exit' to exit")
        print("\n")

    def run(self):
        while True:
            try:
                self.menu()
                user=input("Type your choice: ")
                print()
                if user=='1':
                    id = input("Enter the id: ")
                    name = input("Enter the name: ")
                    phone = input("Enter the phone number: ")
                    self._operation.add_person(id, name, phone)
                elif user=='2':
                    id=input("Enter the id of the person you want to remove: ")
                    self._operation.remove_person(id)
                elif user=='3':
                    id=input("Enter the id of the person that you want to update: ")
                    name = input("Enter the new name of the person: ")
                    phone = input("Enter the new phone number of the person: ")
                    self._operation.replace_person(id, name, phone)
                elif user=='4':
                    self._operation.print_persons()
                elif user=='5':
                    act_id=input("Enter the activity id: ")
                    p_id=input("Enter the person id that does this activity: ")
                    date=input("Enter the date: ")
                    time=input("Enter the time: ")
                    desc=input("Enter the description: ")
                    self._operation.add_activity(act_id, p_id, date, time, desc)
                elif user=='6':
                    id=input("Enter the activity id that you want to remove: ")
                    self._operation.remove_activity(id)
                elif user=='7':
                    id=input("Enter the id of the activity you want to update: ")
                    date = input("Enter the date you want the repalce the activiy with: ")
                    time = input("Enter the time you want to replace the activity with: ")
                    desc = input("Enter the description you want the replace the activity with: ")
                    self._operation.replace_activity(id, date, time, desc)
                elif user=='8':
                    self._operation.print_activities()
                elif user=='9':
                    id=input("Enter the activity id you want to add the person to: ")
                    person = input("Enter the id of the person you want to add to the activity: ")
                    self._operation.add_person_to_activity(id, person)
                elif user=='10':
                    id=input("Enter the id of the activity you want to remove the person from: ")
                    person = input("Enter the person id you want to remove: ")
                    self._operation.remove_person_from_activity(id, person)
                elif user=='11':
                    id=input("Enter the id of the activity you want to list: ")
                    self._operation.list_all_activities_with_id(id)
                elif user=='12':
                    person=input("Enter the id of the person you want to list all activities of: ")
                    self._operation.list_all_activities_of_person(person)
                elif user=='13':
                    date=input("Enter the day you want to see: ")
                    self._operation.function_listing_all_activities_of_given_day(date)
                elif user=='14':
                    self._operation.p_14()
                elif user=='15':
                    search=input("Type the name/phone number of the person you want to search: ")
                    self._operation.p_15(search)
                elif user=='16':
                    search=input("Type the date/time/description of the activity you want to search for: ")
                    self._operation.p_16(search)
                elif user=='undo':
                    self._operation.undo()
                elif user=='redo':
                    self._operation.redo()
                elif user=='test':
                    unittest.main(module="tests",exit=False)
                elif user=='exit':
                    exit()
                else:
                    raise InvalidInputError
            except InvalidInputError:
                print("!ERROR! The input is invalid!")
            except IdNotFoundError:
                print("!ERROR! This id is not found in the list!")
            except SameIdError:
                print("!ERROR! This id is already found in the list!")
            except EmptyListError:
                print("!ERROR! The list is empty!")
            except BusyPersonError:
                print("!ERROR! The person is already doing something at this time!")
            except NotDoingAnyActivitiesError:
                print("!ERROR! The person is not doing any activities!")
            except NotDoingActivityError:
                print("!ERROR! This person is not doing this activity!")
            except NoActivityInThisDayError:
                print("!ERROR! There are no activities in the given day!")
            except PhoneIdSameError:
                print("!ERROR! This id/phone number is already found in the list!")
            except NoUndoRedoError:
                print("!ERROR! There is no operation to undo/redo!")
            except SearchNotFoundError:
                print("!ERROR! Nothing was found during the search!")