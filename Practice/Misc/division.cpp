typedef vector<vector<string>> vvs;
typedef vector<double> vd;

class Solution {
public:
    unordered_map<string, int> ID; // ID map
    int n_ids = 0;
    vector<int> UF; // Union-find vector
    // Maps connected graph components to a single root
    // Roots are identified by UF[i] = -1
    vector<double> ratio; // Ratio vector
    // Keeps track of i / root(i), where root is the UF root.

    int getID(string s, bool allownewnodes) {
        auto id = ID.find(s);
        if (id == ID.end()) { // Create a new graph node
            if (!allownewnodes) return -1;
            UF.push_back(-1); // Needs a UF entry
            ratio.push_back(1); // Needs a ratio entry
            return ID[s] = n_ids++;
        }
        return id->second;
    }

    int find(int v) {
        if (UF[v] == -1) return v; // Return if root
        int parent = UF[v];
        UF[v] = find(parent); // Path shortening
        ratio[v] *= ratio[parent]; // Ratio multiplication
        return UF[v];
    }
    
    vd calcEquation(vvs& equations, vd& values, vvs& queries) {
        for (int i=0; i<equations.size(); i++) {
            auto eq = equations[i];
            auto val = values[i];
            int a = getID(eq[0], 1);
            int b = getID(eq[1], 1);
            int a_root = find(a);
            int b_root = find(b);
            if (a_root == b_root) continue; // Already connected
            UF[a_root] = b_root;
            // val == ratio[a]*ratio[a_root]/ratio[b];
            ratio[a_root] = val * ratio[b] / ratio[a];
        }
        vd ans;
        for (auto q : queries) {
            int a = getID(q[0], 0);
            int b = getID(q[1], 0);
            if (a == -1 || b == -1) {
                ans.push_back(-1);
                continue;
            }
            int a_root = find(a);
            int b_root = find(b);
            if (a_root != b_root) {
                ans.push_back(-1);
            } else {
                ans.push_back(ratio[a] / ratio[b]);
            }
        }
        return ans;
    }
};