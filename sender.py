import sys
import time
import dataconversion
import input_sensor_data
streaming_data_limit = 50

A2D_readings = input_sensor_data.A2D_readings
temperature_readings = input_sensor_data.temperature_sensor_readings

def send_data_to_receiver(data):
    sys.stdout.write(data)
    return data

def process_sensor_data(A2D_value, temperature_value):
    current = dataconversion.map_adc_value_to_amps(A2D_value, dataconversion.ADC_12Bit)
    temperature = dataconversion.map_celsius_to_fahrenheit(temperature_value)
    data = current + "," + temperature + "\n"
    return data

def start_sending():
    for reading in range (streaming_data_limit):
        data = process_sensor_data(float(A2D_readings[reading]), float(temperature_readings[reading]))
        data_sent = send_data_to_receiver(data)
        time.sleep(0.5)

start_sending()
