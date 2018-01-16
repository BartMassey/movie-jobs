/* Copyright (c) 2018 Bart Massey
   [This program is licensed under the "MIT License"]
   Please see the file LICENSE in the source
   distribution of this software for license terms. */

#include <assert.h>
#include <stdlib.h>

#include "solve.h"

/* Append an instance to the current list. */
static void
save_inst(jobs_t *inst, int *nresult, jobs_t ***result) {
        /* Extend the candidate list to make room. */
        *result = realloc(*result, (*nresult + 1) * sizeof **result);
        assert(result);

        /* Make a copy of the instance. */
        jobs_t *app = malloc(sizeof *app);
        assert(app);
        *app = *inst;

        /* Append the instance, increase the count, leave. */
        (*result)[*nresult] = app;
        (*nresult)++;
}

/* Return all possible subsets of a given instance. */
void
subsets(jobs_t inst, int *nresult, jobs_t ***result) {
    /* Base case: save empty set and return. */
    if (inst.njobs == 0) {
        save_inst(&inst, nresult, result);
        return;
    }

    /* Recursive case: Make all subsets with and without the last job. */

    /* Remove and save the last job */
    jobs_t new_inst = inst;
    new_inst.njobs--;
    interval_t last = new_inst.jobs[new_inst.njobs];
    jobs_t **candidates = 0;
    int ncandidates = 0;
    subsets(new_inst, &ncandidates, &candidates);
    for (int i = 0; i < ncandidates; i++) {
        save_inst(candidates[i], nresult, result);
    }
    for (int i = 0; i < ncandidates; i++) {
        candidates[i]->jobs[candidates[i]->njobs] = last;
        (candidates[i]->njobs)++;
        save_inst(candidates[i], nresult, result);
    }
    for (int i = 0; i < ncandidates; i++)
        free(candidates[i]);
    free(candidates);
}
