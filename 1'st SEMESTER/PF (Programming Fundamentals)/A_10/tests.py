from services import *
from domain import *
from repository import *
from ui import *
from exceptions import *
import unittest

class Tests(unittest.TestCase):

    def test_generator(self):

        # Test for the generator
        pers = Repository()
        act = Repository()
        services = Services(pers, act)
        services.generator()

        self.assertEqual(len(services._personrep.get_items()), 20)
        self.assertEqual(len(services._actrep.get_items()), 20)

    def test_p_1(self):

        # Test for adding a person to the perosnrepo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        self.assertRaises(Exception, lambda: services.add_person('','',''))
        self.assertRaises(Exception, lambda: services.add_person('a', 'b', 'c'))
        self.assertRaises(Exception, lambda: services.add_person('1', '6', '0770169055'))
        self.assertRaises(Exception, lambda: services.add_person('1', 'nick', '07701690'))

        services.add_person('1','nico','0770169055')
        person1=services._personrep.get_items()[0]
        self.assertEqual(person1._id,'1')
        self.assertEqual(person1._name,'nico')
        self.assertEqual(person1._phone,'0770169055')

        self.assertRaises(Exception, lambda: services.add_person('1','aura','0716723456'))

        services.add_person('2','aura','0716723456')
        person2=services._personrep.get_items()[1]
        self.assertEqual(person2._id, '2')
        self.assertEqual(person2._name, 'aura')
        self.assertEqual(person2._phone, '0716723456')

    def test_p_2(self):

        # Test for removing a person from the personrepo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        services.add_person('1', 'nico', '0770169055')
        services.add_person('2', 'aura', '0716723456')

        self.assertRaises(Exception, lambda: services.remove_person('3'))
        self.assertRaises(Exception, lambda: services.remove_person(''))
        self.assertRaises(Exception, lambda: services.remove_person('a'))

        services.remove_person('1')
        self.assertEqual(len(services._personrep.get_items()), 1)
        services.remove_person('2')
        self.assertEqual(len(services._personrep.get_items()), 0)

    def test_p_3(self):

        # Test for updating the information of a person in the person repo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        services.add_person('1', 'nico', '0770169055')
        services.add_person('2', 'aura', '0716723456')

        self.assertRaises(Exception, lambda: services.replace_person('','',''))
        self.assertRaises(Exception, lambda: services.replace_person('a','1','b'))
        self.assertRaises(Exception, lambda: services.replace_person('3','air','0770169055'))

        services.replace_person('1','papi','0712345678')
        person1=services._personrep.get_items()[0]
        self.assertEqual(person1._id, '1')
        self.assertEqual(person1._name, 'papi')
        self.assertEqual(person1._phone, '0712345678')

    def test_p_5(self):

        # Test for adding an activity to the actrepo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        self.assertRaises(Exception, lambda: services.add_activity('','','','',''))
        self.assertRaises(Exception, lambda: services.add_activity('a', 'b', 'c', 'd', 'e'))
        self.assertRaises(Exception, lambda: services.add_activity('1', '2', 'a', 'b', '1'))
        self.assertRaises(Exception, lambda: services.add_activity('1', '1', '2', '29', '187'))

        services.add_person('1', 'nico', '0770169055')
        services.add_activity('1','1','12','2','code')
        activity1=services._actrep.get_items()[0]
        self.assertEqual(activity1._a_id, '1')
        self.assertEqual(activity1._p_id, ['1'])
        self.assertEqual(activity1._date, '12')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'code')

        self.assertRaises(Exception, lambda: services.add_activity('1', '1', '16', '1', 'code2'))

        services.add_activity('2', '1', '16', '21', 'code2')
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1'])
        self.assertEqual(activity2._date, '16')
        self.assertEqual(activity2._time, '21')
        self.assertEqual(activity2._desc, 'code2')

    def test_p_6(self):

        # Test for removing an activity from the actrepo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        self.assertRaises(Exception, lambda: services.remove_activity(''))
        self.assertRaises(Exception, lambda: services.remove_activity('a'))
        self.assertRaises(Exception, lambda: services.remove_activity('1'))

        services.add_person('1', 'nico', '0770169055')
        services.add_activity('1', '1', '12', '2', 'code')
        services.add_activity('2', '1', '16', '21', 'code2')
        services.remove_activity('1')
        self.assertEqual(len(services._actrep.get_items()),1)
        services.remove_activity('2')
        self.assertEqual(len(services._actrep.get_items()), 0)

    def test_p_7(self):

        # Test for updating an activity information in the actrepo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        services.add_person('1', 'nico', '0770169055')
        services.add_activity('1', '1', '12', '2', 'code')
        services.add_activity('2', '1', '16', '21', 'code2')

        self.assertRaises(Exception, lambda: services.replace_activity('','','',''))
        self.assertRaises(Exception, lambda: services.replace_activity('k','1','1','1'))
        self.assertRaises(Exception, lambda: services.replace_activity('a', 'b', 'c', 'd'))
        self.assertRaises(Exception, lambda: services.replace_activity('3', '12', '3', 'code'))

        services.replace_activity('1','1','1','code')
        activity1=services._actrep.get_items()[0]
        self.assertEqual(activity1._a_id, '1')
        self.assertEqual(activity1._p_id, ['1'])
        self.assertEqual(activity1._date, '1')
        self.assertEqual(activity1._time, '1')
        self.assertEqual(activity1._desc, 'code')
        services.replace_activity('2', '2', '2', 'cod2')
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1'])
        self.assertEqual(activity2._date, '2')
        self.assertEqual(activity2._time, '2')
        self.assertEqual(activity2._desc, 'cod2')

    def test_p_9(self):

        # Test for adding a person to an activity in the actrepo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        services.add_person('1', 'nico', '0770169055')
        services.add_person('2', 'aura', '0712345678')
        services.add_activity('1', '1', '12', '2', 'code')
        services.add_activity('2', '1', '16', '21', 'code2')

        self.assertRaises(Exception, lambda: services.add_person_to_activity('',''))
        self.assertRaises(Exception, lambda: services.add_person_to_activity('a', 'b'))
        self.assertRaises(Exception, lambda: services.add_person_to_activity('5', '10'))

        services.add_person_to_activity('2','2')
        activity1=services._actrep.get_items()[1]
        self.assertEqual(activity1._a_id, '2')
        self.assertEqual(activity1._p_id, ['1','2'])
        self.assertEqual(activity1._date, '16')
        self.assertEqual(activity1._time, '21')
        self.assertEqual(activity1._desc, 'code2')

    def test_p_10(self):

        # Test for removing a person from an activity in the actrepo
        pers = Repository()
        act = Repository()
        services = Services(pers, act)

        services.add_person('1', 'nico', '0770169055')
        services.add_person('2', 'aura', '0712345678')
        services.add_activity('1', '1', '12', '2', 'code')
        services.add_activity('2', '1', '16', '21', 'code2')
        services.add_person_to_activity('1', '2')

        self.assertRaises(Exception, lambda: services.remove_person_from_activity('',''))
        self.assertRaises(Exception, lambda: services.remove_person_from_activity('a', 'b'))
        self.assertRaises(Exception, lambda: services.remove_person_from_activity('5', '10'))
        self.assertRaises(Exception, lambda: services.remove_person_from_activity('1', '-1'))

        activity1 = services._actrep.get_items()[0]
        self.assertEqual(activity1._a_id, '1')
        self.assertEqual(activity1._p_id, ['1','2'])
        self.assertEqual(activity1._date, '12')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'code')

        services.add_person_to_activity('2','2')
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1','2'])
        self.assertEqual(activity2._date, '16')
        self.assertEqual(activity2._time, '21')
        self.assertEqual(activity2._desc, 'code2')

        services.remove_person_from_activity('2','1')

        activity1 = services._actrep.get_items()[1]
        self.assertEqual(activity1._a_id, '2')
        self.assertEqual(activity1._p_id, ['2'])
        self.assertEqual(activity1._date, '16')
        self.assertEqual(activity1._time, '21')
        self.assertEqual(activity1._desc, 'code2')

    def test_undo_redo(self):

        #Tests for the undo and redo operations
        pers = Repository()
        act = Repository()
        services = Services(pers, act)
        services.add_person('1', 'nico', '0770169055')
        services.add_person('2', 'aura', '0712345678')
        self.assertEqual(len(services._personrep.get_items()), 2)

        services.undo()
        self.assertEqual(len(services._personrep.get_items()),1)

        services.redo()
        self.assertEqual(len(services._personrep.get_items()), 2)

        services.remove_person('1')
        self.assertEqual(len(services._personrep.get_items()), 1)

        services.undo()
        self.assertEqual(len(services._personrep.get_items()), 2)

        services.redo()
        self.assertEqual(len(services._personrep.get_items()), 1)
        services.remove_person('2')
        self.assertEqual(len(services._personrep.get_items()), 0)

        services.add_person('1', 'nico', '0770169055')
        services.add_person('2', 'aura', '0712345678')
        self.assertEqual(len(services._personrep.get_items()), 2)

        services.replace_person('1', 'papi', '0712345678')
        person1 = services._personrep.get_items()[0]
        self.assertEqual(person1._id, '1')
        self.assertEqual(person1._name, 'papi')
        self.assertEqual(person1._phone, '0712345678')

        services.undo()
        person1 = services._personrep.get_items()[0]
        self.assertEqual(person1._id, '1')
        self.assertEqual(person1._name, 'nico')
        self.assertEqual(person1._phone, '0770169055')

        services.redo()
        person1 = services._personrep.get_items()[0]
        self.assertEqual(person1._id, '1')
        self.assertEqual(person1._name, 'papi')
        self.assertEqual(person1._phone, '0712345678')

        services.add_activity('1', '1', '12', '2', 'code')
        activity1 = services._actrep.get_items()[0]
        self.assertEqual(activity1._a_id, '1')
        self.assertEqual(activity1._p_id, ['1'])
        self.assertEqual(activity1._date, '12')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'code')
        services.add_activity('2', '1', '16', '21', 'code2')
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1'])
        self.assertEqual(activity2._date, '16')
        self.assertEqual(activity2._time, '21')
        self.assertEqual(activity2._desc, 'code2')

        services.undo()
        self.assertEqual(len(services._actrep.get_items()),1)

        services.undo()
        self.assertEqual(len(services._actrep.get_items()), 0)

        services.redo()
        self.assertEqual(len(services._actrep.get_items()), 1)

        services.redo()
        self.assertEqual(len(services._actrep.get_items()), 2)

        services.remove_activity('1')
        self.assertEqual(len(services._actrep.get_items()), 1)

        services.undo()
        self.assertEqual(len(services._actrep.get_items()), 2)
        services.redo()
        self.assertEqual(len(services._actrep.get_items()), 1)
        services.undo()

        services.remove_activity('1')
        services.remove_activity('2')
        self.assertEqual(len(services._actrep.get_items()), 0)

        services.undo()
        services.undo()
        self.assertEqual(len(services._actrep.get_items()), 2)

        services.remove_activity('1')
        services.remove_activity('2')
        services.add_activity('1', '1', '12', '2', 'code')
        services.add_activity('2', '1', '16', '21', 'code2')
        services.replace_activity('1', '1', '1', 'cod')
        activity1 = services._actrep.get_items()[0]
        self.assertEqual(activity1._a_id, '1')
        self.assertEqual(activity1._p_id, ['1'])
        self.assertEqual(activity1._date, '1')
        self.assertEqual(activity1._time, '1')
        self.assertEqual(activity1._desc, 'cod')
        services.replace_activity('2', '2', '2', 'cod2')
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1'])
        self.assertEqual(activity2._date, '2')
        self.assertEqual(activity2._time, '2')
        self.assertEqual(activity2._desc, 'cod2')

        services.undo()
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1'])
        self.assertEqual(activity2._date, '16')
        self.assertEqual(activity2._time, '21')
        self.assertEqual(activity2._desc, 'code2')

        services.undo()
        activity1 = services._actrep.get_items()[0]
        self.assertEqual(activity1._a_id, '1')
        self.assertEqual(activity1._p_id, ['1'])
        self.assertEqual(activity1._date, '12')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'code')

        services.redo()
        activity1 = services._actrep.get_items()[0]
        self.assertEqual(activity1._a_id, '1')
        self.assertEqual(activity1._p_id, ['1'])
        self.assertEqual(activity1._date, '1')
        self.assertEqual(activity1._time, '1')
        self.assertEqual(activity1._desc, 'cod')

        services.redo()
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1'])
        self.assertEqual(activity2._date, '2')
        self.assertEqual(activity2._time, '2')
        self.assertEqual(activity2._desc, 'cod2')

        services.add_person_to_activity('2', '2')
        activity1 = services._actrep.get_items()[1]
        self.assertEqual(activity1._a_id, '2')
        self.assertEqual(activity1._p_id, ['1', '2'])
        self.assertEqual(activity1._date, '2')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'cod2')

        services.undo()
        activity2 = services._actrep.get_items()[1]
        self.assertEqual(activity2._a_id, '2')
        self.assertEqual(activity2._p_id, ['1'])
        self.assertEqual(activity2._date, '2')
        self.assertEqual(activity2._time, '2')
        self.assertEqual(activity2._desc, 'cod2')

        services.redo()
        activity1 = services._actrep.get_items()[1]
        self.assertEqual(activity1._a_id, '2')
        self.assertEqual(activity1._p_id, ['1', '2'])
        self.assertEqual(activity1._date, '2')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'cod2')

        services.remove_person_from_activity('2', '1')
        activity1 = services._actrep.get_items()[1]
        self.assertEqual(activity1._a_id, '2')
        self.assertEqual(activity1._p_id, ['2'])
        self.assertEqual(activity1._date, '2')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'cod2')

        services.undo()
        activity1 = services._actrep.get_items()[1]
        self.assertEqual(activity1._a_id, '2')
        self.assertEqual(activity1._p_id, ['1', '2'])
        self.assertEqual(activity1._date, '2')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'cod2')

        services.redo()
        activity1 = services._actrep.get_items()[1]
        self.assertEqual(activity1._a_id, '2')
        self.assertEqual(activity1._p_id, ['2'])
        self.assertEqual(activity1._date, '2')
        self.assertEqual(activity1._time, '2')
        self.assertEqual(activity1._desc, 'cod2')
