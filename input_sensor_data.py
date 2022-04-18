import csv

A2D_readings = []
temperature_sensor_readings = []

with open('Input_example.csv', newline='') as csvfile:
    filereader = csv.reader(csvfile, delimiter=',')
    start_read = False
    for row in filereader:
        if row == "END":
            start_read = False
        if start_read == True:
            A2D_readings.append(row[0])
            temperature_sensor_readings.append(row[1])
            print(f'element1:{row[0]}, element2:{row[1]}')
        if row == "START":
            start_read = True
