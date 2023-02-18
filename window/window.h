#ifndef	WINDOW_H
# define WINDOW_H

#include <stdio.h>
#include <mlx.h>

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		error_code;
}	t_window;

t_window	create_window(int x, int y, char *title);
#endif