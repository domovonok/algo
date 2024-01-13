template <typename T>
struct point {
    T x, y;

    point() {
        x = 0;
        y = 0;
    }

    point(const T &_x, const T &_y) {
        x = _x;
        y = _y;
    }

    point(const point &a, const point &b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    point operator+(const point &other) {
        return point(x + other.x, y + other.y);
    }

    point operator-(const point &other) {
        return point(x - other.x, y - other.y);
    }

    T operator*(const point &other) {
        return x * other.x + y * other.y;
    }

    T operator%(const point &other) {
        return x * other.y - other.x * y;
    }
};

template <typename T>
istream& operator>>(istream& in, point<T> &p) {
    in >> p.x >> p.y;
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, point<T> &p) {
    out << p.x << ' ' << p.y;
    return out;
}

template <typename T>
T len2(const point<T> &p) {
    return p.x * p.x + p.y * p.y;
}

template <typename T>
T dist2(const point<T> &a, const point<T> &b) {
    return len2(point<T>(a, b));
}

using pt = point<ll>;
