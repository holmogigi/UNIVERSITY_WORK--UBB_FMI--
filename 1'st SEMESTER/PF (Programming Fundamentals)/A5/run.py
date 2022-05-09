from ui import *
from services import Services
import random

services=Services()
ui=Ui(services)

# Creating a list with names from which we are going to randomlly choose 10
name_list=['Oliver Jake','Jack Connor','Harry Callum','Jacob Black','Charlie Kyle','Thomas Joe','George Reece',
           'Oscar Rhys','James Charlie','William Damian','Noah James','Liam	John','Jacob Michael','William William'
            ,'Ethan	David','David Laid','Jeff Said','Lex Little','Michael Richard','Alexander Joseph',
           'James Charles','Daniel Thomas','Calin Pop','Alexandru Gherman','Dragos Tarta','Marc Borleanu',
           'Razvan Cordea','Andrei Filip','Andrei Tara','Vlad Stoicescu','Andrei Kollar','Alexandru Madaras',
           'Alex Dulfu','Alexandru Covaciu','Angelo Silaghi','David Pal','Gabii Muresan','Mahdi Momeni',
           'Mark Szabo','Muresan Rares','Rus Cezar','Tudor Boitor','Tudor Iakkel','Tudor Poran','Vlad Costin',
           'Vlad Zamuruev','Ali Cerrahoglu','Aziz Shavershian','Bladee','EccoTwoK']

# Adding the randomized values to the list
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))
services.add_stud(Student(random.randint(1,99999),name_list[random.randint(0,49)],random.randint(1,10)))


def test_name_check():

    # Tests the name check function
    a='2'
    b='abc'
    c='12h'

    assert name_check(a)==0
    assert name_check(b)==1
    assert name_check(c)==1

def test_group_check():

    # Tests the group check function
    a='-1'
    b='ABC'
    c='32'

    assert group_check(a)==0
    assert group_check(b)==0
    assert group_check(c)==1

def test_filter_stud(stud=Services()):

    # Tests the filtering function
    stud._list = [Student(1,'nico',123),Student(2,'nick',321),Student(3,'LOL',123)]
    stud.filter_stud('123')
    assert len(stud._list)==1
    stud.filter_stud('3210')
    assert len(stud._list)==1

def test_add_stud(stud=Services()):

    # Tests the add function
    stud._list =[]
    stud.add_stud(Student(1,'i',3))
    assert len(stud._list)==1 \
        and stud._list[0].id==1 \
        and stud._list[0].name=='i'\
        and stud._list[0].group==3

def run_tests():

    # Runs the tests
    stud=Services()
    test_name_check()
    test_group_check()
    test_filter_stud(stud)
    test_add_stud(stud)

# Starting the app
run_tests()
ui.start()