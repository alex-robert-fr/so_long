#include "./time.h"
#include <time.h>
#include <unistd.h>

void	add_time(t_time *time)
{
	time->current_time++;
}

void	loop_time(t_game *game)
{
//	printf("\033[33mLOOP_TIME\033[0m\n");
//	printf("\033[33mPREVIOUS_TIME = %i\033[0m\n", game->time.previous_time);
	game->time.current_time = clock();
//	printf("\033[33mCURRENT_TIME = %i\033[0m\n", game->time.current_time);
	game->time.elapsed_time = game->time.current_time - game->time.previous_time;
//	printf("\033[33mELAPSED_TIME = %i\033[0m\n", game->time.elapsed_time);
	game->time.previous_time = game->time.current_time;
//	printf("\033[33mPREVIOUS_TIME = %i\033[0m\n", game->time.previous_time);
	game->time.lag += game->time.elapsed_time;
//	printf("\033[33mLAG = %i\033[0m\n", game->time.lag);
	//ft_putstr_fd("Add time: ", 1);
	//ft_putnbr_fd(game->time.current_time, 1);
	//ft_putstr_fd("\n", 1);
	//ft_putstr_fd("TIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMEEEEEEEEEEEEEEEEEEEEEEEEEEEE",1);
	while (game->time.lag >= 1500)
	{
		move(&game->player, game->map);
		game->time.lag -= 1500;
		printf("\033[41mLOOP\033[0m\n");
	}
	//collision(&game->player, game->map);
//	game->time.previous_time = game->time.current_time;
//	printf("\033[33mEND\033[0m\n");
//	usleep(start + 1500 - (unsigned long)time(NULL));
}
