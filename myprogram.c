#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h" 

void pid_info(int pid) {
	struct pstat p;
	int res;
	if ((res = getpinfo(&p)) != 0) {
		printf(1, "failed to get pinfo\n");
		exit();
	}
	printf(1, "Size of pstat struct is  %d\n", sizeof(p));

	int idx = 0;
	for (idx = 0; idx < NPROC; idx++) {
		if (pid != p.pid[idx]) {
			continue;
		}

		int num_tickets = p.tickets[idx];
		int num_ticks = p.ticks[idx];
		printf(1, "Num tickets: %d, num of scheduler ticks assigned: %d\n", num_tickets, num_ticks);
		break;
	}
}

int
main(void)
{
  int mypid = getpid();
  printf(1, "my pid is %d\n", mypid);

  pid_info(mypid);

  printf(1, "Increasing num tickets of this process\n");

  if (settickets(3) != 0) {
	  printf(1, "failed to set new ticket number\n");
	  exit();
  }

  pid_info(mypid);

  exit();
}

