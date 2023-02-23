#include "map.h"

void			generate_map(char **map, t_window win, t_info_map info_map, t_game game)
{
	t_sprites	imgs;
	int		x;
	int		y;

	y = 0;
	imgs = import_img(win);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				/* -------------------------------------------------------------------------- */
				/*                                     MUR                                    */
				/* -------------------------------------------------------------------------- */
				// Mur gauche
				if (x == 0 && map[y][x + 1] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp3_0, (x * 24), (y * 24));
				}
				// Mur Droite
				else if (x == info_map.columns - 1 && map[y][x - 1] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp2_0, (x * 24), (y * 24));
				}
				// Mur Haut
				else if (y == 0 && map[y + 1][x] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp10_0, (x * 24), (y * 24));
				}
				// Mur Bas
				else if (y == info_map.rows - 1 && map[y - 1][x] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp13_0, (x * 24), (y * 24));
				}
				// Angle 0, 0
				else if (x == 0 && y == 0)
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp1_0, (x * 24), (y * 24));
				}
				// Angle 0, 1
				else if (x == info_map.columns - 1 && y == 0)
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp0_0, (x * 24), (y * 24));
				}
				// Angle 1, 0
				else if (x == 0 && y == info_map.rows - 1)
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp5_0, (x * 24), (y * 24));
				}
				// Angle 1, 1
				else if (x == info_map.columns - 1 && y == info_map.rows -1)
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp4_0, (x * 24), (y * 24));
				}
				// Mur Haut + extension gauche
				else if (y == 0 && map[y + 1][x] == '1' && map[y + 1][x - 1] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp11_2, (x * 24), (y * 24));
				}
				// Mur Haut + extension droite
				else if (y == 0 && map[y + 1][x] == '1' && map[y + 1][x + 1] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp10_2, (x * 24), (y * 24));
				}
				/* -------------------------------------------------------------------------- */
				/*                                    BLOC                                    */
				/* -------------------------------------------------------------------------- */
				// Bloc Haut
				else if (map[y][x - 1] == '1' && map[y][x + 1] == '1' && map[y - 1][x] == '0' && map[y + 1][x] == '1')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp14_0, (x * 24), (y * 24));
				}
				// Bloc bas
				else if (map[y][x - 1] == '1' && map[y][x + 1] == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp4_1, (x * 24), (y * 24));
				}
				// Bloc gauche
				else if (map[y][x - 1] == '0' && map[y][x + 1] == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '1')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp9_1, (x * 24), (y * 24));
				}
				// Bloc droite
				else if (map[y][x - 1] == '1' && map[y][x + 1] == '0' && map[y - 1][x] == '1' && map[y + 1][x] == '1')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp8_1, (x * 24), (y * 24));
				}
				// Angle Bloc 0, 0
				else if (map[y][x - 1] == '0' && map[y][x + 1] == '1' && map[y - 1][x] == '0' && map[y + 1][x] == '1')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp7_1, (x * 24), (y * 24));
				}
				// Angle Bloc 0, 1
				else if (map[y][x - 1] == '1' && map[y][x + 1] == '0' && map[y - 1][x] == '0' && map[y + 1][x] == '1')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp6_1, (x * 24), (y * 24));
				}
				// Angle Bloc 1, 0
				else if (map[y][x - 1] == '0' && map[y][x + 1] == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp9_2, (x * 24), (y * 24));
				}
				// Angle Bloc 1, 1
				else if (map[y][x - 1] == '1' && map[y][x + 1] == '0' && map[y - 1][x] == '1' && map[y + 1][x] == '0')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp10_1, (x * 24), (y * 24));
				}
				// Interieur bloc
				else if (map[y][x - 1] == '1' && map[y][x + 1] == '1' && map[y - 1][x] == '1' && map[y + 1][x] == '1')
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.sp12_2, (x * 24), (y * 24));
				}
				else
				{
					mlx_put_image_to_window(win.mlx, win.win, imgs.spxxx, (x * 24), (y * 24));
				}
			}
			else if (map[y][x] == 'G')
			{
				mlx_put_image_to_window(win.mlx, win.win, game.gost.sprite, game.gost.position.x, game.gost.position.y);
			}
			ft_putchar_fd('[', 1);
			ft_putnbr_fd(y, 1);
			ft_putchar_fd(',', 1);
			ft_putnbr_fd(x, 1);
			ft_putchar_fd(']', 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}

t_sprites		import_img(t_window win)
{
	t_sprites sprites;
	int	size;
	int	g_size;

	size = 24;
	g_size = 33;
	sprites.sp0_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map0_0.xpm",&size, &size);
	sprites.sp1_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map1_0.xpm", &size, &size);
	sprites.sp2_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map2_0.xpm", &size, &size);
	sprites.sp3_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map3_0.xpm", &size, &size);
	sprites.sp4_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map4_0.xpm", &size, &size);
	sprites.sp4_1 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map4_1.xpm", &size, &size);
	sprites.sp5_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map5_0.xpm", &size, &size);
	sprites.sp6_1 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map6_1.xpm", &size, &size);
	sprites.sp7_1 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map7_1.xpm", &size, &size);
	sprites.sp8_1 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map8_1.xpm", &size, &size);
	sprites.sp9_1 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map9_1.xpm", &size, &size);
	sprites.sp9_2 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map9_2.xpm", &size, &size);
	sprites.sp10_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map10_0.xpm", &size, &size);
	sprites.sp10_1 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map10_1.xpm", &size, &size);
	sprites.sp10_2 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map10_2.xpm", &size, &size);
	sprites.sp11_2 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map11_2.xpm", &size, &size);
	sprites.sp12_2 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map12_2.xpm", &size, &size);
	sprites.sp13_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map13_0.xpm", &size, &size);
	sprites.sp14_0 = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_map14_0.xpm", &size, &size);
	sprites.spxxx = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_no_valid.xpm", &size, &size);
	sprites.gost = mlx_xpm_file_to_image(win.mlx, "./convert_size/new_assets/new_gost.xpm", &g_size, &g_size);
	return (sprites);
}
