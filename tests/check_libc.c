/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_libc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunpark <sunpark@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:48:32 by sunpark           #+#    #+#             */
/*   Updated: 2020/02/26 16:13:19 by sunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "../libft.h"
#include <stdlib.h>
#include <string.h>

START_TEST(test_ft_memset)
{
	char	origin[] = "abcdasdf\0asdfwb";
	char	now[] = "abcdasdf\0asdfwb";

	ck_assert_mem_eq(memset(origin, 100, 4), ft_memset(now, 100, 4), 12);
	ck_assert_str_eq(origin, now);
}	END_TEST

START_TEST(test_ft_bzero)
{
	char	origin[] = "abcdasdf\0asdfwb";
	char	now[] = "abcdasdf\0asdfwb";
	
	bzero(origin, 5);
	ft_bzero(now, 5);
	ck_assert_str_eq(origin, now);
	ck_assert_mem_eq(origin, now, 12);
}	END_TEST

START_TEST(test_ft_memcpy)
{
	char	origin[] = "Hello My name\0 is Sungwoo!!!";
	char	*ori;
	char	*newc;
	
	ori = (char *)malloc(50);
	newc = (char *)malloc(50);
	ori[15] = 100;
	newc[15] = 100;
	ori[16] = 1;
	newc[16] = 1;
	ck_assert_mem_eq(memcpy(ori, origin, 15), ft_memcpy(newc, origin, 15), 17);
	ck_assert_str_eq(ori, newc);
	free(ori);
	free(newc);
}	END_TEST

START_TEST(test_ft_memccpy)
{
	char	origin[10] = {'h', 'e', 'l', 'l', 'o', 10, 127, -10, 0, '!'};
	char	*ccpy, *ftccpy;

	ccpy = (char *)malloc(20);
	ftccpy = (char *)malloc(20);
	for(int i=0;i<20;i++)
	{
		ccpy[i] = 0;
		ftccpy[i] = 0;
	}
	memccpy(ccpy, origin, 'l', 8);
	ft_memccpy(ftccpy, origin, 'l', 8);
	ck_assert_str_eq(ccpy, ftccpy);
	memccpy(ccpy, origin, -1, 9);
	ft_memccpy(ftccpy, origin, -1, 9);
	ck_assert_mem_eq(ccpy, ftccpy, 9);
	memccpy(ccpy, origin, 200, 10);
	ft_memccpy(ftccpy, origin, 200, 10);
	ck_assert_mem_eq(ccpy, ftccpy, 10);
	free(ccpy);
	free(ftccpy);
}	END_TEST

Suite	*libc_suite(void)
{
	Suite	*s;
	TCase	*tc_core;

	s = suite_create("LibC");
	tc_core = tcase_create("Memory");
	tcase_add_test(tc_core, test_ft_memset);
	tcase_add_test(tc_core, test_ft_bzero);
	tcase_add_test(tc_core, test_ft_memcpy);
	tcase_add_test(tc_core, test_ft_memccpy);
	suite_add_tcase(s, tc_core);
	return s;
}

int		main(void)
{
	int		no_failed = 0;
	Suite	*s;
	SRunner	*runner;

	s = libc_suite();
	runner = srunner_create(s);
	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (no_failed)?EXIT_FAILURE:EXIT_SUCCESS;
}
