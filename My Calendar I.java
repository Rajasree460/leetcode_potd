import java.util.ArrayList;

class MyCalendar {
    private ArrayList<int[]> bookings;

    public MyCalendar() {
        bookings = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        // Loop through all previously booked events
        for (int[] event : bookings) {
            int existingStart = event[0];
            int existingEnd = event[1];
            
            // Check for overlap
            if (start < existingEnd && end > existingStart) {
                return false;
            }
        }
        // No overlap, add the new event
        bookings.add(new int[] {start, end});
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
