class Iterable:
    def __init__(self):
        self.__data = list()

    def __setitem__(self, key, value):
        if key < len(self.__data):
            self.__data[key]=value
        elif key==len(self.__data):
            self.__data.append(value)
        else:
            raise IndexError

    def __getitem__(self, item):
        return self.__data[item]

    def __delitem__(self, key):
        self.__data.remove(key)

    def __next__(self):
        if self.__iterator < len(self.__data)-1:
            self.__iterator+=1
            return self.__data[self.__iterator]
        else:
            raise StopIteration

    def __iter__(self):
        self.__iterator=-1
        return self

    def __len__(self):
        return len(self.__data)

    def __next__(self):
        if self.__iterator < len(self.__data)-1:
            self.__iterator+=1
            return self.__data[self.__iterator]
        else:
            raise StopIteration

    def __str__(self):
        return str(self.get_object())

    def append(self,value):
        self.__setitem__(len(self.__data),value)

    def remove(self,key):
        self.__delitem__(key)

    def get_object(self):
        return self.__data

    def index(self, object):
        for searched_index in range (0, len(self.__data)):
            if self.__data[searched_index] == object:
                return searched_index
        return -1

    @staticmethod
    def gnome_sort(listt, function):
        i = 0
        len = len(listt)
        if length == 1:
            return None
        elif length > 1:
            while i < len:
                if i == 0:
                    i = i + 1
                if function(listt[i], listt[i - 1]) is True:
                    i = i + 1
                else:
                    listt[i], listt[i - 1] = listt[i - 1], listt[i]
                    i = i - 1
        else:
            raise IndexError("Can't sort empty list")

    @staticmethod
    def filter(data, filter_function):
        filtered_list=[]
        for value in data:
            if filter_function(value):
                filtered_list.append(value)
        return filtered_list

