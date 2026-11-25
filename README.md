# MemoryPerformanceLab

A hands-on C++23 and Linux performance engineering laboratory focused on memory architecture, CPU caches, memory access patterns, and hardware-level performance analysis.

## Overview

This project combines theoretical concepts with practical experiments inspired by Ulrich Drepper's paper, *What Every Programmer Should Know About Memory* (2007).

The objective is to understand how hardware architecture and software design decisions influence application performance, particularly in low-latency, high-throughput, and real-time systems.

The project includes independent implementations, reproducible benchmarks, hardware performance measurements, and technical documentation.

## Learning Objectives

- Understand CPU cache architecture and memory hierarchy.
- Explore spatial and temporal locality.
- Investigate sequential and random memory access patterns.
- Understand cache lines, cache associativity, and cache misses.
- Analyze hardware prefetching and memory bandwidth.
- Investigate TLB behavior and virtual memory.
- Explore cache coherence and false sharing.
- Understand NUMA architecture.
- Apply cache-aware data structure design.
- Measure and optimize C++ application performance.

## Technologies and Tools

- C++23
- Linux
- CMake
- Ninja
- Linux perf
- Hardware Performance Counters
- Git and GitHub

## Project Structure

```text
MemoryPerformanceLab/
├── CMakeLists.txt
├── README.md
├── README.fa.md
├── docs/
│   ├── en/
│   └── fa/
├── experiments/
│   └── 01-memory-access-patterns/
├── benchmarks/
├── results/
└── tests/
```

## Experiments

| ID | Experiment | Status |
|---|---|---|
| 01 | Sequential vs. Random Memory Access | In progress |
| 02 | Memory Hierarchy and Working Set Size | Planned |
| 03 | Cache Line Utilization | Planned |
| 04 | Cache Associativity and Conflict Misses | Planned |
| 05 | Spatial and Temporal Locality | Planned |
| 06 | Hardware Prefetching | Planned |
| 07 | Memory Alignment and Padding | Planned |
| 08 | False Sharing | Planned |
| 09 | TLB and Page Size | Planned |
| 10 | Memory Bandwidth and Latency | Planned |
| 11 | NUMA Architecture | Planned |
| 12 | Cache-Aware Data Structures | Planned |

## Preliminary Benchmark Results

The first experiment compares sequential and randomized indexed access to a 64 MiB data array.

| Metric | Sequential | Random |
|---|---:|---:|
| Run 1 | 19.625 ms | 435.984 ms |
| Run 2 | 16.826 ms | 455.897 ms |

The preliminary measurements demonstrate a performance difference of approximately 22–27x despite identical algorithmic time complexity.

These results are preliminary and hardware-dependent. Further measurements and controlled benchmarking are in progress.

## Test Environment

- Machine: Lenovo ThinkPad T14 Gen 1
- Operating System: Linux
- L1 Data Cache: 32 KiB per instance
- L1 Instruction Cache: 32 KiB per instance
- L2 Cache: 256 KiB per instance
- L3 Cache: 8 MiB
- Cache Line Size: 64 bytes
- perf version: 7.0.14

## Build

```bash
cmake -S . -B build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release

cmake --build build
```

## Applications

The concepts explored in this laboratory are particularly relevant to:

- High-Frequency Trading (HFT)
- Low-Latency Systems
- Financial Trading Infrastructure
- Real-Time Systems
- Embedded Linux
- High-Performance Computing
- Database Engines
- ML Systems Performance

## Documentation

## Documentation

Technical documentation includes theoretical concepts,
practical experiments, benchmark methodologies,
and performance analysis.

- [Chapter 01 — Introduction](docs/en/01-introduction.md)


## Reference

Ulrich Drepper, *What Every Programmer Should Know About Memory*, 2007.

The documentation and experiments in this repository are independently developed educational materials. Historical hardware descriptions are distinguished from modern architectural considerations.

## Project Status

Active development.
