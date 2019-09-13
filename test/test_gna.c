#include "../src/util.h"
#include "../src/gna.h"

void test_gna() {
    int seed;

    /**
     * 0 is not really expected in this block
     */
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);
    assert_equal_double(0.0, gna(), 6);

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

void test_gnai() {
    assert_equal(1, cdigits(gnai(1)));
    assert_equal(2, cdigits(gnai(2)));
    assert_equal(3, cdigits(gnai(3)));
    assert_equal(4, cdigits(gnai(4)));
    assert_equal(5, cdigits(gnai(5)));
    assert_equal(6, cdigits(gnai(6)));
    assert_equal(7, cdigits(gnai(7)));
    assert_equal(8, cdigits(gnai(8)));
    assert_equal(9, cdigits(gnai(9)));
    assert_equal(10, cdigits(gnai(10)));
    assert_equal(11, cdigits(gnai(11)));
    assert_equal(12, cdigits(gnai(12)));
    assert_equal(13, cdigits(gnai(13)));
    assert_equal(14, cdigits(gnai(14)));
    assert_equal(18, cdigits(gnai(18))); // limit for now (ul_int has 64 bits)
}

void test_gnab() {
    /**
     * 0 is not really expected in this block
     */
    assert_equal(0, gnab(0));
    assert_equal(0, gnab(1));
    assert_equal(0, gnab(2));
    assert_equal(0, gnab(3));
    assert_equal(0, gnab(4));
    assert_equal(0, gnab(5));
    assert_equal(0, gnab(16));
    assert_equal(0, gnab(32)); // yet not supported
}

int main() {
    // test_gna();
    // test_gnai();
    test_gnab();
}
