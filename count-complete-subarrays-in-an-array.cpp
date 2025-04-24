#include <bits/stdc++.h>
using namespace std;

long long countCompleteSubarrays(const vector<int>& nums) {
    int n = nums.size();
    // पूरे array के distinct काउंट
    unordered_set<int> s(nums.begin(), nums.end());
    int needed = s.size();

    unordered_map<int,int> freq;
    long long ans = 0;
    int have = 0, j = 0;

    for (int i = 0; i < n; ++i) {
        // j बढ़ाओ जब तक window complete न हो
        while (j < n && have < needed) {
            if (freq[nums[j]] == 0) 
                have++;
            freq[nums[j]]++;
            j++;
        }
        // अगर complete है, तो (n-j+1) subarrays count करो
        if (have == needed) {
            ans += (n - j + 1);
        } else {
            break;  // आगे बढ़ने के लिए पूरा window नहीं बन पा रहा
        }
        // i बढ़ाने से पहले nums[i] हटाओ
        freq[nums[i]]--;
        if (freq[nums[i]] == 0) 
            have--;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Array का साइज पढ़ो
    cin >> n;
    vector<int> nums(n);
    // Array के elements पढ़ो
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // फ़ंक्शन कॉल करके रिज़ल्ट निकालो
    long long result = countCompleteSubarrays(nums);

    // रिज़ल्ट प्रिंट करो
    cout << result << "\n";
    return 0;
}
