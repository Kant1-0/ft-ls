/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 12:37:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_std(t_ls_meta *meta, const char *path)
{
	t_ls_file	*list;

	errno = 0;
	if ((list = ls_list_dir(path, meta)))
	{
		display(&list, meta);
		free_file(list);
	}
	else if (errno)
		ft_printf("ft_ls: %s: %s\n", path, strerror(errno));
}
