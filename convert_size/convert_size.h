#ifndef CONVERT_SIZE_H
typedef struct s_img
{
	char	**o_img;
	char	**colors;
}	t_img;

int		convert_file(char *file_path);
t_img	read_img(int fd);
int		generate_file(char *file_name, t_img img);
int		read_info_img(char *info_str, int num_info);

#endif