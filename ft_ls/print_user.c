#include "ft_ls.h"

char	*ft_get_uid(t_file *file)
{
    t_passwd	*passwd;
    
    passwd = getpwuid(file->stat->st_uid);
    return (passwd->pw_name);
}

char	*ft_get_grid(t_file *file)
{
    t_group	*group;

    group = getgrgid(file->stat->st_gid);
    return (group->gr_name);
}

void	ft_print_user(t_file *file, int size_max, int size_g_max)
{
    int		size;
    char	*uid;
    char	*grid;

    uid = ft_get_uid(file);
    grid = ft_get_grid(file);
    size = ft_strlen(uid);
    while (size < size_max)
    {
	ft_putchar(' ');
	size++;
    }
    ft_putstr(uid);
    ft_putchar(' ');
    size = ft_strlen(grid);
    while (size < size_g_max)
    {
	ft_putchar(' ');
	size++;
    }
    ft_putstr(grid);
    ft_putchar(' ');
}
