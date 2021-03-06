import random

def init():
    random.seed()

def booRoll(float_chance):

    if type(float_chance) != float:
        raise Exception("this function only operates with floats")

    if float_chance >= 1.0:
        return True

    if float_chance <= 0.0:
        return False

    else: return random.random() < float_chance

# for list passed (x, y, z), random value returns according to the 
# proportion of x:sum, y:sum, z:sum
# catRoll(10, 20, 30) has a 10/60 chance of returning 0, 20/60 chance of
# returning 1, and 30/60 chance of returning 2
# dicts passed use the value of each element for the proportion, and return
# a corresponding key
def catRoll(options):
    if len(options) == 0:
        raise Exception("this function does not accept empty sequences")
    
    if type(options) == list:
        specified_type = type(options[0])
        total = sum(options)
        seed = specified_type(0)

        if specified_type == int:
            seed = random.randint(0, total)

        elif specified_type == float:
            seed = random.uniform(0, total)
            
        else:
            raise Exeption("function detected invalid proportion values")

        current_check = specified_type(0)
        for i in range(len(options)):
            if type(options[i]) != specified_type:
                raise Exeption("function detected mixed types within sequence")

            current_check += options[i]
            if seed < current_check:
                return i

            elif i == len(options) - 1:
                return i
                 
    elif type(options) == dict:
        key_list = list(options.keys())
        value_list = list(options.values())

        return key_list[catRoll(value_list)]

    else: raise Exception("this function only operates on lists and dictionaries")
                        
