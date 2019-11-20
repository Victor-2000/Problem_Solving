//Condition of the problem: https://www.infoarena.ro/problema/ai

#include <bits/stdc++.h>	
#define DN 1005
#define INF (1<<30) - 1	
#define x first
#define y second
#define LL long long
 
using namespace std;
 
typedef pair<int, int> point;
 
bool is_occupied[DN][DN];
int is_intersection[DN][DN], dist[2][2];
bool viz[DN][DN];
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int find_max_wall(bool on_lines) {
	int res = 0, local_res, next;
	for (int i = 0; i < n; ++i) {
		local_res = 0;
		for (int j = 0; j < n; ++j) {
			if (on_lines) next = is_occupied[i][j];
			else next = is_occupied[j][i];
 
			if (next == true)
				++local_res;
			res = max(res, local_res);
			if (next == false)
				local_res = 0;
		}
	}
	return res;
}
 
bool is_inside(point node) {
	return node.x >= 0 && node.x < n &&
		   node.y >= 0 && node.y < n;
}
 
int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	int r = a % b;
	while (r) { a = b; b = r; r = a % b; }
	return b;
}
 
void find_robot_distances(point initial_position, int robot_index) {
	pair<point, int> crt, next;
	queue<pair<point, int> > q;
	int intersection_type;
	memset(viz, 0, sizeof(viz));
 
	q.push(make_pair(initial_position, 0));
	viz[initial_position.x][initial_position.y] = 1;
	while (!q.empty()) {
		crt = q.front();
		q.pop();
 
		intersection_type = is_intersection[crt.x.x][crt.x.y];
		if (intersection_type) {
			-- intersection_type;
			dist[robot_index][intersection_type] = min(dist[robot_index][intersection_type], crt.y);
		}
		for (int i = 0; i < 4; ++i) {
			next = make_pair(make_pair(crt.x.x + dx[i], crt.x.y + dy[i]), crt.y + 1);
			if (is_inside(next.x) && !is_occupied[next.x.x][next.x.y] && !viz[next.x.x][next.x.y]) {
				viz[next.x.x][next.x.y] = 1;
				q.push(next);
			}
		}
	}
}
 
void find_intersection_points(point a, point b, int source_index) {
	point node;
	int dist_x = abs(a.x - b.x);
	int dist_y = abs(a.y - b.y);
	int nr_points = gcd(dist_y, dist_x);
	int piece_x = dist_x/nr_points, piece_y = dist_y/nr_points;
	point start = a;
	if (a.x > b.x)
		start = b;
	for (int i = 0; i <= nr_points; ++i) {
		node.x = start.x + piece_x * i;
		if (start.y > min(a.y, b.y))
			node.y = start.y - piece_y * i;
		else
			node.y = start.y + piece_y * i;
		is_intersection[node.x][node.y] = source_index;
	}
}
 
void normalize(point &p) {
	--p.x; --p.y;
}
 
int main() {
	int k;
	point target, s1, s2, r1, r2, obs;
    // freopen("input.txt", "r", stdin);
    ifstream fin("ai.in");
    ofstream fout("ai.out");
 
    fin >> n;
    fin >> target.x >> target.y >> s1.x >> s1.y >> s2.x >> s2.y >> r1.x >> r1.y >> r2.x >> r2.y;
    normalize(target); normalize(s1); normalize(s2); normalize(r1); normalize(r2);
    fin >> k;
    for (int i = 0; i < k; ++i) {
    	fin >> obs.x >> obs.y;
    	normalize(obs);
    	is_occupied[obs.x][obs.y] = 1;
    }
    is_occupied[target.x][target.y] = 1;
 
    // Part I
    int max_wall_length = max(find_max_wall(true), find_max_wall(false));
    fout << max_wall_length << '\n';
 
    // Part II
    find_intersection_points(s1, target, 1);
    find_intersection_points(s2, target, 2);
    is_intersection[target.x][target.y] = 0;
 
    for (int i = 0; i < 2; ++i)
    	for (int j = 0; j < 2; ++j)
    		dist[i][j] = INF;
    find_robot_distances(r1, 0);
    find_robot_distances(r2, 1);
 
   	fout << min(max(dist[0][0], dist[1][1]), max(dist[0][1], dist[1][0]));
    return 0;
}
