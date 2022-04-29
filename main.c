#include "load_philosophers/philo_load.h"
#include "not_libft/not_libft.h"
#include "functions/util.h"

int	main(int len, char **args)
{
	int				success;
	int				amount_philo;
	t_philo_list	**philo_top;

	if (len != 5 && len != 6)
		return (msg_bool(false, "Invalid argument length, got %d expected 5-6",
			len));
	amount_philo = ft_atoi(args[1], &success);
	if (!success)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	philo_top = load_philos(load_philo_data(len, args), amount_philo);
	t_philo_list	*entry;
	entry = *philo_top;
	while (entry)
	{
		ft_printf(2, "philo %d", entry->id);
		entry = entry->next;
	}
	return (0);
}
