/*
** lemipc.h for header in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:16:10 2015 Rémi DURAND
** Last update Mon Mar  2 16:25:35 2015 Ambroise Coutarel
*/

#ifndef _LEM_H_
# define _LEM_H_

# include <limits.h>
# include <unistd.h>
# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <stdio.h>

# define MAP_SIDE 10
# define MAP_SIZE 100
# define NB_MINIONS 7

int	        init_player(int shm_id, key_t key);
char		map_max(char *map);
int		map_nb_minions(char *map);
int	        find_offset(char *map);
int		fill_map(char nb_player, char *map);
void		display_map(char *map);
struct sembuf  	sembuf_init();
int		sem_set(int sem_id, struct sembuf *ops, int value);

#endif /* !_LEM_H_ */
