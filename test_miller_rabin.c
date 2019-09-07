#include "miller_rabin.h"
#include "stdio.h"
#include "util.h"

void test_get_rd() {
    int n, r, d;

    n = -1;
    assert_equal(false, get_rd(n, &r, &d));

    n = 0;
    assert_equal(false, get_rd(n, &r, &d));

    n = 1;
    assert_equal(false, get_rd(n, &r, &d));

    n = 2;
    assert_equal(true, get_rd(n, &r, &d));
    assert_equal(r, 0);
    assert_equal(d, 1);

    n = 3;
    assert_equal(true, get_rd(n, &r, &d));
    assert_equal(r, 1);
    assert_equal(d, 1);
}

int main() {
    test_get_rd();
}