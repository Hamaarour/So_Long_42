/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:39:33 by hamaarou          #+#    #+#             */
/*   Updated: 2023/01/05 22:31:17 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 400

//*start Libft functions
int			ft_strncmp(char *s1, char *s2, unsigned int n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin_split(char *s1, char *s2);
char		*ft_substr_split(char *s, unsigned int start, size_t len);
char		**ft_split(char *s, char sep);
char		*ft_itoa(int l);
//*start Libft functions

// *start printf functions
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			count_nbr(unsigned long nbr, int bs, int sign);
int			ft_putnbr(long int nbr);
int			ft_putnbr_hex(unsigned long nbr, char bs);
size_t		ft_strlen(const char *str);
int			ft_printf(const char *str, ...);
// *end printf functions

// *start Get next line functions
int			ft_strchr(char *str);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char **s, char *buff);
char		*get_next_line(int fd);
// *END Get next line functions

typedef struct s_vars
{
	void	*mlx;
	void	*win;

}			t_vars;

typedef struct s_data
{
	void	*img_player;
	void	*img_wall;
	void	*img_gr;
	void	*img_collect;
	void	*img_exit;
	void	*img_open_exit;
	int		width;
	int		height;
}			t_img;

typedef struct s_pl
{
	int		player_x;
	int		player_y;
}	t_ply;

typedef struct s_po
{
	int	ex_x;
	int	ex_y;
}	t_pos;

typedef struct s_map
{
	char	**data_map;
	char	**map_c;
	char	**map_e;
	char	*lines;
	int		refer_coin;
	int		refer_exit;
	int		fd;
	int		y;
	int		width;
	int		booln;
	int		height;
	int		collectible;
	int		total_moves;
	char	*ani[10];
	char	*enemy[4];
	int		enemy_x;
	int		enemy_y;
	int		timer;
	int		index;
	int		index_enemy;
	t_img	img;
	t_vars	vars;
	t_ply	pl;
	t_pos	ex_pos;
}	t_map;

/* ------------so long--------------*/
int			ft_check_map_path(char *map_path);
int			key_hook_press(int keycode, t_map *param);
int			ft_exit(void);
int			check_player_position(t_map *map);
int			check_line_length(t_map *map);
int			check_square(t_map *map);
int			map(t_map *map, char *argv);
void		render_map(t_map *map);
int			check_one_p_e_c(t_map *map);
void		put_image(t_map *p);

/* --------Move player position--------*/
int			move_up(t_map *vm);
int			move_left(t_map *m);
int			move_right(t_map *m);
int			move_down(t_map *m);

/* -----Animation--------*/
void		animation(t_map *map);
void		fill_arr_animation(t_map *m);
int			animation_timer(t_map *map);
void		animation_enemy(t_map *map);
void		fill_arr_animation_enemy(t_map *m);

/* -----open the door--------*/
int			door_open(t_map *m, int x, int y);
void		win(void);
void		lose(void);
int			check_path(t_map *map);
int			check_p(t_map *map, t_ply *pl);

/* -----Error msg--------*/
void		error_map(void);
void		duplicate(void);
void		not_element(void);

#endif
