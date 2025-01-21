#!/usr/bin/env sh

set -e
ghc Fibonacciness.hs && cat Fibonacciness.in | ./Fibonacciness
