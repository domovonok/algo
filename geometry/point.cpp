template <typename T>
struct point {
    T x, y;

    point() {
        x = 0;
        y = 0;
    }

    point(T _x, T _y) {
        x = _x;
        y = _y;
    }

    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    point operator+(point other) {
        return point(x + other.x, y + other.y);
    }

    point operator-(point other) {
        return point(x - other.x, y - other.y);
    }

    T operator*(point other) {
        return x * other.x + y * other.y;
    }

    T operator%(point other) {
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
T len2(point<T> p) {
    return p.x * p.x + p.y * p.y;
}

template <typename T>
T dist2(point<T> a, point<T> b) {
    return len2(point<T>(a, b));
}

template <typename T>
db len(point<T> p) {
    return sqrt(len2(p));
}

template <typename T>
db dist(point<T> a, point<T> b) {
    return sqrt(dist2(a, b));
}

using pt = point<ll>;