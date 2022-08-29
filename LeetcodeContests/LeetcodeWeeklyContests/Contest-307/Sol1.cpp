// TC: O(N)
// SC: O(1)

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        
        
        int hours = 0;
        for (int i = 0; i < energy.size(); i++)
        {
            if (energy[i] >= initialEnergy) // if opponent energy is greater , then we need this much hours of training before hand
            {
                hours += (energy[i] - initialEnergy) + 1;
                initialEnergy += (energy[i] - initialEnergy) + 1;
            }
            if (experience[i] >= initialExperience) // if opponent experience is greater,then we need this much hours of training before hand
            {
                hours += (experience[i] - initialExperience) + 1;
                initialExperience += (experience[i] - initialExperience) + 1;
            }
            // if not counted in training hours but still energy would be decreasing n experience would be increasing
			// At the end increase the experience by experience[i] and decrease the energy by energy[i].
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return hours;
        
    }
};