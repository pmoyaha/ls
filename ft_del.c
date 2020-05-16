#include "ft_ls.h"

void	ft_delonelong(t_long **alst)
{
	free((*alst)->permission);
	free(*alst);
	*alst = NULL;
}

void	ft_delonename(t_long **alst)
{
	free(*alst);
	*alst = NULL;
}

void	ft_del_n(t_long **alst)
{
	if ((*alst)->next)
		ft_del_n(&(*alst)->next);
	ft_delonename(alst);
}

void	ft_del_l(t_long **alst)
{
	if ((*alst)->next)
		ft_del_l(&(*alst)->next);
	ft_delonelong(alst);
}

void    ft_del_p(t_paths **alst)
{
    if ((*alst)->next)
        ft_del_p(&(*alst)->next);
    ft_delonepath(alst);
}

void    ft_delonepath(t_paths **alst)
{
    free(*alst);
    *alst = NULL;
}
