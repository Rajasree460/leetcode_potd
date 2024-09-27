// Approach -2

class MyCalendarTwo {
    private List<int[]> events;        // List to store all events
    private List<int[]> doubleBookings; // List to store double bookings

    public MyCalendarTwo() {
        events = new ArrayList<>();        // Initialize list to store events
        doubleBookings = new ArrayList<>(); // Initialize list to store double bookings
    }

    public boolean book(int start, int end) {
        // Check if the current event would cause a triple booking
        for (int[] db : doubleBookings) {
            if (start < db[1] && end > db[0]) {
                // Triple booking detected, reject this event
                return false;
            }
        }

        // Check for overlaps with existing events to see if a double booking occurs
        for (int[] event : events) {
            if (start < event[1] && end > event[0]) {
                // There is an overlap, add the overlapping part to doubleBookings
                doubleBookings.add(new int[]{Math.max(start, event[0]), Math.min(end, event[1])});
            }
        }

        // Add the new event to the events list
        events.add(new int[]{start, end});
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */

 
