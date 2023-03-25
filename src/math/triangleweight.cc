typedef pair<ld, ld> dd;

// Find weights of vertices of a triangle to average
// point p inside the triangle, returns a boolean
// indicating if the point is in the triangle. If the
// point is not inside the triangle, the weights are
// not calculated correctly
bool triangleWeights(dd p, dd v1, dd v2, dd v3, ld &w1,
ld &w2, ld &w3) {
    // This lambda will return the weight of v1
    auto f = [](dd p, dd v1, dd v2, dd v3) -> ld {
        dd v = {v2.x - v3.x, v2.y - v3.y};
        // Calculate distance to line v2,v3 from both
        // v1 and p
        ld a = v.y, b = -v.x;
        ld c = v.x * v2.y - v.y * v2.x;
        ld dv = a * v1.x + b * v1.y + c;
        ld dp = a * p.x + b * p.y + c;
        if (dv == 0.0)
            return 0.0;
        return dp / dv;
    };
    // Calculate weight of every vertex
    w1 = f(p, v1, v2, v3);
    w2 = f(p, v2, v1, v3);
    w3 = f(p, v3, v1, v2);
    return w1 >= 0.0 && w2 >= 0.0 && w3 >= 0.0;
}