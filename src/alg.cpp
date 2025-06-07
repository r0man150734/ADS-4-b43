// Copyright 2021 NNTU-CS
int lower_bound(int *arr, int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
int upper_bound(int *arr, int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (i != j && arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count / 2;
}
int countPairs2(int *arr, int len, int value) {
    int left = 0, right = len - 1;
    int count = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum < value) {
            ++left;
        } else if (sum > value) {
            --right;
        } else {
            int l_val = arr[left], r_val = arr[right];
            int l_count = 0, r_count = 0;

            while (left < right && arr[left] == l_val) {
                ++l_count;
                ++left;
            }
            while (left <= right && arr[right] == r_val) {
                ++r_count;
                --right;
            }

            count += l_count * r_count;
        }
    }

    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        if (target < 0) continue;

        int low = lower_bound(arr, i + 1, len, target);
        int high = upper_bound(arr, i + 1, len, target);

        count += (high - low);
    }

    return count;
}
