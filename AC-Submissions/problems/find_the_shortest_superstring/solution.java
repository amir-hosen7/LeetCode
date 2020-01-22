class Solution {
    private String merge(String s1, String s2) {
        int len1 = s1.length(), len2 = s2.length();
        int overlapped1 = 0, overlapped2 = 0;

        for (int len = 1; len1 - len >= 0 && len <= len2; len++) {
            // substring(begin)
            // substring(begin, end)
            if (s1.substring(len1 - len).equals(s2.substring(0, len))) {
                overlapped1 = len;
            }
        }

        for (int len = 1; len2 - len >= 0 && len <= len1; len++) {
            if (s2.substring(len2 - len).equals(s1.substring(0, len))) {
                overlapped2 = len;
            }
        }

        if (overlapped1 >= overlapped2) {
            return s1.substring(0, len1 - overlapped1) + s2;
        } else {
            return s2.substring(0, len2 - overlapped2) + s1;
        }
    }

    public String shortestSuperstring(String[] A) {
        List<String> list = new ArrayList(Arrays.asList(A));

        while (true) {
            if (list.size() == 1) break;

            int n = list.size();
            int max = -1;
            int index1 = 0, index2 = 0;
            String newStr = "";
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    String s1 = list.get(i);
                    String s2 = list.get(j);
                    String merged = merge(s1, s2);

                    int savedLen = s1.length() + s2.length() - merged.length();

                    if (savedLen > max) {
                        max = savedLen;
                        index1 = i;
                        index2 = j;
                        newStr = merged;
                    }
                }
            }

            String str1 = list.get(index1);
            String str2 = list.get(index2);
            list.remove(str1);
            list.remove(str2);
            list.add(newStr);
        }

        return list.get(0);
    }
}
