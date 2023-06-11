// class SnapshotArray {
// public:
//     map<int,map<int,int>>mp;
//     int count=0;
//     SnapshotArray(int length) {
//         // mp.resize(length);
//         // for(int i=0;i<length;i++)
//         // {
//         //     mp[i][0]=0;
//         // }
//     }
    
//     void set(int index, int val) {
//         mp[index][count]=val;
//     }
    
//     int snap() {
//         count++;
//         return (count-1);
//     }
    
//     int get(int index, int snap_id) {
//          auto it = mp[index].lower_bound(snap_id+1);
        
//         int v=0;
        
//         if(it!=mp[index].begin())
//         {
//             it--;
//             v = it->second;
//         }
        
//         return v;
        
//     }
// };

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */



 class SnapshotArray {
public:
    vector<vector<pair<int, int>>> values;
    int activeSnapId;
    int size;
    SnapshotArray(int length) {
        activeSnapId = 0;
        values.resize(length);
    }
    
    void set(int index, int val) {
        values[index].push_back({activeSnapId, val});
    }
    
    int snap() {
        ++activeSnapId;
        return activeSnapId - 1;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int, int>>::iterator iter = upper_bound(values[index].begin(), values[index].end(), make_pair(snap_id, INT_MAX));
        if (iter == values[index].begin()) {
            return 0;
        }
        return prev(iter)->second;
    }
};
