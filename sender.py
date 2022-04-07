ADC_12Bit = {"max_permissible_value" : 4094 , "intercept" : 0 , "max_current_range" : 10}

def map_adc_value_to_amps(A2Dvalue, ADC_dict):
    result = ""
    value = A2Dvalue
    value -= ADC_dict["intercept"]
    if value<=ADC_dict["max_permissible_value"] :
        result = str(abs(round(((value)/ADC_dict["max_permissible_value"])*ADC_dict["max_current_range"])))
    return (result)
  
def map_celsius_to_fahrenheit(temperature):
    temperature_in_fahrenheit = ((temperature * 9/5) + 32)
    return str(round(temperature_in_fahrenheit))
