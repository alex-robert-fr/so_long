#include <math.h>
#include <stdio.h>
#include "player.h"

t_player	spawn_player(t_window win, int x, int y)
{
	t_player	player;
	t_vector2 direction;

	direction.x = 1;
	direction.y = 0;
	player.sprite = import_player(win, "./convert_size/new_assets/new_pacman.xpm");
	player.position.x = (x * 24);
	player.position.y = (y * 24);
	player.speed = 1;
	player.direction = direction;
	player.next_direction = direction;
	return (player);
}

void	*import_player(t_window win, char *path)
{
	void	*player;
	int		size;

	size = 33;
	player = mlx_xpm_file_to_image(win.mlx, path, &size -1, &size);
	return (player);
}

void	move(t_player *player, t_map map)
{
	//float	x_pos;
	//float	y_pos;
//
	//x_pos = ceilf((float)player->position.x / 24);
	//y_pos = ceilf((float)player->position.y / 24);
	check_direction(player, map);
	if (player->direction.x > 0)
	{
//		if (map.map[(int)y_pos][(int)x_pos + 1] == '1' && ((float)player->position.y / 24) == ceilf((float)player->position.y / 24))
		player->position.x += player->speed;
	}
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

int		check_direction(t_player *player, t_map map)
{
	float	x_pos;
	float	y_pos;

	x_pos = ceilf((float)player->position.x / 24);
	y_pos = ceilf((float)player->position.y / 24);
	if ((float)player->position.x / 24 == ceilf((float)player->position.x / 24) - 1)
		printf("\033[36mTEST ===> %f == %f\033[0m\n", (float)player->position.x / 24, ceilf((float)player->position.x / 24));
//	printf("%f < %f\n", (float)player->position.x / 24, ceilf((float)player->position.x / 24) );
	printf("X: %f, Y; %f\n", x_pos, y_pos);
	printf("X: %i, Y; %i => %c\n", (int)x_pos, (int)y_pos, map.map[(int)y_pos + 1][(int)x_pos - 1]);
	fflush(stdout);
	if (player->next_direction.y > 0)
	{
		ft_putstr_fd("\033[31mPASS NEXT\033[0m\n", 1);
		if (map.map[(int)y_pos + 1][(int)x_pos] == '0' && ((float)player->position.x / 24) == ceilf((float)player->position.x / 24))
		{
			ft_putstr_fd("DIRECTIOHN\n",1);
			player->direction.y = 1;
			player->direction.x = 0;
		}
	}
	if (player->next_direction.x > 0)
	{
		ft_putstr_fd("YOOO", 1);
		if (map.map[(int)y_pos][(int)x_pos + 1] == '0' && ((float)player->position.y / 24) == ceilf((float)player->position.y / 24))
		{
			ft_putstr_fd("ALEX\n",1);
			player->direction.y = 0;
			player->direction.x = 1;
		}
	}
	if (player->next_direction.y < 0)
	{
		ft_putstr_fd("YOOO", 1);
		if (map.map[(int)y_pos - 1][(int)x_pos] == '0' && ((float)player->position.x / 24) == ceilf((float)player->position.x / 24))
		{
			ft_putstr_fd("ALEX\n",1);
			player->direction.y = -1;
			player->direction.x = 0;
		}
	}
	if (player->next_direction.x < 0)
	{
		ft_putstr_fd("YOOO", 1);
		if (map.map[(int)y_pos][(int)x_pos - 1] == '0' && ((float)player->position.y / 24) == ceilf((float)player->position.y / 24))
		{
			ft_putstr_fd("ALEX\n",1);
			player->direction.y = 0;
			player->direction.x = -1;
		}
	}
	return (0);
}

void	collision(t_player *player, t_map map)
{
	int	current_x;
	int	current_y;
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
