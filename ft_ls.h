#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>

typedef struct	s_longformet
{
	struct stat			fstat;
	char				type;
	char				*path;
	char				*permission;
	char				*user;
	char				*group;
	char				*filename;
	int					blocks;
	int					nlink;
	long				time;
	struct s_longformet	*next;
}				t_long;

typedef struct	s_paths
{
	char			*path;
	long			time;
	struct s_paths	*next;
}				t_paths;

t_paths			*ft_newpath(char *path);
t_long			*ft_newnames(char *path, struct dirent *fname);
t_long			*ft_names(char *flags, char *path);
void			ft_callnames(t_long **lst, char *flags);
void			ft_addpath(t_paths **lst, t_paths *nlst);
void			ft_sortpath(t_paths **lst, char *flags);
void			ft_sort(t_long **lst, char *flags);
void			ft_recurse(char *path, char *flags, t_long **lst);
void			ft_printnames(t_long *lst);
void			ft_printsub(char const *s, unsigned int start, size_t len);
void			ft_printlong(t_long **lst, char *path);
void			ft_impliment(char *path, char *flags);
void			ft_delonelong(t_long **alst);
void			ft_delonename(t_long **alst);
void			ft_del_n(t_long **alst);
void			ft_del_l(t_long **alst);
void			ft_addnames(t_long **lst, t_long *nlst);
void			ft_err(t_long **lst, char *path);
char			*ft_checkflag(int ac, char **av);
char			*ft_joint(char *s1, char *s2, char *s3);
char			ft_type(struct stat buff);
int				ft_cmp(const char *s1, const char *s2);
void            ft_delonepath(t_paths **alst);
void			ft_del_p(t_paths **alst);

#endif
