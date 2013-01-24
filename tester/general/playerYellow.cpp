#include "../ai/ai.h"

//analysis module to update velocity info to Coach FieldState from memory info
//and activates a strategy of choice (player made)
YellowCoach::analysis()
{
	// updates velocity using only two positions (current and last), then calls basicStrat
	fs.ball.speed_x = (_memory[4].balls(0).x() - _memory[3].balls(0).x()) / (_memory[4].t_sent() - _memory[3].t_sent());
	fs.ball.speed_y = (_memory[4].balls(0).y() - _memory[3].balls(0).y()) / (_memory[4].t_sent() - _memory[3].t_sent());

	for(int i = 0, i < _memory[4].robots_blue_size(); i++)
	{
		for(int j = 0, j < _memory[3].robots_blue_size(); j++)
		{
			if(_memory[4].robots_blue(i).robot_id() == _memory[3].robots_blue(j).robot_id())
			{
				// v = d1 - d2 / t
				for(int k = 0; k < fs.Bbots.size(); ++k)
				{
					if(_memory[4].robots_blue(i).robot_id() == fs.Bbots[k])
					{
						fs.Bbots[k].speed_x = (_memory[4].robots_blue(i).x() - _memory[3].robots_blue(j).x()) /
											  (_memory[4].t_sent() - _memory[3].t_sent());
						fs.Bbots[k].speed_y = (_memory[4].robots_blue(i).y() - _memory[3].robots_blue(j).y()) /
											  (_memory[4].t_sent() - _memory[3].t_sent());
					}
				}
			}
		}
	}
	for(int i = 0; i < _memory[4].robots_yellow_size(); i++)
	{
		for(int j = 0, j < _memory[3].robots_yellow_size(); j++)
		{
			if(_memory[4].robots_yellow(i).robot_id() == _memory[3].robots_yellow(j).robot_id())
			{
				// v = d1 - d2 / t
				for(int k = 0; k < fs.Bbots.size(); ++k)
				{
					if(_memory[4].robots_yellow(i).robot_id() == fs.Bbots[k])
					{
						fs.Ybots[k].speed_x = (_memory[4].robots_yellow(i).x() - _memory[3].robots_yellow(j).x()) /
											  (_memory[4].t_sent() - _memory[3].t_sent());
						fs.Ybots[k].speed_y = (_memory[4].robots_yellow(i).y() - _memory[3].robots_yellow(j).y()) /
											  (_memory[4].t_sent() - _memory[3].t_sent());
					}
				}
			}
		}
	}

	basicStrat myStrat = basicStrat();
	activateStrategy(&myStrat);
}

//basic strategy, one robot moves up and kicks ball to goal
class basicStrat: public Strat
{
public:
	void implement_one()
	{

	}
	void implement_two()
	{
		//not implemented
	}
	void implement_three()
	{
		//not implemented
	}
	void implement_four()
	{
		//not implemented
	}
	void implement_five()
	{
		//not implemented
	}
	basicStrat()
	{
		//nothing to do here
	}
};

