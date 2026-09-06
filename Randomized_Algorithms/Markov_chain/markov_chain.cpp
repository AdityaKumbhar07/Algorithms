#include <iostream>
#include <immintrin.h>

unsigned int true_random() {
    unsigned int val;
    while (!_rdrand32_step(&val));
    return val;
}

int main()
{
    const int target = 10;
    int bucket1[] = {1,0,1,0,1,0,1,0,1,0};
    int bucket2[] = {0,1,0,1,1,1,0,1,1,1};

    int val1 = 0, val0 = 0;
    int state = true_random() % 2;

    for (int i = 0; i < target; i++) {
        int rg = true_random() % 10;
        if (state == 1) {
            int x = bucket1[rg];
            if (x == 1) { val1++; state = 1; }
            else { val0++; state = 0; }
        } else {
            int x = bucket2[rg];
            if (x == 0) { val0++; state = 0; }
            else { val1++; state = 1; }
        }
    }

    std::cout << "value of 1's = " << val1 << std::endl;
    std::cout << "value of 0's = " << val0;
    return 0;
}

// Two State Markov Chain Simulation

// Simulates a discrete-time markov chain with 2 states: 1 and 0

// Transition probabilities:
//   From state 1: P(1->1) = 0.5   P(1->0) = 0.5
//   From state 0: P(0->1) = 0.7   P(0->0) = 0.3

// Stationary distribution (long-run fraction of time in each state):
//   Solve:  pi1 = 0.5*pi1 + 0.7*pi0
//           pi1 + pi0 = 1
//           pi1 = 7/12 ~ 0.58333
//           pi0 = 5/12 ~ 0.41667
  
// (edit `target` in main() to change sample size)
