class Solution {
    public int countCollisions(String directions) {
        Stack<Character> stak = new Stack<>();
        int collisions=0;
        for(int i=0;i<directions.length();i++) {
            if(stak.isEmpty() || directions.charAt(i) == 'R')
                stak.push(directions.charAt(i));
            else if(directions.charAt(i) == 'S') {
                while(!stak.isEmpty() && stak.peek() == 'R') {
                    collisions++;
                    stak.pop();
                }
                stak.push('S');
            } else if(directions.charAt(i) == 'L') {
                if(!stak.isEmpty() && stak.peek() == 'S') {
                    collisions++;
                    stak.push('S');
                } else if(!stak.isEmpty() && stak.peek() == 'R') {
                    collisions+=2;
                    stak.pop();
                    while(!stak.isEmpty() && stak.peek() == 'R') {
                        collisions++;
                        stak.pop();
                    }
                    stak.push('S');
                } else
                    stak.push(directions.charAt(i));
            }
        }
        return collisions;
    }
}
