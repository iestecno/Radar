#pragma config(Sensor, S4,     radar,          sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//



void startRadar()
{

/* Setting up all the variables*/

	nxtEraseRect (0, 0, 100, 64); 											//Initializing the display
	nMotorEncoder[motorA]=0;														//Initializing the encoder
	nMotorEncoderTarget[motorA] = 1000;									//Target for the encoder
	motor[motorA]=15;																		//Speed for the motor

/*Since the gears on the radar require the motor to turn 5 turns for every full turn of the
head, we turn the motor by 1000 degrees, which results in a head rotation of 1000 / 5 = 200 degrees.

The first part of the while loop is responsible for rotating the head with the sensor on it back and forth and
for preparing the progress bar on the NXT's display.

The second part of the while loop is responsible for reading the angle position of the sensor head
and filling in the progress bar on the NXT display at that angle position.  The process
repeats rapidly enough to get a reading for every different horizontal postiion on the NXT display.*/

	while (nMotorEncoder[motorA] < 1000) 								//While the motor has not reached its target
		{

			int distance =SensorValue [radar];							//Initializing Radar Distance
			int pos = nMotorEncoder[motorA];								//Initializing Radar Position
			nxtDrawLine(0, 0, 99, 0);  											//Display a line between the points (0,0) and (99,0)
			nxtDrawLine(0, 4, 99, 4);  											//Display a line between the points (0,4) and (99,4)
						nxtDrawRect (0, 3, pos/10, 0);  					//Display how the radar is moving

			if ((distance < 100) && (distance > 4))					//Representing Objects when in range
			{
				nxtDrawCircle (pos/10, (distance*64)/100, 3);
				nxtEraseRect (0 , 4, (pos/10)-20, 64);				//Erasing old data
			}

		}

/*Same code for the counterclockwise movement*/

	nxtEraseRect (0, 0, 100, 64); 												//Initialize the display
	nMotorEncoder[motorA]=0;															//Initialize the encoder
	nMotorEncoderTarget [motorA]= -1000;									//Target for the encoder
	motor[motorA]=-15;																		//Rotational Speed

	while (nMotorEncoder[motorA] > -1000)									//While the motor has not reached its target
		{
			int distance =SensorValue [radar];
			int pos = nMotorEncoder[motorA];
			nxtDrawLine(0, 0, 99, 0);  												//Displaying a line between the points (0,0) and (99,0)
			nxtDrawLine(0, 4, 99, 4);  												//Displaying a line between the points (0,4) and (99,4)
			nxtDrawRect (100, 3, (100 + pos/10), 0);  				//Displaying a line between the points (0,4) and (99,4)

			if ((distance < 100) && (distance > 4))
			{
				nxtDrawCircle ((100 + pos/10), (distance*64)/100, 3);
				nxtEraseRect (100 , 4, (100 + pos/10)+20, 64);
			}
		}


}


task main()
{

	while (true)
	{
		startRadar();
	}

}
