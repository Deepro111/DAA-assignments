import matplotlib.pyplot as plt

def linear_search(arr, key):
    comparisons = 0
    for i in range(len(arr)):
        comparisons += 1
        if arr[i] == key:
            return comparisons
    return comparisons

# Data collection
min_comparisons = []
max_comparisons = []
avg_comparisons = []
input_sizes = range(10, 105, 5)

for n in input_sizes:
    arr = list(range(n))  # Array of size n
    total_comparisons = 0
    
    # n successful searches
    for key in arr:
        total_comparisons += linear_search(arr, key)
    
    # 1 unsuccessful search
    total_comparisons += linear_search(arr, -1)  # Key not in array
    
    min_comparisons.append(1)  # Best case: first element
    max_comparisons.append(n + 1)  # Worst case: unsuccessful search
    avg_comparisons.append(total_comparisons / (n + 1))  # Average comparisons


plt.figure(figsize=(10, 6))
plt.plot(input_sizes, min_comparisons, label='Best Case (Min Comparisons)', marker='o')
plt.plot(input_sizes, max_comparisons, label='Worst Case (Max Comparisons)', marker='x')
plt.plot(input_sizes, avg_comparisons, label='Average Comparisons', marker='s')

plt.title('Linear Search Comparisons')
plt.xlabel('Input Size (n)')
plt.ylabel('Number of Comparisons')
plt.legend()
plt.grid(True)
plt.show()
