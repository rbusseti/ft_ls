#include "ft_ls.h"

static void	ft_perms_others(mode_t st_mode)
{
    if (st_mode & S_IROTH)
	ft_putchar('r');
    else
	ft_putchar('-');
    if (st_mode & S_IWOTH)
        ft_putchar('w');
    else
	ft_putchar('-');
    if (st_mode & S_IXOTH)
        ft_putchar('x');
    else
	ft_putchar('-');
}

static void	ft_perms_group(mode_t st_mode)
{
    if (st_mode & S_IRGRP)
	ft_putchar('r');
    else
	ft_putchar('-');
    if (st_mode & S_IWGRP)
        ft_putchar('w');
    else
	ft_putchar('-');
    if (st_mode & S_IXGRP)
        ft_putchar('x');
    else
	ft_putchar('-');
}

static void	ft_perms_user(mode_t st_mode)
{
    if (st_mode & S_IRUSR)
	ft_putchar('r');
    else
	ft_putchar('-');
    if (st_mode & S_IWUSR)
        ft_putchar('w');
    else
	ft_putchar('-');
    if (st_mode & S_IXUSR)
        ft_putchar('x');
    else
	ft_putchar('-');
}

void		ft_print_perms(t_stat *stat)
{
    if (stat->st_mode & S_IFDIR)
        ft_putchar('d');
    else if (stat->st_mode & S_IFREG)
        ft_putchar('-');
    else if (stat->st_mode & S_IFLNK)
	ft_putchar('l');
    ft_perms_user(stat->st_mode);
    ft_perms_group(stat->st_mode);
    ft_perms_others(stat->st_mode);
    ft_putchar(' ');
}
