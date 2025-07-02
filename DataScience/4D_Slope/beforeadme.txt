WARNING: To run the code, import the MQInfo.cpython-311.pyc file into the C:\Users\user\AppData\Local\Programs\Python\Python311\Lib\__pycache__\MQInfo.cpython-311.pyc path.

NOTE: This code is suitable for gas sensors measuring standard gases.

Sensor modes measuring "Standard Gases": MQ135, MQ2, MQ3, MQ4, MQ5, MQ6, MQ7, MQ8, MQ9, MQ131, MQ136, MQ137, MQ138, MQ214

This code aims to predict future data based on past data. 
Please update the xlsx excel file to the sensor mode you are using and the past results you have obtained.
The data you need to measure for this code: Gas Sensor Percentage, Celsius Temperature, Relative Humidity (DHT22, recommended).

-- WARNING --
If you are using MQ131, make sure it measures with low sensitivity.
To understand the sensitivity of MQ131, look at its concentration range (if ppb --> low ModelSlope.py) (if ppm --> high 4DSlope.py).

If the sensor you are working with is not listed, please check the list of "Model Gases". (ModelSlope.py)
