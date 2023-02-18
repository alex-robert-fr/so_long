#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <dirent.h>
#include "convert_size.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	size;

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc == 1)
	{
		printf("Compiled files in directory\n");
		size = 24;
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir("./assets")) != NULL) {
		    while ((ent = readdir(dir)) != NULL) {
				if (ent->d_name[0] != '.')
				{
					str = ft_strjoin("./assets/", ent->d_name);
					printf("%s\n", str);
					if (convert_file(str))
					{
						printf("ERROR !");
						return(1);
					}
				}
		    }
		    closedir(dir);
		}
		
	}
	else if (argc == 3)
	{
		printf("Compiled file\n\n");
		size = ft_atoi(argv[2]);
		if (convert_file(argv[1]))
		{
			printf("ERROR !");
			return(1);
		}
	}
	else
		printf("Not argument");
	return (0);
}

int		convert_file(char *file_path)
{
	int	fd;
	t_img img;

	fd = open(file_path, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (1);
	img = read_img(fd);
	img.new_img = convert_size(&img);
	printf("C->%i\n", img.info_img.column);
	printf("R->%i\n", img.info_img.rows);
	if (generate_file(ft_get_file_name(file_path), img))
		return (1);
	return (0);
}

t_img		read_img(int fd)
{
	t_img 	img;
	t_info_img info_img;
	t_data_img data_img;
	char	*line;
	int		nb_info;
	int		i;
	int 	i_colors;

	i = 0;
	i_colors = 0;
	nb_info = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '"')
		{
			if ((line[1] >= '0' && line[1] <= '9') && nb_info == 1)
			{
				nb_info++;
				info_img = get_info_img(line);
				continue ;
			}
			else if (nb_info == 2)
			{
				nb_info++;
				data_img.colors = get_colors_img(fd, info_img);
				continue ;
			}
			else
			{
				data_img.img = get_data_img(fd, info_img);
				break ;
			}
		}
		line = get_next_line(fd);
		if (!line)
			break;
	}
	img.o_img = data_img;
	img.info_img = info_img;
	return (img);	
}

t_info_img		get_info_img(char *src)
{
	t_info_img dest;
	int	i;
	int	data_number;

	i = 0;
	data_number = 1;
	while (src[i] != '\n')
	{
		if (src[i] == ' ')
			data_number++;
		if (ft_isdigit(src[i]) && (src[i - 1] == ' ' || src[i - 1] == '"'))
		{
			if (data_number == 1)
				dest.column = ft_atoi(src + i);
			if (data_number == 2)
				dest.rows = ft_atoi(src + i);
			if (data_number == 3)
				dest.colors = ft_atoi(src + i);
		}
		i++;
	}
	return (dest);
}

char	**get_colors_img(int fd, t_info_img info_img)
{
	char	**colors_img;
	int	i;
	
	colors_img = ft_calloc(info_img.colors + 1, sizeof(char*));
	i = 0;
	while (i < info_img.colors)
	{
		colors_img[i] = ft_strtrim(get_next_line(fd), "\"\n,");

		printf("IN COLORS=> %s\n",colors_img[i]);
		i++;
	}
	return (colors_img);
}

char	**get_data_img(int fd, t_info_img info_img)
{
	char	**data_img;
	char	*str;
	int		i;

	data_img = ft_calloc(info_img.rows + 1, sizeof(char*));
	i = 0;
	while (i < info_img.rows)
	{
		str = get_next_line(fd);
		if (*str == '"')
		{
			data_img[i] = ft_strtrim(str, "\"\n,");
			printf("IN IMG=> %s\n",data_img[i]);
			i++;
		}
	}
	return (data_img);
}

int		generate_file(char *file_name, t_img img)
{
	int	new_fd;
	int	i;

	new_fd = open(ft_strjoin("./new_assets/new_", file_name), O_WRONLY | O_CREAT, 00700);
	if (new_fd < 0)
		return (1);
	i = 0;
	ft_putstr_fd("/* XPM */\nstatic char *img[] = {\n", new_fd);
	ft_putchar_fd('"', new_fd);
	ft_putnbr_fd(img.info_img.column, new_fd);
	ft_putchar_fd(' ', new_fd);
	ft_putnbr_fd(img.info_img.rows, new_fd);
	ft_putchar_fd(' ', new_fd);
	ft_putnbr_fd(img.info_img.colors, new_fd);
	ft_putchar_fd(' ', new_fd);
	ft_putchar_fd('1', new_fd);
	ft_putstr_fd("\",\n", new_fd);
	while (img.o_img.colors[i])
	{
		ft_putchar_fd('"', new_fd);
		ft_putstr_fd(img.o_img.colors[i], new_fd);
		ft_putstr_fd("\",\n", new_fd);
		i++;
	}
	i = 0;
	while (img.new_img[i])
	{
		ft_putchar_fd('"', new_fd);
		ft_putstr_fd(img.new_img[i], new_fd);
		ft_putstr_fd("\"\n", new_fd);
		i++;
	}
	ft_putstr_fd("};", new_fd);
	close(new_fd);
	return (0);
}
 
char	**convert_size(t_img *img)
{
	float	c;
	float	r;
	int		i;
	int x;
	int		i_rows;
	char 	**line;

	i = 0;
	c = roundf((float)size / img->info_img.column);
	r = roundf((float)size / img->info_img.rows);
	printf("Base: %dx%d\nNew: %fx%f\n", img->info_img.column, img->info_img.rows, c, r);
	printf("MALLOC: %f\n", img->info_img.rows * r);
	line = ft_calloc((img->info_img.rows * r) + 10, sizeof(char *));
	i_rows = 0;
	while (i < img->info_img.rows)
	{	
		x = 0;
		while (x < r)
		{
			line[i_rows] = write_by_x(img->o_img.img[i], c, img->info_img);
			x++;
			i_rows++;
		}
		i++;
	}
	img->info_img.column *= c;
	img->info_img.rows *= r;
	return (line);
}

char	*write_by_x(char *str, int num_x, t_info_img info_img)
{
	int	i;
	int x;
	int i_line;
	char *line;

	i = 0;
	i_line = 0;
	if (!str)
		return (NULL);
	line = ft_calloc(roundf((float)size / info_img.column) * info_img.column + 1, 1);
	while (i < info_img.column)
	{
		x = 0;
		while (x < num_x)
		{
			// ft_putchar_fd(str[i], 1);
			line[i_line] = str[i];
			i_line++;
			x++;
		}
		i++;
	}
	printf("%s\n", line);
	return (line);
}