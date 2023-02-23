#ifndef TIME_H
# define TIME_H
#include <time.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../player/player.h"
#include "../gosts/gost.h"

typedef struct s_time
{
	int	current_time;
	int	previous_time;
	int	elapsed_time;
	int	lag;
}	t_time;


typedef struct s_game
{
	t_window	win;
	t_player	player;
	t_gost		gost;
	t_time		time;
	t_map		map;
	void		*img;
}	t_game;
void	add_time(t_time *time);
void	loop_time(t_game *game);
#endif
