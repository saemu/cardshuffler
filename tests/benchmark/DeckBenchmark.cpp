//
// Created by Samuel Brand on 08.07.20.
//

#include <benchmark/benchmark.h>

#include "Deck.hpp"

static void shuffle(benchmark::State& state) {
    Deck deck(0U);
    for (auto _ : state) {
        // This code gets timed
        deck.shuffle();
    }
}

static void draw(benchmark::State& state) {
    Deck deck(0U);
    for (auto _ : state) {
        while (deck.hasNext()) {
            benchmark::DoNotOptimize(deck.drawNextCard());
        }
    }
}

// Register the function as a benchmark
BENCHMARK(shuffle);
BENCHMARK(draw);
// Run the benchmark
BENCHMARK_MAIN();
