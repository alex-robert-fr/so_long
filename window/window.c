#include "window.h"

t_window	create_window(int x, int y, char *title)
{
	t_window window;

	window.mlx = mlx_init();
	window.error_code = 0;
	if (!window.mlx)
	{
		window.error_code = 1;
		return (window);
	}
	window.win = mlx_new_window(window.mlx, x, y, "Pacman");
	return (window);
}