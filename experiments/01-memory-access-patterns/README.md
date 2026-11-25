# Experiment 01 — Sequential vs. Random Memory Access

## 1. Objective

Measure the impact of memory access patterns on execution time with identical traversal logic and O(N) complexity.

## 2. Methodology

- Data array: 16,777,216 `uint32_t` elements (64 MiB).
- Combined array payload: 128 MiB.
- Independent sequential and random execution modes.
- Fixed random seed: 42.
- One warm-up iteration.
- Seven measured iterations.
- Minimum, median, and maximum execution times.
- Automatic checksum validation.
- Initialization outside the timed region.

## 3. Build & Run

```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build

./build/memory_access_patterns sequential
./build/memory_access_patterns random
```

Hardware counter analysis:

```bash
perf stat -e cycles,instructions ./build/memory_access_patterns sequential
perf stat -e cycles,instructions ./build/memory_access_patterns random

perf stat -e cache-references,cache-misses ./build/memory_access_patterns sequential
perf stat -e cache-references,cache-misses ./build/memory_access_patterns random
```

## 4. Results

| Metric | Sequential | Random |
|---|---:|---:|
| Minimum | 9.852 ms | 212.131 ms |
| Median | 9.947 ms | 216.757 ms |
| Maximum | 11.163 ms | 446.361 ms |
| IPC | 1.943 | 0.456 |
| Cache misses | 27.18 M | 261.00 M |
| Checksum | PASS | PASS |

**Median speedup: 21.79x**

Hardware counters were collected in separate executions.

## 5. Analysis

The data array is eight times larger than the processor's 8 MiB L3 cache.

Sequential access benefits from spatial locality, cache line utilization, and hardware prefetching.

Random access increases cache pressure and reduces prefetching effectiveness.

Identical algorithmic complexity does not guarantee identical execution performance.

## 6. Limitations

- Hardware counters include initialization, shuffling, and warm-up.
- CPU affinity was not applied.
- Individual cache and TLB effects were not isolated.
- Random access exhibited significant timing variability.

## Related Documentation

- [Theoretical Background](../../docs/01-introduction.md)
- [Detailed Benchmark Results](../../results/01-memory-access-patterns.md)
