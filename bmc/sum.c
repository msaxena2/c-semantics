extern void __VERIFIER_error() __attribute__ ((__noreturn__));
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: __VERIFIER_error();
  }
  return;
}

int main() {
  unsigned int n = __VERIFIER_nondet_uint(), s = 0;
  for (unsigned int i = 1; i <= n; ++i) {
    s += i;
  }
  __VERIFIER_assert(s == (n * (n + 1)) / 2);
  return 0;
}

