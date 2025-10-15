#!/usr/bin/env sh

src="$1"
mode="${2:-dev}"
base="${src%.c}"
mkdir -p out

CFLAGS="-Wall -Wextra -Wformat=2 -std=c11 -pedantic"
LDFLAGS="-lm"

case "$mode" in
    dev)
        flags=""
        ;;
    debug)
        flags="-g -pg -O0"
        ;;
    release)
        flags="-O3"
        ;;
    *)
        echo "Unknown mode: $mode"
        echo "Usage: ./build.sh file.c [dev|debug|release]"
        return 1
        ;;
esac

gcc $CFLAGS $flags "$src" -o out/"$base" $LDFLAGS
