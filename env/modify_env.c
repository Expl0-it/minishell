#include "minishell.h"

bool	overwrite_env_var(t_env *overwrite, char **split)
{
	if (NULL == overwrite || NULL == split)
		return (false);
	free(overwrite->val);
	overwrite->val = NULL;
	if (NULL == split[2])
		overwrite->val = ft_strdup(split[1]);
	else
		overwrite->val = concat_split(split, '=', 1);
	if (NULL == overwrite->val)
		return (false);
	else
		return (true);
}
