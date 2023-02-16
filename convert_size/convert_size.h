#ifndef CONVERT_SIZE_H

typedef struct s_info_img
{
	int	column;
	int	rows;
	int	colors;
}	t_info_img;

typedef struct s_data_img
{
	char	**colors;
	char	**img;
}	t_data_img;

typedef struct s_img
{
	t_info_img	info_img;
	t_data_img	o_img;
	char		**new_img;
}	t_img;

int			convert_file(char *file_path);
t_img		read_img(int fd);
int			generate_file(char *file_name, t_img img);
char		**get_colors_img(int fd, t_info_img info_img);
char		**convert_size(t_img *img);
char		**get_data_img(int fd, t_info_img info_img);
t_info_img	get_info_img(char *src);
char	*write_by_x(char *str, int num_x, t_info_img info_img);

#endif