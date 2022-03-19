# Geriatric-jlcpcb
What is Geriatric?
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Care robots are machines,operating partly or completely autonomously,that are intended to assist older people
and their care givers.Care robots are seen as one part of the solution to the aging population, allowing fewer
professional care givers to provide the necessary assistance and care. Despite the potential benefits, the
dissemination of carer obots,and welfare technology ingeneral,is limited in Swedish elder care.

![image](https://user-images.githubusercontent.com/84837431/159132964-14dbfe6b-51ba-44c0-a0d2-3bab28cff414.png)

![download](https://user-images.githubusercontent.com/84837431/159133846-08fd1584-5e76-48d3-ab37-9f9ec5f39a69.jpg)


----------------------------------------------------------------------------------------------------------------------------------------------------------------------                                                               
PROBLEM STATEMENT:


Generally an elders faces different health issues and needs proper care . There are not enough care takers by their relatives to meet the growing needs of their necessity and saving elders from lives of loneliness

THE TEAMS APPROACH TO THE PROBLEM:-
=======================================================================================================================================================================
Creating an assistant robot Which takes care about the elder people which measures pulse rate, temperature in the emergency situation it sends the information to nearby hospitals and family members through GSM module. This will also provide necessary requirements to the elder people and pregnant people.

So keeping in the mind to take care of the elder people at the time of normal and emergency situation. At first the user needs to give the command to activate the robot by pressing the push button present on the glouse, then the nrf transmits to the receiver if the push button is in high position then the main code is able to run. First ultrasonic sensor in bot can detect any hurdles in the path within range of 40cm, If there is no hurdles in range then it proceed to IR sensors. Two IR sensors are arranged in our bot. They can control the motor here  black strip acts as a reference as no object .if IR sensors records 1,0 that means 1st ir sensor will be on black strip and second it sensor will be on the floor .. then  wheels will move in right direction, if IR sensors record 0,1 then wheels will rotate in left directiin . Our robot works  in 3 degrees of freedom(forward,left,right)by this process the bot can reach to the person then the ultrasonic sensors are rotated in 180 degrees by servo because ultrasonic sensor detects the hurdle(body of the bot) then it stop proceeding of IR sensors then the person will take his required items from bot.

 
 At the emergency situation :
 
 
 
We arrange a belt like structure to the hand which has a capable of handle pulse meter, arduino board, and temperature sensor and gsm module. When the user arranges the belt in his hand and on the module it can take the values of temperature and pulse if at all the readings in abnormal stage the gsm sends the information to the near hospitals and the user can save their life. 




Block diagram:





![transmitter](https://user-images.githubusercontent.com/84837431/159133873-7cc5a50c-2c5b-4184-a063-af7cac1485c2.jpeg)
![Receiver](https://user-images.githubusercontent.com/84837431/159133878-a893240b-6bb4-4163-bf9f-0bae8ca7e33d.jpeg)


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
What inspired you to select the problem?


Nowadays as people are not getting time in their busy schedule to take care of the old parents so the old people are only doing all their works including going out to get the groceries and for other purposes while they are alone while going to store or somewhere else .So we wants to introduce an interactive bot .That can helps at emergency situation. 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Circuit Diagram


![image](https://user-images.githubusercontent.com/84837431/159133916-7420b5b5-6b50-448e-be0b-9ed7f9303a5d.png)


* HARDWAR COMPONENTS: 
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
1. Arduino UNO
2. NodeMCU-ESP8266
3 .Ultrasonic sensor(hcsr04)
4 .IR SENSOR
5 .Servo Motor
6 .GSM Module
7. GPS Module
8 Temperature sensor
9. Pulse sensor 
10. Buzzers
11. Centre shaft motors
 12. nrf module
13. 12V Batteries
14. Wheels
15 .L298n Motor Driver
16. Jumper Wires
17.L-clamps
18.5V Relay

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

We had used 3 types of software to develop this project.
  SOFTWARE LIST
1.Arduino IDE
2.Proteus
3.Fusion 360


1. ARDUINO IDE

 >  One of the softwareswe used in programming for our bot is Arduino IDE. 
 
 >  We used Arduino UNO microcontroller to control the motors.to program it the software used is arduino IDE.
 
 >  The open source arduino software makes it easy to write code and upload it to the board.
 
 >  It runs on windows, Mac OS X and linux. It supportsthe languages C and C++ using special rules of source structuring. 
 
 >  Projects made using this software are known as sketches .programming a microcontroller is somewhat different from programming a computer , there are a number of       specific libraries for different boards .
 
 >  we have to write the code in this software based on our necessity. 

 >  There are different methods and keywords so that our board understands what the action to be performed.

Syntax :

Void setup(){

//put your code here, to run once
}

Void loop (){

//put your main code here

}

Here in setup method we initialise the pins we use pinMode ( pin , INPUT/OUTPUT).In the loop we write about the action such as whether the pin to be in on or off state using digitalWrite , digitalRead , analogRead and analogWrite keywords based on the pins we use and also on the purpose we use them such as input or output . We also use delay ( ms ) to delay for certain milliseconds . 

![image](https://user-images.githubusercontent.com/84837431/159134090-c623e174-d484-4843-8db5-1cf545159565.png)

2 .PROTEUS

 >The Proteus Design Suite is a Windows application for schematic capture, simulation, and PCB (Printed Circuit Board) layout design.
 
 > It can be purchased in many configurations, depending on the size of designs being produced and the requirements for microcontroller simulation.  
 
 > Schematic capture in the Proteus Design Suite is used for both the simulation of designs and as the design phase of a PCB layout project.
 
 >  It is therefore a core component and is included with all product configurations. 
 
 >  The micro-controller simulation in Proteus works by applying either a hex file or a debug file to the microcontroller part on the schematic. 
 
 >  It is then co-simulated along with any analog and digital electronics connected to it.
 
 >   This enables its use in a broad spectrum of project prototyping in areas such as motor control, temperature control and user interface design. 
 
 >   It also finds use in the general hobbyist community and, since no hardware is required, is convenient to use as a training or teaching tool.    
![schematicLrg](https://user-images.githubusercontent.com/84837431/159134160-037438a9-d30d-49e2-8829-40cdf0979144.jpg)


3 .FUSION 360

Fusion 360 is the first 3D CAD, CAM, CAE, and PCB tool of its kind, connecting your entire product development process into one cloud-based platform used many small and big enterprises for product design and prototyping.

![image](https://user-images.githubusercontent.com/84837431/159134225-5cf1373b-a116-4539-b6e6-1b1d8e14c77e.png)
![image](https://user-images.githubusercontent.com/84837431/159134131-7212dd92-bbd7-4b3e-9de7-0f80fba4e1be.png)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

SIMULATION

![image](https://user-images.githubusercontent.com/84837431/159134263-63940c19-3a05-44b7-9402-545d479b9159.png)


This is the simulation done in proteus software.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

CONCLUCION


We need take our grandparents even though we are in the busy schedule. It is possible to need take care our grandparent’s life  and save them from saving elders from lives of loneliness by using this interactive bot.

