#include "ft_ls.h"

void	ft_printnames(t_long *lst)
{
	while (lst != NULL)
	{
		if (lst->filename)
			ft_putendl(lst->filename);
		if ((lst = lst->next) == NULL)
			break ;
	}
}
