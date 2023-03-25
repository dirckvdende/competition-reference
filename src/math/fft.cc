typedef complex<ld> cd;
const ld PI = acos(-1.0);

// This function calculates the fft and inverse fft of
// a polynomial function coefficients a. The result is
// again put in a. The size of a needs to be 2^n
void fft(vector<cd> &a, bool invert) {
    if (sz(a) == 1)
        return;
    // Determines left and right sides and applies
    // transform on them separately
    vector<cd> l(sz(a) / 2), r(sz(a) / 2);
    REP(i, sz(a) / 2)
        l[i] = a[2 * i], r[i] = a[2 * i + 1];
    // Apply FFT to left and right sides
    fft(l, invert), fft(r, invert);
    // Calculate w1
    ld ang = 2.0 * PI / ld(sz(a)) * (invert ? -1.0 :
    1.0);
    cd w(1.0), wn(cos(ang), sin(ang));
    REP(i, sz(a) / 2) {
        a[i] = l[i] + w * r[i];
        a[i + sz(a) / 2] = l[i] - w * r[i];
        if (invert)
            a[i] /= 2.0, a[i + sz(a) / 2] /= 2.0;
        w *= wn;
    }
}

// Calculates the coefficients of two polynomials
// multiplied
vi mul(const vi &a, const vi &b) {
    vector<cd> fa(all(a)), fb(all(b));
    // Calculate the size rounded up to 2^n
    ll n = 1;
    while (n < sz(a) + sz(b))
        n <<= 1;
    fa.resize(n), fb.resize(n);
    // Apply FFT to two polynomials separately
    fft(fa, false), fft(fb, false);
    REP(i, n)
        fa[i] *= fb[i];
    // Apply inverse FFT to product
    fft(fa, true);
    vi res(n);
    REP(i, n)
        res[i] = round(fa[i].real());
    return res;
}