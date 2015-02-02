#include "ft_ls.h"

void	ft_get_files(t_list **list, char *path)
{
    DIR		*fd;
    t_dirent	*dirent;
    t_list	*temp;

    temp = NULL;
    if (!(fd = opendir(path)))
	ft_putstr("mauvais nom repertoire");
    while ((dirent = readdir(fd)) != NULL)
    {
	if (dirent->d_name)
	    ft_list_push_back(&temp, ft_strdup(dirent->d_name));
	else
	    ft_putstr("me suis gourrer");
    }
    *list = temp;
    closedir(fd);
}
