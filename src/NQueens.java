import java.util.Vector;

public class NQueens {
    int n;
    Vector<String[]> boards = new Vector<String[]>();
    public NQueens(int n) {
        this.n = n;
        int[] pl = new int[n];
        int[] pos = queenBuilder(pl, 1, 0);
        while (pos != null) {
            String[] board = new String[n];
            for (int i = 0; i < n; i++) {
                String s = "";
                for (int j = 0; j < n; j++) {
                    if (j == pos[i]) {
                        s += " Q ";
                    } else {
                        s += " * ";
                    }
                }
                board[i] = s;
            }
            boards.add(board);
            pos[n - 1] += 1;
            pos = queenBuilder(pos, n - 1, pos[n - 1] + 1);
        }
    }

    public int[] queenBuilder(int[] place, int ind, int st){
        if (ind>=n){return place;}
        if (ind==0){
            if (st>=n){return null;}
            place[ind] =  st;
            return queenBuilder(place, ind+1, 0);
        }
        else if (st >= n){
            return queenBuilder(place, ind-1, place[ind-1]+1);
        }

        int i = ind, j=st;
        while (j<n){
            boolean free = true;
            for (int a=0; a<i; a++){
                if (place[a] == j || a+place[a] == i+j || a-place[a] == i-j){
                    j+=1;
                    free = false;
                    break;
                }
            }
            if (free){
                place[ind] = j;
                return queenBuilder(place, ind+1, 0);
            }
        }
        return queenBuilder(place, ind-1, place[ind-1]+1);
    }
    public static int fact(int k){
        if (k<= 1){
            return 1;
        }
        return k*fact(k-1);
    }
    public static void main(String[] args){
        NQueens Q = new NQueens(6);

        for (String[] board : Q.boards){
            for (int i=0; i<Q.n; i++){
                System.out.println(board[i]);
            }
            System.out.print("\n\n\n");
        }
    }
}
