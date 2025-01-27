struct Point {
	int x, y;
	Point () {
		this->x = 0;
		this->y = 0;
	}	
	Point (int x, int y) {
		this->x = x;
		this->y = y;
	}	
	bool operator ==(const Point& p) {
		return (this->x == p.x and this->y == p.y);
	}
	bool operator <(const Point& p) {
		return make_pair(this->x, this->y) < make_pair(p.x, p.y); // with respect to x-axis
		// // with respect to angle from (0, 0)
		// if (*this * p == 0) {
		// 	return dis() < p.dis();
		// }
		// return (*this * p < 0);
	}
	void operator -=(const Point& p) {
		this->x -= p.x;
		this->y -= p.y;
	}
	Point operator -(const Point& p) const {
		Point q;
		q.x = this->x - p.x;
		q.y = this->y - p.y;
		return q;
	}
	long long operator *(const Point& p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}
	bool isInside(Point& a, Point& b) const { // if p is inside segment a-b
		if ((a - *this) * (b - *this) != 0) return false;
		bool d1 = this->x >= min(a.x, b.x) and this->x <= max(a.x, b.x); 
		bool d2 = this->y >= min(a.y, b.y) and this->y <= max(a.y, b.y);
		return d1 and d2;
	}
	bool rayIntersect(Point a, Point b) {
		Point q(this->x, INT32_MAX);	// if p-q ray intersects segment a-b
		for (int rep = 0; rep < 2; ++rep) {
			if ((a - *this) * (q - *this) <= 0 and (b - *this) * (q - *this) > 0 and (a - *this) * (b - *this) < 0) {
				return true;
			}
			swap(a, b);
		}
		return false;
	}
	friend istream& operator >>(istream& cin, Point& p) {  
		cin >> p.x >> p.y;
		return cin;
	}
	friend ostream& operator <<(ostream& cout, const Point& p) {
		cout << p.x << " " << p.y;
		return cout;
	}
};

// upper and lower part
void solve() {
	int n;
	cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<Point> hull;
	for (int rep = 0; rep < 2; ++rep) {
		const int sz = hull.size();
		for (auto C: v) {
			while (hull.size() >= sz + 2) {
				Point A = hull.end()[-2];
				Point B = hull.end()[-1];
				if (((B - A) * (C - A)) <= 0) {
					break;
				}
				hull.pop_back();
			}
			hull.push_back(C);
		}
		hull.pop_back();
		reverse(v.begin(), v.end());
	}
	cout << hull.size() << "\n";
	for (auto p: hull) {
		cout << p << "\n";
	}
}

// sorting by angle
void solve() {
	int n;
	cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (make_pair(v[i].x, v[i].y) < make_pair(v[0].x, v[0].y)) {
			swap(v[i], v[0]);
		}
	}
	for (int i = 1; i < n; ++i) {
		v[i] -= v[0];
	}
	sort(v.begin() + 1, v.end());
	int j = n - 1;
	while (j >= 2 and v[j] * v[j - 1] == 0) {
		--j;
	}
	reverse(v.begin() + j, v.end());
	vector<Point> hull;
	hull.push_back(Point{0, 0});
	for (int i = 1; i < n; ++i) {
		auto C = v[i];
		while (hull.size() >= 2) {
			Point A = hull.end()[-2];
			Point B = hull.end()[-1];
			if (((B - A) * (C - A)) <= 0) {
				break;
			}
			hull.pop_back();
		}
		hull.push_back(C);
	}
	cout << hull.size() << "\n";
	for (auto& p: hull) {
		p += v[0];
		cout << p << "\n";
	}
}