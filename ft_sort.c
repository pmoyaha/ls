#include "ft_ls.h"

static void	ft_swap(t_long **a, t_long **b)
{
	char	*name;
	char	type;
	long	time;

	name = (*a)->filename;
	type = (*a)->type;
	time = (*a)->time;
	(*a)->filename = (*b)->filename;
	(*a)->type = (*b)->type;
	(*a)->time = (*b)->time;
	(*b)->filename = name;
	(*b)->type = type;
	(*b)->time = time;
}

static void	ft_reverse(t_long **lst)
{
	t_long		*tmp;
	t_long		*hld;
	t_long		*next;

	tmp = *lst;
	hld = NULL;
	next = tmp->next;

	while(tmp != NULL)
	{
		tmp->next = hld;
		hld = tmp;
		tmp = next;
		if(tmp != NULL)
			next = tmp->next;
	}
	*lst = hld;
}

static void	ft_sort_a(t_long **lst)
{
	t_long	*temp;

	temp = *lst;
	while ((*lst)->next != NULL)
	{
		if (ft_cmp((*lst)->filename, (*lst)->next->filename) == -1)
		{
			ft_swap(&(*lst), &(*lst)->next);
			*lst = temp;
		}
		else
			*lst = (*lst)->next;
	}
	*lst = temp;
}

static void	ft_sort_t(t_long **lst)
{
	t_long	*temp;

	temp = *lst;
	while ((*lst)->next != NULL)
	{
		if ((*lst)->time > (*lst)->next->time)
		{
			ft_swap(&(*lst)->next, &(*lst));
			*lst = temp;
		}
		else if ((*lst)->time == (*lst)->next->time)
		{
			if (ft_cmp((*lst)->filename, (*lst)->next->filename) == -1)
				ft_swap(&(*lst), &(*lst)->next);
			*lst = (*lst)->next;
		}
		else
			*lst = (*lst)->next;
	}
	*lst = temp;
}

void		ft_sort(t_long **lst, char *flags)
{
	if (flags[4] == '1' && (*lst) != NULL)
		ft_sort_t(&(*lst));
	else if ((*lst) != NULL)
		ft_sort_a(&(*lst));
	if (flags[3] == '1' && (*lst) != NULL)
		ft_reverse(&(*lst));
}
