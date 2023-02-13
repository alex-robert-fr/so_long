#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

int		size = 6;

// char	*get_unique_char(char *str);
void	convert_size(char *str);
void	write_suite(char c, int start, int end);

int		main(int argc, char *argv[])
{
	int fd;
	int i_size;
	char *str;

	str = "";
	fd = open("./convert_size/pacman.txt", O_RDONLY);
	while (str)
	{
		str = get_next_line(fd);
		i_size = 0;
		while (i_size < size)
		{
			ft_putchar_fd('"', 1);
			convert_size(str);
			ft_putchar_fd('"', 1);
			ft_putchar_fd(',', 1);
			ft_putchar_fd('\n', 1);
			i_size++;
		}
		
	}
	close(fd);
}

void	convert_size(char *str)
{
	char	caractere;
	int		len_str;
	int		i;
	int		ii;
	int i_size;

	if (!str)
		return ;
	i = 0;
	len_str = ft_strlen(str);
	while (str[i])
	{
		i_size = 0;
		caractere = str[i];
		if (caractere == '\n')
		{
			i++;
			continue ;
		}
		ii = i + 1;
		while (str[ii] == caractere)
			ii++;
		write_suite(caractere, i, ii);
		i = ii;
	}

}

void	write_suite(char c, int start, int end)
{
	int i;

	i = 0;
	while (i < (end - start) * size)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}