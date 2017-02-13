/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:11:53 by gauffret          #+#    #+#             */
/*   Updated: 2017/02/13 12:14:09 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Compte le nombre de lettre majuscules contenu dans la chaine
** une fois divise par 4 cela donne le nombre de piece
*/

int			ft_len_line(char *str)
{
	int i;

	i = 0;
	while (str[i] == '.')
		i++;
	return (i);
}

static int	ft_count_letters(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if ((str[i] >= 65) && (str[i] <= 90))
			nb++;
		i++;
	}
	return (nb);
}

t_lst		**ft_return_tab(int nb_piece, char *str)
{
	char	**majstr;
	int		i;
	int		size;
	t_lst	**tab;
	int		index;

	size = 0;
	index = 0;
	i = 0;
	majstr = (ft_strsplit(str, '\n'));
	tab = ft_be_carefull(nb_piece, majstr);
	free(str);
	while (majstr[i])
	{
		free(majstr[i]);
		i++;
	}
	free(majstr);
	return (tab);
}

t_point		*ft_change_ori(t_point *blok, int x, int y, size_t size)
{
	if (size == 0)
	{
		(blok[size]).x = (x);
		(blok[size]).y = (y);
	}
	else if (size != 0)
	{
		(blok[size]).x = (x - (blok[0].x));
		(blok[size]).y = (y - (blok[0].y));
	}
	return (blok);
}

/*
** Recupere le fichier mis en argument et le transforme en chaine de caractere
** appelle les fonction pour ranger les pieces (le plus petit plateau possible)
*/

int			main(int ac, char **av)
{
	int		nb_piece;
	char	*set;

	if (ac != 2)
		ft_putendl("usage: ./fillit source_file");
	else
	{
		if ((set = ft_open_file(av)) == 0)
		{
			ft_putendl("error");
			return (0);
		}
		if (!ft_check_file(set) || !set)
			ft_putendl("error");
		else if ((nb_piece = ft_count_letters(set) / 4))
			ft_init_tab(nb_piece, ft_return_tab(nb_piece, set));
	}
	return (0);
}
