/* Copyright (c) 2018 Bart Massey
   [This program is licensed under the "MIT License"]
   Please see the file LICENSE in the source
   distribution of this software for license terms. */

/* Hard limit on number of jobs per instance. */
#define MAX_JOBS 100

/* Hard limit on number of characters per coordinate. */
#define MAX_COORD 20

typedef struct interval {
    int bounds[2];
} interval_t;

typedef struct jobs {
    interval_t jobs[MAX_JOBS];
    int njobs;
} jobs_t;

extern void subsets(jobs_t, int *, jobs_t ***);
