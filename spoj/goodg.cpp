#include<bits/stdc++.h>
using namespace std;

template <class T>
struct ConvexHullSet {
	struct Line {
		T a, b; mutable long double x; bool type;
		bool operator<(const Line& rhs) const {
			return type || rhs.type ? x < rhs.x : a < rhs.a;
		}
		long double intersect(const Line &rhs) const {
			return ((long double)(b - rhs.b) / (long double)(rhs.a - a));
		}
	};
	static constexpr long double MAX = std::numeric_limits<T>::max() / 10;
	static constexpr long double MIN = std::numeric_limits<T>::min() / 10;
	set<Line> lines;
	void adjust(typename set<ConvexHullSet<T>::Line>::iterator it) {
		if (it != lines.begin()) {
			auto pit = prev(it);
			pit->x = it != lines.end() ? pit->intersect(*it) : MAX;
		}
	}
	bool empty() { return lines.empty(); }
	T query(T x) {
		auto it = lines.lower_bound(Line{T(0), T(0), (long double)(x), true});
		return it != lines.end() ? it->a * x + it->b : MIN;
	}
	void insert(T a, T b) {
		Line ln = Line{a, b, 0.0, false};
		auto it = lines.lower_bound(ln);
		if (it != lines.end() && it->a == a) {
			if (it->b >= b) return;
			adjust(it = lines.erase(it));
		}
		ln.x = it != lines.end() ? it->intersect(ln) : MAX;
		while (it != lines.end() && ln.x >= it->x) {
			adjust(it = lines.erase(it));
			ln.x = it != lines.end() ? it->intersect(ln) : MAX;
		}
		while (it != lines.begin()) {
			--it;
			long double nx = it->intersect(ln);
			if (nx >= it->x) return;
			if (it != lines.begin() && prev(it)->x >= nx)
				adjust(it = lines.erase(it));
			else break;
		}
		it = lines.insert(ln).first;
		adjust(it); adjust(next(it));
	}
};
long long a[1000006];
long long  d[1000006];
int main()
{
	int n;
	scanf("%d",&n);
	ConvexHullSet<long long> ans;
		
	for(int i = 0; i < n ; i++)
	{
		scanf("%lld %lld",&a[i],&d[i]);
	}
	ans.insert(0LL,0LL);
	for(int i  = 0; i < n ; i++)
	{	
		long long m = ans.query(i) + a[i];
		//cout << ans.query(i) << ' ' << a[i] << " **\n";
		long long nn = m + (i) * d[i]; 
		//cout << nn << '\n';
		ans.insert(-d[i],nn);
	}
	printf("%lld\n",ans.query(n));
	return 0;
}