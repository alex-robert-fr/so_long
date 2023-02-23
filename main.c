#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./engine/time.h"
#include "pacman.h"
#include "./map/map.h"
#include "./player/player.h"
#include "./keyboard/keyboard.h"
int	start(char *map_file);

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	int		i;
}			t_vars;


int		ft_close(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}
int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (start(argv[1]))
		{
			printf("Error\n");
			return (0);
		}
		printf("With map");
	}
	else
		printf("Error\n");
}

int	start(char *map_file)
{
	t_map		map;
	t_window	win;
	t_game		game;

	
	game.time.current_time = 0;
	game.time.previous_time = 0;
	map = check_file_map(map_file);
	 if (map.error_code)
	 	return (1);
	game.map = map;
	printf("TEST!");
	win = create_window(map.info_map.columns * 24, map.info_map.rows * 24, "Pacman");
	if (win.error_code)
		return (1);
	generate_map(map.map, win, map.info_map);
	game.player = spawn_player(win, 1, 1);
	game.win = win;
	mlx_hook(win.win, 17, 0, ft_close, &win);
	mlx_loop_hook(win.mlx, render_next_frame, &game);
	mlx_key_hook(game.win.win, keyboard, &game.player);
	mlx_loop(win.mlx);
	return (0);
}
  
int		render_next_frame(t_game *game)
{
	int size;

	add_time(&game->time);
	loop_time(game);
	size = 22;
	game->img = mlx_xpm_file_to_image(game->win.mlx, "./convert_size/new_assets/new_pacman.xpm", &size, &size);
	mlx_put_image_to_window(game->win.mlx,game->win.win, game->img, game->player.position.x - 5, game->player.position.y - 5);
	mlx_destroy_image(game->win.mlx, game->img);
	//move(&game->player);
	usleep(1500);
	return (0);
}
