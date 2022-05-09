from src.domain import Person
from src.domain import Activity
from src.repository import *
from src.exceptions import *
from src.ui import *
from src.validator import *
import random
from src.undo_redo import UndoStack

# Lists used for the random generator
persons=['Oliver','Jake','Jack','Connor','Harry','Callum','Jacob','Black','Charlie','Kyle','Thomas','Joe','George',
         'Reece','Oscar','Rhys','James','Charlie','William','Damian','Noah','Lex','Little','Jeff','Said','Calin',
         'Pop','Alexandru','Gherman','Dragos','Tarta','Marc','Borleanu','Razvan','Cordea','Andrei','Filip','Andrei',
         'Tara','Vlad','Stoicescu','Kollar','Madaras','Dulfu','Angelo','Silaghi','David','Pal','Gabii','Muresan','Mahdi'
        ,'Momeni','Mark','Szabo','Muresan','Rares','Rus','Cezar','Tudor','Boitor','Iakkel','Poran','Costin','Zamuruev',
         'Ali','Cerrahoglu','Aziz','Shavershian','Bladee','EccoTwoK','Windy',"Vin’nyla",'Velvette','Velvette','Anomaly'
         ,'Wiatt','Tokyo','Tenysi','Sincere','Aura','Precise','Precise','Kairo','Brayan','Emma','Ava','Charlotte',
         'Sophia','Amelia','Isabella','Mia','Evelyn','Harper','Camila','Ivy','Maya','Amy','Ariana','Samantha','Eva',
         'Rose','Gabi']

descs=['walking','music','photos','reading','gaming','movie','journal','puzzle','coloring','gardening','friends','yoga'
       ,'gym','swiming','singing','dancing','market','instrument','crafting','manicure','pedicure','cooking','jogging',
       'running','museum','picnic','meeting','hiking','massage','voulenteer','library','park','stargazing','climbing',
       'gambling','eating','dinner','lunch','breakfast','school','kindergarten','college','university','homework',
       'assigment','football','handball','basketball']

