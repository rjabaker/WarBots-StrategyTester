#include "playerBlueSample.h"

//blue team strategies (based on number of robots online)
//basic implementation is supposed to let Robot 0 move towards the ball and kick it
void BlueSampleStrategy::implement(Coach *ourCoach)
{
	switch(ourCoach->fs.bBots.size()){
	case 5:
		//intentional fall-thru in switch, until implemented, fall to lowest #bots AI to at lease do something
		//break;
	case 4:
		//intentional fall-thru in switch, until implemented, fall to lowest #bots AI to at lease do something
		//break;
	case 3:
		//intentional fall-thru in switch, until implemented, fall to lowest #bots AI to at lease do something
		//break;
	case 2:
		//intentional fall-thru in switch, until implemented, fall to lowest #bots AI to at lease do something
		//break;
	case 1:
		double kickVelocity;
		double stopDistance;
		std::vector<Robot> *ourTeam;
		Movable *ball;

		kickVelocity = 2.0;
		stopDistance = 800;
		ball = &ourCoach->fs.ball;
		ourTeam = &ourCoach->fs.bBots;	

		if(ourTeam->at(0).distanceTo(ball->pos_x, ball->pos_y) > stopDistance)
			ourTeam->at(0).Move(ball->pos_x, ball->pos_y, 0.5, kickVelocity, ourCoach->teamBlue());	//move towards ball til a distance
		else if(ourTeam->at(0).FaceToward(ball->pos_x, ball->pos_y, kickVelocity, ourCoach->teamBlue()))	//rotate to faceball if close enough
			ourTeam->at(0).Move(ball->pos_x, ball->pos_y, 0.5, kickVelocity, ourCoach->teamBlue());		//go kick if facing right direction
		break;
	default:
		//nothing, no robots D=
		break;
	}
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

	//printFieldState(&ourCoach->fs, "From bluePlayerAnalysis");

	ourCoach->strategy = new BlueSampleStrategy();
	ourCoach->strategy->implement(ourCoach);
}