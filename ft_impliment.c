#include "ft_ls.h"

void	ft_impliment(char *path, char *flags)
{
	t_long *lst;

	if ((lst = ft_names(flags, path)) != NULL)
	{
		if (flags[1] == '1' && lst != NULL)
			ft_printlong(&lst, path);
		else if (lst != NULL)
			ft_printnames(lst);
		if (flags[2] == '1' && lst != NULL)
			ft_recurse(path, flags, &lst);
		if (flags[1] == '1' && lst != NULL)
			ft_del_l(&lst);
		else if (lst != NULL)
			ft_del_n(&lst);
	}
}
