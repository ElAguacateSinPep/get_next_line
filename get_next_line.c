#include "get_next_line.h"

char	*ft_free(char *str, char *buff)
{
	char	*temp;

	temp = ft_strjoin(str, buff);
	return (temp);
}

char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(stash, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		stash = ft_free(stash, buff);
		if (!stash)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*s;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	s = ft_substr(stash, 0, i + 1);
	return (s);
}

char	*ft_new_stash(char *stash)
{
	int		i;
	char	*s;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	s = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}
