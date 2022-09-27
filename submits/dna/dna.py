import csv
import sys
from cs50 import get_string


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python dna.py FILENAME")

    database = []
    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        database = list(reader)
         # i think i should put here a convertion of eements that should be numeric but are gonna be read as strings
         # if thats gonna be the case
         # i have to figure out how to check the number of elements that need to be casted

    # TODO: Read DNA sequence file into a variable
    seqFile = get_string("sequence file" )
    with open(seqFile, 'r') as file:
        sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    with open(sys.argv[1], 'r') as file:
        firstLine = file.readline()
    firstLine = firstLine.strip('\n')
    sub = firstLine.split(',')
    subNum = len(sub)

    # now i want to find the longest sequence for each of subsequences
    # for sub[i] f

    subDict = {}

    for i in range(1, subNum):
        num = longest_match(sequence, sub[i])
        subDict[sub[i]] = num

    # TODO: Check database for matching profiles
    for i in range(len(database)):
        check = 0
        for j in range(1, subNum):
             if subDict[sub[j]] == int(database[i][sub[j]]):
                check += 1
                if check == subNum:
                    print(database[i]['name'])
                elif j == subNum - 1 and i == len(database) - 1:
                    print("No matches")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
