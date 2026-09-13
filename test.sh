#!/usr/bin/env bash

set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$ROOT_DIR/build"

cmake --build build

echo "Configuring project..."
cmake -S "$ROOT_DIR" -B "$BUILD_DIR"

echo "Building tests..."
cmake --build "$BUILD_DIR" --target shell_tests

echo "Running tests..."
ctest --test-dir "$BUILD_DIR" --output-on-failure
