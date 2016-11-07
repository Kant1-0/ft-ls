/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:29:26 by qfremeau          #+#    #+#             */
/*   Updated: 2016/10/10 16:41:57 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_meta(t_ls_meta *meta)
{
	if (meta->targetnb)
		while ((meta->targetnb)--)
			if (meta->target[meta->targetnb])
				free(meta->target[meta->targetnb]);
	if (meta->target)
		free(meta->target);
}

void	free_file(t_ls_file *fst)
{
	t_ls_file	*nxt;

	while (fst)
	{
		nxt = fst->next;
		if (fst->path)
			free(fst->path);
		free(fst);
		fst = nxt;
	}
}
