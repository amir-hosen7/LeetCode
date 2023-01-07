class DataStream {
    int val, kk, cnt = 0;
    public DataStream(int value, int k) {
        val = value;
        kk = k;
    }
    
    public boolean consec(int num) {
        if (num == val) {
            cnt++;
        }
        else{
            cnt = 0;
        }
        if (cnt >= kk) return true;
        else return false;
    }
}

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream obj = new DataStream(value, k);
 * boolean param_1 = obj.consec(num);
 */