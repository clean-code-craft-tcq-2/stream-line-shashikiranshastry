import csv
import random

A2D_readings = []
temperature_sensor_readings = []
Use_file = False

if Use_file == True:
    with open('Input_example.csv', newline='') as csvfile:
        filereader = csv.reader(csvfile, delimiter=',')
        start_read = False
        for row in filereader:
            if row[0] == 'END':
                start_read = False
            if start_read == True:
                A2D_readings.append(row[0])
                temperature_sensor_readings.append(row[1])
                #print(f'element1:{row[0]}, element2:{row[1]}')
            if row[0] == 'START':
                start_read = True
            #print(f'element1:{row[0]}')
else:
    for i in range(50):
        A2D_readings.append(random.randint(0,4094))
        temperature_sensor_readings.append(random.random()*40)
