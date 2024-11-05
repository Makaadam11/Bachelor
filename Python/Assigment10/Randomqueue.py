import random
from collections import deque
import unittest

class RandomQueue:

	def __init__(self,capacity):
		self.capacity = capacity
		self.items = deque();
		self.QueueSize = 0;

	def insert(self, item): 
		random_position = random.randint(0, 1);
		if random_position == 1:
			self.items.append(item); 
		else:
			self.items.appendleft(item); 
		self.QueueSize+=1

	def remove(self):    
		if not self.is_empty():
			random_position = random.randint(0, 1);
			self.QueueSize-=1
			if random_position == 1:
				return self.items.pop() 
			else:
				return self.items.popleft() 
		else:
			raise QueueEmpty("Empty RandomQueue")


	def is_empty(self): 
		return self.QueueSize == 0

	def is_full(self): 
		return self.QueueSize == self.capacity
 
class QueueEmpty(Exception):
	def __init__(self, value):
		self.value = value

	def __str__(self):
		return str(self.value)

class RandomQueueTest(unittest.TestCase):
	def setUp(self):
		self.RandomQueue1 = RandomQueue(0)
		self.RandomQueue2 = RandomQueue(10)
		for item in [6,5,6,2,3,6]:
			self.RandomQueue2.insert(item)

	def testRemove(self):
		self.assertEqual(self.RandomQueue2.remove() in [6,5,6,2,3,6], True)
		with self.assertRaises(QueueEmpty):
			self.RandomQueue2.remove()
			self.RandomQueue1.remove()


if __name__ == '__main__':
	unittest.main()	











