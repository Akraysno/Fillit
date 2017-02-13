/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghennebe <ghennebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:12:50 by ghennebe          #+#    #+#             */
/*   Updated: 2016/12/05 13:12:51 by ghennebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

char			ft_find_char(char **majstr, int x, int y, int nbpiece)
{
	while ((y % 4) <= 3 && y < (nbpiece * 4))
	{
		if (ft_isupper(majstr[y][x]))
			return (majstr[y][x]);
		x++;
		if (x >= 4)
		{
			x = 0;
			y++;
		}
	}
	return ('@');
}

static t_point	*ft_norm(t_point *blok)
{
	blok[0].x = 0;
	blok[0].y = 0;
	return (blok);
}

t_lst			*ft_creatpiece(void)
{
	t_lst	*piece;
	size_t	size;

	size = 4;
	piece = (t_lst *)malloc(sizeof(t_lst));
	if (!piece)
		return (NULL);
	(piece->blok) = (t_point *)malloc(sizeof(t_point) * (size + 1));
	if (!(piece->blok))
		return (NULL);
	(piece->blok)[size].x = '\0';
	(piece->blok)[size].y = '\0';
	return (piece);
}

t_point			*ft_coo_piece(char **in, t_point *blok, int y, int nbpiece)
{
	size_t	size;
	int		x;

	x = 0;
	size = 0;
	while (in[y] != NULL && ((y % 4) <= 3) && y < ((nbpiece * 4)))
	{
		if (in[y][x] == '\n' || x >= 4)
		{
			y++;
			x = 0;
		}
		if (y == (nbpiece * 4))
			return (blok = ft_norm(blok));
		if (in[y][x] == '.')
			x++;
		else if (y < (nbpiece * 4))
		{
			blok = ft_change_ori(blok, x, y, size);
			size++;
			x++;
		}
	}
	return (blok);
}

t_lst			**ft_be_carefull(int nbpiece, char **majstr)
{
	t_lst	**tab;
	int		i;
	int		count;
	int		tmp;
	int		count1;

	count = 0;
	count1 = 0;
	i = 0;
	tab = (t_lst **)malloc(sizeof(t_lst *) * nbpiece + 1);
	while (i != nbpiece)
	{
		tab[i] = ft_creatpiece();
		(tab[i]->car) = ft_find_char(majstr, 0, (count), nbpiece);
		tmp = tab[i]->car;
		tab[i]->blok = ft_coo_piece(majstr, tab[i]->blok, count, nbpiece);
		count1++;
		if (count < (((nbpiece) * 4) - 4))
			count = count1 * 4;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
