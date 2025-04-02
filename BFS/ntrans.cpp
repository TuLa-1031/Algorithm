/*
Xét cặp số nguyên không âm viết tắt là (a,b). Thao tác trên cặp số 
bao gồm: thao tác I, II, III để chuyển (a,b) về (a-b,b) hoặc về (a+b,b)
hoặc về (b,a). Lưu ý thao tác I thực hiện khi a >= b. Đầu vào là bốn số
nguyên c, d, x, y, yêu cầu in ra các thao tác với số bước chuyển thao tác
là ít nhất để chuyển đổi cặp (c,d) sang cặp (x,y) và chỉ dùng 3 loại thao
tác I, II, III được định nghĩa ở trên. Nếu không có cách nào chuyển đổi được 
thì in ra -1.
*/


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    queue<pair<pii , vector<pii>>> q; // dùng queue chứa pair một là vị trí hiện tại, kia là path đi từ điểm xuất phát đến điểm hiện tại
    set<pair<int, int>> vis; // ktra xem đã đi qua ô này chưa
    int c, d, x, y;
    cin >> c >> d >> x >> y;
    if (c == x && d == y) {
        cout << "0 (" << x << " " << y << ")";
        return 0;
    }
    vis.insert({c, d});
    q.push({{c,d}, {{c,d}}});
    while(!q.empty()){
        auto [now, path] = q.front();
        q.pop();
        int a = now.first, b = now.second;
        vector<pii> next = {{a-b, b}, {a+b, b}, {b, a}};
        for (auto [na, nb] : next) {
            if (na < 0 || nb < 0 || na > 30 || nb > 30) continue;
            if (vis.count({na, nb})) continue;
            vector<pii> npath = path;
            npath.push_back({na, nb});
            if (na == x && nb == y) {
                cout << npath.size() - 1 << " ";
                for (auto [xi, yi] : npath) cout << "(" << xi << " " << yi << ") ";
                return 0;
            }
            q.push({{na, nb}, npath});
            vis.insert({na, nb});
        }
    }
    cout << -1;
    return 0;
}

/*
Input:
14 2 2 10
Output:
3 (14 2) (12 2) (10 2) (2 10)
*/