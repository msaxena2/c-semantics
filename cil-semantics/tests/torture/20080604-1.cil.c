/* Generated by CIL v. 1.3.7 */
/* print_CIL_Input is true */

struct barstruct {
   char const   *some_string ;
};
extern  __attribute__((__nothrow__, __noreturn__)) void abort(void)  __attribute__((__leaf__)) ;
struct barstruct x  ;
void ( __attribute__((__noinline__)) foo)(void) 
{ 

  {
  if (! x.some_string) {
    abort();
  }
  return;
}
}
void baz(int b ) 
{ struct barstruct bar ;
  struct barstruct *barptr ;

  {
  if (b) {
    barptr = & bar;
  } else {
    barptr = & x + 1;
    barptr --;
  }
  barptr->some_string = "Everything OK";
  foo();
  barptr->some_string = "Everything OK";
  return;
}
}
int main(void) 
{ 

  {
  x.some_string = (char const   *)((void *)0);
  baz(0);
  if (! x.some_string) {
    abort();
  }
  return (0);
}
}