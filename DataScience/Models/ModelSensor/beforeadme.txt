NOTE: This code is suitable for all sensors that are NOT SUPPORTED.

If the sensor type you are using is a gas sensor, please make sure your sensor model is NOT listed before running this code.

SUPPORTED LİST: MQ135, MQ2, MQ3, MQ4, MQ5, MQ6, MQ7, MQ8, MQ9, MQ131, 
MQ131_LOW, MQ135, MQ136, MQ137, MQ138, MQ214, MQ216, MQ303A, MQ303B, MQ306A, MQ307A, MQ309A

This code aims to predict future data based on past data. 
Please update the xlsx excel file to the sensor mode you are using and the past results you have obtained.
The data you need to measure for this code: Sensor Percentage.

-- WARNING --
For aims to predict future data based on past data:
If the sensor you are using is listed, browse to the 4D_Slope folder.
If the sensor you are using is listed but not in the 4D_Slope list, examine the ModelGases folder. (ModelGases --> ModelSlope.py)

For simulates which gas will give which ppm result at which sensor percentage:
If the sensor you are using is listed, browse to the 3D_Surface folder.
If the sensor you are using is listed but not in the 3D_Surface list, examine the ModelGases folder. (ModelGases --> ModelGraph.py)

-- NOTES --
Since the correction coefficient of unsupported sensors cannot be calculated, it is included in the "Models" folder instead of the "4D_Slope" folder.
Since the ppm of unsupported sensors cannot be calculated in advance by the system:
1) The result data of the program, which aims to predict future data based on past data, was became sensor percentage instead of ppm.
2) Simulations of these sensors such as 3D_Surface.py and ModelGraph.py could not be created.

-- THANKS FOR YOUR CONTRIBUTIONS --
If the sensor you are using is a different model gas sensor, please report it to us as "Issues".
