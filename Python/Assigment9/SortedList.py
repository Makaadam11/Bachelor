
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class SortedList:
    def __init__(self):
        self.head = None
        self.length = 0

    def is_empty(self):
        return self.head is None

    def insert(self, node):
        # Jeśli lista jest pusta, dodaj nowy element jako head
        if self.is_empty():
            self.head = node
            self.length += 1
            return

        # Przechodź przez listę i porównuj wartości elementów
        current = self.head
        while current is not None:
            # Jeśli wartość nowego elementu jest mniejsza niż wartość elementu na liście, dodaj nowy element przed elementem na liście
            if node.value < current.value:
                node.next = current
                if current == self.head:  # Jeśli current jest head, ustaw nowy element jako head
                    self.head = node
                else:  # W przeciwnym razie, ustaw nowy element jako poprzedni element
                    previous.next = node
                self.length += 1
                return
            previous = current
            current = current.next

        # Jeśli nie znaleziono odpowiedniego miejsca dla nowego elementu, dodaj go na końcu listy
        previous.next = node
        self.length += 1

    def remove(self):
        if self.is_empty():
            return None

        removed = self.head
        self.head = self.head.next
        self.length -= 1
        return removed

    def merge(self, other):
        if self.is_empty():
            self.head = other.head
            self.length = other.length
            other.head = None
            other.length = 0
            return

        if other.is_empty():
            return

        # Ustaw head nowej listy jako element o największej wartości z dwóch list
        if self.head.value < other.head.value:
            merged = SortedList()
            merged.head = other.head
            current_other = other.head.next
            current_merged = merged.head


import unittest

class TestSortedList(unittest.TestCase):
    def setUp(self):
        self.sorted_list = SortedList()

    def test_is_empty(self):
        self.assertTrue(self.sorted_list.is_empty())
        self.sorted_list.insert(Node(1))
        self.assertFalse(self.sorted_list.is_empty())

    def test_insert(self):
        self.sorted_list.insert(Node(2))
        self.assertEqual(self.sorted_list.head.value, 2)
        self.assertEqual(self.sorted_list.length, 1)
        self.sorted_list.insert(Node(1))
        self.assertEqual(self.sorted_list.head.value, 1)
        self.assertEqual(self.sorted_list.length, 2)

    def test_remove(self):
        self.sorted_list.insert(Node(2))
        self.sorted_list.insert(Node(1))
        removed = self.sorted_list.remove()
        self.assertEqual(removed.value, 1)
        self.assertEqual(self.sorted_list.length, 1)

    def test_merge(self):
        sorted_list2 = SortedList()
        self.sorted_list.insert(Node(2))
        self.sorted_list.insert(Node(1))
        sorted_list2.insert(Node(4))
        sorted_list2.insert(Node(3))
        self.sorted_list.merge(sorted_list2)
        self.assertEqual(self.sorted_list.length, 2)
        self.assertFalse(sorted_list2.is_empty())

if __name__ == '__main__':
    unittest.main()
