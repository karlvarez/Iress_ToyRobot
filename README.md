# Iress_ToyRobot

Requirements:
	Toy Robot Code Challenge C++ 2022.pdf

VS Solution:

	Iress_ToyRobot.sln

VS Projects:

	Iress_ToyRobot
	- contains Robot, Table and Controller classes
	- produces the Iress_ToyRobot.exe console application
	- Debug and Release build configurations are available


	Files:

		Globals.h
		- contains definitions shared across the classes e.g. Face enum, configurable values like Table size, defined Command IDs, and Position struct

		Iress_ToyRobot.cpp
		- contains the main class
		- instantiates a Controller class
		- parses the input (either from text file or stdin) and sends the command to the Controller

		Robot.h
		Robot.cpp
		- header and definition of the Robot class
		- the Robot class has a Position (x and y coordinate on the Table) and a Face (direction that the robot is facing like North, South, East or West)
		- the Robot class supports Place, Move, Left, Right and Report commands (equivalent to the commands mentioned in the requirements.
		- because the current requirements are straightforward, all checking for valid movements is done in the Robot class. Consider moving that to the Table class esp. if there are obstacles to consider and/or other rules/restrictions.
		- current Report functionality prints directly to stdout, consider changing in the future.

		Table.h
		Table.cpp
		- header and definition of the Table class
		- the Table class has 1 instance of a Robot
		- the Table class has a size i.e. xsize = units in the horizontal direction, ysize = units in the vertical direction
		- (!)IMPORTANT(!) : the coordinate syste is ZERO-based
		- the south west corner is regarded as 0, 0

		Controller.h
		Controller.cpp
		- header and definition of the Controller class
		- the Controller class has 1 instance of a Table
		- the Controller class is intended to abstract between the raw command inputs and the functionalities of the Table and/or Robot
		- because the current requirements are straightforward, Controller class has very minimal processing ang practically just calls the Table functions that effectively moves the Robot
		- for future enhancements (e.g. resizing the table, resetting the robot, etc.) can be implemented in the Controller class
	
		testScript.txt
		- input file for testing. The VS Project is configured to use this as input by default.
 
	UnitTest_All project
	- contains all unit tests for Robot, Table and Controller classes
	- As Designed: Report functionality across all classes is not tested here because it can be easily tested by checking the console

	Files:
		UnitTest_all.cpp
		- contains all unit test code
		- prefix: T_Robot = unit test for Robot class
		- prefix: T_Table = unit test for Table class
		- prefix: T_Controller = unit test for Controller class

Output:
	Iress_ToyRobot.exe
	- console application
	- Usage: "Iress_ToyRobot.exe input_file_name" --> reads input_file_name as text file and executes each command
		- execution terminates at EOF
	- Usage: "Iress_ToyRobot.exe" --> waits for user input through stdin and executes each command provided
		- because there is no specification on what command to terminate the execution, send Break to exit the application