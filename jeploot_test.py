import jeploot
import random
from enum import Enum

jeploot.init()

class item_type(Enum):
    armor = 1
    weapon = 2
    material = 3
    consumable = 4

class item(object):

    value = 0
    original_durability = 100.0
    durability = 100.0
    wear = 0.0

    def __init__(self, value, item_type):
        self.value = value
        self.item_type = item_type

    def getValue(self):
        wear = self.durability / self.original_durability
        return float(self.value) * wear

    def getDurability(self):
        return self.durability

class weapon(item):

    def __init__(self, damage, value):
        self.damage = damage
        self.value = value
        self.item_type = weapon

    def use(self):
        print ("Swing weapon")
        if self.durability > 0:
            self.durability -= 10

class armor(item):

    def __init__(self, strength, value):
        self.strength = strength
        self.value = value
        self.item_type = armor

    def use(self):
        print ("Block attack")
        if self.durability > 0:
            self.durability -= 10

def print_condition(item, name):
    print ("%s durability: %d\n%s value: %d" % (name, item.getDurability(), name, item.getValue()))

def legendary_item():
    print ("Legendary item found!")

def rare_item():
    print ("Rare item found!")

def common_item():
    print ("Common item found!")

# dictionary loaded with functions
function_dict = {legendary_item: 1, rare_item: 3, common_item: 6}

for i in range(10):
    jeploot.catRoll(function_dict)()

# testing parent/child classes
axe = weapon(50, 100)
chestplate = armor(75, 120)

print_condition(axe, "Battle Axe")
print_condition(chestplate, "Guilded Chestplate")
axe.use()
chestplate.use()
print_condition(axe, "Battle Axe")
print_condition(chestplate, "Guilded Chestplate")
axe.use()
chestplate.use()
print_condition(axe, "Battle Axe")
print_condition(chestplate, "Guilded Chestplate")

chance_test = .3
string_test = "this is a test"
int_test = 42


# testing jeploot functions
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
    selection = jeploot.catRoll(list_two)
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

