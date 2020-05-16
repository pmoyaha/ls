#include "ft_ls.h"

static void		ft_multiflags(char **flags, char *v)
{
	int		i;
	int		j;
	char	*flg;

	flg = ft_strdup("alRrt");
	i = 1;
	while (v[i] != '\0')
	{
		j = 0;
		while (flg[j] != '\0')
		{
			if (v[i] == flg[j])
				*(flags[0] + j) = '1';
			j++;
		}
		i++;
	}
	ft_strdel(&flg);
}

static char		mosima(char *flags)
{
	char legalflags[7];
	char invalidFlag;

	ft_strcpy(legalflags, "-alRrt");
	while (*flags)
	{
		if (!ft_strchr(legalflags, *flags))
		{
			invalidFlag = *flags;
			return (invalidFlag);
		}
		
		flags++;
	}
	return ('\0');
}

static void		ft_monoflag(char **flags, char *v)
{
	int		j;
	char	*flg;

	flg = ft_strdup("alRrt");
	j = 0;
	while (flg[j] != '\0')
	{
		if (v[1] == flg[j])
			*(flags[0] + j) = '1';
		j++;
	}
	ft_strdel(&flg);
}

char			*ft_checkflag(int ac, char **av, char *rc)
{
	char	*flags;
	int		cnt;
	int		l;

	cnt = 1;
	flags = ft_strdup("00000");
	while (av[cnt] != NULL && av[cnt][0] == '-' && ac > cnt)
	{
		*rc = mosima(av[cnt]);
		if (*rc)
			return (flags);
		l = ft_strlen(av[cnt]);
		if (l > 2)
			ft_multiflags(&flags, av[cnt]);
		else
			ft_monoflag(&flags, av[cnt]);
		cnt++;
	}
	return (flags);
}
