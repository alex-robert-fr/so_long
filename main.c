#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

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

int		move(int keycode, t_vars *vars)
{
	write(1, "A", 1);
	return (0);
}

int		render_next_frame(t_vars *pacman)
{
	int size;
	size = 64;
	pacman->img = mlx_xpm_file_to_image(pacman->mlx, "./assets/pacman_test.xpm", &size, &size);
	mlx_put_image_to_window(pacman->mlx, pacman->win, pacman->img, pacman->i, 0);
	mlx_destroy_image(pacman->mlx, pacman->img);
	write(1, "X", 1);
	usleep(10000);
	pacman->i++;
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		h;
	int		l;

	h = 242;
	l = 429;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	vars.i = 0;
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Pacman");
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./assets/o_map.xpm", &l, &l);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.i, 0);
	// mlx_key_hook(vars.win, move, (void *)0);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	// mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}