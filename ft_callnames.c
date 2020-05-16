#include "ft_ls.h"

static char	*ft_permissions(struct stat buff)
{
	char *str;

	str = ft_strnew(9);
	str[0] = (buff.st_mode & S_IRUSR) ? 'r' : '-';
	str[0] = (buff.st_mode & S_IRUSR) ? 'r' : '-';
	str[1] = (buff.st_mode & S_IWUSR) ? 'w' : '-';
	str[2] = (buff.st_mode & S_IXUSR) ? 'x' : '-';
	str[3] = (buff.st_mode & S_IRGRP) ? 'r' : '-';
	str[4] = (buff.st_mode & S_IWGRP) ? 'w' : '-';
	str[5] = (buff.st_mode & S_IXGRP) ? 'x' : '-';
	str[6] = (buff.st_mode & S_IROTH) ? 'r' : '-';
	str[7] = (buff.st_mode & S_IWOTH) ? 'w' : '-';
	str[8] = (buff.st_mode & S_IXOTH) ? 'x' : '-';
	return (str);
}

static void	ft_fill(t_long **lst, struct stat buff)
{
	struct group	*grp;
	struct passwd	*pss;

	grp = getgrgid(buff.st_gid);
	pss = getpwuid(buff.st_uid);
	(*lst)->group = grp->gr_name;
	(*lst)->user = pss->pw_name;
	(*lst)->permission = ft_permissions(buff);
	(*lst)->blocks = buff.st_size;
	(*lst)->nlink = buff.st_nlink;
}

static void	ft_print_l(t_long *lst)
{
	while (lst != NULL)
	{
		ft_putchar(lst->type);
		ft_putstr(lst->permission);
		ft_putchar('\t');
		ft_putnbr(lst->nlink);
		ft_putchar(' ');
		ft_putstr(lst->user);
		ft_putchar('\t');
		ft_putstr(lst->group);
		ft_putchar('\t');
		ft_putnbr(lst->blocks);
		ft_putchar('\t');
		ft_printsub(ctime(&lst->time), 4, 12);
		ft_putchar('\t');
		ft_putendl(lst->filename);
		lst = lst->next;
	}
}

void		ft_callnames(t_long **lst, char *flags)
{
	struct stat	buff;
	t_long		*temp;

	temp = (*lst);
	ft_sort(&(*lst), flags);
	if (flags[1] == '1')
	{
		while ((*lst) != NULL)
		{
			lstat((*lst)->path, &buff);
			ft_fill(&(*lst), buff);
			*lst = (*lst)->next;
		}
		*lst = temp;
		ft_print_l(*lst);
	}
	else
		ft_printnames(*lst);
}
