#include <stdio.h>
int main() {
    int arr[100], choice, key, n;

    // Input the number of elements
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Menu system without using do-while loop
    while (1) {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Linear Search
            printf("Enter the element to search: ");
            scanf("%d", &key);
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    printf("Element %d found at index %d (Linear Search)\n", key, i);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Element %d not found (Linear Search)\n", key);
            }

        } else if (choice == 2) {
            // Binary Search (first, sort the array)
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            // Perform Binary Search
            printf("Enter the element to search: ");
            scanf("%d", &key);
            int beg = 0, end = n - 1, found = 0;
            while (beg <= end) {
                int mid = beg + (end - beg) / 2;
                if (arr[mid] == key) {
                    printf("Element %d found at index %d (Binary Search)\n", key, mid);
                    found = 1;
                    break;
                } else if (arr[mid] < key) {
                    beg = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            if (!found) {
                printf("Element %d not found (Binary Search)\n", key);
            }

        } else if (choice == 3) {
            // Exit the program
            printf("Exiting...\n");
            break;
        } else {
            // Invalid option
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
