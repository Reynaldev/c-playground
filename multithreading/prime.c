#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define ARRAY_LENGTH(x) ((sizeof x) / (sizeof *x)) 

#define USE_MUTEX
#if defined(USE_MUTEX)
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#endif

typedef struct {
    pthread_t *threads;
    uint32_t num_of_threads;
} ThreadPool;

typedef struct {
    ThreadPool *thread_pool;
    uint32_t *primes;
    uint32_t low;
    uint32_t high;
    int32_t id;
} PrimeThreadArg;

bool is_prime(uint32_t n) {
    if (n <= 1)
        return false;

    for (uint32_t i = 2; i <= roundl(sqrtl(n)); i++) {
        if (n % i == 0) {
            return false;
        } 
    }

    return true;
}

void * count_prime(void *args) {
#if defined(USE_MUTEX)
    pthread_mutex_lock(&mutex);
#endif

    PrimeThreadArg *arg = (PrimeThreadArg *)args;

    // static const uint8_t S[] = { 1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59 };
    // static const uint8_t S1[] = { 1, 13, 17, 29, 32, 41, 49, 53 };
    // static const uint8_t S2[] = { 7, 19, 31, 43 };
    // static const uint8_t S3[] = { 11, 23, 47, 59 };

#if defined(USE_MUTEX)
    pthread_mutex_unlock(&mutex);
#endif

    for (uint32_t i = arg->low; i <= arg->high; i++) {
        if (is_prime(i))
            *(arg->primes + i) = i;
    }

    // for (uint32_t x = 1; x <= sqrt(arg->high); x++) {
    //      for (uint32_t y = 1; y <= sqrt(arg->high) * 2; y++) {
    //         int32_t m = 4 * pow(x, 2) + pow(y, 2);
    //         int32_t am = m % 60;
    //
    //         for (uint32_t z = 0; z < ARRAY_LENGTH(S); z++) {
    //             if (am == S1[z] && m <= arg->high) {
    //                 arg->primes[m] 
    //             }
    //         }
    //     }
    // }

#if defined(USE_MUTEX)
    pthread_mutex_lock(&mutex);
#endif

    printf("Thread %d finished.\n", arg->id);
    arg->thread_pool->num_of_threads--;

#if defined(USE_MUTEX)
    pthread_mutex_unlock(&mutex);
#endif

    return NULL;
}

int main(int argc, char *argv[]) {
    uint32_t n = 10000;
    uint32_t thread_num = 1;

    if (argc == 3) {
        n = atoi(argv[1]);
        thread_num = atoi(argv[2]);
    }

    uint32_t *primes = calloc(n, sizeof(uint32_t));
    PrimeThreadArg args[thread_num];

    ThreadPool thread_pool = {
        .threads = malloc(sizeof(pthread_t) * thread_num),
        .num_of_threads = thread_num
    };

    time_t t = clock();   

    uint32_t batch = n / thread_num;
    for (uint32_t i = 0; i < thread_num; i++) {
        args[i].thread_pool = &thread_pool;
        args[i].primes = primes;
        args[i].low = batch * i;
        args[i].high = batch * (i + 1);
        args[i].id = i;

        int result = pthread_create(&thread_pool.threads[i], NULL, count_prime, (void *)&args[i]);

        if (!result) {
            printf("%p\t", &args[i]);
            printf("Thread %d is running\n", i);
        }
        else 
            printf("Thread %d failed to run\n", i);
    }
   
    while (thread_pool.num_of_threads > 0);
    
    t = clock() - t;

    // print
    for (uint32_t i = 0; i < n; i++) {
        if (primes[i] != 0)
            printf("%d ", primes[i]);
    }
    
    printf("\nTime completed %f\n", (double)(t) / CLOCKS_PER_SEC);

    free(primes);

    pthread_exit(NULL);
    free(thread_pool.threads);
    thread_pool.threads = NULL;

    return 0;
}
