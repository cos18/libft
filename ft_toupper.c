/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:51:28 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/26 22:56:02 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef LIBFT_BONUS_H
# include "libft_bonus.h"
#endif

int	ft_toupper(int c)
{
#ifdef LIBFT_BONUS_H
	if (ft_islower(c) != 0)
#else
	if ('a' <= c && c <= 'z')
#endif
		c += ('A' - 'a');
	return (c);
}
