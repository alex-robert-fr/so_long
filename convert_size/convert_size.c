#include <fcntl.h>
#include <stdio.h>
#include "convert_size.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		printf("Compiled files in directory");
	else if (argc == 2)
	{
		printf("Compiled file\n");
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
	if (!img.o_img)
		return (1);
	printf("%s\n", file_path);
	printf("PASS");
	if (generate_file(ft_get_file_name(file_path), img))
		return (1);
	return (0);
}

t_img		read_img(int fd)
{
	t_img 	img;
	char	*line;
	char	*str;
	int		start_img;
	int		end_img;
	int		i_to_start;
	int		i;
	int		i_tab;
	int 	i_colors;

	i = 0;
	i_tab = 0;
	line = "";
	img.o_img = NULL;
	img.colors = NULL;
	start_img = 0;
	i_to_start = 0;
	i_colors = 0;
	while (line)
	{
		i++;
		line = get_next_line(fd);
		if (!line)
			break;
		if (*line == '"')
		{
			if (!i_to_start)
			{
				start_img = read_info_img(line, 3);
				end_img = read_info_img(line, 2);
				if (start_img < 0)
				{
					img.o_img = NULL;
					return (img);
				}
			}
			if (!img.colors)
			{
				img.colors = ft_calloc(start_img + 1, sizeof(char*));
				if (!img.colors)
				{
					img.colors = NULL;
					return (img);
				}
			}
			if (i_colors < start_img && line[3] == 'c')
			{
				str = ft_strtrim(line, "\"\n,");
				if (!str)
				{
					img.o_img = NULL;
					return (img);
				}
				img.colors[i_colors] = str;
				printf("%s\n", img.colors[i_colors]);
				i_colors++;
			}
			if (!img.o_img)
			{
				img.o_img = ft_calloc((end_img - start_img) + 4, sizeof(char*));
				if (!img.o_img)
				{
					img.o_img = NULL;
					return (img);
				}
			}
			if (i_to_start > start_img)
			{
				str = ft_strtrim(line, "\"\n");
				if (!str)
				{
					img.o_img = NULL;
					return (img);
				}
				img.o_img[i_tab] = str;
				i_tab++;
			}
			i_to_start++;
		}
	}
	return (img);	
}

int		generate_file(char *file_name, t_img img)
{
	int	new_fd;
	int	i;

	new_fd = open(ft_strjoin("new_", file_name), O_WRONLY | O_CREAT, 00700);
	if (new_fd < 0)
		return (1);
	i = 0;
	ft_putstr_fd("/* XPM */\nstatic char *img[] = {\n", new_fd);
	while (img.colors[i])
	{
		ft_putchar_fd('"', new_fd);
		ft_putstr_fd(img.colors[i], new_fd);
		ft_putstr_fd("\",\n", new_fd);
		i++;
	}
	i = 0;
	while (img.o_img[i])
	{
		ft_putchar_fd('"', new_fd);
		ft_putstr_fd(img.o_img[i], new_fd);
		ft_putstr_fd("\",\n", new_fd);
		i++;
	}
	ft_putstr_fd("};", new_fd);
	close(new_fd);
	return (0);
}

// int		generate_img()

int		read_info_img(char *info_str, int num_info)
{
	int	info_img;
	int	count_space;
	int i;

	i = 0;
	info_img = 0;
	count_space = 0;
	while (info_str[i] && !info_img)
	{
		if (info_str[i] == ' ')
			count_space++;
		i++;
		if (count_space == (num_info - 1))
			info_img = ft_atoi(info_str + i);
	}
	return (info_img);
}
// int		size = 3;

// void	convert_size(char *str);
// void	write_suite(char c, int start, int end);

// int		main(int argc, char *argv[])
// {
// 	int fd;
// 	int i_size;
// 	char *str;

// 	str = "";
// 	fd = open("./map.txt", O_RDONLY);
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		i_size = 0;
// 		while (i_size < size)
// 		{
// 			ft_putchar_fd('"', 1);
// 			convert_size(str);
// 			ft_putchar_fd('"', 1);
// 			ft_putchar_fd(',', 1);
// 			ft_putchar_fd('\n', 1);
// 			i_size++;
// 		}
		
// 	}
// 	close(fd);
// }

// void	convert_size(char *str)
// {
// 	char	caractere;
// 	int		len_str;
// 	int		i;
// 	int		ii;
// 	int i_size;

// 	if (!str)
// 		return ;
// 	i = 0;
// 	len_str = ft_strlen(str);
// 	while (str[i])
// 	{
// 		i_size = 0;
// 		caractere = str[i];
// 		if (caractere == '\n')
// 		{
// 			i++;
// 			continue ;
// 		}
// 		ii = i + 1;
// 		while (str[ii] == caractere)
// 			ii++;
// 		write_suite(caractere, i, ii);
// 		i = ii;
// 	}

// }

// void	write_suite(char c, int start, int end)
// {
// 	int i;

// 	i = 0;
// 	while (i < (end - start) * size)
// 	{
// 		ft_putchar_fd(c, 1);
// 		i++;
// 	}
// }