#ifndef FT_LS_H

# define FT_LS_H

# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h> // a enlever?
# include <pwd.h>
# include <grp.h>
# include <time.h>

# include "libft.h"

# define O_LONG options[0]
# define O_RECURSIVE options[1]
# define O_HIDDEN options[2]
# define O_REVERSE options[3]
# define O_TIME options[4]

/*
** OPTIONS
** 0 = l
** 1 = R
** 2 = a
** 3 = r
** 4 = t
*/

typedef struct stat	t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct	s_data
{
    t_list	*targets;
    int		options[5];
}		t_data;

typedef struct	s_file
{
    char	*name;
    t_stat	*stat;
}		t_file;

void		ft_browse_arg(t_data *data, char **argv);
void		ft_exec_ls(t_data *data, int line, char *aff_dir, char *path);
t_file		*ft_fill_stat(char *name);
void		ft_get_files(t_list **list, char *path);
void		ft_aff_ls(t_list **targets, int line_break, char *aff_dir, int *options);
void		ft_time_sort(t_list **targets);
void		ft_alph_sort(t_list **targets);
void		ft_rev_sort(t_list **targets);
void		ft_rec_ls(t_data *data, int line, char *aff_dir, char *path);
int		ft_check_hidden(char *str);
void		ft_aff_long(t_list **targets, int *options);
void		ft_print_perms(t_stat *stat);
void		ft_linkdir(t_file *file, int size);
void		ft_print_user(t_file *file, int size_max, int size_g_max);
void		ft_print_date(t_stat *stat);
void		ft_print_bytes(t_stat *stat, int b_max);
void		ft_blank_spaces(int size, int print);
int		ft_get_size_max(t_list **targets, int *options);
int		ft_size_ldir(t_list **targets, int *options);
int		ft_get_dir_nbr(t_file *file);
int		ft_get_usr_max(t_list **targets, int *options);
int		ft_get_grp_max(t_list **targets, int *options);
char		*ft_get_uid(t_file *file);
char		*ft_get_grid(t_file *file);

#endif
