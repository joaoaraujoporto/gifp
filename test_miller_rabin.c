#include "miller_rabin.h"
#include "stdio.h"
#include "util.h"

void test_get_rd() {
    int n, r, d;

    n = -1;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 0;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 1;
    assert_equal_bool(false, get_rd(n, &r, &d));

    n = 2;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal_bool(r, 0);
    assert_equal_bool(d, 1);

    n = 3;
    assert_equal_bool(true, get_rd(n, &r, &d));
    assert_equal_bool(r, 1);
    assert_equal_bool(d, 1);
}

void test_is_prime() {
    assert_equal_bool(false, is_prime(-1, 1));
    assert_equal_bool(false, is_prime(0, 1));
    assert_equal_bool(false, is_prime(4, 1));
    assert_equal_bool(false, is_prime(6, 1));

    assert_equal_bool(true, is_prime(1, 10));
    assert_equal_bool(true, is_prime(2, 10));
    assert_equal_bool(true, is_prime(3, 10));
    assert_equal_bool(true, is_prime(5, 10));
}

int main() {
    // test_get_rd();
    test_is_prime();
}