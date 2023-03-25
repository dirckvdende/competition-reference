const ld EPS = 1e-12;

// Finds some root of a function f, given f, f' and an
// initial guess x. It would perform well if x is close
// to a root. A max iteration count could be added
ld newton(ld (*f)(ld), ld (*fp)(ld), ld x = 0.0) {
    while (abs(f(x)) > EPS) {
        if (abs(fp(x)) < EPS )
            x = x - EPS;
        else
            x = x - f(x) / fp(x);
    }
    return x;
}