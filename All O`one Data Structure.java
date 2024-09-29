class AllOne {
    private Map<String, Integer> hash;
    private List<String> keys;

    public AllOne() {
        hash = new HashMap<>();
        keys = new ArrayList<>();
    }

    public void inc(String key) {
        if (!hash.containsKey(key)) {
            hash.put(key, 0);
            keys.add(key);
        }
        hash.put(key, hash.get(key) + 1);

        int value = hash.get(key);
        keys.remove(key);  // Remove the key from the current position

        // Perform binary search to insert at correct position
        int low = 0, high = keys.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (hash.get(keys.get(mid)) < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        keys.add(low, key);  // Insert key at the new correct position
    }

    public void dec(String key) {
        if (!hash.containsKey(key)) return;

        hash.put(key, hash.get(key) - 1);
        if (hash.get(key) == 0) {
            hash.remove(key);
            keys.remove(key);  // Safely remove the key if its value is 0
        } else {
            int value = hash.get(key);
            keys.remove(key);  // Remove the key from its current position

            // Perform binary search to insert at correct position
            int low = 0, high = keys.size();
            while (low < high) {
                int mid = (low + high) / 2;
                if (hash.get(keys.get(mid)) < value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            keys.add(low, key);  // Reinsert the key at the correct position
        }
    }

    public String getMinKey() {
        return keys.isEmpty() ? "" : keys.get(0);  // Return the first key or an empty string if list is empty
    }

    public String getMaxKey() {
        return keys.isEmpty() ? "" : keys.get(keys.size() - 1);  // Return the last key or an empty string if list is empty
    }
}
