class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map_dict = {}
        for i,string in enumerate(strs):
            tmp = ("").join(sorted(string))
            try:
                map_dict[tmp].append(strs[i])
            except:
                map_dict[tmp] = [strs[i]]

        return list(map_dict.values())