WarBots-StrategyTester
======================

Purpose
-------
+ To provide a platform to brainstorm, experiment, and test possible strategies for RoboCup SSL Gameplay
+ To provide a competition platform of virtual soccer gameplay with changeable GameMode settings

Competition Rules
-----------------
+ GameMode is changed in tester/general/settings.cpp
	- initSetting() is called once at the start of the game
	- repeatedSetting() is called at every iteration to ensure certain criteria
	- both are arbritary functions, which will allow any game configuration to be implemented
+ The only files that players are allowed to modify are test/general/playerBlue.cpp and playerYellow.cpp
	- players are expected to build strategy classes and analysis function for their Coach to invoke their strategy
	- nothing else can be modified, official versions of other files are used in simulations, it is up to the players to comply with the game setup and standards

Core Code BreakDown
-------------------
+ grSim/
	- Virual soccer server developed by ParsianRobotics
+ tester/WarBots-StrategyTester.pro
	- Qt project file
	- qmake to generate Makefile
+ tester/Makefile
	- make to compile project
+ tester/main.cpp
	- declares Coaches
	- Attempts to connect to grSim, is successful, game starts
+ tester/proto/
	- folder containing message protocols
+ tester/comm/
	- receiver.cpp
		+ multicast listener, sends updates to Coaches whenever a new packet is received
	- sender.cpp
		+ UDP based sender, used to send grSim command packets
+ tester/general/
	- defs.h
		+ contains templates of Movable, Robot, FieldState and GameSetting classes
	- defs.cpp
		+ contains the constructors of Movable, Robot, FieldState and GameSetting classes
	- playerBlue.cpp
		+ contains the analysis function definition for BlueCoach
		+ players change this file to create their own strategies and invoke them
	- playerYellow.cpp
		+ contains the analysis function definition for YellowCoach
		+ players change this file to create their own strategies and invoke them	
	- settings.cpp
		+ contains the game setting infomation, varies from game to game
+ tester/ai/
	- ai.h
		+ contains the templates for Coaches and Strategy classes
		+ any strategy must declare implementations for all different number of robots in play (even if the actino is to do nothing)
	- ai.cpp
		+ most notable functions are Coach::update(SSL_DetectionFrame newFrame) and Strat::implement(), remember that players CANNOT modify these functions (or this file entirely)
		+ update will send the new DetectionFrame into coach memory and update positions in FieldState, analysis() (player defined) is called to invoke player's strategy
