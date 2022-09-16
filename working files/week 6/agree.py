from cs50 import get_string

s = get_string("Do you agree? ").lower() # Binding two functions


if s in ["Y", "yes"]:
    print("Agreed.")
elif s == "N" or s =="n":
    print("Not agreed.")