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

void test_gna_i() {
    real n;
    integer seed;

    init_r(n);
    init_i(seed);

    /**
     * 0 is not really expected in this block
     */
    gna_i(n);
    assert_equal_r_d(0.0, n);
    gna_i(n);
    assert_equal_r_d(0.0, n);
    gna_i(n);
    assert_equal_r_d(0.0, n);
    gna_i(n);
    assert_equal_r_d(0.0, n);
    gna_i(n);
    assert_equal_r_d(0.0, n);
    gna_i(n);
    assert_equal_r_d(0.0, n);
    gna_i(n);
    assert_equal_r_d(0.0, n);
    gna_i(n);
    assert_equal_r_d(0.0, n);

    /**
     * Expected is a aproximation in this block then result is false
     */
    set_i_ui(seed, 99);
    sgna_i(n, seed);
    assert_equal_r_d(0.002136341763, n);
    gna_i(n);
    assert_equal_r_d(0.0002136295662, n);
    gna_i(n);
    assert_equal_r_d(0.8998077288, n);
    gna_i(n);
    assert_equal_r_d(0.9899594099, n);
    gna_i(n);
    assert_equal_r_d(0.7090151681, n);
    gna_i(n);
    assert_equal_r_d(0.4719055758, n);
    gna_i(n);
    assert_equal_r_d(0.5762890408, n);
    gna_i(n);
    assert_equal_r_d(0.8104383465, n);
    gna_i(n);
    assert_equal_r_d(0.5234149306, n);
    gna_i(n);
    assert_equal_r_d(0.5712976584, n);

    /**
     * Expected is a aproximation in this block then result is false
     */
    set_i_ui(seed, 10);
    sgna_i(n, seed);
    assert_equal_r_d(0.0002157920973, n);
    gna_i(n);
    assert_equal_r_d(0.00002157874406, n);
    gna_i(n);
    assert_equal_r_d(0.9999805787, n);
    gna_i(n);
    assert_equal_r_d(0.09999589999, n);
    gna_i(n);
    assert_equal_r_d(0.9100015321, n);
    gna_i(n);
    assert_equal_r_d(0.3810005632, n);
    gna_i(n);
    assert_equal_r_d(0.9470999031, n);
    gna_i(n);
    assert_equal_r_d(0.556609934, n);
    gna_i(n);
    assert_equal_r_d(0.8609510031, n);
    gna_i(n);
    assert_equal_r_d(0.3304341069, n);

    clear_r(n);
    clear_i(seed);
}

void test_gnai() {
    assert_equal(1, n_digits(gnai(1)));
    assert_equal(2, n_digits(gnai(2)));
    assert_equal(3, n_digits(gnai(3)));
    assert_equal(4, n_digits(gnai(4)));
    assert_equal(5, n_digits(gnai(5)));
    assert_equal(6, n_digits(gnai(6)));
    assert_equal(7, n_digits(gnai(7)));
    assert_equal(8, n_digits(gnai(8)));
    assert_equal(9, n_digits(gnai(9)));
    assert_equal(10, n_digits(gnai(10)));
    assert_equal(11, n_digits(gnai(11)));
    assert_equal(12, n_digits(gnai(12)));
    assert_equal(13, n_digits(gnai(13)));
    assert_equal(14, n_digits(gnai(14)));
    assert_equal(18, n_digits(gnai(18))); // limit for now (ul_int has 64 bits)
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
    assert_equal(0, gnab(32));
    assert_equal(0, gnab(64)); // not supported
}

void test_gnab_i() {
    integer n;
    init_i(n);

    /**
     * 0 is not really expected in this block
     */
    gnab_i(n, 1);
    assert_equal_i_ui(0, n);
    gnab_i(n, 2);
    assert_equal_i_ui(0, n);
    gnab_i(n, 3);
    assert_equal_i_ui(0, n);
    gnab_i(n, 4);
    assert_equal_i_ui(0, n);
    gnab_i(n, 5);
    assert_equal_i_ui(0, n);
    gnab_i(n, 16);
    assert_equal_i_ui(0, n);
    gnab_i(n, 32);
    assert_equal_i_ui(0, n);
    gnab_i(n, 64);
    assert_equal_i_ui(0, n);
    gnab_i(n, 4096);
    assert_equal_i_ui(0, n);
    gnab_i(n, 8192);
    assert_equal_i_ui(0, n);

    clear_i(n);
}

void test_gna_i_ranged() {
    integer n, b, e;
    inits_i(n, b, e, NULL);

    set_i_ui(b, 0);
    set_i_ui(e, 10);
    gna_i_ranged(n, b, e);
    assert_equal_i_ui(0, n); // 0 is not really expected
    assert_equal_bool(true, cmp_i(n, b) >= 0 && cmp_i(n, e) <= 0);

    gna_i_ranged(n, b, e);
    assert_equal_i_ui(0, n); // 0 is not really expected
    assert_equal_bool(true, cmp_i(n, b) >= 0 && cmp_i(n, e) <= 0);

    set_i_ui(b, 50);
    set_i_ui(e, 100);
    gna_i_ranged(n, b, e);
    assert_equal_i_ui(0, n); // 0 is not really expected
    assert_equal_bool(true, cmp_i(n, b) >= 0 && cmp_i(n, e) <= 0);

    set_i_ui(b, 500);
    set_i_ui(e, 1000);
    gna_i_ranged(n, b, e);
    assert_equal_i_ui(0, n); // 0 is not really expected
    assert_equal_bool(true, cmp_i(n, b) >= 0 && cmp_i(n, e) <= 0);

    set_i_ui(b, 5000);
    set_i_ui(e, 10000);
    gna_i_ranged(n, b, e);
    assert_equal_i_ui(0, n); // 0 is not really expected
    assert_equal_bool(true, cmp_i(n, b) >= 0 && cmp_i(n, e) <= 0);

    clears_i(n, b, e, NULL);
}

int main() {
    // test_gna();
    // test_gnai();
    // test_gna_i();
    // test_gnab();
    // test_gnab_i();
    test_gna_i_ranged();
}
