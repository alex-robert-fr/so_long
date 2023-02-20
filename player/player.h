#ifndef	PLAYER_H
# define PLAYER_H

#include "../libft/libft.h"
#include "../map/map.h"
#include "../window/window.h"

typedef struct s_vector2
{
	 int	x;
	 int	y;
}	t_vector2;


typedef struct s_player
{
	t_vector2	position;
	int		speed;
	void		*sprite;
	t_vector2	direction;
	t_vector2	next_direction;
}	t_player;


t_player	spawn_player(t_window win, int x, int y);
void		*import_player(t_window win, char *path);
void		move(t_player *player, t_map map);
int		check_direction(t_player *player, t_map map);
void		collision(t_player *player, t_map map);
#endif
