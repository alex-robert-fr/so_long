#include "gost.h"
#include "../window/window.h"

t_gost	spawm_gost(t_window win, int x, int y)
{
	t_gost		gost;
	t_vector2	direction;

	direction.x = 0;
	direction.y = -1;
	gost.sprite = import_gost(win, "./convert_size/new_assets/new_gost.xpm");
	gost.position.x = (x * 24);
	gost.position.y = (y * 24);
	gost.speed = 1;
	gost.direction = direction;
	return (gost);
}

void	*import_gost(t_window win, char *path)
{
	void	*gost;
	int		size;

	size = 33;
	gost = mlx_xpm_file_to_image(win.mlx, path, &size, &size);
	return (gost);
}
