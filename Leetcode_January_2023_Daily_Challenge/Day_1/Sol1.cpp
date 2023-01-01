class Solution {
public:
	bool wordPattern(string pattern, string s) {
		vector<string> v;
		int i = 0;
		string temp = "";
        
        // for doing task of stringstream
		while(i < s.size()){
			if(s[i] == ' '){
				v.push_back(temp);
				temp = "";
			}
			else{
				temp += s[i];
			}
			i++;
		}
		v.push_back(temp);

		if(v.size() != pattern.size()){
			return false;
		}
		unordered_map<char, string> m;
		unordered_set<string> st;
		for(int i = 0; i < pattern.size(); i++){
			if(m.find(pattern[i]) != m.end()){
				if(m[pattern[i]] != v[i]){
					return false;
				}
			}
			else{
				if(st.count(v[i])){ // this represents it was already mapped
					return false;
				}
				m[pattern[i]] = v[i];
				st.insert(v[i]);
			}
		}
		return true;
	}
};