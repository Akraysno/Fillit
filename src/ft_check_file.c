/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:21:25 by gauffret          #+#    #+#             */
/*   Updated: 2016/11/23 10:50:37 by gauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Permet de verifier que la chaine d'entree fais la bonne taille
*/

static int	ft_len_file(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (((len + 1) % 21) != 0)
		return (0);
	return (1);
}

/*
** Verifie que les caracteres de la piece traitee sont les bons
** Si ils sont bon, appelle ft_check_form
*/

static char	*ft_verif_square(char *str, char c, int start, int len)
{
	int		nb_hash;
	int		nb_line;
	int		nb_dots;
	int		i;

	i = 0;
	nb_hash = 0;
	nb_line = 0;
	nb_dots = 0;
	while (i < len)
	{
		if ((str[start + i] == '.') && ((i + 1) % 5 != 0))
			nb_dots++;
		if ((str[start + i] == '#') && ((i + 1) % 5 != 0))
			nb_hash++;
		if ((str[start + i] == '\n') && ((i + 1) % 5 == 0))
			nb_line++;
		i++;
	}
	if (nb_dots == 12 && nb_hash == 4 && nb_line == 4)
		str = ft_check_form(str, c, start, 20);
	else
		return (NULL);
	return (str);
}

/*
** parcours toute la string pour verifie que les pieces separees come il faut
** Appelle ft_verif_square pour chaque piece
*/

static int	ft_verif_char(char *str)
{
	int	tmp;
	int i;
	int nb_square;

	i = 0;
	tmp = 0;
	nb_square = 0;
	while (str[i])
	{
		if ((str[i] == '\n') && ((str[i + 1] == '\n') || (str[i + 1] == '\0')))
		{
			if (str[i + 2] == '\n')
				return (0);
			str = ft_verif_square(str, 'A' + nb_square, tmp, 20);
			if (!str)
				return (0);
			nb_square++;
			tmp = i + 2;
		}
		i++;
	}
	if (nb_square > 26)
		return (0);
	return (1);
}

/*
** Appelle les fonctions pour verifier la validite du fichier d'entree
*/

int			ft_check_file(char *str)
{
	if (str == NULL)
		return (0);
	if (!ft_len_file(str))
		return (0);
	if (!ft_verif_char(str))
		return (0);
	return (1);
}
