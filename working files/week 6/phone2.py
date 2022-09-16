import csv
from cs50 import get_string

with open("phone2.csv", "a") as file:

name = get_string("Name: ")
number = get_string("Number: ")

writer = csv.writer(file)
writer.writerow([name, number])
