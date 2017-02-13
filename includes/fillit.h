/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:22:26 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/22 14:23:11 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFSIZE	550

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_lst
{
	char		car;
	t_point		*blok;
}				t_lst;

void			ft_bzero(void *s, size_t n);
void			ft_memdel(void **ap);
int				ft_check_file(char *str);
char			*ft_check_form(char *str, char c, int start, int len);
int				ft_fillit(int nb_piece, t_lst **piece, int *var);
int				ft_check_tab(int *tab);
void			ft_print_plt(char **plt, int *var, t_lst **piece, int *tab);
char			*ft_open_file(char **av);
int				ft_len_line(char *plt);
int				ft_init_tab(int nb_piece, t_lst **piece);
char			**ft_put_pi(char **plt, t_lst *piece, int pos, int len_line);
char			**ft_rm_pi(char **plt, t_lst *piece, int pos, int len_line);
int				ft_check_pos(char **plt, t_lst *piece, int max, int pos);
t_point			*ft_coo_piece(char **in, t_point *blok, int y, int nbpiece);
t_lst			**ft_be_carefull(int nbpiece, char **majstr);
t_point			*ft_change_ori(t_point *blok, int x, int y, size_t size);
char			ft_find_char(char **majstr, int x, int y, int nbpiece);
t_lst			**ft_return_tab(int nb_piece, char *str);
t_lst			*ft_creatpiece(void);
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putnbrendl(int n);
void			ft_putnbr(int n);
int				ft_isupper(int c);
size_t			ft_strlen(const char *str);
void			ft_putstr(char const *s);
char			*ft_strdup(const char *src);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);

#endif
