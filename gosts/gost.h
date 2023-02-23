#ifndef GOST_H
# define GOST_H
#include "../player/player.h"
typedef struct s_gost
{
	t_vector2	position;
	int		speed;
	void		*sprite;
	t_vector2	direction;
}	t_gost;
t_gost	spawm_gost(t_window win, int x, int y);
void		*import_gost(t_window win, char *path);
#endif
