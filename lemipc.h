/*
** lemipc.h for header in /home/durand_u/github/PSU_2014_lemipc
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Mon Mar  2 12:16:10 2015 Rémi DURAND
** Last update Thu Mar  5 14:05:22 2015 Ambroise Coutarel
*/

#ifndef _LEM_H_
# define _LEM_H_

# include <limits.h>
# include <unistd.h>
# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>

# define MAP_SIDE 10
# define MAP_SIZE 100
# define EQ_LIM 7
# define X(of) (of % 10)
# define Y(of) (of / 10)

typedef struct	s_player
{
  char		x;
  char		y;
  char		eq;
  char	        not_dead;
}		t_player;

typedef struct	s_msg
{
  long		mtype;
  char		str[1];
  
}		t_msg;

int	        init_player(int shm_id, key_t key);
char		map_max(char *map);
int		map_nb_minions(char *map);
int	        find_offset(char *map);
int	        add_player(t_player *player, char *map);
void		display_map(char *map);
struct sembuf  	sembuf_init(int sem_num, int sem_op, int sem_flg);
int		sem_set(int sem_id, struct sembuf *ops, int value);
void		init_map(int shm_id);
void	        moves(t_player *player, char *map, int msgq_id);
int		checkForEnemies(t_player *player, char *map, int block);
void		first_aff(char *map);
void		sendMessage(int msgq_id, t_msg *msg, int remaining, long type);
char		nbTeam(char *map);

#endif /* !_LEM_H_ */
