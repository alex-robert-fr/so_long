#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	// mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

// int		move(int keycode, t_vars *vars)
// {
// 	write(1, "A", 1);
// 	return (0);
// }

// int		render_next_frame(t_vars *pacman)
// {
// 	int size;
// 	size = 64;
// 	pacman->img = mlx_xpm_file_to_image(pacman->mlx, "./assets/pacman_test.xpm", &size, &size);
// 	mlx_put_image_to_window(pacman->mlx, pacman->win, pacman->img, pacman->i, 0);
// 	mlx_destroy_image(pacman->mlx, pacman->img);
// 	write(1, "X", 1);
// 	usleep(10000);
// 	pacman->i++;
// 	return (0);
// }

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
	// t_vars	vars;
	// int		h;
	// int		l;

	// h = 242;
	// l = 429;
	// vars.mlx = mlx_init();
	// if (!vars.mlx)
	// 	return (0);
	// vars.i = 0;
	// vars.win = mlx_new_window(vars.mlx, 500, 500, "Pacman");
	// vars.img = mlx_xpm_file_to_image(vars.mlx, "./convert_size/new_assets/new_map9_0.xpm", &l, &l);
	// mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.i, 0);
	// // mlx_key_hook(vars.win, move, (void *)0);
	// mlx_hook(vars.win, 17, 0, ft_close, &vars);
	// // mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	// mlx_loop(vars.mlx);
}

int	start(char *map_file)
{
	t_map		map;
	t_window	win;
	t_game		game;
	
	map = check_file_map(map_file);
	 if (map.error_code)
	 	return (1);
	game.map = map;
	printf("TEST!");
	win = create_window(map.info_map.columns * 24, map.info_map.rows * 24, "Pacman");
	if (win.error_code)
		return (1);
	generate_map(map.map, win, map.info_map);
	game.player = spawn_player(win, 24, 24);
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

	size = 22;
	game->img = mlx_xpm_file_to_image(game->win.mlx, "./convert_size/new_assets/new_pacman.xpm", &size, &size);
	mlx_put_image_to_window(game->win.mlx,game->win.win, game->img, game->player.position.x - 5, game->player.position.y - 5);
	mlx_destroy_image(game->win.mlx, game->img);
	move(&game->player);
	collision(&game->player, game->map);
	usleep(10000);
	return (0);
}