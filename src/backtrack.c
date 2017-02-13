/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:19:41 by gauffret          #+#    #+#             */
/*   Updated: 2016/12/05 15:34:33 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static	int	ft_free_space(char **plt, t_lst *piece, int pos, int max)
{
	int		i;
	int		j;

	i = pos / max;
	j = pos % max;
	if ((i + (piece->blok)[0].y) < max && \
			(j + (piece->blok)[0].x) < max)
		if ((i + (piece->blok)[1].y) < max && \
				(j + (piece->blok)[1].x) < max)
			if ((i + (piece->blok)[2].y) < max && \
					(j + (piece->blok)[2].x) < max)
				if ((i + (piece->blok)[3].y) < max && \
						(j + (piece->blok)[3].x) < max)
					if (plt[i + (piece->blok)[0].y]\
							[j + (piece->blok)[0].x] == '.')
						if (plt[i + (piece->blok)[1].y]\
								[j + (piece->blok)[1].x] == '.')
							if (plt[i + (piece->blok)[2].y]\
									[j + (piece->blok)[2].x] == '.')
								if (plt[i + (piece->blok)[3].y]\
										[j + (piece->blok)[3].x] == '.')
									return (1);
	return (0);
}

/*
** verfie si toute les pieces sont posees ou non
*/

int			ft_check_tab(int *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == -1)
			return (0);
		i++;
	}
	return (1);
}

/*
** place la piece dans l'espace libre
*/

char		**ft_put_pi(char **plt, t_lst *piece, int pos, int len_line)
{
	int		i;
	int		j;

	i = pos / len_line;
	j = pos % len_line;
	plt[i + (piece->blok)[0].y][j + (piece->blok)[0].x] = piece->car;
	plt[i + (piece->blok)[1].y][j + (piece->blok)[1].x] = piece->car;
	plt[i + (piece->blok)[2].y][j + (piece->blok)[2].x] = piece->car;
	plt[i + (piece->blok)[3].y][j + (piece->blok)[3].x] = piece->car;
	return (plt);
}

/*
** supprime la piece du plateau
*/

char		**ft_rm_pi(char **plt, t_lst *piece, int pos, int max)
{
	int		i;
	int		j;

	i = pos / max;
	j = pos % max;
	if ((i + (piece->blok)[0].y) <= max && \
								(j + (piece->blok)[0].x) <= max)
		if ((i + (piece->blok)[1].y) <= max && \
										(j + (piece->blok)[1].x) <= max)
			if ((i + (piece->blok)[2].y) <= max && \
											(j + (piece->blok)[2].x) <= max)
				if ((i + (piece->blok)[3].y) <= max && \
												(j + (piece->blok)[3].x) <= max)
				{
					plt[i + (piece->blok)[0].y][j + (piece->blok)[0].x] = '.';
					plt[i + (piece->blok)[1].y][j + (piece->blok)[1].x] = '.';
					plt[i + (piece->blok)[2].y][j + (piece->blok)[2].x] = '.';
					plt[i + (piece->blok)[3].y][j + (piece->blok)[3].x] = '.';
				}
	return (plt);
}

/*
** verifie si la place de la piece est libre
*/

int			ft_check_pos(char **plt, t_lst *piece, int max, int pos)
{
	int		i;
	int		j;

	i = pos / max;
	j = pos % max;
	while (i < max)
	{
		if (ft_isupper(plt[i][j]) || \
			!ft_free_space(plt, piece, pos, max))
		{
			if (j++ == max - 1)
				i++;
			if (j == max)
				j = 0;
			pos = (max * i) + j;
		}
		else
			break ;
	}
	pos = ((i == max && j == max) ? (i * j) : ((max * i) + j));
	return (pos);
}
