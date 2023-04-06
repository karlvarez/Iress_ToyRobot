# Iress_ToyRobot

Overview:

	This is a Coding Challenge from Iress. The requirements are in the file:

		Toy Robot Code Challenge C++ 2022.pdf


VS Solution:

	Iress_ToyRobot.sln


VS Projects:

	Iress_ToyRobot project

		- contains Robot, Table and Controller classes
		- produces the Iress_ToyRobot.exe console application
		- Debug and Release build configurations are available
		- Important configurations:
			- Debugging > Command Arguments is set to "testScript.txt"


		Files:

			Globals.h
				- contains definitions shared across the classes i.e. Face enum

			Iress_ToyRobot.cpp
				- contains the main() function
				- instantiates a Controller class
				- parses the input (either from text file or stdin) and sends the
				  command to the Controller

			Controller.h
			Controller.cpp
				- the Controller class centralizes management of any lower-level modules
				  (at the moment, Table class only. future, maybe a GUI, logging, scoring, etc.)
				- the Controller class has 1 instance of a Table and sets its size to the fixed
				  requirement, 5x5
				- the Controller calls the necessary Table function based on the command (at the
				  moment, minimal to no processing)

			Table.h
			Table.cpp
				- the Table class has 1 instance of a Robot and controls the robot while making
				  sure it does not fall off the table
					- additional robots can be instantiated here in the future -> consider having
					  IDs to identify each robot
				- the Table class calls the TryXXXXX() functions of the robot prior to actually
				  relaying a Place/Move command to the robot (TryPlace() and TryMove())
					- if the TryXXXXX() function returns false, the Table sill not relay the
					  corresponding Place/Move command to the robot
				- the Table class represents an actual table with size of 'xsize' units in the
				  horizontal direction and 'ysize' units in the vertical direction
				- (!)IMPORTANT(!) : the coordinate syste is ZERO-based
					- position or coordinate (0, 0) is the South West corner
					- (0, ysize - 1) is the North West corner
					- (xsize - 1, 0) is the South East corner
					- (xsize - 1, ysize - 1) is the North East corner

			Robot.h
			Robot.cpp
				- the Robot class has a Position (x and y) pertaining to the coordinates on the
				  Table and a Face pertaining to the direction that the robot is facing like North,
				  South, East or West
				- the Robot class supports Place, Move, Left, Right and Report commands and
				  auxiliary functions TryPlace, TryMove (see Table class documentation)
				- because the current requirements are straightforward, all checking for valid
				  movements is done in the Robot class --> consider moving that to the Table class
				  esp. if there are other factors to consider like obstacles or other robots to
				  consider
				- the current Report functionality prints directly to stdout, consider changing
				  that in the future.

			testScript.txt
				- input file for testing
				- VS project is configured to use this as input by default
				- this is the most basic and quick test, devs are free to edit this conveniently
				  for debugging

			testScript2.txt
				- input file for invalid inputs testing e.g. alpha instead of numeric x or y
				  coordinate, negative x or y coordinate, invalid face/direction, unrecognized
				  commands, commands with wrong number of arguments, etc.

			testScript3.txt
				- input file for testing Place and Move commands
				- places the robot: in various points in the table (all corners, all midpoints of
				  the edges and at the center) and in each possible orientation (N, S, E, W) then
				  tries to Move, of course without falling
				- See Test Matrix for details

			testScript4.txt
				- input file for testing Left and Right commands
				- places the robot in the corners of the table and makes the robot rotate clockwise and
				  counter-clockwise (i.e. 4 left commands should return the robot to the original position and
				  face, even number of left and right commands should do the same, etc.)
				- places the robot in the corners of the table and traverses the table diagonally (e.g. Left,
				  Move, Right, Move, <Repeat>), robot should end up in the opposite corner of the table, of
				  course without falling

			all other testScriptX.txt
				- additional input files for testing any specific scenario


		Output:

			Iress_ToyRobot.exe
				- console application
				- Usage: "Iress_ToyRobot.exe input_file_name" --> reads input_file_name as text file and
				  executes each command
					- execution terminates at EOF or newline
				- Usage: "Iress_ToyRobot.exe" --> waits for user input through stdin and executes each
				  command provided
					- execution terminates if input is a newline (or Break sinal is sent to the application)


	UnitTest_All project

		- contains all unit tests for Robot, Table and Controller classes
		- Run tests within VS and view via Test Explorer
		- Important configurations:
			- Additional include dirs and libraries/obj files to link Iress_ToyRobot
		- As Designed: Report functionality across all classes is not tested here because it can be easily
		  tested by checking the console


		Files:

		UnitTest_all.cpp
			- contains all unit test code
			- prefix: T_Robot = unit test for Robot class
			- prefix: T_Table = unit test for Table class
			- prefix: T_Controller = unit test for Controller class
