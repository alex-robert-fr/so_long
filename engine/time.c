#include "./time.h"

void	add_time(t_time *time)
{
	time->current_time++;
}

void	loop_time(t_game *game)
{
	if (game->time.previous_time + 5 == game->time.current_time)
	{
		//ft_putstr_fd("Add time: ", 1);
		//ft_putnbr_fd(game->time.current_time, 1);
		//ft_putstr_fd("\n", 1);
		//ft_putstr_fd("TIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMEEEEEEEEEEEEEEEEEEEEEEEEEEEE",1);
		move(&game->player, game->map);
		//collision(&game->player, game->map);
		game->time.previous_time = game->time.current_time;
	}
}
