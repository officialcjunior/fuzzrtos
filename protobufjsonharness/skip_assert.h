#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

jmp_buf *get_jmp_buf() {
    return &env;
}

void __assert_fail(const char * assertion, const char * file, unsigned int line, const char * function) {
    // don't bail on asserts
    printf("Assert encountered: \"%s\" in %s on line %d of %s\n",
           assertion, function, line, file);
    longjmp(env, 1);
}