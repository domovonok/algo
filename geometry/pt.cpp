struct pt {
    ll x, y;

    pt() {
        x = 0;
        y = 0;
    }

    pt(ll _x, ll _y) {
        x = _x;
        y = _y;
    }

    pt(pt a, pt b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    pt operator+(pt other) {
        return pt(x + other.x, y + other.y);
    }

    pt operator-(pt other) {
        return pt(x - other.x, y - other.y);
    }

    ll operator*(pt other) {
        return x * other.x + y * other.y;
    }

    ll operator%(pt other) {
        return x * other.y - other.x * y;
    }
};

istream& operator>>(istream& in, pt &p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, pt &p) {
    out << p.x << ' ' << p.y;
    return out;
}

ll len2(pt p) {
    return p.x * p.x + p.y * p.y;
}

ll dist2(pt a, pt b) {
    return len2(pt(a, b));
}
