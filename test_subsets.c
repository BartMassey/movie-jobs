#include <stdio.h>
#include "solve.h"

jobs_t inst = {{{{0,1}}, {{2,3}}, {{4,5}}}, 3};

int main() {
    jobs_t **candidates = 0;
    int ncandidates = 0;
    subsets(inst, &ncandidates, &candidates);
    for (int j = 0; j < ncandidates; j++) {
        jobs_t *soln = candidates[j];
        printf("-> %d\n", soln->njobs);
        for (int i = 0; i < soln->njobs; i++)
            printf("%d %d\n", soln->jobs[i].bounds[0], soln->jobs[i].bounds[1]);
        printf("\n");
    }
}

