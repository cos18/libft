/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnul_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 23:30:47 by sunpark           #+#    #+#             */
/*   Updated: 2020/04/03 23:25:42 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strnul(void)
{
	char	*result;

	result = (char *)malloc(1);
	if (result)
		*result = '\0';
	return (result);
}
