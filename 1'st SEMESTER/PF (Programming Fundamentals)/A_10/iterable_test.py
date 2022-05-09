import unittest
from iterable import *

class iterable_test(unittest.TestCase):

    def test(self):
        it=Iterable()

        it.append(12)
        self.assertEqual(it,[12])
        it[1]=14
        self.assertEqual(it,[12,14])
        it[0]=7
        self.assertEqual(it,[7,14])
        it[2]=0
        it[3]=12
        self.assertEqual(it,[7,14,0,12])
        del it[0]
        self.assertEqual(it,[7,14,12])
        self.assertEqual(len(it),3)
        it.append(4)
        it.append(8)
        self.assertEqual(len(it),5)
        self.assertEqual(it[0],7)
        self.assertEqual(it[1], 14)
        self.assertEqual(it[2], 12)
        self.assertEqual(it[3], 4)
        self.assertEqual(it[4], 8)
        self.assertEqual(it,[7,14,12,4,8])
