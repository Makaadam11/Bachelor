class Stack:
    def __init__(self, size):
        self.stack = []
        self.size = size
        self.present = [False for _ in range(size)]  # Tablica przechowująca informację, czy dana liczba znajduje się na stosie

    def push(self, value):
        if value < 0 or value >= self.size:  # Ignoruj wartości spoza zakresu 0-size-1
            return
        if not self.present[value]:  # Jeśli wartość nie znajduje się na stosie, dodaj ją
            self.stack.append(value)
            self.present[value] = True

    def pop(self):
        if not self.stack:  # Jeśli stos jest pusty, zwróć None
            return None
        value = self.stack.pop()
        self.present[value] = False
        return value

import unittest

class TestStack(unittest.TestCase):
    def setUp(self):
        self.stack = Stack(5)

    def test_push(self):
        self.stack.push(3)
        self.assertEqual(self.stack.stack, [3])
        self.stack.push(2)
        self.assertEqual(self.stack.stack, [3, 2])
        self.stack.push(3)  # Powtórzenie wartości, ignorowane
        self.assertEqual(self.stack.stack, [3, 2])
        self.stack.push(5)  # Wartość spoza zakresu 0-4, ignorowane
        self.assertEqual(self.stack.stack, [3, 2])
        self.stack.push(-1)  # Wartość spoza zakresu 0-4, ignorowane
        self.assertEqual(self.stack.stack, [3, 2])

    def test_pop(self):
        self.stack.push(3)
        self.stack.push(2)
        value = self.stack.pop()
        self.assertEqual(value, 2)
        self.assertEqual(self.stack.stack, [3])
        value = self.stack.pop()
       
if __name__ == '__main__':
	unittest.main()