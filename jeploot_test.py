import jeploot
import random

jeploot.init()

chance_test = .3
string_test = "this is a test"
int_test = 42

hit_count = 0

for i in range(1000):
    if jeploot.booRoll(chance_test):
        hit_count += 1

print (hit_count)

list_one = [10, 20, 40, 30]
list_two = [.1, .2, .4, .3]
dict_one = {"first thing": 10, "second thing": 20, "third thing": 70}

list_results = [0, 0, 0, 0]
dict_results = [0, 0, 0]

for i in range(1000):
    selection = jeploot.catRoll(list_one)
    list_results[selection] += 1

for i in range(1000):
    pick = jeploot.catRoll(dict_one)

    keylist = list(dict_one.keys())

    for i in range(len(keylist)):
        if pick == keylist[i]:
            dict_results[i] += 1
    
print ("list test: ", list_results)
print ("dict test: ", dict_results)

#jeploot.booRoll(string_test)
#jeploot.booRoll(int_test)

