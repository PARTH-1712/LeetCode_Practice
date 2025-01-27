class Solution {
private:
    int getAvg(vector<vector<int>> &img, int i, int j){

        int cnt = 1;
        int sum = img[i][j];

        if(i - 1 >= 0){
            sum += img[i - 1][j];
            cnt++;
        }

        if(j - 1 >= 0){
            sum += img[i][j - 1];
            cnt++;
        }

        if(i + 1 < img.size()){
            sum += img[i + 1][j];
            cnt++;
        }

        if(j + 1 < img[0].size()){
            sum += img[i][j + 1];
            cnt++;
        }

        if(i - 1 >= 0 && j - 1 >= 0){
            sum += img[i - 1][j - 1];
            cnt++;
        }

        if(i + 1 < img.size() && j + 1 < img[0].size()){
            sum += img[i + 1][j + 1];
            cnt++;
        }

        if(i - 1 >= 0 && j + 1 < img[0].size()){
            sum += img[i - 1][j + 1];
            cnt++;
        }

        if(i + 1 < img.size() && j - 1 >= 0){
            sum += img[i + 1][j - 1];
            cnt++;
        }

        return floor(sum / cnt);

    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        vector<vector<int>> ans(img.size(), vector<int> (img[0].size()));

        for(int i = 0; i < img.size(); i++){
            for(int j = 0; j < img[0].size(); j++){
                ans[i][j] = getAvg(img, i, j);
            }
        }

        return ans;
    }
};