/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:30:31 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/29 11:08:57 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Regarde si la piece est valide
** Le remplace par la bonne lettre
*/

static char	ft_modif_piece(char *str, char c, int pos)
{
	if (str[pos - 1] && str[pos - 1] == c)
		str[pos] = c;
	else
	{
		if (str[pos - 5] && str[pos - 5] == c)
			str[pos] = c;
		else
		{
			if (str[pos - 4] && str[pos - 4] == c && str[pos + 1] == '#')
				str[pos] = c;
			else
			{
				if (str[pos - 3] && str[pos - 3] == c && \
								str[pos + 1] == '#' && str[pos + 2] == '#')
					str[pos] = c;
				else
					return (0);
			}
		}
	}
	return (str[pos]);
}

/*
** Trouve le premier caractere du tetriminos et le remplace par la bonne lettre
** Si la premiere piece a ete trouvee, appelle ft_modif_piece
*/

char		*ft_check_form(char *str, char c, int start, int len)
{
	int i;
	int	first;

	i = 0;
	first = 0;
	while (str[start + i] && (i < len))
	{
		if (str[start + i] == '#')
		{
			if (!first && str[start + i] == '#')
				str[start + i] = c;
			if (!first && str[start + i] == c)
				first++;
			else
			{
				str[start + i] = ft_modif_piece(str, c, start + i);
				if (!str[start + i])
					return (0);
			}
		}
		i++;
	}
	return (str);
}
