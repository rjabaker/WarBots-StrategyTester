#include "../ai/ai.h"
#include "../comm/sender.h"

//blue team strategies (based on number of robots online)
//basic implementation is supposed to let Robot 1 move towards the ball at all times
void bluePlayerImplementOneRobot(Coach *ourCoach)
{
	std::vector<Robot> *ourTeam;
	ourTeam = &ourCoach->fs.bBots;
	Move(ourTeam->at(0).pos_x, ourTeam->at(0).pos_y, ourCoach->fs.ball.pos_x, ourCoach->fs.ball.pos_y,
		 ourTeam->at(0).orientation, 1.0, true, ourCoach->teamBlue(), 0);
}
void bluePlayerImplementTwoRobot(Coach *ourCoach)
{
	bluePlayerImplementOneRobot(ourCoach);
}
void bluePlayerImplementThreeRobot(Coach *ourCoach)
{
	bluePlayerImplementOneRobot(ourCoach);
}
void bluePlayerImplementFourRobot(Coach *ourCoach)
{
	bluePlayerImplementOneRobot(ourCoach);
}
void bluePlayerImplementFiveRobot(Coach *ourCoach)
{
	bluePlayerImplementOneRobot(ourCoach);
}

//analysis module to update velocity info to Coach FieldState from memory info
//and activates a strategy of choice (player made)
void bluePlayerAnalysis(Coach *ourCoach)
{
	// updates velocity using only two positions (current and last), then calls basicStrat
	ourCoach->fs.ball.speed_x = (ourCoach->memory()->at(4).balls(0).x() - ourCoach->memory()->at(3).balls(0).x()) / (ourCoach->memory()->at(4).t_sent() - ourCoach->memory()->at(3).t_sent());
	ourCoach->fs.ball.speed_y = (ourCoach->memory()->at(4).balls(0).y() - ourCoach->memory()->at(3).balls(0).y()) / (ourCoach->memory()->at(4).t_sent() - ourCoach->memory()->at(3).t_sent());

	for(int i = 0; i < ourCoach->memory()->at(4).robots_blue_size(); i++)
	{
		for(int j = 0; j < ourCoach->memory()->at(3).robots_blue_size(); j++)
		{
			if(ourCoach->memory()->at(4).robots_blue(i).robot_id() == ourCoach->memory()->at(3).robots_blue(j).robot_id())
			{
				// v = d1 - d2 / t
				for(int k = 0; k < ourCoach->fs.bBots.size(); ++k)
				{
					if(ourCoach->memory()->at(4).robots_blue(i).robot_id() == ourCoach->fs.bBots[k].id)
					{
						ourCoach->fs.bBots[k].speed_x = (ourCoach->memory()->at(4).robots_blue(i).x() - ourCoach->memory()->at(3).robots_blue(j).x()) /
											  			(ourCoach->memory()->at(4).t_sent() - ourCoach->memory()->at(3).t_sent());
						ourCoach->fs.bBots[k].speed_y = (ourCoach->memory()->at(4).robots_blue(i).y() - ourCoach->memory()->at(3).robots_blue(j).y()) /
											  			(ourCoach->memory()->at(4).t_sent() - ourCoach->memory()->at(3).t_sent());
					}
				}
			}
		}
	}
	
	for(int i = 0; i < ourCoach->memory()->at(4).robots_yellow_size(); i++)
	{
		for(int j = 0; j < ourCoach->memory()->at(3).robots_yellow_size(); j++)
		{
			if(ourCoach->memory()->at(4).robots_yellow(i).robot_id() == ourCoach->memory()->at(3).robots_yellow(j).robot_id())
			{
				// v = d1 - d2 / t
				for(int k = 0; k < ourCoach->fs.bBots.size(); ++k)
				{
					if(ourCoach->memory()->at(4).robots_yellow(i).robot_id() == ourCoach->fs.bBots[k].id)
					{
						ourCoach->fs.yBots[k].speed_x = (ourCoach->memory()->at(4).robots_yellow(i).x() - ourCoach->memory()->at(3).robots_yellow(j).x()) /
											  (ourCoach->memory()->at(4).t_sent() - ourCoach->memory()->at(3).t_sent());
						ourCoach->fs.yBots[k].speed_y = (ourCoach->memory()->at(4).robots_yellow(i).y() - ourCoach->memory()->at(3).robots_yellow(j).y()) /
											  (ourCoach->memory()->at(4).t_sent() - ourCoach->memory()->at(3).t_sent());
					}
				}
			}
		}
	}

	printFieldState(&ourCoach->fs, "From bluePlayerAnalysis");

	Strategy myStrat = Strategy();
	myStrat.implement(ourCoach);
}