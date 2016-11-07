/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 12:37:42 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_w_param(char c)
{
	ft_dprintf(2, "ft_ls: illegal option -- %c\n%s\n", c,
		"usage: ft_ls [-FRUacflnprtu] [file ...]");
	return (-1);
}

void	arg_error(char *name)
{
	ft_dprintf(2, "ft_ls: %s: ", name);
	perror(NULL);
}
