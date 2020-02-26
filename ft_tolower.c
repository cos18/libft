/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:52:57 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/26 22:57:55 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef LIBFT_BONUS_H
# include "libft_bonus.h"
#endif

int	ft_tolower(int c)
{
#ifdef LIBFT_BONUS_H
	if (ft_isupper(c) != 0)
#else
	if ('A' <= c && c <= 'Z')
#endif
		c += ('a' - 'A');
	return c;
}
