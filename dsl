#!/usr/bin/env bash
# Usage:  ./dsl <question number>     e.g.  ./dsl 5      (compiles and runs Q05)
#         ./dsl list                  shows all questions
# Works from a cloned repo (uses local files) or downloads the file from GitHub if not found locally.

GITHUB_USER="YOUR_USERNAME"
GITHUB_REPO="YOUR_REPO"
BRANCH="main"

if [ -z "$1" ] || [ "$1" = "list" ]; then
  echo "Usage: dsl <1-16>"
  echo " 1 Linear Search            9 Pinnacle Club - Delete/Concat"
  echo " 2 Binary Search           10 Cinemax Ticket Booking"
  echo " 3 Selection Sort          11 Balanced Parentheses"
  echo " 4 Bubble Sort             12 Pizza Parlor Queue"
  echo " 5 Hash - Linear Probing   13 BST - Longest Path/Min"
  echo " 6 Hash - Double Hashing   14 BST - Mirror/Search"
  echo " 7 Hash - Quadratic        15 Flight Graph - BFS"
  echo " 8 Pinnacle Club - Add     16 Flight Graph - DFS"
  exit 0
fi

NUM=$(printf "%02d" "$((10#$1))" 2>/dev/null) || { echo "Enter a number from 1 to 16"; exit 1; }
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" 2>/dev/null && pwd)"
FILE=$(ls "$DIR"/Q${NUM}_*.cpp 2>/dev/null | head -n 1)

if [ -z "$FILE" ]; then
  TMP=$(mktemp -d)
  NAME=$(curl -s "https://api.github.com/repos/$GITHUB_USER/$GITHUB_REPO/contents?ref=$BRANCH" \
         | grep -o "\"name\": *\"Q${NUM}_[^\"]*\.cpp\"" | head -n 1 | sed 's/.*: *"//;s/"//')
  [ -z "$NAME" ] && { echo "Question $1 not found."; exit 1; }
  curl -s "https://raw.githubusercontent.com/$GITHUB_USER/$GITHUB_REPO/$BRANCH/$NAME" -o "$TMP/$NAME"
  FILE="$TMP/$NAME"
fi

OUT=$(mktemp)
g++ -o "$OUT" "$FILE" && "$OUT"
echo
rm -f "$OUT"
