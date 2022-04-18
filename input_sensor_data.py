import csv

with open('input_example.csv', newline='') as csvfile:
    filereader = csv.reader(csvfile)
    for row in filereader:
        print(row)
