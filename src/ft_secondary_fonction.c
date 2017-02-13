/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secondary_fonction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghennebe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:17:26 by ghennebe          #+#    #+#             */
/*   Updated: 2016/12/06 18:17:28 by ghennebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	void	ft_free_leaks(char **plt, int *var, t_lst **piece, int *tab)
{
	int		index;

	index = 0;
	while (plt[index])
	{
		free(plt[index]);
		index++;
	}
	index = 0;
	free(plt);
	plt = NULL;
	while (piece[index])
	{
		free(piece[index]->blok);
		piece[index]->blok = NULL;
		free(piece[index]);
		index++;
	}
	free(piece);
	piece = NULL;
	free(var);
	var = NULL;
	free(tab);
	tab = NULL;
}

void			ft_print_plt(char **plt, int *var, t_lst **piece, int *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!piece)
		return ;
	while (i < var[0])
	{
		while (j < var[0])
		{
			ft_putchar(plt[i][j]);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	ft_free_leaks(plt, var, piece, tab);
}

void			ft_piece_ok(int tab, char **plt, int *var, t_lst *piece)
{
	plt = ft_put_pi(plt, piece, var[1], var[0]);
	tab = 1;
}

int				ft_init_tab(int nb_piece, t_lst **piece)
{
	int		*var;

	var = (int *)malloc(sizeof(int) * 2);
	var[0] = 0;
	var[1] = 0;
	ft_fillit(nb_piece, piece, var);
	return (0);
}

char			*ft_open_file(char **av)
{
	char	*set;
	int		fd;
	int		ret;
	char	buf[BUFSIZE + 1];

	fd = open(av[1], O_RDWR);
	if (fd < 0)
		return (0);
	while ((ret = read(fd, buf, BUFSIZE)))
	{
		buf[ret] = '\0';
		set = ft_strdup(buf);
	}
	close(fd);
	if (!set)
		return (0);
	return (set);
}
