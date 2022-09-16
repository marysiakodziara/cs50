from cs50 import get_string

people = {
    "Carter": "+1-617",
    "David": "+1-949"
}

name = get_string("Name: ")
if name in people:
    number = people[name]
    print(f"Number: {people[name]}")