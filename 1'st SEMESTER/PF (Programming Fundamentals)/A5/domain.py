class Student:

    def __init__(self,id,name,group):
        self.id=id
        self.name=name
        self.group=group

    def __repr__(self):
        return "Student ID: " + str(self.id) + " || Student name: " + str(self.name) + " || Student group: " + str(self.group)

    def id(self):
        return self.id

    def name(self):
        return self.name

    def group(self):
        return self.group

    def group(self,groupp):
        self.group=int(groupp)

    def id(self,idd):
        self.id=int(idd)

    def name(self,namee):
        self.name=namee


