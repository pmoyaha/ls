#include "ft_ls.h"

static void ft_swap(t_paths **a, t_paths **b)
{	
	char	*path;
	long	time;

	path = (*a)->path;
	time = (*a)->time;
	(*a)->path = (*b)->path;
	(*a)->time = (*b)->time;
	(*b)->path = path;
	(*b)->time = time;
}

static void ft_path_a(t_paths **lst)
{
	t_paths  *temp;

	temp = *lst;
	while ((*lst)->next != NULL)
	{ft_putendl("path");
		if (ft_cmp((*lst)->path, (*lst)->next->path) == -1)
		{
			ft_swap(&(*lst), &(*lst)->next);
			*lst = temp;
		}
		else
			*lst = (*lst)->next;
	}
	*lst = temp;
}

static void	ft_path_t(t_paths **lst)
{
	t_paths *temp;
	
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
			if (ft_cmp((*lst)->path, (*lst)->next->path) == -1)
				ft_swap(&(*lst), &(*lst)->next);
			*lst = (*lst)->next;
		}
		else
			*lst = (*lst)->next;
	}
	*lst = temp;
}

static void ft_sort_r(t_paths **lst)
{
	t_paths      *tmp;
	t_paths      *hld;
	t_paths      *tmp2;

	tmp = *lst;
	hld = NULL;
	while (*lst != NULL)
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		if (hld == NULL)
		{
			hld = *lst;
			tmp2 = hld;
		}
		else
		{
			hld->next = *lst;
			hld = hld->next;
		}
		(*lst)->next = NULL;
		*lst = tmp;
	}
	*lst = tmp2;
}

void		ft_sortpath(t_paths **lst, char *flags)
{
	if (flags[4] == '1')
	{
		ft_path_t(&(*lst));
	}
	else
	{
		ft_path_a(&(*lst));
	}
	if (flags[3] == '1')
		ft_sort_r(&(*lst));
}
