#ifndef	MAP_H
# define MAP_H

#include <stdio.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include "../window/window.h"
#include "../gosts/gost.h"
#include "../player/player.h"
#include "../engine/time.h"

typedef struct s_info_map
{
	int	columns;
	int	rows;
	int	error_code;
}	t_info_map;

typedef struct s_map
{
	char		**map;
	t_info_map	info_map;
	int			error_code;
}	t_map;

typedef struct s_sprites
{
	void	*sp0_0;
	void	*sp1_0;
	void	*sp2_0;
	void	*sp3_0;
	void	*sp4_0;
	void	*sp4_1;
	void	*sp5_0;
	void	*sp6_1;
	void	*sp7_1;
	void	*sp8_1;
	void	*sp9_1;
	void	*sp9_2;
	void	*sp10_0;
	void	*sp10_1;
	void	*sp10_2;
	void	*sp12_2;
	void	*sp11_2;
	void	*sp13_0;
	void	*sp14_0;
	void	*spxxx;
	void	*gost;
}	t_sprites;


t_map			check_file_map(char *map_file);
t_info_map		check_map_and_get_info(char *map_file);
char			**file_to_array(char *map_file, t_info_map info_map);
void			generate_map(char **map, t_window win, t_info_map info_map, t_game game);
t_sprites		import_img(t_window win);
#endif
