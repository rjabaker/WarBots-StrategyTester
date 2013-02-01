#include "debug.h"

void printDetectionFrame(SSL_DetectionFrame* df, const char* dmsg)
{
	printf("\nPrinting DetectionFrame, debug message: %s\n", dmsg);
	printf("Frame number: %d, Time stamp: %f\n", df->frame_number(), df->t_sent());
	printf("Number of balls: %d\n", df->balls_size());
	for (int i = 0; i < df->balls_size(); ++i)
	{
		printf("\tBall #%d: x: %f, y: %f\n", i, df->balls(i).x(), df->balls(i).y());
	}
	printf("Number of blue robots: %d\n", df->robots_blue_size());
	for (int i = 0; i < df->robots_blue_size(); ++i)
	{
		printf("\tBlue bot #%d: [%f, %f], orientation: %f\n", 
												df->robots_blue(i).robot_id(),
												df->robots_blue(i).x(), 
												df->robots_blue(i).y(),
												df->robots_blue(i).orientation());
	}

	printf("Number of yellow robots: %d\n", df->robots_yellow_size());
	for (int i = 0; i < df->robots_yellow_size(); ++i)
	{
		printf("\tYellow bot #%d: [%f, %f], orientation: %f\n", 
												df->robots_yellow(i).robot_id(),
												df->robots_yellow(i).x(), 
												df->robots_yellow(i).y(),
												df->robots_yellow(i).orientation());
	}
	printf("\n");
}

void printFieldState(FieldState* fs, const char* dmsg)
{
	printf("\nPrinting FieldState, debug message: %s\n", dmsg);
	printf("\tBall position: [%f, %f], velocity: [%f, %f]\n",
												fs->ball.pos_x, fs->ball.pos_y,
												fs->ball.speed_x, fs->ball.speed_y);

	printf("Number of blue robots: %d\n", fs->bBots.size());
	for (int i = 0; i < fs->bBots.size(); ++i)
	{
		printf("\tBlue bot #%d: position: [%f, %f]\n\t\tvelocity: [%f, %f] orientation: %f\n", 
												fs->bBots[i].id,
												fs->bBots[i].pos_x, 
												fs->bBots[i].pos_y,
												fs->bBots[i].speed_x, 
												fs->bBots[i].speed_y,
												fs->bBots[i].orientation);
	}

	printf("Number of yellow robots: %d\n", fs->yBots.size());
	for (int i = 0; i < fs->yBots.size(); ++i)
	{
		printf("\tYellow bot #%d: position: [%f, %f]\n\t\tvelocity: [%f, %f] orientation: %f\n", 
												fs->yBots[i].id,
												fs->yBots[i].pos_x, 
												fs->yBots[i].pos_y,
												fs->yBots[i].speed_x, 
												fs->yBots[i].speed_y,
												fs->yBots[i].orientation);
	}
	printf("\n");
}