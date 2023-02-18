#include "player.h"

t_player	spawn_player(t_window win, int x, int y)
{
	t_player	player;
	t_vector2 direction;

	direction.x = 1;
	direction.y = 0;
	player.sprite = import_player(win, "./convert_size/new_assets/new_pacman.xpm");
	player.position.x = x;
	player.position.y = y;
	player.speed = 1;
	player.direction = direction;
	return (player);
}

void	*import_player(t_window win, char *path)
{
	void	*player;
	int		size;

	size = 33;
	player = mlx_xpm_file_to_image(win.mlx, path, &size, &size);
	return (player);
}

void	move(t_player *player)
{
	if (player->direction.x > 0)
		player->position.x += player->speed;
	if (player->direction.x < 0)
		player->position.x -= player->speed;
	if (player->direction.y > 0)
		player->position.y += player->speed;
	if (player->direction.y < 0)
		player->position.y -= player->speed;
	// ft_putstr_fd("POS X: ",1);
	// ft_putnbr_fd((float)player->position.x / 24,1);
	// ft_putstr_fd("\n",1);
}

void	collision(t_player *player, t_map map)
{
	int	current_x;
	int	current_y;
	ft_putstr_fd("X: ",1);
	ft_putnbr_fd(player->position.x / 24, 1);
	ft_putstr_fd("Y: ",1);
	ft_putnbr_fd(player->position.y / 24, 1);
	ft_putstr_fd("\n",1);
	if (player->direction.x > 0)
		current_x = (player->position.x + 20) / 24;
	if (player->direction.x <= 0)
		current_x = (player->position.x) / 24;
	if (player->direction.y > 0)
		current_y = (player->position.y + 20) / 24;
	if (player->direction.y <= 0)
		current_y = player->position.y / 24;
	if ((player->direction.x < 0 && map.map[current_y][current_x] == '1') || (player->direction.x > 0 && map.map[current_y][current_x] == '1'))
	{
		player->position.x -= player->speed * player->direction.x;
		player->direction.x = 0;
		ft_putstr_fd("TA MERE",1);
	}
	if ((player->direction.y < 0 && map.map[current_y][current_x] == '1') || (player->direction.y > 0 && map.map[current_y][current_x] == '1'))
	{
		player->position.y -= player->speed * player->direction.y;
		player->direction.y = 0;
		ft_putstr_fd("TON PERE",1);
	}
	
	// else if (map.map[current_y + 1][current_x] == '1')
	// {
	// 	player->direction.y = 0;
	// 	player->position.y -= player->speed;
	// }
	// else if (map.map[current_y - 1][current_x] == '1')
	// {
	// 	player->direction.y = 0;
	// 	player->position.y += player->speed;
	// }
}