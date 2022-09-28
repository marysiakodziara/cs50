import csv
import re

titles = {}
count = 0
with open("favorites.csv",  "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        if re.search("^(MEOW|THE MEOW)$", title):
            count += 1

print(f"Meow was mentioned by {count} people")