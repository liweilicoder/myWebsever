#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

/* Simple error handling functions */

#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

static void * sig_thread(void *arg) {
    printf( "yyyyy, thread id is: %ld\n", pthread_self() );
    sigset_t *set = (sigset_t *) arg;
    int s, sig;

    for (;;) {
        s = sigwait(set, &sig);
        if (s != 0) handle_error_en(s, "sigwait");
        printf("Signal handling thread got signal %d\n", sig);
    }
}

static void handler( int arg )
{
	printf( "xxxxx, thread id is: %ld\n", pthread_self() );
}

int main(int argc, char* argv[]) {
    pthread_t thread;
    sigset_t set;
    int s;
    sigemptyset(&set);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGUSR1);
    s = pthread_sigmask(SIG_BLOCK, &set, NULL);
    //signal(SIGQUIT, handler);
    s = pthread_create(&thread, NULL, &sig_thread, (void*) &set);


    //s = pthread_sigmask(SIG_BLOCK, &set, NULL);
    //if (s != 0) handle_error_en(s, "pthread_sigmask");

    if (s != 0) handle_error_en(s, "pthread_create");

    printf( "sub thread with id: %ld\n", thread );

    pause();

}