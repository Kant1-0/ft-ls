/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 12:37:45 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_ls_file **file, t_ls_meta *meta)
{
	t_ls_file	*tmp;

	tmp = *file;
	if (meta->param & (1 << 2) || meta->param & (1 << 5))
		long_display(file, meta->param);
	else
	{
		while (tmp)
		{
			ft_putstr(tmp->dp.d_name);
			(meta->param & (1 << 6)) ? disp_mf(tmp->filestat.st_mode) : 0;
			(meta->param & (1 << 10)) ?
				disp_p(tmp->filestat.st_mode, meta->param) : 0;
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
}
