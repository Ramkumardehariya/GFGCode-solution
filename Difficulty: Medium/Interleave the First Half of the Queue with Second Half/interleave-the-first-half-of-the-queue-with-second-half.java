class Solution {
    public void rearrangeQueue(Queue<Integer> q) {
        // code here
        int size = q.size();
        int i = size ;
        ArrayList<Integer> st = new ArrayList<>();
        ArrayList<Integer> st1 = new ArrayList<>();

        while (i > 0) {
            if (i > size / 2) {
                st1.add(q.poll());
            } else {
                st.add(q.poll());
            }
            i--;
        }

        while (st1.size() != 0 && st.size() != 0) {
            q.add(st1.getFirst());
            st1.removeFirst();
            q.add(st.getFirst());
            st.removeFirst();
        }
    }
}
