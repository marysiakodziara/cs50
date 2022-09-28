import csv

titles = {}
count = 0
with open("favorites.csv",  "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        if "MEOW" in title:
            count += 1

print(f"Meow was mentioned by {count} people")