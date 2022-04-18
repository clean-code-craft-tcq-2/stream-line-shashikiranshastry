import csv

with open('Input_example.csv', newline='') as csvfile:
    filereader = csv.reader(csvfile)
    for row in filereader:
        print(row)
