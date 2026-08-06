class CountSquares {
   public:
    unordered_map<int, unordered_map<int, int>> ptCnt;
    CountSquares() {}

    void add(vector<int> point) { ptCnt[point[0]][point[1]]++; }

    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0];
        int y1 = point[1];
        for (auto& [y2, cnt] : ptCnt[x1]) {
            int side = y2 - y1;
            if (side == 0) continue;
            int x3 = x1 + side;
            int x4 = x1 - side;
            res += cnt * ptCnt[x3][y1] * ptCnt[x3][y2];
            res += cnt * ptCnt[x4][y1] * ptCnt[x4][y2];
        }
        return res;
    }
};
