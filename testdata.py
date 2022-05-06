import sys
import time
import sender
import unittest
import input_sensor_data

#sys.stdin.read()
class sender_test(unittest.TestCase):
  
  def test(self):
    for test_data in range (len(input_sensor_data.test_A2D_readings)):
      self.assertEqual(sender.start_sending(input_sensor_data.test_A2D_readings[test_data],input_sensor_data.test_temperature_readings[test_data]), input_sensor_data.result_data[test_data] , "not equal")
      print ("--------------------------")
        
unittest.main()
