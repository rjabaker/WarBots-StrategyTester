WarBots-StrategyTester
======================

Purpose
-------
+ To provide a platform to brainstorm, experiment, and test possible strategies for RoboCup SSL Gameplay
+ To provide a competition platform of virtual soccer gameplay with changeable GameMode settings

How to Run
----------
+ run grSim/bin/grSim, keep default settings
+ run tester/WarBots-StrategyTester
    - run from console to see debugging output

Competition Rules
-----------------
+ GameMode is changed in tester/general/settings.cpp
	- initGameSetting() is called once at the start of the game
	- repeatedGameSetting() is called at every iteration to ensure certain criteria
	- both are arbritary functions, which will allow any game configuration to be implemented
+ The only files that players are allowed to modify are test/player/playerBlue.cpp and playerYellow.cpp
	- players are expected to build strategy classes and analysis function for their Coach to invoke their strategy
	- nothing else can be modified, official versions of other files are used in simulations, it is up to the players to comply with the game setup and standards

Program Structure
-----------------
+ Simulator
    - grSim is the soccer simulation platform (credits to Parsian Robotics)
    - grSim periodically scans the field and sends the information in the form of SSL_WrapperPacket
    - grSim receives commands in the form of grSim_Packet
    - Both the packets mentioned are google protobuf messages, check tester/proto/ for relevant files
+ Three-level AI
    - The tester adopts a three-level AI structure
        1. Decision AI (Coach)
            - performs analysis on the field information, consult past information from memory, and invokes a strategy
        2. Implementation AI (Strategy)
            - commands robots using some predefined logic, which is deemed ideal by the coach
        2. Basic AI (Robot)
            - contains basic movesets of a robot (move by direction, move to a point, pass, kick, etc...)
                + creates the corresponding command and sends it through the send functions (tester/comm/sender.cpp)
                + may not be ideal if it is necessary to send more commands in the same command packet
                + player has access to send function, allowed to construct their command packet to send
            - NOTE: NOT YET IMPLEMENTED, basic movesets are currently defined in tester/comm/sender.cpp
    - The propagation of information follows this order
+ Tester
    - Upon boot, tester creates two coaches (one for blue team, one for yellow team)
    - Tester checks if there exist special settings, if yes, it runs the game's initial setup function here
        + NOTE: NOT YET IMPLEMENTED
    - Tester has a recevier class which listens for incoming SSL_WrapperPacket (iterations start)
    - Once a packet arrives, tester decodes the message/packet and:
        1. Passes this packet to the coaches by calling the coaches' Update(SSL_DetectionFrame& newFrame) member function
        2. The coaches' update function adds the new packet to their respective memory, and performance analysis using memory
        3. The analysis refreshes the contents of the coaches' FieldState members, which contains the position and velocity (computed from past frames in memory)
            - position updates are given in the coaches' Update functions natively
            - velocity updates are up to the players to decide, a simple scheme is given as sample (using the last two frames)
            - see tester/player/playerBlue.cpp and tester/player/playerYellow.cpp for the sample velocity update
        4. At the end of the analysis, it is expected that the players invoke some strategy to implement
            - players can just define empty strategy class and pass down their coaches
            - the default strategy will call the corresponding functions in the player files (tester/player/player*.cpp)
            - players are expect to code logic to play soccer in those functions, based on the number of robots they have available
    - Tester checks if there exist special settings, if yes, it runs the game's repeated setup function here
    - The next iteration starts

Source Code BreakDown
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
	- settings.cpp
		+ contains the game setting infomation, varies from game to game
	- debug.h
		+ contains function templates of debug functions
		+ wrapping print functions for complicated classes
	- debug.cpp
		+ contains function definitions of debug functions
+ tester/ai/
	- ai.h
		+ contains the templates for Coaches and Strategy classes
		+ any strategy must declare implementations for all different number of robots in play (even if the actino is to do nothing)
	- ai.cpp
		+ most notable functions are Coach::update(SSL_DetectionFrame newFrame) and Strat::implement(), remember that players CANNOT modify these functions (or this file entirely)
		+ update will send the new DetectionFrame into coach memory and update positions in FieldState, analysis() (player defined) is called to invoke player's strategy
+ tester/player/
	- playerBlue.cpp
		+ contains the analysis function definition for BlueCoach
		+ players change this file to create their own strategies and invoke them
	- playerYellow.cpp
		+ contains the analysis function definition for YellowCoach
		+ players change this file to create their own strategies and invoke them