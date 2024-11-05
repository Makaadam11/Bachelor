import itertools
import sys
import time
import random

print("\n-------------------zadanie 7.6 --------------------\n") 

print("===================================\n Binary\n")
 
count = 0

for i in itertools.cycle('01'):
    if count > 300:
        break
    else:
        count += 1
        sys.stdout.write(str(i)+' ')
        sys.stdout.flush()
        time.sleep(0.03)    


print("\n\n===================================\n Directions\n")
 
float_list = ['N','E','S','W']
for i in range(300):
    
    sys.stdout.write(str(random.choice(float_list))+' ')
    sys.stdout.flush()
    time.sleep(0.03)
 

print("\n\n===================================\n Days\n")
 
count = 0

for i in itertools.cycle('0123456'):
    if count > 300:
        break
    else:
        count += 1
        sys.stdout.write(str(i)+' ')
        sys.stdout.flush()
        time.sleep(0.03)            