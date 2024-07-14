#include<bits/stdc++.h>
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>>st;
        st.push(unordered_map<string, int>());
        
        int index = 0;
        
        while(index < formula.length())
        {
            if(formula[index] == '(')
            {
                st.push(unordered_map<string, int>());
                index++;
            }
            
            else if(formula[index] == ')')
            {
                unordered_map<string, int> currMap = st.top();
                st.pop();
                index++;
                string multiplier;
                while(index < formula.length() && isdigit(formula[index]))
                {
                    multiplier += formula[index];
                    index++;
                }
                
                if(!multiplier.empty())
                {
                    int mult = stoi(multiplier);
                    for(auto& [atom, count] : currMap)
                    {
                        currMap[atom] = count*mult;
                    }
                }
                
                for(auto & [atom, count]: currMap)
                {
                    st.top()[atom] += count;
                }
            }
            
            else
            {
                string currAtom;
                currAtom += formula[index];
                index++;
                
                while(index < formula.length() && islower(formula[index]))
                {
                    currAtom += formula[index];
                    index++;
                }
                
                string currCount;
                while(index < formula.length() && isdigit(formula[index]))
                {
                    currCount += formula[index];
                    index++;
                }
                
                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count;
            }
        }
        
        map<string, int> finalMap(st.top().begin(), st.top().end());
        
        string ans;
        for(auto& [atom, count] : finalMap)
        {
            ans += atom;
            if(count > 1)
            {
                ans += to_string(count);
            }
        }
        
        return ans;
    } 
};