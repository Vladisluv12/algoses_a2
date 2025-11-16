import pandas as pd
import matplotlib.pyplot as plt

df1 = pd.read_csv('mergeSortTests.csv')
df2 = pd.read_csv('mixedSortTests.csv')
df = pd.concat([df1, df2])

array_types = {0: 'random', 1: 'reverse_sorted', 2: 'almost_sorted'}

fig, axes1 = plt.subplots(1, 3, figsize=(18, 6))

for i, array_type in enumerate([0, 1, 2]):
    data = df[df['ArrayType'] == array_type]
    classic = data[data['Threshold'] == 0]
    if not classic.empty:
        axes1[i].plot(classic['Size'], classic['TimeMicros'], label='Classic Merge', linewidth=3, color='red')
    axes1[i].set_title(f'{array_types[array_type]} arrays')
    axes1[i].set_xlabel('Size')
    axes1[i].set_ylabel('Time (microseconds)')
    axes1[i].legend()
    axes1[i].grid(True)

plt.tight_layout()
plt.savefig('merge_sort_comparison.png', dpi=150, bbox_inches='tight')
plt.show()

fig, axes2 = plt.subplots(1, 3, figsize=(18, 6))
for i, array_type in enumerate([0, 1, 2]):
    data = df[df['ArrayType'] == array_type]
    
    for threshold in [5, 10, 20, 30, 50]:
        hybrid = data[data['Threshold'] == threshold]
        if not hybrid.empty:
            axes2[i].plot(hybrid['Size'], hybrid['TimeMicros'], label=f'Threshold {threshold}', linewidth=2)
    
    axes2[i].set_title(f'{array_types[array_type]} arrays')
    axes2[i].set_xlabel('Size')
    axes2[i].set_ylabel('Time (microseconds)')
    axes2[i].legend()
    axes2[i].grid(True)

plt.tight_layout()
plt.savefig('mixed_sort_comparison.png', dpi=150, bbox_inches='tight')
plt.show()