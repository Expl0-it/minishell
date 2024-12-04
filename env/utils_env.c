#include "minishell.h"

// NOTE: used in case when enviromental variable has '=' inside it
char	*concat_split(char **split, char split_delimeter, int i_start)
{
	int		i;
	int		len;
	int		curr;
	char	*ret;

	if (NULL == split)
		return (NULL);
	i = i_start;
	len = 0;
	while (split[i])
		len += ft_strlen(split[i++]) + 1;
	ret = (char *)ft_calloc(len, sizeof(char));
	i = i_start;
	curr = 0;
	while (split[i])
	{
		curr = ft_strlcat(ret, split[i], len);
		if (NULL != split[++i])
			ret[curr] = split_delimeter;
	}
	return (ret);
}

bool	is_valid_env_var(char **split)
{
	int		i;
	char	*key;

	if (NULL == split || NULL == split[0] || NULL == split[1])
		return (false);
	key = split[0];
	i = 0;
	while (0 != key[i])
	{
		if (0 == ft_isalnum(key[i]) && '_' != key[i])
			return (false);
		i++;
	}
	return (true);
}
