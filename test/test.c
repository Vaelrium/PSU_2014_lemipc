#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <strings.h>
#include <limits.h>

typedef struct s_msg
{
  long	mtype;
  char	str[32];
}		t_msg;

int	main(int ac, char **av)
{
  char	path[PATH_MAX + 1];
  key_t	key = getcwd(path, PATH_MAX);
  int	msg_id;
  t_msg	msg;

  key = ftok(path, 0);
  msg_id = msgget(key, SHM_R | SHM_W);
  if (msg_id == (-1))
    {
      msg_id = msgget(key, IPC_CREAT | SHM_R | SHM_W);
      printf("created %d\n", msg_id);
      msgrcv(msg_id, &msg, sizeof(msg), 42, 0);
      printf("recieved %ld : %s\n", msg.mtype, msg.str);
    }
  else
    {
      bzero(&msg, sizeof(msg));
      msg.mtype = 42;
      sprintf(msg.str, "Hello world !");
      msgsnd(msg_id, &msg, sizeof(msg), 0);
      printf("using msgq %d\n", msg_id);
    }
  return (0);
}
