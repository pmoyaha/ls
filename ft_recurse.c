#include "ft_ls.h"

static char	*ft_dirn(t_long **lst, char *flags)
{
	t_long	*temp;
	char	*str;
	char	*str2;


	temp = *lst;
	str = ft_strnew(0);
	while (temp != NULL)
	{
		if (temp->type == 'd' && ft_cmp(temp->filename, ".") != 0
				&& ft_cmp(temp->filename, "..") != 0)
		{
			str2 = ft_strjoin(str, "^");
			free(str);
			if (temp->filename != NULL)
			str = ft_strjoin(str2, temp->filename);
			free(str2);
		}
		temp = temp->next;
	}
	if (flags[1] == '3')
		ft_del_l(&(*lst));
	else
		ft_del_n(&(*lst));
	return (str);
}

void		ft_recurse(char *path, char *flags, t_long **lst)
{
	char	*s;
	char	**str;
	char	*p;
	int		i;


	s = NULL;
	if (lst != NULL)
		s = ft_dirn(&(*lst), flags);
	if (s != NULL)
	{
		str = ft_strsplit(s, '^');
		free(s);
		i = 0;
		while (str[i] != NULL)
		{
			p = ft_joint(path, "/", str[i]);
			ft_putstr(p);
			ft_putendl(":");
			ft_impliment(p, flags);
			free(p);
			i++;
		}
		free(*str);
	}
}
