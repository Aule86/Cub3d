/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:22:08 by ciestrad          #+#    #+#             */
/*   Updated: 2025/01/14 11:13:36 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdint.h>
# define BLOCK_SIZE 32

# define PI 3.14159265358979323846

# define PIH 1.57079632679489661923

# define PI3H 4.71238898038468985769

# define SOUTH PI3H
# define NORTH PIH
# define EAST 0
# define WEST PI

# define WIDTH 1920
# define HEIGHT 1080

# define ANGLE_TO_RADIAN 0.0174533

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_player
{
	double	py;
	double	px;
	int		player; // si hay player
	double	angulo;
	double	fov;
}			t_player;

typedef struct s_properties
{
	uint32_t	width;
	uint32_t	height;
	uint32_t	**pixel;
}				t_properties;

typedef struct s_texture
{
	t_properties	north;
	t_properties	south;
	t_properties	east;
	t_properties	west;
}				t_texture;


//$(CC) $(CFLAGS) $(MLXFLAGS) $^ libft.a libmlx.a -o $@

typedef struct s_ray
{
	double	angle;
	double	lenght;
	char	type;
	double	rx;
	double	ry;
}	t_ray;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	char		*no;
	char		*we;
	char		*so;
	char		*ea;
	int			f;
	int			c;
	t_player	player;
}		t_map;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_t		*mlx_win;
	t_ray		rayo[WIDTH];
	t_texture	texture;
	int			wall_size;
	int			wall_diff;
	int			sky_size;
	int			viewpoint;
	int			ceiling;
	int			floor;

}	t_game;



//----errors----
int				ft_error(int code);

//----ft_parseo----
int				check_input(t_map *map, char *line);
void			set_map(t_map *map);
int				set_map_size(char *file, int *size);

//----parsing_check----
int				check_map(t_map *map);
int				check_elements(t_map *map);
int				check_players(t_map *map);
void			flot_fill(t_map *map, char **map_copy, int y, int x);


//----utils_parse----
int				set_only(char *line, char *set);
int				is_set(char c, char *set);
size_t			count_arrays(char **array);
size_t			free_array(char **array);
void			free_map(t_map *map);

//----utils_parse02----
int				ft_color(char *line);
char			**copy_map(t_map *map);

//----parse_struct----
int				read_file(t_map *map, char *file, int size);
int				check_element(t_map *map, char *line);
int				get_element(t_map *map, char *line);
int				get_map(int fd, t_map *map, char *file, int size);
size_t			max_line(char **map);

//----gent_next_line----
char			*ft_strjoin_gnl(char *s1, char *s2);
char			*ft_read(int fd, char *save);
char			*get_line(char *buffer);
void			remake_save(char *save);
char			*get_next_line(int fd, char **out, int clear);

//----parse_grid----
char			**fill_map_x(char **map);

// RAYOS

//----ray_cating----
void			rayos(t_game *game);
void			which_angle(t_game *game, double angle,
					t_ray *rayo_h, t_ray *rayo_v);
void			init_rayo(t_ray *rayo_h, t_ray *rayo_v);

//----ray_utils----
double			radian_circle(double angle);

//----ray_select----
void			ray_north(t_game *game, double agn, t_ray *ray);
void			ray_south(t_game *game, double agn, t_ray *ray);
void			ray_west(t_game *game, double agn, t_ray *ray);
void			ray_east(t_game *game, double agn, t_ray *ray);

//----DRAW----

//draw_walls---
void			draw_imagen(t_game *game);
void			draw_sky(t_game *game, int sky_size, int x);
void			draw_floor(t_game *game, int sky_size, int x);

//----draw_utils----
int				to_rgba_hex(int red, int green, int blue, int alpha);

//----init_textures----
void			init_texture(t_game *game);
t_properties	texture_formatter(mlx_texture_t *texture);

//---textures---
void			draw_textures(t_game *game, int x, int y);
void			draw_north_texture(t_game *game, int x, int y);
void			draw_south_texture(t_game *game, int x, int y);
void			draw_west_texture(t_game *game, int x, int y);
void			draw_east_texture(t_game *game, int x, int y);

#endif