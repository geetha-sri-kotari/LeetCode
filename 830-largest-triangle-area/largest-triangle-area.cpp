class Solution {
public:
    double find_area(vector<vector<int>>& points, int idx1, int idx2, int idx3) {
        int x1 = points[idx1][0], y1 = points[idx1][1];
        int x2 = points[idx2][0], y2 = points[idx2][1];
        int x3 = points[idx3][0], y3 = points[idx3][1];
        double area = (double)0.5*abs( x1 * (y2 - y3) + 
                                       x2 * (y3 - y1) +
                                 x3 * (y1 - y2));
        //cout << area << endl;
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double large_tri_area = 0;
        double tri_area = 0;
        for(int i=0; i<points.size()-2; i++) {
            for(int j=i+1; j<points.size()-1; j++) {
                for(int k=j+1; k<points.size(); k++) {
                    tri_area = find_area(points, i, j, k);
                    large_tri_area = max(large_tri_area, tri_area);
                }
            }
        }
        return large_tri_area;
    }
};