from cs50 import get_string

people = {
    "Carter": "+1-617",
    "David": "+1-949"
}

name = get_string("Name: ")
if name in people:
    print(f"Number: {poeple[name]}")