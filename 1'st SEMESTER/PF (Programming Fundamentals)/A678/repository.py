from src.exceptions import *

class Repository:
    def __init__(self):
        self.__data = []

    def add(self, object):
        if object in self.__data:
            raise SameIdError
        self.__data.append(object)

    def remove(self, object):
        if object not in self.__data:
            raise IdNotFoundError
        self.__data.remove(object)

    def replace(self, object):
        if object not in self.__data:
            raise IdNotFoundError
        index = self.__data.index(object)
        self.__data[index] = object

    def __str__(self):
        to_str = ""
        for obj in self.__data:
            to_str += str(obj)
        return to_str

    def get_object(self, object):
        if object not in self.__data:
            return None
        position = self.__data.index(object)
        return self.__data[position]

    def get_items(self):
        return self.__data