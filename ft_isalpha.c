/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:59:26 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/26 22:09:07 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifdef LIBFT_BONUS_H
# include "libft_bonus.h"
#endif

int	ft_isalpha(int c)
{
#ifdef LIBFT_BONUS_H
	return (ft_islower(c) || ft_isupper(c));
#else
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
#endif
}
