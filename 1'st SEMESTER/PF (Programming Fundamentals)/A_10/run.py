from domain import *
from repository import *
from exceptions import *
from services import *
from ui import *
from tests import *

def set_up_repository():
    with open("settings.properties", "r") as file:
        lines = file.readlines()
        if len(lines) != 3:
            raise Exception("invalid file")
        repo_type = lines[0].split("=")[1][:-1]
        if repo_type == "inmemory":
            return Repository(), Repository()
        person_file = lines[1].split("=")[1][:-1]
        activity_file = lines[2].split("=")[1]
        if repo_type == "file":
            return FileRepository(person_file, Person.write, Person.read), FileRepository(activity_file, Activity.write, Activity.read)
        if repo_type == "binary":
            return BinaryRepository(person_file), BinaryRepository(activity_file)
        raise Exception("invalid type")

pers, act = set_up_repository()
services = Services(pers, act)
ui = UI(services)
ui.run()