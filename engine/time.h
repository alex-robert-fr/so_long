#ifndef TIME_H
# define TIME_H
#include "../libft/libft.h"
#include "../player/player.h"

typedef struct s_time
{
	int	current_time;
	int	previous_time;
}	t_time;


typedef struct s_game
{
	t_window	win;
	t_player	player;
	t_time		time;
	t_map		map;
	void		*img;
}	t_game;
void	add_time(t_time *time);
void	loop_time(t_game *game);
#endif
