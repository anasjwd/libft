/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:49:18 by ajawad            #+#    #+#             */
/*   Updated: 2023/11/03 02:17:56 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isc(char s, char c)
{
	return (c == s);
}

static int	wordcounter(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (ft_isc(str[i], c) == 0 && (ft_isc(str[i + 1], c) == 1 || str[i
					+ 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	fill(const char *str, char **array, char c)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		if (ft_isc(str[i], c) == 1)
		{
			i++;
			continue ;
		}
		tmp = i;
		while (ft_isc(str[i], c) == 0 && str[i])
			i++;
		array[index] = malloc(sizeof(char) * (i - tmp + 1));
		ft_strncpy(array[index], &str[tmp], i - tmp);
		index++;
	}
}

char	**ft_split(const char *str, char c)
{
	char	**array;
	int		nbr_words;

	nbr_words = wordcounter(str, c);
	array = malloc(sizeof(char *) * (nbr_words + 1));
	if (array == NULL)
		return (NULL);
	array[nbr_words] = 0;
	fill(str, array, c);
	return (array);
}
