class Person:

    def __init__(self,id,name,phone):
        self._id=id
        self._name=name
        self._phone=phone

    def __repr__(self):
        return "Person ID: " +str(self._id) + " || Name: " +str(self._name) + " || Phone number: " +str(self._phone)+str("\n")

    def get_id(self):
        return self._id

    def get_name(self):
        return self._name

    def get_phone(self):
        return self._phone

    def set_id(self,idd):
        self._id=idd

    def set_name(self,namee):
        self._name=namee

    def set_phone(self,phonee):
        self._phone=phonee

    def __eq__(self, other):
        if not isinstance(other, Person):
            return False
        return other._id == self._id

    def write(self):
        return f"{self._id};{self._name};{self._phone}"

    @staticmethod
    def read(string):
        tokens = string.split(";")
        if len(tokens) != 3:
            return None
        return Person(tokens[0], tokens[1], tokens[2])


class Activity:

    def __init__(self,a_id,p_id,date,time,desc):
        self._a_id=a_id
        self._p_id=p_id
        self._date=date
        self._time=time
        self._desc=desc

    def __repr__(self):
        return "Activity ID: " + str(self._a_id) + " || Person ID: " + str(self._p_id) + " || Date: " + str(self._date)\
               + " || Time: " + str(self._time) + " || Description: " + str(self._desc) + str("\n")

    def get_a_id(self):
        return  self._a_id

    def get_p_id(self):
        return self._p_id

    def get_date(self):
        return self._date

    def get_time(self):
        return self._time

    def get_desc(self):
        return self._desc

    def set_a_id(self,a_idd):
        self._a_id=a_idd

    def set_p_id(self,p_idd):
        self._p_id=p_idd

    def set_date(self,datee):
        self._date=datee

    def set_time(self,timee):
        self._time=timee

    def sef_desc(self,descc):
        self._desc=descc

    def add_p_id(self, p_idd):
        self._p_id.append(p_idd)

    def remove_p_id(self, p_idd):
        self._p_id.remove(p_idd)

    def __eq__(self, other):
        if not isinstance(other, Activity):
            return False
        return other._a_id == self._a_id

    def write(self):
        list_str = "["
        for i in range(len(self._p_id)):
            list_str += self._p_id[i]
            if i != len(self._p_id) - 1:
                list_str += ","
        list_str += "]"
        return f"{self._a_id};{list_str};{self._date};{self._time};{self._desc}"

    @staticmethod
    def read(string):
        tokens = string.split(";")
        if len(tokens) != 5:
            return None
        pid_string = tokens[1]
        pid_full_str = pid_string[1:-1]
        all_pid = pid_full_str.split(',')
        pid_tokens = []
        for pid in all_pid:
            pid_tokens.append(pid)
        return Activity(tokens[0], pid_tokens, tokens[2], tokens[3], tokens[4])