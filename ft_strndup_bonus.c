/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:23:49 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:18:07 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	newsize;
	char	*result;
	char	*now;

	newsize = ft_strlen(s1);
	newsize = (newsize > n) ? n : newsize;
	result = (char *)malloc(newsize + 1);
	if (result)
	{
		now = result;
		while (newsize--)
			*(now++) = *(s1++);
		*now = '\0';
	}
	return (result);
}
