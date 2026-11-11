#!/usr/bin/env python3
"""
Stress-test ./push_swap --medium with checker_linux.

Run:
    python3 test_medium.py

Optional:
    python3 test_medium.py --push-swap ./push_swap --checker ./checker_linux
    python3 test_medium.py --random-cases 300 --max-size 500
"""
import argparse
import random
import subprocess
import sys

INT_MIN = -(2 ** 31)
INT_MAX = 2 ** 31 - 1


def run_case(push_swap, checker, values, label):
    args = [str(x) for x in values]

    try:
        generated = subprocess.run(
            [push_swap, "--medium", *args],
            text=True,
            capture_output=True,
            timeout=10,
        )
    except (OSError, subprocess.TimeoutExpired) as exc:
        return False, f"{label}: push_swap failed: {exc}"

    if generated.returncode != 0:
        return False, (
            f"{label}: push_swap exited {generated.returncode}\n"
            f"stderr: {generated.stderr.strip()}"
        )

    try:
        checked = subprocess.run(
            [checker, *args],
            input=generated.stdout,
            text=True,
            capture_output=True,
            timeout=10,
        )
    except (OSError, subprocess.TimeoutExpired) as exc:
        return False, f"{label}: checker failed: {exc}"

    result = checked.stdout.strip()
    if checked.returncode != 0 or result != "OK":
        return False, (
            f"{label}: expected OK, got {result or '(no output)'}\n"
            f"Input: {' '.join(args)}\n"
            f"Operations:\n{generated.stdout}"
            f"Checker stderr: {checked.stderr.strip()}"
        )

    operations = [line for line in generated.stdout.splitlines() if line.strip()]
    return True, f"{label}: OK ({len(operations)} operations)"


def build_cases(random_cases, max_size, seed):
    rng = random.Random(seed)
    cases = []

    # Small sizes: all common arrangements.
    for n in range(2, 11):
        base = list(range(1, n + 1))
        cases.append((f"sorted n={n}", base))
        cases.append((f"reverse n={n}", base[::-1]))
        cases.append((f"rotated n={n}", base[1:] + base[:1]))
        shuffled = base[:]
        rng.shuffle(shuffled)
        cases.append((f"random-small n={n}", shuffled))

    # Important boundary sizes for block-size calculations.
    for n in [11, 19, 20, 21, 49, 50, 51, 99, 100, 101, max_size]:
        if 2 <= n <= max_size:
            base = list(range(-n // 2, -n // 2 + n))
            for kind in ("sorted", "reverse", "random"):
                values = base[:]
                if kind == "reverse":
                    values.reverse()
                elif kind == "random":
                    rng.shuffle(values)
                cases.append((f"{kind} boundary n={n}", values))

    # Integer extremes and mixed signs.
    edge_sets = [
        [INT_MIN, INT_MAX],
        [INT_MIN, 0, INT_MAX],
        [INT_MAX, 1, 0, -1, INT_MIN],
        [-9, -1, -7, 3, 0, 8, 2, -3],
    ]
    for i, values in enumerate(edge_sets, 1):
        cases.append((f"integer-edge-{i}", values))

    # Larger random permutations.
    for i in range(random_cases):
        n = rng.randint(2, max_size)
        values = rng.sample(range(INT_MIN, INT_MAX + 1), n)
        cases.append((f"random-{i + 1} n={n}", values))

    return cases


def main():
    parser = argparse.ArgumentParser(description="Stress-test the MEDIUM algorithm.")
    parser.add_argument("--push-swap", default="./push_swap")
    parser.add_argument("--checker", default="./checker_linux")
    parser.add_argument("--random-cases", type=int, default=200)
    parser.add_argument("--max-size", type=int, default=500)
    parser.add_argument("--seed", type=int, default=42)
    args = parser.parse_args()

    if args.max_size < 2 or args.random_cases < 0:
        parser.error("--max-size must be >= 2 and --random-cases must be >= 0")

    cases = build_cases(args.random_cases, args.max_size, args.seed)
    passed = 0

    print(f"Running {len(cases)} MEDIUM tests (seed={args.seed})...")
    for label, values in cases:
        ok, message = run_case(args.push_swap, args.checker, values, label)
        if ok:
            passed += 1
            print(message)
        else:
            print("\nFAIL:", message, file=sys.stderr)
            print(f"\nResult: {passed}/{len(cases)} passed.", file=sys.stderr)
            return 1

    print(f"\nALL TESTS PASSED: {passed}/{len(cases)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
