import pickle
from exceptions import *
from iterable import *

class Repository:
    def __init__(self):
        self._data = Iterable()

    def add(self, object):
        if object in self._data:
            raise SameIdError
        self._data.append(object)

    def remove(self, object):
        if object not in self._data:
            raise IdNotFoundError
        self._data.remove(object)

    def replace(self, object):
        if object not in self._data:
            raise IdNotFoundError
        index = self._data.index(object)
        self._data[index] = object

    def __str__(self):
        to_str = ""
        for obj in self._data:
            to_str += str(obj)
        return to_str

    def get_object(self, object):
        if object not in self._data:
            return None
        position = self._data.index(object)
        return self._data[position]

    def get_items(self):
        return self._data.get_object()

class FileRepository(Repository):
    def __init__(self, filename, write_function, read_function):
        super().__init__()
        self.__write = write_function
        self.__read = read_function
        self.__filename = filename
        with open(self.__filename, "a"):
            pass

    def __read_from_file(self):
        self._data = []
        with open(self.__filename, "r") as file:
            lines = file.readlines()
            for line in lines:
                line = line.strip()
                if line != '':
                    obj = self.__read(line)
                    self._data.append(obj)

    def __write_to_file(self):
        with open(self.__filename, "w") as file:
            for obj in self._data:
                line = self.__write(obj) + "\n"
                file.write(line)
        self._data = []

    def add(self, object):
        self.__read_from_file()
        Repository.add(self, object)
        self.__write_to_file()

    def remove(self, object):
        self.__read_from_file()
        Repository.remove(self, object)
        self.__write_to_file()

    def replace(self, object):
        self.__read_from_file()
        Repository.replace(self, object)
        self.__write_to_file()

    def __str__(self):
        self.__read_from_file()
        to_str = Repository.__str__(self)
        self.__write_to_file()
        return to_str

    def get_items(self):
        self.__read_from_file()
        all_items = self._data.copy()
        self.__write_to_file()
        return all_items

    def get_object(self, object):
        self.__read_from_file()
        data = self._data.copy()
        self.__write_to_file()
        if object not in data:
            return None
        position = data.index(object)
        return data[position]

class BinaryRepository(Repository):
    def __init__(self, filename):
        super().__init__()
        self.__filename = filename
        with open(self.__filename, "a"):
            pass

    def __read_from_file(self):
        self._data = []
        try:
            with open(self.__filename, "rb") as file:
                self._data = pickle.load(file)
        except EOFError:
            pass

    def __write_to_file(self):
        with open(self.__filename, "wb") as file:
            pickle.dump(self._data, file)
        self._data = []

    def add(self, object):
        self.__read_from_file()
        Repository.add(self, object)
        self.__write_to_file()

    def remove(self, object):
        self.__read_from_file()
        Repository.remove(self, object)
        self.__write_to_file()

    def replace(self, object):
        self.__read_from_file()
        Repository.replace(self, object)
        self.__write_to_file()

    def __str__(self):
        self.__read_from_file()
        to_str = Repository.__str__(self)
        self.__write_to_file()
        return to_str

    def get_items(self):
        self.__read_from_file()
        all_items = self._data.copy()
        self.__write_to_file()
        return all_items

    def get_object(self, object):
        self.__read_from_file()
        data = self._data.copy()
        self.__write_to_file()
        if object not in data:
            return None
        position = data.index(object)
        return data[position]