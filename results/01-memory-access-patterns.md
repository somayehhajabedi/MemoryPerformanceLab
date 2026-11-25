# Experiment 01 — Benchmark Results

## Hardware and Software Environment

| Parameter | Value |
|---|---|
| Machine | Lenovo ThinkPad T14 Gen 1 |
| OS | Linux |
| Language | C++23 |
| Build type | Release |
| perf version | 7.0.14 |
| L1d Cache | 32 KiB |
| L1i Cache | 32 KiB |
| L2 Cache | 256 KiB |
| L3 Cache | 8 MiB |
| Cache line size | 64 bytes |

## Benchmark Configuration

| Parameter | Value |
|---|---:|
| Elements | 16,777,216 |
| Data size | 64 MiB |
| Random seed | 42 |
| Expected checksum | 140737479966720 |

## Preliminary Timing Results

| Run | Sequential (ms) | Random (ms) | Speedup |
|---|---:|---:|---:|
| 1 | 19.625 | 435.984 | 22.22x |
| 2 | 16.826 | 455.897 | 27.10x |

## Hardware Performance Counters

| Metric | Value |
|---|---:|
| CPU cycles | 1,566,115,256 |
| Instructions | 1,523,597,862 |
| Cache references | 120,829,848 |
| Cache misses | 76,006,997 |
| IPC | 0.973 |
| Cache miss/reference ratio | 62.90% |
| Total elapsed time | 0.995 s |
| Counter running/enabled ratio | ~75% |

## Measurement Notes

- Hardware counters include the entire process.
- Counter multiplexing was active.
- Both access patterns produced the expected checksum.
- Results are preliminary and hardware-dependent.

## Status

Controlled and repeated measurements are pending.

## Repeated Benchmark Results (Version 2)

- Warm-up iterations: 1
- Measured iterations: 7
- Independent execution modes: sequential and random
- Combined array payload per process: 128 MiB

| Metric | Sequential | Random |
|---|---:|---:|
| Minimum (ms) | 9.852 | 212.131 |
| Median (ms) | 9.947 | 216.757 |
| Maximum (ms) | 11.163 | 446.361 |
| Time per element (ns, based on median) | 0.59 | 12.92 |
| Checksum validation | PASS | PASS |

**Median speedup: 21.79x**

The repeated measurements confirm a substantial performance difference between sequential and randomized memory access.

Random access exhibited higher execution time variability. Further profiling is required to identify the cause.

CPU affinity and region-specific hardware counter measurements remain pending.

## Hardware Performance Counters (Version 2)

### CPU Counters

| Metric | Sequential | Random |
|---|---:|---:|
| CPU cycles | 542,770,216 | 4,525,623,531 |
| Instructions | 1,054,493,289 | 2,064,751,403 |
| IPC | 1.943 | 0.456 |
| Median execution time (ms) | 10.933 | 361.838 |
| Process elapsed time (s) | 0.162229 | 3.794981 |

### Cache Counters

| Metric | Sequential | Random |
|---|---:|---:|
| Cache references | 44,227,826 | 379,792,196 |
| Cache misses | 27,178,040 | 260,996,684 |
| Miss/reference ratio | 61.45% | 68.72% |
| Median execution time (ms) | 10.347 | 260.064 |
| Process elapsed time (s) | 0.167736 | 2.765710 |

### Observations

- Random mode incurred approximately 9.60x more cache misses.
- Sequential mode achieved approximately 4.26x higher IPC.
- Both modes passed checksum validation.
- Random access exhibited significant timing variability.

### Limitations

- Counters include initialization, shuffling, warm-up, and measured iterations.
- CPU and cache counters were collected in separate executions.
- Generic cache event semantics are hardware-dependent.
- CPU affinity and region-specific counter measurements were not applied.
