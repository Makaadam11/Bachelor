print("\n-------------------zadanie 3.1 --------------------") 
# Czy podany kod jest poprawny składniowo w Pythonie? Jeśli nie, to dlaczego?

x=2 ; y=3;         # nie potrzeba średnika po y=3 w jezyku Python
if(x>y):
	result = x;    # nie potrzebny średnik w jezyku Python
else:
	result = y;    # nie potrzebny średnik w jezyku Python
print(result)


# for i in "axby": if ord(i) < 100: print (i)   niepoprawna składnia po pętli 

# porawiona wersja:
for i in 'axby':
	if ord(i) < 100: print(i)

# ten kod jest poprawny
for i in "axby": print(ord(i) if ord(i) < 100 else i)

print("\n-------------------zadanie 3.2 --------------------") 
# Co jest złego w kodzie:

L = [3, 5, 4] ; L = L.sort()
print(L)

# lepiej wyprintować od razu L.sort()

# ----------------------------------------- 

# x, y = 1, 2, 3

# mamy 2 zmienne i 3 wartości trzeba albo dodać zmienną albo odjąć wartość 

# -----------------------------------------

#X = 1, 2, 3 ; X[1] = 4

# nie możemy nadpisać wartości na indexie 1 

# -----------------------------------------

#X = [1, 2, 3] ; X[3] = 4

# nie możemy dodać bo nie ma indexu 3

# -----------------------------------------

#X = "abc" ; X.append("d")

# Obiekt string nie ma metody 'append()'

# -----------------------------------------

#L = list(map(pow, range(8)))

# pow przyjmuje 2 argumenty liczba i potęga 

		
print("\n-------------------zadanie 3.3 --------------------") 
# Wypisać w pętli liczby od 0 do 30 z wyjątkiem liczb podzielnych przez 3.

for x in range(30):
	if x % 3 != 0:
		print(x, end=" ")
	else:
		print("", end="")


print("\n-------------------zadanie 3.4 --------------------") 
# Napisać program pobierający w pętli od użytkownika liczbę rzeczywistą 
# x (typ float) i wypisujący x oraz trzecią potęgę x. 
# Zatrzymanie programu następuje po wpisaniu z klawiatury stop. 
# Jeżeli użytkownik wpisze napis zamiast liczby, to program ma 
# wypisać komunikat o błędzie i kontynuować pracę.

while True:
	x=input("x: ")
	if x == "stop":
		break
	try:
		print(float(x) ** 3)
	except ValueError:
		print("Invalid number")

print("\n-------------------zadanie 3.5 --------------------") 
# Napisać program rysujący "miarkę" o zadanej długości. 
# Należy prawidłowo obsłużyć liczby składające się z kilku cyfr 
# (ostatnia cyfra liczby ma znajdować się pod znakiem kreski pionowej). 
# Należy zbudować pełny string, a potem go wypisać.

import math

while True:
	try:
		length=int(input("Declare length of the ruller: "))
		break
	except ValueError:
		print("Invalid  length!")

print("|", end="")
for n in range(length):
	print("....", end="|")
print("")

for n in range(length+1):
	print(str(n), end="")
	spaces=4 - math.ceil(len(str(n + 1)) // 2)
	print(" "*spaces, end="")
print("")

print("\n-------------------zadanie 3.6 --------------------") 
# Napisać program rysujący prostokąt zbudowany z małych kratek. 
# Należy zbudować pełny string, a potem go wypisać. 
# Przykładowy prostokąt składający się 2x4 pól ma postać:

while True:
	try:
		width=int(input("Declare width: "))
		length=int(input("Declare length: "))
		break
	except ValueError:
		print("Intiger value was not declared!")

start="+"
x=width

while x != 0:
	start+="---+"
	x-=1
square=start + "\n"

for n in range(length):
	k=width
	line1="|"
	line2="+"
	while k != 0:
		line1+="   |"
		line2+="---+"
		k-=1
	square+=line1 + "\n"
	square+=line2 + "\n"

print(square)

print("\n-------------------zadanie 3.7 --------------------") 
# Podany fragment programu pokaże problem z wyświetlaniem list obiektów
#  stworzonych przez użytkownika, jeżeli nie została zdefiniowana 
# metoda __repr__. Jeżeli zdefiniowano tylko metodę __repr__, 
# to zostanie ona użyta również wtedy, gdy zwykle pracuje __str__. 
# Sprawdzić działanie kodu, 
# jeżeli wykomentujemy metodę __str__() lub metodę __repr__().


print("\ncomment _str_:")
class Time:

    def __init__(self, seconds=0):
        self.s = seconds

   # def __str__(self):
    #    return "{} sec".format(self.s)

    def __repr__(self):
        return "Time({})".format(self.s)

time1 = Time(12)
time2 = Time(3456)
print("{} {}".format(time1, time2))   # Python wywołuje str()
print("{}".format([time1, time2]))   # Python wywołuje repr()



print("\ncomment _repr_:")

class Time:

    def __init__(self, seconds=0):
        self.s = seconds

    def __str__(self):
        return "{} sec".format(self.s)

   # def __repr__(self):
    #    return "Time({})".format(self.s)

time1 = Time(12)
time2 = Time(3456)
print("{} {}".format(time1, time2))   # Python wywołuje str()
print("{}".format([time1, time2]))   # Python wywołuje repr()


# zadanie 3.8 
print("\n-------------------zadanie 3.8 --------------------") 
set_A = (2,4,5,2,2,2,3,4)
set_B = (3,4,2,4,5,1)
print(set(set_A).intersection(set(set_B)))
print(set(set_A).union(set(set_B)))

# zadanie 3.9 
print("\n-------------------zadanie 3.9 --------------------") 
Array = [[], [4], (1, 2), [3, 4], (5, 6, 7)]
result = []
for x in Array:
	result.append(sum(x))
print(result)

# zadanie 3.10
print("\n-------------------zadanie 3.10 --------------------") 

# source code https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/

def roman2int():
	Roman={"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
	rnumber=input("Give roman number: ")
	res = 0
	i = 0
 
	while (i < len(rnumber)):
 
		# Getting value of symbol s[i]
		s1 = Roman[rnumber[i]]
 
		if (i+1 < len(rnumber)):
 
			# Getting value of symbol s[i+1]
			s2 = Roman[rnumber[i+1]]
 
			# Comparing both values
			if (s1 >= s2):

				# Value of current symbol is greater
				# or equal to the next symbol
				res = res + s1
				i = i + 1
			else:
 
				res = res + s2 - s1
				i = i + 2
		else:
			res = res + s1
			i = i + 1
 
	return res

if __name__ == '__main__':
	print(roman2int())
