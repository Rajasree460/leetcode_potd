class Solution {
    int Helper(vector<int>&gas,vector<int>&cost){
        int CurrS=0;
        int Tfuel=0;
        int Tcst=0;
        int st=0;
       // Forcounting the amount of fuel
       for(int &i:gas){
           Tfuel+=i;
       }
       // Forcounting the  total cost
       for(int &i:cost){
           Tcst+=i;
       }
       // Corner Case
       if(Tfuel<Tcst) return -1;
       for(int i=0;i<gas.size() && i<cost.size();i++){
           CurrS+=(gas[i]-cost[i]);
           if(CurrS<0){
               st=i+1;
               CurrS=0;
           }
       }
       return st;
    }
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return Helper(gas,cost);
    }
};
