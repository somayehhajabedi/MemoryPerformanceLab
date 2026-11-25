#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <vector>

using Clock = std::chrono::steady_clock;

constexpr std::size_t DEFAULT_N = 16 * 1024 * 1024;
constexpr int REPETITIONS = 7;

struct BenchmarkResult
{
    double elapsed_ms;
    std::uint64_t checksum;
};

BenchmarkResult benchmark(
    const std::vector<std::uint32_t>& data,
    const std::vector<std::uint32_t>& indices)
{
    std::uint64_t sum = 0;

    const auto start = Clock::now();

    for (const auto index : indices)
    {
        sum += data[index];
    }

    const auto end = Clock::now();

    const double elapsed =
        std::chrono::duration<double, std::milli>(
            end - start).count();

    return {elapsed, sum};
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: memory_access_patterns "
                  << "<sequential|random> [elements]\n";
        return 1;
    }

    const std::string_view mode = argv[1];

    if (mode != "sequential" && mode != "random")
    {
        std::cerr << "Invalid access mode\n";
        return 1;
    }

    std::size_t n = DEFAULT_N;

    if (argc > 2)
    {
        try
        {
            n = std::stoull(argv[2]);
        }
        catch (const std::exception&)
        {
            std::cerr << "Invalid element count\n";
            return 1;
        }
    }

    if (n == 0 || n > UINT32_MAX)
    {
        std::cerr << "Invalid element count\n";
        return 1;
    }

    std::vector<std::uint32_t> data(n);
    std::iota(data.begin(), data.end(), 0u);

    std::vector<std::uint32_t> indices(n);
    std::iota(indices.begin(), indices.end(), 0u);

    if (mode == "random")
    {
        std::mt19937 generator(42);

        std::shuffle(
            indices.begin(),
            indices.end(),
            generator
        );
    }

    const std::uint64_t expected =
        static_cast<std::uint64_t>(n) * (n - 1) / 2;

    // Warm-up
    const auto warmup = benchmark(data, indices);

    if (warmup.checksum != expected)
    {
        std::cerr << "Warm-up checksum mismatch\n";
        return 1;
    }

    std::vector<double> timings;
    timings.reserve(REPETITIONS);

    for (int i = 0; i < REPETITIONS; ++i)
    {
        const auto result = benchmark(data, indices);

        if (result.checksum != expected)
        {
            std::cerr << "Checksum mismatch\n";
            return 1;
        }

        timings.push_back(result.elapsed_ms);
    }

    std::sort(timings.begin(), timings.end());

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "Mode: " << mode << '\n';
    std::cout << "Elements: " << n << '\n';

    std::cout << "Data size: "
              << n * sizeof(std::uint32_t)
                   / (1024.0 * 1024.0)
              << " MiB\n";

    std::cout << "Repetitions: " << REPETITIONS << '\n';
    std::cout << "Min: " << timings.front() << " ms\n";
    std::cout << "Median: " << timings[REPETITIONS / 2]
              << " ms\n";
    std::cout << "Max: " << timings.back() << " ms\n";
    std::cout << "Checksum: " << expected << '\n';

    return 0;
}
