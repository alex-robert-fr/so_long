#include "map.h"

t_map	check_file_map(char *map_file)
{
	t_map		map;

	map.info_map = check_map_and_get_info(map_file);
	map.error_code = 0;
	if (map.info_map.error_code)
	{
		map.error_code = 1;
		return (map);
	}
	printf("\nC: %i, R: %i\n", map.info_map.columns, map.info_map.rows);
	map.map = file_to_array(map_file, map.info_map);
	return (map);
}

t_info_map	check_map_and_get_info(char *map_file)
{
	t_info_map	info_map;
	char		*str;
	int			x_map;
	int			y_map;
	int			fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		info_map.error_code = 1;
		return (info_map);
	}
	x_map = 0;
	y_map = 0;
	str = "";
	while (str)
	{
		str = ft_strtrim(get_next_line(fd), "\n");
		printf("%s", str);
		if (!y_map)
			x_map = ft_strlen(str);
		if (str)
			y_map++;
	}
	info_map.columns = x_map;
	info_map.rows = y_map;
	info_map.error_code = 0;
	close(fd);
	return (info_map);
}

char	**file_to_array(char *map_file, t_info_map info_map)
{
	char	**map;
	char	*str;
	int		fd;
	int		i;

	printf("FILE TO ARRAY\n");
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	str = "";
	map = ft_calloc(info_map.rows + 1, sizeof(char*));
	while (i < info_map.rows)
	{
		map[i] = ft_strtrim(get_next_line(fd), "\n");
		printf("%s", map[i]);
		i++;
	}
	close(fd);
	return (map);
}