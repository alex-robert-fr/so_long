#include "./player/player.h"

typedef struct s_game
{
	t_window	win;
	t_player	player;
	t_map		map;
	void		*img;
}	t_game;


int		render_next_frame(t_game *game);