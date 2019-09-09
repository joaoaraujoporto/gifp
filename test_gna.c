#include "util.h"
#include "gna.h"

void test_gna() {
    int seed;

    seed = 99;
    assert_equal_double(0.002136341763, sgna(seed), 6);
    assert_equal_double(0.0002136295662, gna(), 6);
    assert_equal_double(0.8998077288, gna(), 6);
    assert_equal_double(0.9899594099, gna(), 6);
    assert_equal_double(0.7090151681, gna(), 6);
    assert_equal_double(0.4719055758, gna(), 6);
    assert_equal_double(0.5762890408, gna(), 6);
    assert_equal_double(0.8104383465, gna(), 6);
    assert_equal_double(0.5234149306, gna(), 6);
    assert_equal_double(0.5712976584, gna(), 6);

    seed = 10;
    assert_equal_double(0.0002157920973, sgna(seed), 6);
    assert_equal_double(0.00002157874406, gna(), 6);
    assert_equal_double(0.9999805787, gna(), 6);
    assert_equal_double(0.09999589999, gna(), 6);
    assert_equal_double(0.9100015321, gna(), 6);
    assert_equal_double(0.3810005632, gna(), 6);
    assert_equal_double(0.9470999031, gna(), 6);
    assert_equal_double(0.556609934, gna(), 6);
    assert_equal_double(0.8609510031, gna(), 6);
    assert_equal_double(0.3304341069, gna(), 6);
}

int main() {
    test_gna();
}