#include"push_swap.h"
long	ps_atoi_long(const char *nptr)
{
	int		i;
	long	sum;
	int		sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		sum = (sum * 10) + (nptr[i++] - '0');
	if (nptr[i] != '\0')
		return (99999999999999);
	return (sum * sign);
}
int	ps_atoi_checked(const char *s, int *out)
{
	long	res;

	if (!check(s))
		return (0);
	res = ps_atoi_long(s);
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	*out = (int)res;
	return (1);
}
int	*ps_tokens_to_numbers(char **tokens)
{
	int		i;
	int		count;
	int		*store;

	count = ps_tokens_len(tokens);
	store = malloc(count * sizeof(int));
	if (!store)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		if (!ps_atoi_checked(tokens[i], &store[i]))
		{
			free(store);
			return (NULL);
		}
		i++;
	}
	return (store);
}
int	ps_has_duplicate(int *numbers, int count)
{
	int i;
	int j;

	i=0;
	while(i<count)
	{j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return(0);
}
int	ps_tokens_len(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}