class Services():

    def __init__(self,personrep,actrep):
        self._personrep = personrep
        self._actrep = actrep
        self._undos = UndoStack()
        self._redos = UndoStack()

    def generator(self):

        # Function that randomly generates 20 persons and activities and puts them in the repo
        i = 1
        x = '07'
        while i <= 20:
            self._personrep.add(Person(str(i), persons[random.randint(0, 101)], str(x + str(random.randint(10000000, 99999999)))))
            self._actrep.add(Activity(str(i), [str(i)], str(random.randint(1, 31)), str(random.randint(1, 24)),descs[random.randint(0, 47)]))
            i += 1

    def add_person(self, id, name, phone):

        # Function that adds a person to the list
        person = Person(id, name, phone)
        Validator.validate_person(person)
        self._personrep.add(Person(id, name, phone))
        undo_action = UndoAction(person, self._personrep.remove, person, self._personrep.add)
        self._undos.push_stack(undo_action)
        self._redos.clear_stack()

    def remove_person(self, id):

        # Function that removes a person from the list based on id
        person = Person(id, "Nico", "0774004059")
        Validator.validate_person(person)
        deleted_person = self._personrep.get_object(person)
        self._personrep.remove(person)

        first_undo_action = UndoAction(deleted_person, self._personrep.add, deleted_person, self._personrep.remove)
        list_of_undos = [first_undo_action]
        for activity in self._actrep.get_items():
            if id in activity.get_p_id():
                new_list_of_person = activity.get_p_id().copy()
                new_list_of_person.remove(id)
                new_activity = Activity(activity.get_a_id(), new_list_of_person, activity.get_date(),
                                        activity.get_time(),
                                        activity.get_desc())
                self._actrep.replace(new_activity)
                undo_action = UndoAction(activity, self._actrep.replace, new_activity, self._actrep.replace)
                list_of_undos.append(undo_action)
        complex_undo = ComplexUndoAction(list_of_undos)
        self._undos.push_stack(complex_undo)
        self._redos.clear_stack()

    def replace_person(self, id, name, phone):

        # Function that updates the info of a person
        person = Person(id, name, phone)
        Validator.validate_person(person)
        replaced_person = self._personrep.get_object(person)
        self._personrep.replace(Person(id, name, phone))
        undo_action = UndoAction(replaced_person, self._personrep.replace, person, self._personrep.replace)
        self._undos.push_stack(undo_action)
        self._redos.clear_stack()

    def print_persons(self):

        # Function that lists the persons
        print(self._personrep)

    def check_if_person_overlaps(self, person_id, date, hour):

        # Function that chceks if a person is doing something else at a given time
        for activity in self._actrep.get_items():
            if activity.get_time() == hour and activity.get_date() == date and person_id in activity.get_p_id():
                return True
        return False


    def add_activity(self, act_id, p_id, date, time, desc):

        # Function that adds an activity to the list
        activity = Activity(act_id, [p_id], date, time, desc)
        Validator.validate_activity(activity)
        if self.check_if_person_overlaps(p_id, date, time):
            raise BusyPersonError()
        self._actrep.add(activity)
        undo_action = UndoAction(activity, self._actrep.remove, activity, self._actrep.add)
        self._undos.push_stack(undo_action)
        self._redos.clear_stack()

    def remove_activity(self, id):

        # Function that removes an activity from the actrepo based on id
        activity = Activity(id, "1", "6", "8", "handball")
        Validator.validate_activity(activity)
        deleted_activity = self._actrep.get_object(activity)
        self._actrep.remove(activity)
        undo_action = UndoAction(deleted_activity, self._actrep.add, deleted_activity, self._actrep.remove)
        self._undos.push_stack(undo_action)
        self._redos.clear_stack()

    def replace_activity(self, id, date, time, desc):

        # Functions that updates an activity infomration based on id
        activity = Activity(id, [], date, time, desc)
        Validator.validate_activity(activity)
        replaced_activity = self._actrep.get_object(activity)
        if replaced_activity is not None:
            actt = replaced_activity.get_p_id().copy()
            activity.set_p_id(actt)
        self._actrep.replace(activity)
        undo_action = UndoAction(replaced_activity, self._actrep.replace, activity, self._actrep.replace)
        self._undos.push_stack(undo_action)
        self._redos.clear_stack()

    def print_activities(self):

        # Function that prints the activity repo list
        print(self._actrep)

    def add_person_to_activity(self, id, person):

        # Function that adds a person to an activity from the actrepo
        dummy = Activity(id, "", "", "", "")
        activity = self._actrep.get_object(dummy)
        if activity is None:
            raise IdNotFoundError()

        dummy = Person(person, "", "")
        PPerson = self._personrep.get_object(dummy)
        if PPerson is None:
            raise IdNotFoundError()

        if self.check_if_person_overlaps(person, activity.get_date(), activity.get_time()):
            raise BusyPersonError()
        new_list_of_person = activity.get_p_id().copy()
        new_list_of_person.append(PPerson.get_id())
        new_activity = Activity(activity.get_a_id(), new_list_of_person, activity.get_date(), activity.get_time(), activity.get_desc())
        self._actrep.replace(new_activity)
        undo_action = UndoAction(activity, self._actrep.replace, new_activity, self._actrep.replace)
        self._undos.push_stack(undo_action)
        self._redos.clear_stack()

    def remove_person_from_activity(self, id, person):

        # Function that removes a person from an activity
        dummy = Activity(id, "", "", "", "")
        activity = self._actrep.get_object(dummy)
        if activity is None:
            raise IdNotFoundError()

        dummy = Person(person, "", "")
        person = self._personrep.get_object(dummy)
        if person is None:
            raise IdNotFoundError()

        new_list_of_person = activity.get_p_id().copy()
        if person.get_id() not in new_list_of_person:
            raise IdNotFoundError()

        new_list_of_person.remove(person.get_id())
        new_activity = Activity(activity.get_a_id(), new_list_of_person, activity.get_date(), activity.get_time(),
                                activity.get_desc())
        self._actrep.replace(new_activity)
        undo_action = UndoAction(activity, self._actrep.replace, new_activity, self._actrep.replace)
        self._undos.push_stack(undo_action)
        self._redos.clear_stack()

    def list_all_activities_with_id(self, id):

        # Function that lists all activities with the given id
        for activity in self._actrep.get_items():
            if activity.get_a_id() == id:
                print(activity)

    def list_all_activities_of_person(self, person):

        # Function that lists all activities that a person does
        for activity in self._actrep.get_items():
            if person in activity.get_p_id():
                print(activity)

    def function_listing_all_activities_of_given_day(self, day):

        # Function that lists all activities from a given day in cronological order
        todays_activities = []
        for activity in self._actrep.get_items():
            if activity.get_date() == day:
                todays_activities.append(activity)
        todays_activities=sorted(todays_activities,key=lambda e:int(e._time))
        if len(todays_activities)!=0:
            print(todays_activities)
        else:
            raise EmptyListError

    def p_14(self):

        # Function that lists all days in which activities take place sorted by how much free time there is left in them
        hours=[-1,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24]
        i=0
        for activity in self._actrep.get_items():
            hours[int(activity.get_date())]-=1
            i+=1
        time=23
        while time>=0:
            i=1
            while i<=31:
                if hours[i]==time:
                    print("Day:",i,"  Free time:",hours[i],' hours')
                i+=1
            time-=1

    def p_15(self,search):

        # Function that searches for a person in the personrepo
        if search.isalpha():
            for person in self._personrep.get_items():
                name = person.get_name().lower()
                match = search.lower()
                if name.find(match) != -1:
                    print(person)
        else:
            for person in self._personrep.get_items():
                number = person.get_phone()
                if number.find(search) != -1 or search.find(number) != -1:
                    print(person)

    def p_16(self,search):

        # Function that searches for an activity in the actrepo
        if search.isalpha():
            for activity in self._actrep.get_items():
                description = activity.get_desc().lower()
                match = search.lower()
                if description.find(match) != -1:
                    print(activity)
        else:
            for activity in self._actrep.get_items():
                date = activity.get_date()
                time = activity.get_time()
                if search == date or search == time:
                    print(activity)

    def undo(self):

        # Function that does the undo functionality
        current_undo = self._undos.pop_stack()
        current_undo.undo()
        self._redos.push_stack(current_undo)

    def redo(self):

        # Function that does the redo functionality
        current_redo = self._redos.pop_stack()
        current_redo.redo()
        self._undos.push_stack(current_redo)