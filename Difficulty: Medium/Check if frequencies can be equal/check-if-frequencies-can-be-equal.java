class Solution {
    boolean sameFreq(String s) {
        int car[]=new int[26];
        for(int i=0;i<s.length();i++){
            car[s.charAt(i)-'a']++;
        }
        
        TreeMap<Integer,Integer> tmap = new TreeMap<Integer,Integer>();

        for(int i=0;i<26;i++){
            int f=car[i];
            if(f==0) continue;
            if(tmap.containsKey(f)){
                tmap.put(f,tmap.get(f)+1);
            }
            else tmap.put(f,1);
        }
        if(tmap.size()>2) return false;       
        if(tmap.size()==1) return true;       
        
        int fk=tmap.firstKey();
        int lk=tmap.lastKey();
        
        if(lk==fk+1 && tmap.get(lk)==1){     
            return true;
        }
        
        if(fk==1 && tmap.get(fk)==1){       
            return true;
        }
        return false;
        
    }
}