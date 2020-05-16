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
	char *str;

	str = ft_permissions(buff);
	grp = getgrgid(buff.st_gid);
	pss = getpwuid(buff.st_uid);
	(*lst)->group = grp->gr_name;
	(*lst)->user = pss->pw_name;
	(*lst)->permission = ft_strdup(str);
	(*lst)->blocks = buff.st_size;
	(*lst)->nlink = buff.st_nlink;
	free(str);
}

static void	ft_blocks(int blocks)
{
	int sum;
	sum = ((blocks % 511) == 0) ? 0 : 1;
	sum += (blocks + 511) / 512;
	ft_putstr("total ");
	ft_putendl(ft_itoa((sum / 52)));
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

void		ft_printlong(t_long **lst, char *path)
{
	t_long			*temp;
	struct stat		buff;
	char			*p;
	int				blks;
	int				i;

	temp = *lst;
	blks = 0;
	i = 0;
	while (*lst != NULL)
	{
		p = ft_joint(path, "/", (*lst)->filename);
		lstat(p, &buff);
		ft_fill(&(*lst), buff);
		blks += (*lst)->blocks;
		*lst = (*lst)->next;
		i++;
	}
	*lst = temp;
	ft_blocks(blks * i);
	ft_print_l(*lst);
	*lst = temp;
}
