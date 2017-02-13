/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:22:24 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/29 11:09:15 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** creer le plateau a la taille voulue
*/

static	char	*ft_malloc_line(char *str, int j, int size)
{
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (j < size)
	{
		str[j] = '.';
		j++;
	}
	str[j] = '\0';
	return (str);
}

static	char	**ft_malloc_plt(int size)
{
	int		i;
	int		j;
	char	**str;

	j = 0;
	i = 0;
	while ((i * i) < (size * 4))
		i++;
	size = i;
	i = 0;
	str = (char **)malloc(sizeof(char *) * size + 1);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = ft_malloc_line(str[i], j, size);
		if (!str[i])
			return (NULL);
		i++;
	}
	str[i] = NULL;
	return (str);
}

/*
** tab => 1 -> placee, -1 -> non placee
*/

static	int		ft_test_tab(char **plt, t_lst *piece, int *var)
{
	var[1] = ft_check_pos(plt, piece, var[0], var[1]);
	if (var[1] == var[0] * var[0])
		return (0);
	return (1);
}

static	int		ft_nav_piece(char **plt, t_lst **pi, int *t, int *var)
{
	int		i;
	int		tmp_pos;

	if ((i = -1) && ft_check_tab(t) == 1)
		return (1);
	while (t[++i])
	{
		var[1] = 0;
		while (var[1] < var[0] * var[0] && t[i] == -1)
		{
			if (!ft_test_tab(plt, pi[i], var))
				return (0);
			if (plt == ft_put_pi(plt, pi[i], var[1], var[0]) && (t[i] = 1))
				tmp_pos = var[1];
			if (ft_nav_piece(plt, pi, t, var))
				return (1);
			if (plt == ft_rm_pi(plt, pi[i], tmp_pos, var[0]) && (t[i] = -1))
				var[1] = tmp_pos + 1;
		}
	}
	return (0);
}

int				ft_fillit(int nb_piece, t_lst **piece, int *var)
{
	char	**plt;
	int		*tab;
	int		i;

	i = 0;
	tab = NULL;
	tab = (int *)malloc(sizeof(int) * nb_piece);
	while (i < nb_piece)
	{
		tab[i] = -1;
		i++;
	}
	while (1)
	{
		plt = ft_malloc_plt(nb_piece);
		var[0] = ft_len_line(plt[0]);
		if (ft_nav_piece(plt, piece, tab, var) == 1)
			break ;
		else if ((nb_piece += 1))
			ft_strdel(plt);
	}
	ft_print_plt(plt, var, piece, tab);
	return (1);
}
