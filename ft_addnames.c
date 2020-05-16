#include "ft_ls.h"

void	ft_addnames(t_long **lst, t_long *nlst)
{
	t_long	*temp;

	temp = *lst;
	while ((*lst)->next != NULL)
		*lst = (*lst)->next;
	(*lst)->next = nlst;
	*lst = temp;
}
