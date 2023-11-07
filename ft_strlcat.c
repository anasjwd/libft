/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajawad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:43:57 by ajawad            #+#    #+#             */
/*   Updated: 2023/11/01 09:55:06 by ajawad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(const char *dest, const char *src, size_t dest_size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dest);
	j = dlen;
	i = 0;
	slen = ft_strlen(src);
	if (dest_size == 0 || dest_size <= dlen)
		return (slen + dest_size);
	while (src[i] != '\0' && i < dest_size - dlen - 1)
	{
		((char *)dest)[j++] = ((char *)src)[i++];
	}
	((char *)dest)[j] = '\0';
	return (dlen + slen);
}
