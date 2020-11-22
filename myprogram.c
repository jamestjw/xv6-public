#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h" 

int
main(void)
{
  printf(1, "My first xv6 program\n");
  struct pstat p;
  int res = getpinfo(&p);
  printf(1, "getpinfo status is %d\n", res);
  printf(1, "size of pstat struct is  %d\n", sizeof(p));
  printf(1, "size of res is  %d\n", sizeof(res));

  printf(1, "Increasing num tickets... of this process\n");

  res = settickets(3);
  printf(1, "settickets res is  %d\n", res);

  exit();
}

