import csv

A2D_readings = []
temperature_sensor_readings = []

with open('Input_example.csv', newline='') as csvfile:
    filereader = csv.reader(csvfile)
    for row in filereader:
        A2D_readings.append(row[0])
        temperature_sensor_readings.append(row[1])
        print(f'element1:{row[0]}, element2:{row[1]}')
